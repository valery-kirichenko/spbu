package net.bank;

import javax.servlet.annotation.WebServlet;

import com.vaadin.annotations.Theme;
import com.vaadin.annotations.VaadinServletConfiguration;
import com.vaadin.server.VaadinRequest;
import com.vaadin.server.VaadinServlet;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.*;

import org.springframework.beans.factory.annotation.Autowired;

import java.io.File;
import java.net.URL;
import java.time.ZoneId;
import java.util.Date;
import java.util.Optional;
import java.util.List;

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
    private DataReader dataReader;

    @Autowired
    private DataStorage dataStorage;

    @Override
    protected void init(VaadinRequest vaadinRequest) {

        URL urlClients = Thread.currentThread().getContextClassLoader().getResource("client.omg");
        URL urlCredits = Thread.currentThread().getContextClassLoader().getResource("credit.omg");

        File ClientsFile = new File(urlClients.getPath());
        File CreditsFile = new File(urlCredits.getPath());

        dataStorage.setClientList(dataReader.readClients(ClientsFile));
        dataStorage.setCreditList(dataReader.readCredits(CreditsFile));
        dataStorage.mergeDuplicate();
        dataStorage.correctClientName();

        final VerticalLayout layout = new VerticalLayout();
        final HorizontalLayout horizontal = new HorizontalLayout();
        final HorizontalLayout horizontalCredit = new HorizontalLayout();
        final TextField firstName = new TextField("First Name:");
        final TextField lastName = new TextField("Last name:");
        final TextField middleName = new TextField("Middle name:");
        final TextField phoneNumber = new TextField("Phone Number:");
        final TextField IDNumber = new TextField("Passport:");
        final TextField oldIDNumber = new TextField("Old passport:");
        final DateField birthDate = new DateField("Birth Date:");
        final TextField creditAmount = new TextField("Credit Amount:");
        final TextField percent = new TextField("Percent:");
        final TextField clientPaid = new TextField("Paid:");
        final TextField clientHasToPay = new TextField("More to pay:");
        final DateField closureDate = new DateField("Closure Date:");
        final TextField tempId = new TextField("INT_MIN");
        final Grid<Client> ClientsTable = new Grid<>();
        final Grid<Credit> CreditsTable = new Grid<>();
        final List<Client> outClients = dataStorage.clients;


        CreditsTable.setWidth("1600px");
        CreditsTable.setHeight("300px");
        CreditsTable.addColumn(Credit::getClientID).setCaption("ID").setWidth(100);
        CreditsTable.addColumn(Credit::getCreditAmount).setCaption("Amount");
        CreditsTable.addColumn(Credit::getPercent).setCaption("Percent");
        CreditsTable.addColumn(Credit::getClientPaid).setCaption("Paid");
        CreditsTable.addColumn(Credit::getClientHasToPay).setCaption("More to pay");
        CreditsTable.addColumn(Credit::getClosureDate).setCaption("Closure Date");
        CreditsTable.getEditor().setEnabled(true);
        CreditsTable.setStyleGenerator(credit -> {
            if (credit.isOverdue())
                return "overdue";
            else if (credit.isMayBeOverdue())
                return "maybeOverdue";
            else
                return null;
        });

        ClientsTable.setWidth("1600px");
        ClientsTable.setHeight("400px");
        ClientsTable.addColumn(Client::getID).setCaption("ID").setWidth(100);
        ClientsTable.addColumn(Client::getFirstName).setCaption("First Name");
        ClientsTable.addColumn(Client::getMiddleName).setCaption("Middle Name");
        ClientsTable.addColumn(Client::getLastName).setCaption("Last Name");
        ClientsTable.addColumn(Client::getPhoneNumber).setCaption("Phone");
        ClientsTable.addColumn(Client::getIdNumber).setCaption("Passport");
        ClientsTable.addColumn(Client::getOldIdNumber).setCaption("Old Passport");
        ClientsTable.addColumn(Client::getBirthDate).setCaption("Birth Date");
        ClientsTable.getEditor().setEnabled(true);
        ClientsTable.setStyleGenerator(client -> {
            if (client.isDebtor())
                return "overdue";
            else if (client.mayBeDebtor())
                return "maybeOverdue";
            else
                return null;
        });

        ClientsTable.addSelectionListener(event -> {
            Optional<Client> client = event.getFirstSelectedItem();
            client.ifPresent(client1 -> {
                CreditsTable.setItems(client1.getCredits());
                tempId.setValue(Integer.toString(client1.getID()));
            });
        });

        ClientsTable.setItems(dataStorage.getClientList());

        Button button = new Button("Add new client");
        Button buttonCredit = new Button("Add new credit for selected client");
        button.addClickListener(e -> {
            try {
                if (lastName.getValue().isEmpty() || middleName.getValue().isEmpty() || phoneNumber.getValue().isEmpty() ||
                        IDNumber.getValue().isEmpty() || oldIDNumber.getValue().isEmpty())
                    throw new Exception();
                else {
                    Client client = new Client();
                    Integer maxId = Integer.MIN_VALUE;
                    for (Client clientFor : dataStorage.getClientList())
                        if (maxId < clientFor.getID() || (maxId == Integer.MIN_VALUE)) maxId = clientFor.getID();
                    maxId = (maxId != Integer.MIN_VALUE ? ++maxId : 0);
                    client.setID(maxId);
                    client.setFirstName((firstName.getValue()));
                    client.setLastName(lastName.getValue());
                    client.setMiddleName(middleName.getValue());
                    client.setPhoneNumber(phoneNumber.getValue());
                    client.setIdNumber(Integer.parseInt(IDNumber.getValue()));
                    client.setBirthDate(Date.from(birthDate.getValue().atStartOfDay(ZoneId.systemDefault()).toInstant()));
                    client.setOldIdNumber(Integer.parseInt(oldIDNumber.getValue()));

                    dataStorage.getClientList().add(client);
                    ClientsTable.setItems(dataStorage.clients);
                    Notification.show("A new client " + firstName.getValue() + " has been added.");
                }
            } catch (Exception ex) {
                ex.printStackTrace();
                Notification.show("Incorrect data for new client!");
            }
        });

        buttonCredit.addClickListener(e -> {
            try {
                if (tempId.getValue().isEmpty() || creditAmount.getValue().isEmpty() || percent.getValue().isEmpty() || clientPaid.getValue().isEmpty() ||
                        clientHasToPay.getValue().isEmpty())
                    throw new Exception();
                else {
                    Credit credit = new Credit();

                    credit.setClientID(Integer.parseInt(tempId.getValue()));
                    credit.setCreditAmount(Integer.parseInt(creditAmount.getValue()));
                    credit.setPercent(Float.parseFloat(percent.getValue()));
                    credit.setClientPaid(Integer.parseInt(clientPaid.getValue()));
                    credit.setClientHasToPay(Integer.parseInt(clientHasToPay.getValue()));
                    credit.setClosureDate(Date.from(closureDate.getValue().atStartOfDay(ZoneId.systemDefault()).toInstant()));

                    dataStorage.getCreditList().add(credit);
                    Client client = dataStorage.getClient(Integer.parseInt(tempId.getValue()));
                    client.addCredit(credit);
                    Optional<Client> clientOptional = Optional.of(client);
                    clientOptional.ifPresent(client1 -> CreditsTable.setItems(client1.getCredits()));
                    Notification.show("A new credit for the client with id " + tempId.getValue() + " has been added!");
                }
            } catch (Exception ex) {
                ex.printStackTrace();
                Notification.show("Incorrect data for client's new credit!");
            }
        });

        horizontal.addComponents(firstName, lastName, middleName, phoneNumber, IDNumber, oldIDNumber, birthDate);
        horizontalCredit.addComponents(creditAmount, percent, clientPaid, clientHasToPay, closureDate);
        layout.addComponents(horizontal, button, ClientsTable, CreditsTable, horizontalCredit, buttonCredit);

        setContent(layout);
    }


    @WebServlet(urlPatterns = "/*", name = "MyUIServlet", asyncSupported = true)
    @VaadinServletConfiguration(ui = MyUI.class, productionMode = false)
    public static class MyUIServlet extends VaadinServlet {
    }
}
