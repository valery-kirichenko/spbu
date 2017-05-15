package com.NewDataBase;

import com.vaadin.annotations.Theme;
import com.vaadin.annotations.VaadinServletConfiguration;
import com.vaadin.server.VaadinRequest;
import com.vaadin.server.VaadinServlet;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.*;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Configuration;
import org.springframework.stereotype.Service;
import javax.servlet.annotation.WebServlet;
import java.text.ParseException;
import java.util.List;
import java.util.stream.Collectors;



@Theme("mytheme")
@SpringUI
public class MyUI extends UI {


    @Autowired
    ShowClientWithExpiryCredit expiryClients;
    @Autowired
    ShowExpiryCredit showExpiry;
    @Autowired
    ClientControllerImpl clientController;
    @Autowired
    CreditControllerImpl creditController;

    @Override
    protected void init(VaadinRequest vaadinRequest) {


        final VerticalLayout layout = new VerticalLayout();
        final HorizontalLayout horlayout = new HorizontalLayout();
        final HorizontalLayout horlayout2 = new HorizontalLayout();
        final VerticalLayout layoutClient = new VerticalLayout();
        final VerticalLayout layoutCredit = new VerticalLayout();

        TextField сlientId = new TextField("Enter client id");сlientId.setValue("12121212");
        TextField сlientName = new TextField("Enter Client name");сlientName.setValue("Jamal");
        TextField clientSurName = new TextField("Enter SurName");clientSurName.setValue("Jaoel");
        TextField clientMidName = new TextField("Enter MidName");clientMidName.setValue("Savage");
        TextField clientPhone = new TextField("Enter phone");clientPhone.setValue("89818325441");
        TextField clientPassport = new TextField("Enter Passport");clientPassport.setValue("8012345766");
        TextField clientDate = new TextField("Enter client date.For example:2017-12-01");clientDate.setValue("1998-09-09");
        TextField clientOldPassport = new TextField("Enter Old Passport");clientOldPassport.setValue("8012345611");
        TextField сreditLoan = new TextField("Enter Credit Loan");сreditLoan.setValue("1000");
        TextField creditPercent = new TextField("Enter Credit Percent");creditPercent.setValue("6");
        TextField creditPaidSum = new TextField("Enter Credit Paid Sum");creditPaidSum.setValue("555");
        TextField creditWholeLoan = new TextField("Enter Credit Whole Loan");creditWholeLoan.setValue("1001");
        TextField creditDate = new TextField("Enter Credit Date.For Example : 2017-01-01");creditDate.setValue("1998-01-01");

        Button buttonAddClient = new Button("Add Client");
        Button buttonAddCredit = new Button("Add Credit");
        Button buttonDodjers = new Button("Filter : dodgers");
        Button buttonNotDodjers = new Button("Filter : not dodgers");
        Button buttonAllClients = new Button("All Clients");

        Grid<Clients> grid = new Grid<>();
        grid.setSizeFull();
        grid.addColumn(Clients::getClientId).setCaption("ID").setWidth(100);
        grid.addColumn(Clients::getName).setCaption("Name");
        grid.addColumn(Clients::getSurName).setCaption("SurName");
        grid.addColumn(Clients::getMidName).setCaption("MiddleName");
        grid.addColumn(Clients::getNewPassport).setCaption("Passport");
        grid.addColumn(Clients::getOldPassport).setCaption("OldPassport");
        grid.getEditor().setEnabled(true);

        Grid<Credits> grid2 = new Grid<>();
        grid2.setSizeFull();
        grid2.addColumn(Credits::getId).setCaption("ID").setWidth(100);
        grid2.addColumn(Credits::getLoan).setCaption("Loan");
        grid2.addColumn(Credits::getWholeLoan).setCaption("WholeLoan");
        grid2.addColumn(Credits::getPaidSum).setCaption("PaidSum");
        grid2.addColumn(Credits::getPercent).setCaption("Percent");
        grid2.addColumn(Credits::getCreditData).setCaption("Data").setWidth(400);


        grid.setStyleGenerator(client -> expiryClients.checkClient(client) ? "dead" : null);
        grid2.setStyleGenerator(credit -> showExpiry.getExpiryCredits(credit) ? "expired" : null);


        buttonDodjers.addClickListener(clickEvent -> {
            List<Clients> listDodjers = clientController.getAllClients().stream().filter(client -> expiryClients.checkClient(client)).collect(Collectors.toList());
            grid.setItems(listDodjers);
        });
        buttonNotDodjers.addClickListener(clickEvent -> {
            List<Clients> listNotDodjers = clientController.getAllClients().stream().filter(client -> (!expiryClients.checkClient(client))).collect(Collectors.toList());
            grid.setItems(listNotDodjers);
        });
        buttonAllClients.addClickListener(clickEvent -> {
            grid.setItems(clientController.getAllClients());
        });

        grid.addItemClickListener(event -> {

            grid2.setItems(creditController.getByClientID(event.getItem().getClientId()));

            buttonAddCredit.addClickListener(clickEvent -> {
                try {
                    if (сreditLoan.getValue().isEmpty() || creditPercent.getValue().isEmpty() ||
                            creditPaidSum.getValue().isEmpty() || creditWholeLoan.getValue().isEmpty() ||
                            creditDate.getValue().isEmpty())
                        throw new Exception();
                    else {
                        creditController.saveNewCredit(new Credits(event.getItem().getClientId(), сreditLoan.getValue(),
                                creditPercent.getValue(), creditPaidSum.getValue(), creditWholeLoan.getValue(), creditDate.getValue()));
                    }
                } catch (Exception e) {
                    e.printStackTrace();
                    Notification.show("Incorrect data for new credit!");
                }
                grid2.setItems(creditController.getByClientID(event.getItem().getClientId()));
                сreditLoan.clear();
                creditPercent.clear();
                creditPaidSum.clear();
                creditWholeLoan.clear();
                creditDate.clear();

            });

        });

        buttonAddClient.addClickListener(clickEvent -> {

            try {
                if (сlientName.getValue().isEmpty() || clientSurName.getValue().isEmpty() ||
                        clientMidName.getValue().isEmpty() || clientPhone.getValue().isEmpty() ||
                        clientPassport.getValue().isEmpty() || clientDate.getValue().isEmpty() || clientOldPassport.getValue().isEmpty())
                    throw new Exception();
                else {
                    Clients newClient = new Clients(сlientId.getValue(), сlientName.getValue(), clientSurName.getValue(), clientMidName.getValue(),
                            clientPhone.getValue(), clientPassport.getValue(), clientDate.getValue(), clientOldPassport.getValue());
                    clientController.saveNewClient(newClient);

                    grid.setItems(clientController.getAllClients());
                    grid.getSelectionModel().select(newClient);
                }
            } catch (Exception ex) {
                ex.printStackTrace();
                Notification.show("Incorrect data for new client!");
            }

            сlientId.clear();
            сlientName.clear();
            clientSurName.clear();
            clientMidName.clear();
            clientPhone.clear();
            clientPassport.clear();
            clientDate.clear();
            clientOldPassport.clear();

        });

        grid.setItems(clientController.getAllClients());

        layoutClient.addComponents(сlientId, сlientName, clientSurName, clientMidName, clientPhone, clientPassport,clientDate, clientOldPassport);
        layoutCredit.addComponents(сreditLoan,creditPercent,creditPaidSum,creditWholeLoan,creditDate);
        horlayout2.addComponents( layoutClient,layoutCredit);
        horlayout.addComponents( buttonAddClient, buttonAddCredit, buttonDodjers, buttonNotDodjers,buttonAllClients);
        layout.addComponents(horlayout, grid, grid2, horlayout2);

        setContent(layout);
    }

    @WebServlet(urlPatterns = "/*", name = "MyUIServlet", asyncSupported = true)
    @VaadinServletConfiguration(ui = MyUI.class, productionMode = false)
    public class MyUIServlet extends VaadinServlet {
    }
}

