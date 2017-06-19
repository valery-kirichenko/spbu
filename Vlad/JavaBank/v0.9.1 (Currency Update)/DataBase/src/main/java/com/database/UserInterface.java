package com.database;

import com.database.Cells.Client;
import com.database.Cells.Credit;
import com.database.CurrencyConverter.Currency;
import com.database.CurrencyConverter.CurrencyServiceClass;
import com.vaadin.annotations.Theme;
import com.vaadin.data.HasValue;
import com.vaadin.server.Page;
import com.vaadin.server.VaadinRequest;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.*;
import com.vaadin.ui.components.grid.EditorSaveListener;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;

import java.util.ArrayList;
import java.util.List;
import java.util.Set;

@Theme("mytheme")
@SpringUI
public class UserInterface extends UI {

    @Autowired
    JdbcTemplate template;
    @Autowired
    MainControllerClass controllerClass;
    @Autowired
    CurrencyServiceClass currencyService;

    private List<Credit> creditUpdate(Currency newCurrency, Integer id) {
        List<Credit> creditUpdatedList = template.query("SELECT * FROM credits WHERE clientID =" + id, new CreditRowMapper());
        System.out.println(newCurrency);
        System.out.println(Currency.RUB);
        if (!newCurrency.equals(Currency.RUB)) {
            Double multiplication = currencyService.getRate(Currency.RUB, newCurrency);
            for (Credit credit : creditUpdatedList) {
                credit.setCashTotal(credit.getCashTotal() * multiplication);
                credit.setCashWithPercent(credit.getCashWithPercent() * multiplication);
                credit.setCashPaid(credit.getCashPaid() * multiplication);
            }
        }
        return creditUpdatedList;
    }

    @Override
    protected void init(VaadinRequest vaadinRequest) {
        VerticalLayout layout = new VerticalLayout();

        List<Client> clientList = template.query("SELECT * FROM clients", new ClientRowMapper());

        final Grid<Client> clientGrid = new Grid<>();
        clientGrid.getEditor().setEnabled(true);

        clientGrid.setHeight("400px");
        clientGrid.setWidth("100%");

        clientGrid.setItems(clientList);
        clientGrid.addColumn(Client::getId).setCaption("ID");
        clientGrid.addColumn(Client::getName).setCaption("Name").setEditorComponent(new TextField(), Client::setName);
        clientGrid.addColumn(Client::getBirthday).setCaption("Birthday").setEditorComponent(new TextField(), Client::setBirthday);
        clientGrid.addColumn(Client::getPhoneNumber).setCaption("Phone Number").setEditorComponent(new TextField(), Client::setPhoneNumber);
        clientGrid.addColumn(Client::getPassport).setCaption("Passport").setEditorComponent(new TextField(), Client::setPassport);
        clientGrid.addColumn(Client::getOldPassport).setCaption("Old Passport").setEditorComponent(new TextField(), Client::setOldPassport);

        clientGrid.getEditor().addSaveListener((EditorSaveListener<Client>) editorSaveEvent -> {
            controllerClass.updateClient(
                    editorSaveEvent.getBean().getId(),
                    editorSaveEvent.getBean().getName(),
                    editorSaveEvent.getBean().getPhoneNumber(),
                    editorSaveEvent.getBean().getBirthday(),
                    editorSaveEvent.getBean().getPassport(),
                    editorSaveEvent.getBean().getOldPassport()
            );
        });


        final Grid<Credit> creditGrid = new Grid<>();
        creditGrid.setHeight("400px");
        creditGrid.setWidth("100%");

        creditGrid.addColumn(Credit::getID).setCaption("ID");
        creditGrid.addColumn(Credit::getClientID).setCaption("Client ID");
        creditGrid.addColumn(Credit::getCashTotal).setCaption("Total Cash");
        creditGrid.addColumn(Credit::getCashWithPercent).setCaption("Total Cash With Percent");
        creditGrid.addColumn(Credit::getPercent).setCaption("Percent");
        creditGrid.addColumn(Credit::getCashPaid).setCaption("Paid Cash");
        creditGrid.addColumn(Credit::getDeadline).setCaption("Deadline");
        creditGrid.setStyleGenerator(credit -> credit.isOverdue() ? "overdue" : null);

        HorizontalLayout createClientLayout = new HorizontalLayout();
        Button createClientButton = new Button("Create New Client");
        createClientButton.setHeight("60px");
        TextField createClientName = new TextField("Name: ");
        TextField createClientPhoneNumber = new TextField("Phone Number:");
        TextField createClientBirthday = new TextField("Birthday:");
        TextField createClientPassport = new TextField("Passport:");
        TextField createClientOldPassport = new TextField("Old Passport:");
        createClientLayout.addComponents(
                createClientButton,
                createClientName,
                createClientBirthday,
                createClientPhoneNumber,
                createClientPassport,
                createClientOldPassport
        );

        createClientButton.addClickListener(clickEvent -> {
            try {
                if (createClientOldPassport.isEmpty()) {
                    createClientOldPassport.setValue("NULL");
                }
                controllerClass.createClient(
                        createClientName.getValue(),
                        createClientPhoneNumber.getValue(),
                        createClientBirthday.getValue(),
                        createClientPassport.getValue(),
                        createClientOldPassport.getValue()
                );

                List<Client> clientUpdate = template.query("SELECT * FROM clients", new ClientRowMapper());
                clientGrid.setItems(clientUpdate);

                createClientName.clear();
                createClientPhoneNumber.clear();
                createClientBirthday.clear();
            }
            catch (IllegalArgumentException e) {
                new Notification(
                        e.toString(),
                        Notification.Type.ERROR_MESSAGE).show(Page.getCurrent()
                );
            }
            createClientPassport.clear();
            createClientOldPassport.clear();
        });

        HorizontalLayout createCreditLayout = new HorizontalLayout();
        Button createCreditButton = new Button("Create New Credit");
        createCreditButton.setHeight("60px");
        TextField createCreditClientID = new TextField("Client ID:");
        TextField createCreditCashWithOutPercent = new TextField("Credit Without Percent:");
        TextField createCreditPercent = new TextField("Percent:");
        TextField createCreditCashWithPercent = new TextField("Credit With Percent:");
        TextField createCreditCashPaid = new TextField("Cash Paid:");
        DateField createCreditDeadline = new DateField("Deadline:");

        createCreditButton.setEnabled(false);
        createCreditClientID.setEnabled(false);
        createCreditCashWithOutPercent.setEnabled(false);
        createCreditPercent.setEnabled(false);
        createCreditCashWithPercent.setEnabled(false);
        createCreditCashPaid.setEnabled(false);
        createCreditDeadline.setEnabled(false);

        createCreditLayout.addComponents(
                createCreditButton,
                createCreditClientID,
                createCreditCashWithOutPercent,
                createCreditPercent,
                createCreditCashWithPercent,
                createCreditCashPaid,
                createCreditDeadline
        );

        ////
        //  Currency
        List<Currency> namesCurrency = new ArrayList<>();
        namesCurrency.add(Currency.RUB);
        namesCurrency.add(Currency.USD);
        namesCurrency.add(Currency.EUR);
        ComboBox<Currency> boxCurrency = new ComboBox<>("Currency");
        boxCurrency.setEmptySelectionAllowed(false);
        boxCurrency.setItems(namesCurrency);
        boxCurrency.setValue(Currency.RUB);

        boxCurrency.setItemCaptionGenerator(Currency::toString);
        boxCurrency.addValueChangeListener(valueChangeEvent -> {
            if (!createCreditClientID.isEmpty()) {
                Integer id = Integer.parseInt(createCreditClientID.getValue());
                creditGrid.setItems(creditUpdate(boxCurrency.getValue(), id));
            }
        });
        //
        ////

        createCreditButton.addClickListener(clickEvent -> {
            Integer id = Integer.parseInt(createCreditClientID.getValue());
            try {
                controllerClass.createCredit(
                        id,
                        Double.parseDouble(createCreditCashWithOutPercent.getValue()),
                        Double.parseDouble(createCreditCashPaid.getValue()),
                        Double.parseDouble(createCreditCashWithPercent.getValue()),
                        Double.parseDouble(createCreditPercent.getValue()),
                        createCreditDeadline.getValue()
                );
                //private List<Credit> creditUpdate(Currency actualCurrency, Currency newCurrency, Integer id) {
                creditGrid.setItems(creditUpdate(boxCurrency.getValue(), id));
            }
            catch (IllegalArgumentException e) {
                new Notification(
                        e.toString(),
                        Notification.Type.ERROR_MESSAGE).show(Page.getCurrent()
                );
            }

            createCreditCashWithOutPercent.clear();
            createCreditCashPaid.clear();
            createCreditCashWithPercent.clear();
            createCreditPercent.clear();
            createCreditDeadline.clear();
        });

        createCreditPercent.addValueChangeListener(valueChangeEvent -> {
            if (!createCreditPercent.isEmpty()) {
                Double temp = Double.parseDouble(createCreditCashWithOutPercent.getValue())*(Double.parseDouble(createCreditPercent.getValue()) + 100)/100;
                createCreditCashWithPercent.setValue(temp.toString());
            }
        });

        HorizontalLayout deleteLayout = new HorizontalLayout();
        Button deleteClientButton = new Button("Delete Client");
        deleteClientButton.setHeight("60px");
        Button deleteCreditButton = new Button("Delete Credit");
        deleteCreditButton.setHeight("60px");
        TextField deleteCreditID = new TextField("Selected Credit ID");
        deleteClientButton.setEnabled(false);
        deleteCreditButton.setEnabled(false);
        deleteCreditID.setEnabled(false);

        deleteClientButton.addClickListener((Button.ClickListener) clickEvent -> {
            Integer id = Integer.parseInt(createCreditClientID.getValue());
            controllerClass.deleteClient(id);
            List<Client> clientUpdate = template.query("SELECT * FROM clients", new ClientRowMapper());
            clientGrid.setItems(clientUpdate);
            creditGrid.setItems(creditUpdate(boxCurrency.getValue(), id));
        });

        deleteCreditButton.addClickListener((Button.ClickListener) clickEvent -> {
            Integer id = Integer.parseInt(createCreditClientID.getValue());
            controllerClass.deleteCredit(Integer.parseInt(deleteCreditID.getValue()));
            creditGrid.setItems(creditUpdate(boxCurrency.getValue(), id));
        });

        deleteLayout.addComponents(
                deleteClientButton,
                deleteCreditButton,
                deleteCreditID
        );

        layout.addComponents(boxCurrency, clientGrid, createClientLayout, createCreditLayout, deleteLayout, creditGrid);
        setContent(layout);

        clientGrid.addSelectionListener(selectionEvent -> {
            Set<Client> fClient = selectionEvent.getAllSelectedItems();
            if (!fClient.isEmpty()) {
                Integer id = fClient.stream().findFirst().get().getId();
                creditGrid.setItems(creditUpdate(boxCurrency.getValue(), id));

                createCreditButton.setEnabled(true);
                createCreditClientID.setValue(id.toString());
                createCreditCashWithOutPercent.setEnabled(true);
                createCreditPercent.setEnabled(true);
                createCreditCashPaid.setEnabled(true);
                createCreditDeadline.setEnabled(true);

                deleteClientButton.setEnabled(true);
            }
            else {
                createCreditButton.setEnabled(false);
                createCreditClientID.clear();
                createCreditCashWithOutPercent.setEnabled(false);
                createCreditPercent.setEnabled(false);
                createCreditCashPaid.setEnabled(false);
                createCreditDeadline.setEnabled(false);

                deleteClientButton.setEnabled(false);
            }
        });

        creditGrid.addSelectionListener(selectionEvent -> {
           Set<Credit> fCredit = selectionEvent.getAllSelectedItems();
           if (!fCredit.isEmpty()) {
               Integer id = fCredit.stream().findFirst().get().getID();
               deleteCreditID.setValue(id.toString());
               deleteCreditButton.setEnabled(true);
           }
           else {
               deleteCreditID.clear();
               deleteCreditButton.setEnabled(false);
           }
        });
    }
}
