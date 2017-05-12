package net.task.bank.app;

import javax.servlet.annotation.WebServlet;

import com.vaadin.annotations.Theme;
import com.vaadin.annotations.VaadinServletConfiguration;
import com.vaadin.server.VaadinRequest;
import com.vaadin.server.VaadinServlet;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.*;

import net.task.bank.dao.DBClientsController;
import net.task.bank.dao.DBCreditsController;
import net.task.bank.models.Client;
import net.task.bank.models.Credit;
import net.task.bank.rsdata.Reader;
import net.task.bank.rsdata.Storage;
import org.springframework.beans.factory.annotation.Autowired;

import java.io.File;
import java.io.FileOutputStream;
import java.net.URL;
import java.net.URLDecoder;
import java.time.ZoneId;
import java.util.Date;
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
    private Reader dataReader;

    @Autowired
    private Storage dataStore;

    @Autowired
    private DBClientsController clientsController;

    @Autowired
    private DBCreditsController creditsController;

    @Override
    protected void init(VaadinRequest vaadinRequest) {
        File fileOutClients = new File("client_out.txt");
        File fileOutCredits = new File("credit_out.txt");

        URL urlClients = Thread.currentThread().getContextClassLoader().getResource("clients.omg");
        URL urlCredits = Thread.currentThread().getContextClassLoader().getResource("credits.omg");

        try {
            urlClients = new URL(URLDecoder.decode(urlClients.toString(), "utf-8"));
            urlCredits = new URL(URLDecoder.decode(urlCredits.toString(), "utf-8"));
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        File fileClients = new File(urlClients.getPath());
        File fileCredits = new File(urlCredits.getPath());

        dataStore.setClientList(dataReader.readClients(fileClients));
        dataStore.setCreditList(dataReader.readCredits(fileCredits));
        dataStore.mergeDuplicate();
        dataStore.changeClientInfo();

        try (FileOutputStream outClients = new FileOutputStream(fileOutClients);
             FileOutputStream outCredits = new FileOutputStream(fileOutCredits)
        ) {
            dataStore.outDataToTxt(outClients, outCredits);
        } catch (Exception ex) {
            ex.printStackTrace();
        }

        for (Client client : dataStore.getClientList()) {
            clientsController.saveNewClient(client);
        }
        for (Credit credit : dataStore.getCreditList()) {
            creditsController.saveNewCredit(credit);
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        final VerticalLayout layout = new VerticalLayout();
        final HorizontalLayout horizontal = new HorizontalLayout();
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

        final Label copyright = new Label("© All rights reserved, V. V. Vasilyev; " +
                "Valery Kirichenko (https://t.me/valera5505); 2017");


        outTableCredits.setWidth("1800px");
        outTableCredits.setHeight("250px");
        outTableCredits.addColumn(Credit::getClientID).setCaption("ID").setWidth(100);
        outTableCredits.addColumn(Credit::getAmount).setCaption("Amount");
        outTableCredits.addColumn(Credit::getPercent).setCaption("Percent");
        outTableCredits.addColumn(Credit::getPaidSum).setCaption("Paid Sum");
        outTableCredits.addColumn(Credit::getNeedPaid).setCaption("Need Paid");
        outTableCredits.addColumn(Credit::getClosingDate).setCaption("Closing Date");
        outTableCredits.getEditor().setEnabled(true);
        outTableCredits.setStyleGenerator(credit -> credit.isOverdue() ? "overdue" :
                (credit.isMayBeOverdue() ? "mayBeOverdue" : null));

        outTableClients.setWidth("1800px");
        outTableClients.setHeight("350px");
        outTableClients.addColumn(Client::getID).setCaption("ID").setWidth(100);
        outTableClients.addColumn(Client::getFirstName).setCaption("First Name");
        outTableClients.addColumn(Client::getMiddleName).setCaption("Middle Name");
        outTableClients.addColumn(Client::getLastName).setCaption("Last Name");
        outTableClients.addColumn(Client::getPhone).setCaption("Phone");
        outTableClients.addColumn(Client::getPassport).setCaption("Passport");
        outTableClients.addColumn(Client::getOldPassport).setCaption("Old Passport");
        outTableClients.addColumn(Client::getBirthday).setCaption("Birthday");
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

        buttonClient.addClickListener(e -> {
            try {
                if (name.getValue().isEmpty() || lastName.getValue().isEmpty() ||
                        middleName.getValue().isEmpty() || phone.getValue().isEmpty() ||
                        passport.getValue().isEmpty() || oldPassport.getValue().isEmpty())
                    throw new Exception();
                else {
                    Client client = new Client();
                    Integer maxId = -1;
                    for (Client clientFor : clientsController.getAllClients())
                        if (maxId < clientFor.getID() || (maxId == -1)) {
                            maxId = clientFor.getID();
                        }
                    maxId = (maxId != -1? ++maxId : 0);
                    client.setID(maxId);
                    client.setFirstName(name.getValue());
                    client.setLastName(lastName.getValue());
                    client.setMiddleName(middleName.getValue());
                    client.setPhone(phone.getValue());
                    client.setPassport(Integer.parseInt(passport.getValue()));
                    client.setBirthday(Date.from(birthday.getValue().
                            atStartOfDay(ZoneId.systemDefault()).toInstant()));
                    client.setOldPassport(Integer.parseInt(oldPassport.getValue()));

                    clientsController.saveNewClient(client);
                    dataStore.getClientList().add(client);

                    outTableClients.setItems(dataStore.getClientList());
                    Notification.show("Client " + name.getValue() + " was added!");
                }
            } catch (Exception ex) {
                ex.printStackTrace();
                Notification.show("Incorrect data for new client!");
            }
        });

        buttonCredit.addClickListener(e -> {
            try {
                if (tempId.getValue().isEmpty() || amount.getValue().isEmpty() ||
                        percent.getValue().isEmpty() || paidSum.getValue().isEmpty() ||
                        needPaid.getValue().isEmpty())
                    throw new Exception();
                else {
                    Credit credit = new Credit();

                    credit.setClientId(Integer.parseInt(tempId.getValue()));
                    credit.setAmount(Integer.parseInt(amount.getValue()));
                    credit.setPercent(Double.parseDouble(percent.getValue()));
                    credit.setPaidSum(Double.parseDouble(paidSum.getValue()));
                    credit.setNeedPaid(Double.parseDouble(needPaid.getValue()));
                    credit.setClosingDate(Date.from(closingDate.getValue().
                            atStartOfDay(ZoneId.systemDefault()).toInstant()));

                    creditsController.saveNewCredit(credit);
                    dataStore.getCreditList().add(credit);

                    Client client = dataStore.getClient(Integer.parseInt(tempId.getValue()));
                    client.addCredit(credit);

                    Optional<Client> clientOptional = Optional.of(client);
                    clientOptional.ifPresent(client1 -> outTableCredits.setItems(client1.getCredits()));
                    Notification.show("Credit for client with id " + tempId.getValue() + " was added!");
                }
            } catch (Exception ex) {
                ex.printStackTrace();
                Notification.show("Incorrect data for new client's credit!");
            }
        });

        horizontal.addComponents(name, lastName, middleName, phone, passport, oldPassport, birthday);
        horizontalCredit.addComponents(amount, percent, paidSum, needPaid, closingDate);
        layout.addComponents(horizontal, buttonClient, outTableClients, outTableCredits,
                horizontalCredit, buttonCredit, copyright);

        setContent(layout);
    }


    @WebServlet(urlPatterns = "/*", name = "MyUIServlet", asyncSupported = true)
    @VaadinServletConfiguration(ui = MyUI.class, productionMode = false)
    public static class MyUIServlet extends VaadinServlet {
    }
}
