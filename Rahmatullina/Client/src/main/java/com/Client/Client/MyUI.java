package com.Client.Client;

import com.vaadin.annotations.Theme;
import com.vaadin.annotations.VaadinServletConfiguration;
import com.vaadin.server.VaadinRequest;
import com.vaadin.server.VaadinServlet;
import com.vaadin.shared.Registration;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.Button;
import com.vaadin.ui.UI;
import com.vaadin.ui.VerticalLayout;
import org.springframework.beans.factory.annotation.Autowired;

import javax.servlet.annotation.WebServlet;
import java.io.FileNotFoundException;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.List;

/**
 * Created by Я on 27.05.2017.
 */
@SpringUI
@Theme("mytheme")
public class MyUI extends UI {

    @Autowired
    CreditRestController creditRestController;

    @Autowired
    ClientRestController clientRestController;

    @Autowired
    GettingClientFromFile gettingClientFromFile;

    @Override
    protected void init(VaadinRequest request) {


        VerticalLayout layout = new VerticalLayout();
        Button send = new Button("SEND");

        send.addClickListener((Button.ClickEvent clickEvent) -> {
            send.setCaption("We sent");
            try {
                List<Credits> creditList = new ArrayList<>();
                List<Clients> clientList = gettingClientFromFile.getClient();
                for (Clients client : clientList)
                    creditList.addAll(client.getCredit());

                for (Clients client : clientList) {
                    clientRestController.saveNewClient(client);
                }

                for (Credits credit : creditList) {
                    creditRestController.saveNewCredit(credit);
                    System.out.println(58);
                }
                send.setEnabled(false);
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        });

        layout.addComponent(send);
        setContent(layout);

    }

    @WebServlet(urlPatterns = "/*", name = "MyUIServlet", asyncSupported = true)
    @VaadinServletConfiguration(ui = MyUI.class, productionMode = false)
    public static class MyUIServlet extends VaadinServlet {
    }
}
