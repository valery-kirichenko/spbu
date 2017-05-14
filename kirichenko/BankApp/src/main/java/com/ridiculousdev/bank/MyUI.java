package com.ridiculousdev.bank;

import javax.servlet.annotation.WebServlet;

import com.mysql.jdbc.Statement;
import com.vaadin.annotations.Theme;
import com.vaadin.annotations.VaadinServletConfiguration;
import com.vaadin.data.provider.DataProvider;
import com.vaadin.data.provider.ListDataProvider;
import com.vaadin.server.Page;
import com.vaadin.server.VaadinRequest;
import com.vaadin.server.VaadinServlet;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.*;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.PreparedStatementCreator;
import org.springframework.jdbc.support.GeneratedKeyHolder;
import org.springframework.jdbc.support.KeyHolder;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.time.LocalDate;
import java.util.*;

@SpringUI
@Theme("mytheme")
public class MyUI extends UI {

    private final String[] filters = {"", "Все"};

    private boolean filterClients(Client client) {
        boolean expression = filters[0].equals("") ||
                (client.getFirstName().toLowerCase().contains(filters[0]) ||
                        client.getLastName().toLowerCase().contains(filters[0]) ||
                        client.getMiddleName().toLowerCase().contains(filters[0]) ||
                        Integer.toString(client.getId()).contains(filters[0]) ||
                        Double.toString(client.getPassport()).contains(filters[0]) ||
                        client.getBirthDate().toString().contains(filters[0]) ||
                        client.getPhoneNumber().contains(filters[0]) ||
                        (client.getFirstName() + " " + client.getLastName() + " " + client.getMiddleName())
                                .toLowerCase().contains(filters[0]));
        switch (filters[1]) {
            case "Все":
                return expression;
            case "Должники":
                return expression && !client.isPaid();
            case "Святые":
                return expression && client.isPaid();
        }
        return true;
    }

    @Qualifier("databaseStorage")
    @Autowired
    private DataStorage storage;

    @Autowired
    JdbcTemplate template;

    @Override
    protected void init(VaadinRequest vaadinRequest) {
        storage.readData();
        final VerticalLayout layout = new VerticalLayout();

        ListDataProvider<Client> clientsProvider = DataProvider.ofCollection(storage.getClients());

        final int[] lastId = {0};
        for (Client client : storage.getClients()) {
            if (client.getId() > lastId[0]) lastId[0] = client.getId();
        }

        TextField editFirstName = new TextField();
        TextField editLastName = new TextField();
        TextField editMiddleName = new TextField();
        TextField editPassport = new TextField();
        TextField editPhoneNumber = new TextField();
        DateField editBirthDate = new DateField();

        Grid<Client> clientsGrid = new Grid<>();
        clientsGrid.setWidth("100%");

        clientsGrid.setDataProvider(clientsProvider);
        clientsGrid.addColumn(Client::getId).setCaption("Id");
        clientsGrid.addColumn(Client::getFirstName)
                .setEditorComponent(editFirstName, (client, s) -> {
                    client.setFirstName(s);
                    template.update("UPDATE clients SET firstName = ? WHERE id = ?", s, client.getId());
                })
                .setCaption("Имя");
        clientsGrid.addColumn(Client::getLastName)
                .setEditorComponent(editLastName, (client, s) -> {
                    client.setLastName(s);
                    template.update("UPDATE clients SET lastName = ? WHERE id = ?", s, client.getId());
                })
                .setCaption("Фамилия");
        clientsGrid.addColumn(Client::getMiddleName)
                .setEditorComponent(editMiddleName, (client, s) -> {
                    client.setMiddleName(s);
                    template.update("UPDATE clients SET middleName = ? WHERE id = ?", s, client.getId());
                })
                .setCaption("Отчество");
        clientsGrid.addColumn(Client::getPassportString)
                .setEditorComponent(editPassport, (client, s) -> {
                    client.setPassport(s);
                    template.update("UPDATE clients SET passport = ? WHERE id = ?", s, client.getId());
                })
                .setCaption("Паспорт");
        clientsGrid.addColumn(Client::getPhoneNumber)
                .setEditorComponent(editPhoneNumber, (client, s) -> {
                    client.setPhoneNumber(s);
                    template.update("UPDATE clients SET phoneNumber = ? WHERE id = ?", s, client.getId());
                })
                .setCaption("Номер телефона");
        clientsGrid.addColumn(Client::getBirthDate)
                .setEditorComponent(editBirthDate, (client, s) -> {
                    client.setBirthDate(s);
                    template.update("UPDATE clients SET birthDate = ? WHERE id = ?", java.sql.Date.valueOf(s), client.getId());
                })
                .setCaption("Дата рождения");

        clientsGrid.getEditor().setEnabled(true);
        clientsGrid.setStyleGenerator(client -> client.isDodger() ? "dodger" : client.isPaid() ? null : "unpaid");


        TextField editTotal = new TextField();
        TextField editRate = new TextField();
        TextField editPaid = new TextField();
        DateField editClosingDate = new DateField();

        Grid<Credit> creditsGrid = new Grid<>();
        creditsGrid.setWidth("100%");
        creditsGrid.setHeight("500px");
        creditsGrid.addColumn(Credit::getTotalString)
                .setEditorComponent(editTotal, (credit, s) -> {
                    credit.setTotal(s);
                    template.update("UPDATE credits SET total = ?, payable = ? WHERE id = ?",
                            credit.getTotal(), credit.getPayable(), credit.getDatabaseId());
                })
                .setCaption("Сумма");
        creditsGrid.addColumn(Credit::getRateString)
                .setEditorComponent(editRate, (credit, s) -> {
                    credit.setRate(s);
                    template.update("UPDATE credits SET rate = ?, payable = ? WHERE id = ?",
                            credit.getRate(), credit.getPayable(), credit.getDatabaseId());
                })
                .setCaption("Процент");
        creditsGrid.addColumn(Credit::getPaidString)
                .setEditorComponent(editPaid, (credit, s) -> {
                    credit.setPaid(s);
                    template.update("UPDATE credits SET paid = ? WHERE id = ?",
                            credit.getPaid(), credit.getDatabaseId());
                })
                .setCaption("Заплачено");
        creditsGrid.addColumn(Credit::getPayable).setCaption("К выплате");
        creditsGrid.addColumn(Credit::getClosingDate)
                .setEditorComponent(editClosingDate, (credit, s) -> {
                    credit.setClosingDate(s);
                    template.update("UPDATE credits SET closingDate = ? WHERE id = ?",
                            java.sql.Date.valueOf(credit.getClosingDate()), credit.getDatabaseId());
                })
                .setCaption("Дата закрытия");

        creditsGrid.getEditor().setEnabled(true);
        creditsGrid.setStyleGenerator(credit -> credit.isDodger() ? "dodger" : credit.isPaid() ? null : "unpaid");

        final int[] selectedId = {-1};

        clientsGrid.addSelectionListener(event -> {
            Optional<Client> selected = event.getFirstSelectedItem();
            selected.ifPresent(client -> {
                creditsGrid.setItems(client.getCredits());
                selectedId[0] = client.getId();
            });
        });

        HorizontalLayout addClientForm = new HorizontalLayout();
        final TextField firstName = new TextField("Имя");
        final TextField lastName = new TextField("Фамилия");
        final TextField middleName = new TextField("Отчество");
        final TextField passport = new TextField("Паспорт");
        final TextField phoneNumber = new TextField("Номер телефона");
        final DateField birthDate = new DateField("Дата рождения");
        birthDate.setValue(LocalDate.now().minusYears(18));
        final Button addClient = new Button("Добавить");
        addClientForm.addComponents(firstName, lastName, middleName, passport, phoneNumber, birthDate);

        addClient.addClickListener(clickEvent -> {
            try {
                if (firstName.getValue().equals("") ||
                        lastName.getValue().equals("") ||
                        middleName.getValue().equals("") ||
                        phoneNumber.getValue().equals("")) throw new Exception("Empty field");
                Client newClient = new Client();
                newClient.setId(++lastId[0]);
                newClient.setFirstName(firstName.getValue());
                newClient.setLastName(lastName.getValue());
                newClient.setMiddleName(middleName.getValue());
                newClient.setPassport(Integer.parseInt(passport.getValue()));
                newClient.setPhoneNumber(phoneNumber.getValue());
                newClient.setBirthDate(birthDate.getValue());
                storage.getClients().add(newClient);
                template.update(
                        "INSERT INTO clients (id, passport, firstName, lastName, middleName, phoneNumber, birthDate)" +
                                "VALUES (?, ?, ?, ?, ?, ?, ?)",
                        lastId[0],
                        passport.getValue(),
                        firstName.getValue(),
                        lastName.getValue(),
                        middleName.getValue(),
                        phoneNumber.getValue(),
                        java.sql.Date.valueOf(birthDate.getValue()));
                firstName.setValue("");
                lastName.setValue("");
                middleName.setValue("");
                passport.setValue("");
                phoneNumber.setValue("");
                birthDate.setValue(LocalDate.now().minusYears(18));
            } catch (Exception e) {
                new Notification(
                        "Ошибка",
                        "Неправильно введены данные",
                        Notification.Type.WARNING_MESSAGE).show(Page.getCurrent());
            }
        });

        HorizontalLayout addCreditForm = new HorizontalLayout();
        final TextField total = new TextField("Сумма");
        total.setValue("0.0");
        final TextField rate = new TextField("Процент");
        rate.setValue("1.0");
        final TextField payable = new TextField("К выплате");
        payable.setReadOnly(true);
        final DateField closingDate = new DateField("Дата закрытия");
        closingDate.setValue(LocalDate.now().plusYears(1));
        final Button addCredit = new Button("Добавить");

        total.addValueChangeListener(valueChangeEvent -> {
            try {
                payable.setValue(Double.toString(Double.parseDouble(total.getValue()) * (1.0 + Double.parseDouble(rate.getValue()) / 100)));
            } catch (NumberFormatException e) {
            }
        });

        rate.addValueChangeListener(valueChangeEvent -> {
            try {
                payable.setValue(Double.toString(Double.parseDouble(total.getValue()) * (1.0 + Double.parseDouble(rate.getValue()) / 100)));
            } catch (NumberFormatException e) {
            }
        });

        addCreditForm.addComponents(total, rate, payable, closingDate);

        addCredit.addClickListener(clickEvent -> {
            try {
                double p = Double.parseDouble(total.getValue()) * (1.0 + Double.parseDouble(rate.getValue()) / 100);
                payable.setValue(Double.toString(p));

                if (closingDate.getValue().isBefore(LocalDate.now()))
                    throw new NumberFormatException("Incorrect date");

                Credit newCredit = new Credit();
                newCredit.setId(selectedId[0]);
                newCredit.setClosingDate(closingDate.getValue());
                newCredit.setPaid(0.0);
                newCredit.setPayable(p);
                newCredit.setRate(Double.parseDouble(rate.getValue()));
                newCredit.setTotal(Double.parseDouble(total.getValue()));

                for (Client client : storage.getClients()) {
                    if (client.getId() == selectedId[0]) {
                        creditsGrid.setItems(client.getCredits());
                        KeyHolder holder = new GeneratedKeyHolder();
                        template.update(connection -> {
                            PreparedStatement ps = connection.prepareStatement(
                                    "INSERT INTO credits (total, rate, paid, payable, closingDate, clientId)" +
                                            "VALUES (?, ?, ?, ?, ?, ?)", Statement.RETURN_GENERATED_KEYS);
                            ps.setDouble(1, Double.parseDouble(total.getValue()));
                            ps.setDouble(2, Double.parseDouble(rate.getValue()));
                            ps.setDouble(3, 0.0);
                            ps.setDouble(4, p);
                            ps.setDate(5, java.sql.Date.valueOf(closingDate.getValue()));
                            ps.setInt(6, selectedId[0]);

                            return ps;
                        }, holder);
                        newCredit.setDatabaseId(holder.getKey().intValue());
                        storage.addCredit(newCredit);
                        client.addCredit(newCredit);
                    }
                }
                closingDate.setValue(LocalDate.now().plusYears(1));
                rate.setValue("1.0");
                total.setValue("0.0");
                payable.setValue("");
            } catch (NumberFormatException e) {
                new Notification(
                        "Ошибка",
                        "Неправильно введены данные",
                        Notification.Type.WARNING_MESSAGE).show(Page.getCurrent());
            }
        });

        HorizontalLayout filters = new HorizontalLayout();
        TextField search = new TextField("Поиск");
        search.addValueChangeListener(valueChangeEvent -> {
            clientsProvider.clearFilters();
            this.filters[0] = valueChangeEvent.getValue().toLowerCase();
            clientsProvider.addFilter(this::filterClients);
        });

        RadioButtonGroup<String> clientsFilter = new RadioButtonGroup<>();
        clientsFilter.setItems("Все", "Должники", "Святые");
        clientsFilter.setSelectedItem("Все");
        clientsFilter.addSelectionListener(singleSelectionEvent -> {
            Optional<String> selected = singleSelectionEvent.getSelectedItem();
            selected.ifPresent(selectedString -> {
                clientsProvider.clearFilters();
                this.filters[1] = selectedString;
                clientsProvider.addFilter(this::filterClients);
            });
        });
        filters.addComponents(search, clientsFilter);
        layout.addComponents(addClientForm, addClient, filters, clientsGrid, creditsGrid, addCreditForm, addCredit);

        setContent(layout);
    }

    @WebServlet(urlPatterns = "/*", name = "MyUIServlet", asyncSupported = true)
    @VaadinServletConfiguration(ui = MyUI.class, productionMode = false)
    public static class MyUIServlet extends VaadinServlet {
    }
}
