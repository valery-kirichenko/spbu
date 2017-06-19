package net.task.bank.app;

import javax.servlet.annotation.WebServlet;

import com.vaadin.annotations.Theme;
import com.vaadin.annotations.VaadinServletConfiguration;
import com.vaadin.server.VaadinRequest;
import com.vaadin.server.VaadinServlet;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.*;

import net.task.bank.converter.Currency;
import net.task.bank.dao.DBClientsController;
import net.task.bank.dao.DBCreditsController;
import net.task.bank.models.Client;
import net.task.bank.models.Credit;
import net.task.bank.sdata.Storage;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.ArrayList;
import java.util.List;
import java.util.Optional;


/**
 * This UI is the application entry point. A UI may either represent a browser window
 * (or tab) or some part of a html page where a Vaadin application is embedded.
 * <p>
 * The UI is initialized using {@link #init(VaadinRequest)}. This method is intended to be
 * overridden to add component to the user interface and initialize non-component functionality.
 */
@SpringUI
@Theme("mytheme")
public class MyUI extends UI {
    @Autowired
    private Storage dataStore;

    @Autowired
    private DBClientsController clientsController;

    @Autowired
    private DBCreditsController creditsController;

    @Override
    protected void init(VaadinRequest vaadinRequest) {
        getPage().setTitle("BankServer");

        dataStore.setClientList(clientsController.getAllClients());
        dataStore.setCreditList(creditsController.getAllCredits());

        final VerticalLayout layout = new VerticalLayout();
        final HorizontalLayout horizontalClient = new HorizontalLayout();
        final HorizontalLayout horizontalCredit = new HorizontalLayout();

        final TextField name = new TextField("Name:");
        final TextField lastName = new TextField("Last name:");
        final TextField middleName = new TextField("Middle name:");
        final TextField phone = new TextField("Phone:");
        final TextField passport = new TextField("Passport:");
        final TextField oldPassport = new TextField("Old passport:");
        final DateField birthday = new DateField("Birthday:");

        final TextField amount = new TextField("Amount:");
        final TextField percent = new TextField("Percent:");
        final TextField paidSum = new TextField("Paid Sum:");
        final TextField needPaid = new TextField("Need to Pay:");
        final DateField closingDate = new DateField("Closing Date:");

        final TextField tempId = new TextField("-1");

        final Grid<Client> outTableClients = new Grid<>();
        final Grid<Credit> outTableCredits = new Grid<>();

        final TextField firstNameEditor = new TextField();
        final TextField lastNameEditor = new TextField();
        final TextField middleNameEditor = new TextField();
        final TextField phoneEditor = new TextField();
        final TextField passportEditor = new TextField();
        final TextField oldPassportEditor = new TextField();
        final DateField birthdayEditor = new DateField();


        final Label copyright = new Label("© All rights reserved, V. V. Vasilyev; " +
                "Valery Kirichenko (https://t.me/valera5505); 2017");


        outTableCredits.setWidth("1800px");
        outTableCredits.setHeight("250px");
        outTableCredits.addColumn(Credit::getClientID).setCaption("ID").setWidth(100);
        outTableCredits.addColumn(Credit::getAmount).setCaption("Amount");//.setEditorComponent(amountEditor.getOptionalValue(), Credit::setAmount);
        outTableCredits.addColumn(Credit::getPercent).setCaption("Percent");//.setEditorComponent(percentEditor, Credit::setPercent);
        outTableCredits.addColumn(Credit::getPaidSum).setCaption("Paid Sum");//.setEditorComponent(paidSumEditor, Credit::setPaidSum);
        outTableCredits.addColumn(Credit::getNeedPaid).setCaption("Need Paid");//.setEditorComponent(needPaidEditor, Credit::setNeedPaid);
        outTableCredits.addColumn(Credit::getClosingDate).setCaption("Closing Date")
                .setEditorComponent(closingDate, Credit::setClosingDate);
        outTableCredits.getEditor().setEnabled(true);
        outTableCredits.setStyleGenerator(credit -> credit.isOverdue() ? "overdue" :
                (credit.isMayBeOverdue() ? "mayBeOverdue" : null));

        outTableClients.setWidth("1800px");
        outTableClients.setHeight("350px");
        outTableClients.addColumn(Client::getID).setCaption("ID").setWidth(100);
        outTableClients.addColumn(Client::getFirstName).setCaption("First Name")
                .setEditorComponent(firstNameEditor, Client::setFirstName);
        outTableClients.addColumn(Client::getMiddleName).setCaption("Middle Name")
                .setEditorComponent(middleNameEditor, Client::setMiddleName);
        outTableClients.addColumn(Client::getLastName).setCaption("Last Name")
                .setEditorComponent(lastNameEditor, Client::setLastName);
        outTableClients.addColumn(Client::getPhone).setCaption("Phone")
                .setEditorComponent(phoneEditor, Client::setPhone);
        outTableClients.addColumn(Client::getPassport).setCaption("Passport")
                .setEditorComponent(passportEditor, Client::setPassport);
        outTableClients.addColumn(Client::getOldPassport).setCaption("Old Passport")
                .setEditorComponent(oldPassportEditor, Client::setOldPassport);
        outTableClients.addColumn(Client::getBirthday).setCaption("Birthday")
                .setEditorComponent(birthdayEditor, Client::setBirthday);
        outTableClients.getEditor().setEnabled(true);
        outTableClients.setStyleGenerator(client -> client.isDebtor() ? "overdue" :
                (client.isMayBeDebtor() ? "mayBeOverdue" : null)
        );

        outTableClients.addSelectionListener(event -> {
            Optional<Client> client = event.getFirstSelectedItem();
            client.ifPresent(client1 -> {
                outTableCredits.setItems(client1.getCredits());
                tempId.setValue(Integer.toString(client1.getID()));
            });
        });

        outTableClients.setItems(dataStore.getClientList());

        Button buttonClient = new Button("Add client");
        Button buttonCredit = new Button("Add credit");

        buttonClient.addClickListener(event -> {
            if (name.getValue().isEmpty() || lastName.getValue().isEmpty() ||
                    middleName.getValue().isEmpty() || phone.getValue().isEmpty() ||
                    passport.getValue().isEmpty() || oldPassport.getValue().isEmpty() || birthday.isEmpty())
                Notification.show("Incorrect sdata for new client!");
            else {
                Client client = new Client();
                Integer maxId = -1;
                for (Client clientFor : clientsController.getAllClients())
                    if (maxId < clientFor.getID() || (maxId == -1)) {
                        maxId = clientFor.getID();
                    }
                maxId = (maxId != -1 ? ++maxId : 0);
                client.setID(maxId);
                client.setFirstName(name.getValue());
                client.setLastName(lastName.getValue());
                client.setMiddleName(middleName.getValue());
                client.setPhone(phone.getValue());
                client.setPassport(passport.getValue());
                client.setBirthday(birthday.getValue());
                client.setOldPassport(oldPassport.getValue());

                clientsController.saveNewClient(client);
                dataStore.getClientList().add(client);

                outTableClients.setItems(dataStore.getClientList());
                Notification.show("Client " + name.getValue() + " was added!");

                name.clear();
                lastName.clear();
                middleName.clear();
                phone.clear();
                passport.clear();
                oldPassport.clear();
                birthday.clear();
            }
        });

        buttonCredit.addClickListener(event -> {
            if (tempId.getValue().isEmpty() || amount.getValue().isEmpty() ||
                    percent.getValue().isEmpty() || paidSum.getValue().isEmpty() ||
                    needPaid.getValue().isEmpty() || closingDate.isEmpty())
                Notification.show("Incorrect sdata for new client's credit!");
            else {
                Credit credit = new Credit();

                credit.setClientID(Integer.parseInt(tempId.getValue()));
                credit.setAmount(Double.parseDouble(amount.getValue()));
                credit.setPercent(Double.parseDouble(percent.getValue()));
                credit.setPaidSum(Double.parseDouble(paidSum.getValue()));
                credit.setNeedPaid(Double.parseDouble(needPaid.getValue()));
                credit.setClosingDate(closingDate.getValue());

                creditsController.saveNewCredit(credit);
                dataStore.getCreditList().add(credit);

                Client client = dataStore.getClient(Integer.parseInt(tempId.getValue()));
                client.addCredit(credit);

                Optional<Client> clientOptional = Optional.of(client);
                clientOptional.ifPresent(client1 -> outTableCredits.setItems(client1.getCredits()));
                Notification.show("Credit for client with id " + tempId.getValue() + " was added!");

                amount.clear();
                percent.clear();
                paidSum.clear();
                needPaid.clear();
                closingDate.clear();
            }
        });

        percent.addValueChangeListener(valueChangeEvent -> {
            if (!percent.isEmpty()) {
                Double temp = Double.parseDouble(amount.getValue()) *
                        (Double.parseDouble(percent.getValue()) + 100) / 100;
                needPaid.setValue(temp.toString());
            }
        });

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
            if (!tempId.isEmpty()) {
                Integer id = Integer.parseInt(tempId.getValue());
                outTableCredits.setItems(dataStore.creditUpdate(boxCurrency.getValue(), id));
            }
        });

        horizontalClient.addComponents(name, lastName, middleName, phone, passport, oldPassport, birthday);
        horizontalCredit.addComponents(amount, percent, paidSum, needPaid, closingDate);
        layout.addComponents(horizontalClient, buttonClient, outTableClients, outTableCredits,
                horizontalCredit, buttonCredit, boxCurrency, copyright);

        setContent(layout);
    }


    @WebServlet(urlPatterns = "/*", name = "MyUIServlet", asyncSupported = true)
    @VaadinServletConfiguration(ui = MyUI.class, productionMode = false)
    public static class MyUIServlet extends VaadinServlet {
    }
}
