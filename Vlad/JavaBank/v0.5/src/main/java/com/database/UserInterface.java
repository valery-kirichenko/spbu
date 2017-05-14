package com.database;

import com.database.Cells.Client;
import com.vaadin.server.VaadinRequest;
import com.vaadin.shared.ui.ContentMode;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.*;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import java.util.List;

@SpringUI
public class UserInterface extends UI {

    @Autowired
    JdbcTemplate template;

    @Override
    protected void init(VaadinRequest vaadinRequest) {
        VerticalLayout layout = new VerticalLayout();
        Label label = new Label("<pre>Test\nHTML</pre>", ContentMode.HTML);
        label.setWidth("100%");
        label.setHeight("200px");

        Grid<Client> clientGrid = new Grid<>();
        List<Client> clientList = template.query("SELECT * FROM clients", new ClientRowMapper());

        //SELECTION HANDLER
        clientGrid.setSelectionMode(Grid.SelectionMode.SINGLE);
        clientGrid.addSelectionListener(selectionEvent -> {
            Notification.show("Selected");
        });

        clientGrid.setHeight("600px");
        clientGrid.setWidth("100%");
        clientGrid.setItems(clientList);
        clientGrid.addColumn(Client::getId).setCaption("ID");
        clientGrid.addColumn(Client::getName).setCaption("Name");
        clientGrid.addColumn(Client::getBirthday).setCaption("Birthday");
        clientGrid.addColumn(Client::getPhoneNumber).setCaption("Phone Number");
        clientGrid.addColumn(Client::getPassport).setCaption("Passport");
        clientGrid.addColumn(Client::getOldPassport).setCaption("Old Passport");

        layout.addComponentsAndExpand(clientGrid, label);
        setContent(layout);
    }
}
