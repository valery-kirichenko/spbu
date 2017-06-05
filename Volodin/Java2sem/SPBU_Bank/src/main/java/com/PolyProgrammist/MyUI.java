package com.PolyProgrammist;

import FromFile.ClientInf;
import FromFile.ClientStorage;
import FromFile.CreditInf;
import com.vaadin.annotations.Theme;
import com.vaadin.annotations.VaadinServletConfiguration;
import com.vaadin.server.VaadinRequest;
import com.vaadin.server.VaadinServlet;
import com.vaadin.ui.*;
import com.vaadin.ui.components.grid.ItemClickListener;

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
    private final VerticalLayout layout = new VerticalLayout();

    private void addNewClient(){
        VerticalLayout vl = new VerticalLayout();
        TextField name = new TextField("Name");
        Button b = new Button("OK");
        b.addClickListener(new Button.ClickListener() {
            @Override
            public void buttonClick(Button.ClickEvent clickEvent) {
                if (name.getValue().equals(""))
                    return;
                ClientInf cl = new ClientInf();
                cl.setName(name.getValue());
                System.out.println(cl.getName());
                layout.removeComponent(vl);
            }
        });


        vl.addComponent(name);
        vl.addComponent(b);
        layout.addComponent(vl, 1);
    }

    @Override
    protected void init(VaadinRequest vaadinRequest) {
        layout.setSizeFull();
        System.out.println("lol");

        Grid<ClientInf> grClients = new Grid<>();

        grClients.addColumn(ClientInf::getId).setCaption("ID");
        grClients.addColumn(ClientInf::getName).setCaption("Name");
        grClients.addColumn(ClientInf::getFamily).setCaption("Family");
        grClients.addColumn(ClientInf::getFather).setCaption("Father");
        grClients.addColumn(ClientInf::getPassport).setCaption("Passport");
        grClients.addColumn(ClientInf::getPhone).setCaption("Phone");

        Grid<CreditInf> grCredits = new Grid<>();

        grCredits.addColumn(CreditInf::getClientId).setCaption("ClientID");
        grCredits.addColumn(CreditInf::getSum).setCaption("Sum");
        grCredits.addColumn(CreditInf::getSumToPay).setCaption("Sum to pay");
        grCredits.addColumn(CreditInf::getSumPaid).setCaption("Sum paid");
        grCredits.addColumn(CreditInf::getPercent).setCaption("Percent");
        grCredits.addColumn(CreditInf::getDateToClose).setCaption("Date to close");

        grClients.setItems(ClientStorage.getClientList());
        grCredits.setItems(ClientStorage.getCreditList());

        Button bNewClient = new Button("New Client");
        bNewClient.addClickListener(new Button.ClickListener() {
            @Override
            public void buttonClick(Button.ClickEvent clickEvent) {
                addNewClient();
            }
        });
        layout.addComponent(bNewClient);

        TabSheet ts = new TabSheet();
        layout.addComponent(ts);
        ts.addTab(grClients, "Clients");
        ts.addTab(grCredits, "Credits");
        //ts.addTab(grNowUser, "NowClient");
        grClients.setSizeFull();
        grCredits.setSizeFull();
        grClients.addItemClickListener(new ItemClickListener<ClientInf>() {
            @Override
            public void itemClick(Grid.ItemClick<ClientInf> itemClick) {
                grCredits.setItems(itemClick.getItem().getCredits());
                ts.setSelectedTab(grCredits);
            }
        });

        setContent(layout);
    }

    @WebServlet(urlPatterns = "/*", name = "MyUIServlet", asyncSupported = true)
    @VaadinServletConfiguration(ui = MyUI.class, productionMode = false)
    public static class MyUIServlet extends VaadinServlet {
    }
}
