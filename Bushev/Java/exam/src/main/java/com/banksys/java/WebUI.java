package com.banksys.java;

import com.banksys.java.models.User;
import com.banksys.java.services.JsonHelper;
import com.vaadin.annotations.Theme;
import com.vaadin.annotations.VaadinServletConfiguration;
import com.vaadin.server.ThemeResource;
import com.vaadin.server.VaadinRequest;
import com.vaadin.server.VaadinServlet;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.Grid;
import com.vaadin.ui.UI;
import com.vaadin.ui.VerticalLayout;
import com.vaadin.ui.renderers.HtmlRenderer;
import com.vaadin.ui.renderers.ImageRenderer;
import org.springframework.beans.factory.annotation.Autowired;

import javax.servlet.annotation.WebServlet;
import java.util.List;

@SpringUI
@Theme("mytheme")
public class WebUI extends UI {
    @Autowired
    JsonHelper jsonHelper;

    @Override
    protected void init(VaadinRequest vaadinRequest) {
        List<User> results = jsonHelper.readUsers("https://randomuser.me/api?results=100&nat=US");

        VerticalLayout layout = new VerticalLayout();

        Grid<User> usersTable = new Grid<>();
        usersTable.setItems(results);

        usersTable.addColumn(user -> "<img src='" + user.getImage() + "' style='height: 36px;'>", new HtmlRenderer()).setCaption("Img");
        usersTable.addColumn(User::getName).setCaption("Name");
        usersTable.addColumn(User::getEmail).setCaption("Email").setId("EMAIL_COLUMN");
        usersTable.addColumn(User::getUsername).setCaption("Username");
        usersTable.addColumn(User::getPassword).setCaption("Password");
        usersTable.addColumn(User::getPhone).setCaption("Phone");
        usersTable.addColumn(User::getRegistered).setCaption("Registered");
        usersTable.addColumn(User::getAddress).setCaption("Address");
//        usersTable.addColumn(User::getNat).setCaption("Nationality");

        usersTable.setWidth("100%");
        usersTable.sort("EMAIL_COLUMN");

        layout.addComponent(usersTable);
        setContent(layout);
    }

    @WebServlet(urlPatterns = "/*", name = "MyUIServlet", asyncSupported = true)
    @VaadinServletConfiguration(ui = WebUI.class, productionMode = false)
    public static class MyUIServlet extends VaadinServlet {
    }
}
