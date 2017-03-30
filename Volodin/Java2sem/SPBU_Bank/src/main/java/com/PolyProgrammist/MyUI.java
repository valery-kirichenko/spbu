package com.PolyProgrammist;

import FromFile.ClientInf;
import FromFile.ClientStorage;
import FromFile.CreditInf;
import FromFile.FileBaseInterpreter;
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

    @Override
    protected void init(VaadinRequest vaadinRequest) {
        FileBaseInterpreter rd = new FileBaseInterpreter("testcli.omg", "credits.omg");
        rd.interpret();
        final VerticalLayout layout = new VerticalLayout();
        layout.setSizeFull();
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

        Grid<CreditInf> grNowUser = new Grid<>();
        grNowUser.addColumn(CreditInf::getClientId).setCaption("ClientID");
        grNowUser.addColumn(CreditInf::getSum).setCaption("Sum");
        grNowUser.addColumn(CreditInf::getSumToPay).setCaption("Sum to pay");
        grNowUser.addColumn(CreditInf::getSumPaid).setCaption("Sum paid");
        grNowUser.addColumn(CreditInf::getPercent).setCaption("Percent");
        grNowUser.addColumn(CreditInf::getDateToClose).setCaption("Date to close");

        TabSheet ts = new TabSheet();
        layout.addComponent(ts);
        ts.addTab(grClients, "Clients");
        ts.addTab(grCredits, "Credits");
        //ts.addTab(grNowUser, "NowClient");
        grClients.setSizeFull();
        grCredits.setSizeFull();
        grNowUser.setSizeFull();
        grClients.addItemClickListener(new ItemClickListener<ClientInf>() {
            @Override
            public void itemClick(Grid.ItemClick<ClientInf> itemClick) {
                grNowUser.setItems(itemClick.getItem().getCredits());
                ts.addTab(grNowUser, "NowClient");
                ts.setSelectedTab(grNowUser);
            }
        });

        ts.addSelectedTabChangeListener(new TabSheet.SelectedTabChangeListener() {
            @Override
            public void selectedTabChange(TabSheet.SelectedTabChangeEvent selectedTabChangeEvent) {
                if (!ts.getSelectedTab().equals(grNowUser))
                    ts.removeComponent(grNowUser);

            }
        });
        setContent(layout);
    }

    @WebServlet(urlPatterns = "/*", name = "MyUIServlet", asyncSupported = true)
    @VaadinServletConfiguration(ui = MyUI.class, productionMode = false)
    public static class MyUIServlet extends VaadinServlet {
    }
}
