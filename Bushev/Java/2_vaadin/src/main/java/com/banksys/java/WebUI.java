package com.banksys.java;

import javax.servlet.annotation.WebServlet;

import com.vaadin.annotations.Theme;
import com.vaadin.annotations.VaadinServletConfiguration;
import com.vaadin.server.VaadinRequest;
import com.vaadin.server.VaadinServlet;
import com.vaadin.ui.*;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

/**
 * This UI is the application entry point. A UI may either represent a browser window
 * (or tab) or some part of a html page where a Vaadin application is embedded.
 * <p>
 * The UI is initialized using {@link #init(VaadinRequest)}. This method is intended to be
 * overridden to add component to the user interface and initialize non-component functionality.
 */
@Theme("mytheme")
public class WebUI extends UI {
    private static Storage storage;
    private static int maxId;

    // working with vis objects
    private static Set<Client> selectedUsers;
    private static Set<Credit> selectedCredits;
    private static Grid<Client> usersTable;
    private static Grid<Credit> creditsTable;

    @Override
    protected void init(VaadinRequest vaadinRequest) {
        storage = new Storage();
        maxId = ClientHelper.getCurrentId(storage.getClients());
        usersTable = new Grid<>();
        creditsTable = new Grid<>();

        final VerticalLayout layout = new VerticalLayout();

        usersTable.setItems(storage.getClients());
        usersTable.setCaption("System users");
        usersTable.setSelectionMode(Grid.SelectionMode.MULTI);
        usersTable.getEditor().setEnabled(true);

        usersTable.setWidth("100%");
        if(storage.getClients().size() > 0) {
            usersTable.select(storage.getClients().get(0));
            selectedUsers = new HashSet<>();
            selectedUsers.add(storage.getClients().get(0));
        }

        usersTable.addColumn(Client::getId).setCaption("#");
        usersTable.addColumn(Client::getName).setCaption("Name").setEditorComponent(new TextField(), Client::setName);
        usersTable.addColumn(Client::getSurname).setCaption("Surname").setEditorComponent(new TextField(), Client::setSurname);
        usersTable.addColumn(Client::getMiddlename).setCaption("Middlename").setEditorComponent(new TextField(), Client::setMiddlename);
        usersTable.addColumn(Client::getPhone).setCaption("Phone").setEditorComponent(new TextField(), Client::setPhone);
        usersTable.addColumn(Client::getPassport).setCaption("Passport").setEditorComponent(new TextField(), Client::setPassport);
        usersTable.addColumn(Client::getOldPassport).setCaption("Oldpassport").setEditorComponent(new TextField(), Client::setOldPassport);
        usersTable.addColumn(Client::getDate).setCaption("Birthday");
        usersTable.addColumn(Client::isDebtor).setCaption("Debtor?");

        usersTable.setStyleGenerator(client ->{
            return client.isDebtor().equals("YES") ? "bs-debtor" : null;
        });

        ///
        ///

        creditsTable.setCaption("Users credits");
        creditsTable.setSelectionMode(Grid.SelectionMode.MULTI);
        creditsTable.getEditor().setEnabled(true);

        creditsTable.setWidth("100%");
        if(storage.getClients().size() > 0) {
            creditsTable.setItems(storage.getClients().get(0).credits);
        }

        creditsTable.addColumn(Credit::getId).setCaption("#");
        creditsTable.addColumn(Credit::getAmount).setCaption("Amount").setEditorComponent(new TextField(), Credit::setAmount);
        creditsTable.addColumn(Credit::getPercent).setCaption("Percent").setEditorComponent(new TextField(), Credit::setPercent);
        creditsTable.addColumn(Credit::getPayed).setCaption("Payed").setEditorComponent(new TextField(), Credit::setPayed);
        creditsTable.addColumn(Credit::getNeeded).setCaption("Needed").setEditorComponent(new TextField(), Credit::setNeeded);
        creditsTable.addColumn(Credit::getDate).setCaption("Date");
        creditsTable.addColumn(Credit::isOverdue).setCaption("Overdue?");

        creditsTable.setStyleGenerator(credit ->{
            return credit.isOverdue().equals("YES") ? "bs-overdue" : null;
        });

        ///
        ///

        usersTable.addSelectionListener(e -> {
            selectedUsers = e.getAllSelectedItems();
            ArrayList<Credit> credits = new ArrayList<>();
            for (Client current : selectedUsers) {
                credits.addAll(current.credits);
            }

            if (selectedUsers.isEmpty()) {
                creditsTable.setItems();
            } else {
                creditsTable.setItems(credits);
            }
        });

        creditsTable.addSelectionListener(e -> {
            selectedCredits = e.getAllSelectedItems();
        });

        Button uAdd = new Button("+");
        Button uDel = new Button("-");
        uAdd.addClickListener(this::uBtnListener);
        uDel.addClickListener(this::uBtnListener);

        Button cAdd = new Button("+");
        Button cDel = new Button("-");
        cAdd.addClickListener(this::cBtnListener);
        cDel.addClickListener(this::cBtnListener);

        Button saveBtn = new Button("Save Data");
        saveBtn.addClickListener(e -> {
            storage.rewriteData();
        });

        ///

        TextField searchTextField = new TextField();
        searchTextField.setPlaceholder("Search phrase");

        Button searchBtn = new Button("Search");
        searchBtn.addClickListener(e -> {
            usersTable.setItems(ClientHelper.clientSearch(
                    storage.getClients(), searchTextField.getValue()));
        });

        ///

        layout.addComponents(usersTable, new HorizontalLayout(uAdd, uDel, saveBtn,
                searchTextField, searchBtn));
        layout.addComponents(creditsTable, new HorizontalLayout(cAdd, cDel));
        setContent(layout);
        storage.destroy();
    }

    // id->>>>name---surname\\middlename~~~~phone==passport___time==oldpassport
    private void uBtnListener(Event e) {
        if (((Button) e.getSource()).getCaption().equals("+")) {
            storage.getClients().add(new Client(Integer.toString(++maxId),
                    "REQUIRED", "REQUIRED", "REQUIRED",
                    "12345678901", "123456", LocalDate.now().toString()));
            usersTable.setItems(storage.getClients());
        } else if (selectedUsers != null && !selectedUsers.isEmpty()) {
            for (Client client : selectedUsers) {
                storage.getCredits().removeAll(client.credits);
            }
            storage.getClients().removeAll(selectedUsers);
            usersTable.setItems(storage.getClients());
        }
    }

    //id, amount, percent, payed, needed, date
    private void cBtnListener(Event e) {
        if (selectedUsers == null || selectedUsers.isEmpty()) return;

        if (((Button) e.getSource()).getCaption().equals("+")) {
            if(selectedUsers.size() == 1) {
                Credit credit = new Credit(selectedUsers.iterator().next().getId(),
                        "0", "0", "0", "0", LocalDate.now().toString());

                selectedUsers.iterator().next().credits.add(credit);
                storage.getCredits().add(credit);

                creditsTable.setItems(selectedUsers.iterator().next().credits);
            }
        } else if (selectedCredits != null && !selectedCredits.isEmpty()) {
            ArrayList<Credit> credits = new ArrayList<>();
            for(Client client : selectedUsers){
                client.credits.removeAll(selectedCredits);
                credits.addAll(client.credits);
            }   // inserted full credit list
            storage.getCredits().removeAll(selectedCredits);
            creditsTable.setItems(credits);
        }
    }

    @WebServlet(urlPatterns = "/*", name = "MyUIServlet", asyncSupported = true)
    @VaadinServletConfiguration(ui = WebUI.class, productionMode = false)
    public static class MyUIServlet extends VaadinServlet {
    }
}
