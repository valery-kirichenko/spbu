package com.database;

import com.database.Cells.Client;
import com.database.Cells.Credit;
import com.vaadin.server.Page;
import com.vaadin.server.VaadinRequest;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.*;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;

import java.time.LocalDate;
import java.util.List;

@SpringUI
public class UserInterface extends UI {

    @Autowired
    JdbcTemplate template;
    @Autowired
    MainControllerClass controllerClass;


    @Override
    protected void init(VaadinRequest vaadinRequest) {
        VerticalLayout layout = new VerticalLayout();

        Grid<Client> clientGrid = new Grid<>();
        Grid<Credit> creditGrid = new Grid<>();
        List<Client> clientList = template.query("SELECT * FROM clients", new ClientRowMapper());
        List<Credit> creditList = template.query("SELECT * FROM credits", new CreditRowMapper());


        clientGrid.setHeight("400px");
        clientGrid.setWidth("100%");
        clientGrid.setItems(clientList);
        clientGrid.addColumn(Client::getId).setCaption("ID");
        clientGrid.addColumn(Client::getName).setCaption("Name");
        clientGrid.addColumn(Client::getBirthday).setCaption("Birthday");
        clientGrid.addColumn(Client::getPhoneNumber).setCaption("Phone Number");
        clientGrid.addColumn(Client::getPassport).setCaption("Passport");
        clientGrid.addColumn(Client::getOldPassport).setCaption("Old Passport");

        creditGrid.setHeight("400px");
        creditGrid.setWidth("100%");
        creditGrid.setItems(creditList);
        creditGrid.addColumn(Credit::getID).setCaption("ID");
        creditGrid.addColumn(Credit::getClientID).setCaption("Client ID");
        creditGrid.addColumn(Credit::getCashTotal).setCaption("Total Cash");
        creditGrid.addColumn(Credit::getCashWithPercent).setCaption("Total Cash With Percent");
        creditGrid.addColumn(Credit::getPercent).setCaption("Percent");
        creditGrid.addColumn(Credit::getCashPaid).setCaption("Paid Cash");
        creditGrid.addColumn(Credit::getDeadline).setCaption("Deadline");

        HorizontalLayout secondLayout = new HorizontalLayout();

        Panel panel1 = new Panel();
        panel1.setSizeUndefined(); // Shrink to fit content
        FormLayout layoutAddClient = new FormLayout();
        TextField name = new TextField("Name:");
        TextField phoneNumber = new TextField("Phone Number:");
        TextField birthday = new TextField("Birthday:");
        TextField passport = new TextField("Passport:");
        TextField oldPassport = new TextField("Old Passport:");
        Button createClient = new Button("Create Client");
        name.setMaxLength(50);
        phoneNumber.setMaxLength(12);
        passport.setMaxLength(6);
        oldPassport.setMaxLength(6);
        layoutAddClient.addComponents(createClient, name, phoneNumber, birthday, passport, oldPassport);
        panel1.setContent(layoutAddClient);
        //
        Panel panel2 = new Panel();
        panel2.setSizeUndefined(); // Shrink to fit content
        FormLayout layoutAddCredit = new FormLayout();
        TextField client = new TextField("Client ID:");
        TextField cashTotal = new TextField("Credit without percent:");
        TextField cashPaid = new TextField("Cash paid:");
        TextField percent = new TextField("Percent:");
        TextField cashWithPercent = new TextField("Credit with percent:");
        DateField deadline = new DateField("Deadline:");
        Button createCredit = new Button("Create Credit");
        layoutAddCredit.addComponents(createCredit, client, cashTotal, percent, cashWithPercent, cashPaid, deadline);
        panel2.setContent(layoutAddCredit);
        //
        Panel panel3 = new Panel();
        panel2.setSizeUndefined(); // Shrink to fit content
        FormLayout layoutDeleteClient = new FormLayout();
        TextField clientID = new TextField("Client ID:");
        Button deleteClient = new Button("Delete Client");
        layoutDeleteClient.addComponents(deleteClient, clientID);
        panel3.setContent(layoutDeleteClient);
        //
        Panel panel4 = new Panel();
        panel2.setSizeUndefined(); // Shrink to fit content
        FormLayout layoutDeleteCredit = new FormLayout();
        TextField creditID = new TextField("Credit ID:");
        Button deleteCredit = new Button("Delete Credit");
        layoutDeleteCredit.addComponents(deleteCredit, creditID);
        panel4.setContent(layoutDeleteCredit);
        //

        secondLayout.addComponents(panel1, panel2, panel3, panel4);

        layout.addComponents(clientGrid, creditGrid, secondLayout);
        setContent(layout);

        percent.addValueChangeListener(valueChangeEvent -> {
            Double temp = Double.parseDouble(cashTotal.getValue())*(Double.parseDouble(percent.getValue()) + 100)/100;
            cashWithPercent.setValue(temp.toString());
        });

        createClient.addClickListener(clickEvent -> {
            try {
                controllerClass.createClient(
                        name.getValue(),
                        phoneNumber.getValue(),
                        birthday.getValue(),
                        passport.getValue(),
                        oldPassport.getValue()
                );
            }
            catch (IllegalArgumentException e) {
                new Notification("User with same passport is already existed!", Notification.Type.ERROR_MESSAGE).show(Page.getCurrent());
            }


            name.clear();
            phoneNumber.clear();
            birthday.clear();
            passport.clear();
            oldPassport.clear();
        });

        createCredit.addClickListener(clickEvent -> {
            controllerClass.createCredit(
                    Integer.parseInt(client.getValue()),
                    Double.parseDouble(cashTotal.getValue()),
                    Double.parseDouble(cashPaid.getValue()),
                    Double.parseDouble(cashWithPercent.getValue()),
                    Double.parseDouble(percent.getValue()),
                    deadline.getValue()
            );

            client.clear();
            cashTotal.clear();
            cashPaid.clear();
            cashWithPercent.clear();
            percent.clear();
            deadline.clear();
        });

        deleteClient.addClickListener(clickEvent -> {
           controllerClass.deleteClient(Integer.parseInt(clientID.getValue()));
           clientID.clear();
        });

        deleteCredit.addClickListener(clickEvent -> {
           controllerClass.deleteCredit(Integer.parseInt(creditID.getValue()));
           creditID.clear();
        });

        //SELECTION HANDLER
        clientGrid.setSelectionMode(Grid.SelectionMode.SINGLE);
        clientGrid.addSelectionListener(selectionEvent -> {
            int id = selectionEvent.getFirstSelectedItem().orElse(null).getId();
            List<Credit> credits = template.query("SELECT * FROM credits WHERE clientID = " + id, new CreditRowMapper());
            creditGrid.setItems(credits);
        });
    }
}
