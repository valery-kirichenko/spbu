package com.PolyProgrammist;

import FromFile.ClientInf;
import FromFile.ClientStorage;
import FromFile.CreditInf;
import FromFile.FileBaseInterpreter;
import com.vaadin.annotations.Theme;
import com.vaadin.annotations.VaadinServletConfiguration;
import com.vaadin.server.VaadinRequest;
import com.vaadin.server.VaadinServlet;
import com.vaadin.ui.Button;
import com.vaadin.ui.Grid;
import com.vaadin.ui.UI;
import com.vaadin.ui.VerticalLayout;

import javax.servlet.annotation.WebServlet;

/**
 * This UI is the application entry point. A UI may either represent a browser window 
 * (or tab) or some part of a html page where a Vaadin application is embedded.
 * <p>
 * The UI is initialized using {@link #init(VaadinRequest)}. This method is intended to be 
 * overridden to add component to the user interface and initialize non-component functionality.
 */
@Theme("mytheme")
public class MyUI extends UI {

    @Override
    protected void init(VaadinRequest vaadinRequest) {
        FileBaseInterpreter rd = new FileBaseInterpreter("testcli.omg", "credits.omg");
        rd.interpret();
        final VerticalLayout layout = new VerticalLayout();
        System.out.println("lol");

        Grid<ClientInf> grClients = new Grid<>();
        grClients.setItems(ClientStorage.getClientList());

        grClients.addColumn(ClientInf::getId).setCaption("ID");
        grClients.addColumn(ClientInf::getName).setCaption("Name");
        grClients.addColumn(ClientInf::getFamily).setCaption("Family");
        grClients.addColumn(ClientInf::getFather).setCaption("Father");
        grClients.addColumn(ClientInf::getPassport).setCaption("Passport");
        grClients.addColumn(ClientInf::getPhone).setCaption("Phone");

        Grid<CreditInf> grCredits = new Grid<>();
        grCredits.setItems(ClientStorage.getCreditList());

        grCredits.addColumn(CreditInf::getClientId).setCaption("ClientID");
        grCredits.addColumn(CreditInf::getSum).setCaption("Sum");
        grCredits.addColumn(CreditInf::getSumToPay).setCaption("Sum to pay");
        grCredits.addColumn(CreditInf::getSumPaid).setCaption("Sum paid");
        grCredits.addColumn(CreditInf::getPercent).setCaption("Percent");
        grCredits.addColumn(CreditInf::getDateToClose).setCaption("Date to close");

        Button bClients = new Button("Clients");
        Button bCredits = new Button("Credits");

        VerticalLayout vl = new VerticalLayout();

        bClients.addClickListener(event->{
            vl.removeAllComponents();
            vl.addComponent(grClients);
        });
        bCredits.addClickListener(event->{
            vl.removeAllComponents();
            vl.addComponent(grCredits);
        });

        layout.addComponent(bClients);
        layout.addComponent(bCredits);
        layout.addComponent(vl);

        
        setContent(layout);
    }

    @WebServlet(urlPatterns = "/*", name = "MyUIServlet", asyncSupported = true)
    @VaadinServletConfiguration(ui = MyUI.class, productionMode = false)
    public static class MyUIServlet extends VaadinServlet {
    }
}
