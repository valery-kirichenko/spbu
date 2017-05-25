package net.task.client.app;

import javax.servlet.annotation.WebServlet;

import com.vaadin.annotations.Theme;
import com.vaadin.annotations.VaadinServletConfiguration;
import com.vaadin.server.VaadinRequest;
import com.vaadin.server.VaadinServlet;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.*;

import net.task.client.rsdata.Reader;
import net.task.client.rsdata.Storage;
import net.task.client.dao.ClientsController;
import net.task.client.dao.CreditsController;
import net.task.client.models.Client;
import net.task.client.models.Credit;
import org.springframework.beans.factory.annotation.Autowired;

import java.io.File;
import java.io.FileOutputStream;
import java.net.URL;
import java.net.URLDecoder;


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
    private Reader dataReader;

    @Autowired
    private Storage dataStore;

    @Autowired
    private ClientsController clientsController;

    @Autowired
    private CreditsController creditsController;

    @Override
    protected void init(VaadinRequest vaadinRequest) {
        getPage().setTitle("BankClient");

        File fileOutClients = new File("client_out.txt");
        File fileOutCredits = new File("credit_out.txt");

        URL urlClients = Thread.currentThread().getContextClassLoader().getResource("clients.omg");
        URL urlCredits = Thread.currentThread().getContextClassLoader().getResource("credits.omg");

        try {
            urlClients = new URL(URLDecoder.decode(urlClients.toString(), "utf-8"));
            urlCredits = new URL(URLDecoder.decode(urlCredits.toString(), "utf-8"));
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        File fileClients = new File(urlClients.getPath());
        File fileCredits = new File(urlCredits.getPath());

        final VerticalLayout layout = new VerticalLayout();

        final Button veryImportantButton = new Button("SEND");
        final Label copyright = new Label("© All rights reserved, V. V. Vasilyev; 2017");

        veryImportantButton.addClickListener(clickEvent -> {
            veryImportantButton.setEnabled(false);
            veryImportantButton.setCaption("sent");

            dataStore.setClientList(dataReader.readClients(fileClients));
            dataStore.setCreditList(dataReader.readCredits(fileCredits));
            dataStore.mergeDuplicate();
            dataStore.changeClientInfo();

            try (FileOutputStream outClients = new FileOutputStream(fileOutClients);
                 FileOutputStream outCredits = new FileOutputStream(fileOutCredits)
            ) {
                dataStore.outDataToTxt(outClients, outCredits);
            } catch (Exception ex) {
                ex.printStackTrace();
            }

            for (Client client : dataStore.getClientList()) {
                clientsController.createClient(client);
            }
            for (Credit credit : dataStore.getCreditList()) {
                creditsController.createCredit(credit);
            }
        });

        layout.addComponents(veryImportantButton, copyright);

        setContent(layout);
    }


    @WebServlet(urlPatterns = "/*", name = "MyUIServlet", asyncSupported = true)
    @VaadinServletConfiguration(ui = MyUI.class, productionMode = false)
    public static class MyUIServlet extends VaadinServlet {
    }
}
