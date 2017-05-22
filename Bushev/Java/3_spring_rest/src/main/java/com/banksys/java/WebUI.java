package com.banksys.java;

import com.banksys.java.models.Client;
import com.banksys.java.models.Credit;
import com.vaadin.annotations.Theme;
import com.vaadin.annotations.VaadinServletConfiguration;
import com.vaadin.server.VaadinRequest;
import com.vaadin.server.VaadinServlet;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.*;
import net.minidev.json.JSONObject;
import net.minidev.json.JSONValue;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.client.RestTemplate;

import javax.servlet.annotation.WebServlet;
import java.time.LocalDate;
import java.util.*;

@SpringUI
@Theme("mytheme")
public class WebUI extends UI {
    //private static Storage storage;
    private static int maxId;

    // working with vis objects
    private static Set<Client> selectedUsers;
    private static Set<Credit> selectedCredits;
    private static Grid<Client> usersTable;
    private static Grid<Credit> creditsTable;

    private static Integer currency = 0; // RUB
    private static List<String> currencyList = new ArrayList<>(Arrays.asList("RUB", "USD", "EUR"));

    @Autowired
    RestStorage storage;

    @Override
    protected void init(VaadinRequest vaadinRequest) {
        storage.init();

        System.out.println("Vaadin is started");

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

        usersTable.addColumn(Client::getId).setCaption("#").setId("0");
        usersTable.addColumn(Client::getName).setCaption("Name").setEditorComponent(new TextField(), Client::setName);
        usersTable.addColumn(Client::getSurname).setCaption("Surname").setEditorComponent(new TextField(), Client::setSurname);
        usersTable.addColumn(Client::getMiddlename).setCaption("Middlename").setEditorComponent(new TextField(), Client::setMiddlename);
        usersTable.addColumn(Client::getPhone).setCaption("Phone").setEditorComponent(new TextField(), Client::setPhone);
        usersTable.addColumn(Client::getPassport).setCaption("Passport").setEditorComponent(new TextField(), Client::setPassport);
        usersTable.addColumn(Client::getOldPassport).setCaption("Oldpassport").setEditorComponent(new TextField(), Client::setOldPassport);
        usersTable.addColumn(Client::getDate).setCaption("Birthday").setEditorComponent(new DateField(), Client::setDate);
        usersTable.addColumn(Client::isDebtor).setCaption("Debtor?");

        usersTable.setStyleGenerator(client -> client.isDebtor().equals("YES") ? "bs-debtor" : null);

        ///
        ///

        creditsTable.setCaption("Users credits");
        creditsTable.setSelectionMode(Grid.SelectionMode.MULTI);
        creditsTable.getEditor().setEnabled(true);

        creditsTable.setWidth("100%");
        if(storage.getClients().size() > 0) {
            creditsTable.setItems(storage.getClients().get(0).getCredits());
        }

        creditsTable.addColumn(Credit::getId).setCaption("#").setId("0");
        creditsTable.addColumn(Credit::getAmount).setCaption("Amount").setEditorComponent(new TextField(), Credit::setAmount);
        creditsTable.addColumn(Credit::getPercent).setCaption("Percent").setEditorComponent(new TextField(), Credit::setPercent);
        creditsTable.addColumn(Credit::getPayed).setCaption("Payed").setEditorComponent(new TextField(), Credit::setPayed);
        creditsTable.addColumn(Credit::getNeeded).setCaption("Needed").setEditorComponent(new TextField(), Credit::setNeeded);
        creditsTable.addColumn(Credit::getDate).setCaption("Date").setEditorComponent(new DateField(), Credit::setDate);;
        creditsTable.addColumn(Credit::isOverdue).setCaption("Overdue?");

        creditsTable.setStyleGenerator(credit -> credit.isOverdue().equals("YES") ? "bs-overdue" : null);

        ///
        ///

        usersTable.addSelectionListener(e -> {
            selectedUsers = e.getAllSelectedItems();
            ArrayList<Credit> credits = new ArrayList<>();
            for (Client current : selectedUsers) {
                credits.addAll(current.getCredits());
            }

            if (selectedUsers.isEmpty()) {
                creditsTable.setItems();
            } else {
                creditsTable.setItems(credits);
            }
        });

        creditsTable.addSelectionListener(e -> selectedCredits = e.getAllSelectedItems());

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
            JavaScript.getCurrent().execute("alert('Your data is saved!')");
        });

        ///

        Label currencyLabel = new Label("Currency:");
        currencyLabel.setStyleName("bs-currency");

        ComboBox<String> currencyBox = new ComboBox<>();
        currencyBox.setEmptySelectionAllowed(false);
        currencyBox.setItems(currencyList);
        currencyBox.setSelectedItem(currencyList.get(0));
        currencyBox.addSelectionListener(e -> {
            currency = currencyList.indexOf(e.getFirstSelectedItem().get());
            if(selectedUsers != null){
                creditsTable.setItems(setCredits());
            }
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
                searchTextField, searchBtn, currencyLabel, currencyBox));
        layout.addComponents(creditsTable, new HorizontalLayout(cAdd, cDel));
        setContent(layout);
    }

//     id->>>>name---surname\\middlename~~~~phone==passport___time==oldpassport
    private void uBtnListener(Event e) {
        if (((Button) e.getSource()).getCaption().equals("+")) {
            storage.getClients().add(new Client(Integer.toString(++maxId),
                    "REQUIRED", "REQUIRED", "REQUIRED",
                    "12345678901", "123456", LocalDate.now().toString()));
            usersTable.setItems(storage.getClients());
        } else if (selectedUsers != null && !selectedUsers.isEmpty()) {
            for (Client client : selectedUsers) {
                storage.getCredits().removeAll(client.getCredits());
            }
            storage.getClients().removeAll(selectedUsers);
            usersTable.setItems(storage.getClients());
        }
    }

//    id, amount, percent, payed, needed, date
    private void cBtnListener(Event e) {
        if (selectedUsers == null || selectedUsers.isEmpty()) return;

        if (((Button) e.getSource()).getCaption().equals("+")) {
            if(selectedUsers.size() == 1) {
                Credit credit = new Credit(selectedUsers.iterator().next().getId(),
                        "0", "0", "0", "0", LocalDate.now().toString());

                selectedUsers.iterator().next().getCredits().add(credit);
                storage.getCredits().add(credit);

                creditsTable.setItems(selectedUsers.iterator().next().getCredits());
            }
        } else if (selectedCredits != null && !selectedCredits.isEmpty()) {
            ArrayList<Credit> credits = new ArrayList<>();
            for(Client client : selectedUsers){
                client.getCredits().removeAll(selectedCredits);
                credits.addAll(client.getCredits());
            }   // inserted full credit list
            storage.getCredits().removeAll(selectedCredits);
            creditsTable.setItems(credits);
        }
    }

    private Set<Credit> setCredits(){
        Set<Credit> credits = new HashSet<>();
        for (Client current : selectedUsers) {
            for(Credit credit : current.getCredits()){
                credits.add(new Credit(credit));
            } // new objects needed, no references
        }

        if(currency == 0) return credits;

        RestTemplate template = new RestTemplate();
        JSONObject result = (JSONObject) JSONValue.parse(template.getForObject("http://api.fixer.io/latest?base=RUB"
                + "&symbols=USD,EUR,RUB", String.class));

        JSONObject jsonCurrency = (JSONObject) result.get("rates");

        Double[] value = new Double[2];
        value[0] = (Double) jsonCurrency.get("USD");
        value[1] = (Double) jsonCurrency.get("EUR");;

        for(Credit credit : credits) {
            credit.amount = String.format("%.3f", Double.parseDouble(credit.amount) * value[currency-1]).replace(",", ".");
            credit.payed = String.format("%.3f", Double.parseDouble(credit.payed) * value[currency-1]).replace(",", ".");
            credit.needed = String.format("%.3f", Double.parseDouble(credit.needed) * value[currency-1]).replace(",", ".");
        }

        return credits;
    }

    @WebServlet(urlPatterns = "/*", name = "MyUIServlet", asyncSupported = true)
    @VaadinServletConfiguration(ui = WebUI.class, productionMode = false)
    public static class MyUIServlet extends VaadinServlet {
    }
}
