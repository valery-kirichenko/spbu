package com.NewDataBase;

import com.vaadin.annotations.Theme;
import com.vaadin.annotations.VaadinServletConfiguration;
import com.vaadin.server.VaadinRequest;
import com.vaadin.server.VaadinServlet;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.*;
import org.springframework.beans.factory.annotation.Autowired;

import javax.servlet.annotation.WebServlet;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;


@Theme("mytheme")
@SpringUI
public class MyUI extends UI {
    @Autowired
    private ShowClientWithExpiryCredit expiryClients;

    @Autowired
    private ShowExpiryCredit showExpiry;

    @Autowired
    private ClientControllerImpl clientController;

    @Autowired
    private CreditControllerImpl creditController;

    @Autowired
    private CurrencyService currencyService;

    private List<Credits> creditUpdate(List<Credits> credits, Currency newCurrency) {
        if (!newCurrency.equals(Currency.RUB)) {
            Double multiplication = currencyService.getRate(Currency.RUB, newCurrency);
            for (Credits credit : credits) {
                Double tempLoan = Double.parseDouble(credit.getLoan()) * multiplication;
                Double tempWholeLoan = Double.parseDouble(credit.getWholeLoan()) * multiplication;
                Double tempPaidSum = Double.parseDouble(credit.getPaidSum()) * multiplication;
                credit.setLoan(tempLoan.toString());
                credit.setWholeLoan(tempWholeLoan.toString());
                credit.setPaidSum(tempPaidSum.toString());
            }
        }
        return credits;
    }

    @Override
    protected void init(VaadinRequest vaadinRequest) {
        final VerticalLayout layout = new VerticalLayout();
        final HorizontalLayout horlayout = new HorizontalLayout();
        final HorizontalLayout horlayout2 = new HorizontalLayout();
        final VerticalLayout layoutClient = new VerticalLayout();
        final VerticalLayout layoutCredit = new VerticalLayout();

        TextField сlientId = new TextField("Enter client id");
        сlientId.setValue("12121");
        TextField сlientName = new TextField("Enter Client name");
        сlientName.setValue("Jamal");
        TextField clientSurName = new TextField("Enter SurName");
        clientSurName.setValue("Jaoel");
        TextField clientMidName = new TextField("Enter MidName");
        clientMidName.setValue("Savage");
        TextField clientPhone = new TextField("Enter phone");
        clientPhone.setValue("89818325441");
        TextField clientPassport = new TextField("Enter Passport");
        clientPassport.setValue("8012345766");
        TextField clientDate = new TextField("Enter client date.For example:2017-12-01");
        clientDate.setValue("1998-09-09");
        TextField clientOldPassport = new TextField("Enter Old Passport");
        clientOldPassport.setValue("8012345611");
        TextField сreditLoan = new TextField("Enter Credit Loan");
        сreditLoan.setValue("1000");
        TextField creditPercent = new TextField("Enter Credit Percent");
        creditPercent.setValue("6");
        TextField creditPaidSum = new TextField("Enter Credit Paid Sum");
        creditPaidSum.setValue("555");
        TextField creditWholeLoan = new TextField("Enter Credit Whole Loan");
        creditWholeLoan.setValue("1001");
        TextField creditDate = new TextField("Enter Credit Date.For Example : 2017-01-01");
        creditDate.setValue("1998-01-01");
        TextField IdClientSelected = new TextField("Id of Selected Client");

        Button buttonAddClient = new Button("Add Client");
        Button buttonAddCredit = new Button("Add Credit");
        Button buttonDodjers = new Button("Filter : dodgers");
        Button buttonNotDodjers = new Button("Filter : not dodgers");
        Button buttonAllClients = new Button("All Clients");

        Grid<Clients> clientGrid = new Grid<>();
        clientGrid.setSizeFull();
        clientGrid.addColumn(Clients::getId).setCaption("ID").setWidth(100);
        clientGrid.addColumn(Clients::getName).setCaption("Name");
        clientGrid.addColumn(Clients::getSurName).setCaption("SurName");
        clientGrid.addColumn(Clients::getMidName).setCaption("MiddleName");
        clientGrid.addColumn(Clients::getNewPassport).setCaption("Passport");
        clientGrid.addColumn(Clients::getOldPassport).setCaption("OldPassport");
        clientGrid.getEditor().setEnabled(true);

        Grid<Credits> creditGrid = new Grid<>();
        creditGrid.setSizeFull();
        creditGrid.addColumn(Credits::getCreditId).setCaption("Credit ID ").setWidth(100);
        creditGrid.addColumn(Credits::getId).setCaption("Client ID").setWidth(100);
        creditGrid.addColumn(Credits::getLoan).setCaption("Loan");
        creditGrid.addColumn(Credits::getWholeLoan).setCaption("WholeLoan");
        creditGrid.addColumn(Credits::getPaidSum).setCaption("PaidSum");
        creditGrid.addColumn(Credits::getPercent).setCaption("Percent");
        creditGrid.addColumn(Credits::getDataString).setCaption("Data").setWidth(400);


        clientGrid.setStyleGenerator(client -> expiryClients.checkClient(client) ? "dead" : null);
        creditGrid.setStyleGenerator(credit -> showExpiry.getExpiryCredits(credit) ? "expired" : null);


        buttonDodjers.addClickListener(clickEvent -> {
            List<Clients> listDodjers = clientController.getAllClients().stream().filter(client ->
                    expiryClients.checkClient(client)).collect(Collectors.toList());
            clientGrid.setItems(listDodjers);
        });
        buttonNotDodjers.addClickListener(clickEvent -> {
            List<Clients> listNotDodjers = clientController.getAllClients().stream().filter(client ->
                    (!expiryClients.checkClient(client))).collect(Collectors.toList());
            clientGrid.setItems(listNotDodjers);
        });
        buttonAllClients.addClickListener(clickEvent -> {
            clientGrid.setItems(clientController.getAllClients());
        });

        clientGrid.addSelectionListener(event -> {
            creditGrid.setItems(creditController.getByClientID(event.getFirstSelectedItem().get().getId()));
            IdClientSelected.setValue(event.getFirstSelectedItem().get().getId().toString());
        });
        buttonAddCredit.addClickListener(clickEvent -> {
            if (IdClientSelected.getValue() != null) {
                Credits credit = new Credits();
                credit.setId(Integer.parseInt(IdClientSelected.getValue()));
                credit.setLoan(сreditLoan.getValue());
                credit.setPercent(creditPercent.getValue());
                credit.setPaidSum(creditPaidSum.getValue());
                credit.setWholeLoan(creditWholeLoan.getValue());
                credit.setDataString(creditDate.getValue());
                if (credit.getLoan() == null || credit.getPercent() == null ||
                        credit.getPaidSum() == null || credit.getWholeLoan() == null || credit.getDataString() == null)
                    Notification.show("Incorrect data for new credit!");

                else {
                    creditController.saveNewCredit(credit);
                    Notification.show("We insert new credit to client id :" + IdClientSelected.getValue());
                }
            } else Notification.show("You didn't chose client !");
            creditGrid.setItems(creditController.getByClientID(Integer.parseInt(IdClientSelected.getValue())));
            сreditLoan.clear();
            creditPercent.clear();
            creditPaidSum.clear();
            creditWholeLoan.clear();
            creditDate.clear();

        });

        buttonAddClient.addClickListener(clickEvent -> {
            Clients newClient = new Clients();
            newClient.setId(Integer.parseInt(сlientId.getValue()));
            newClient.setName(сlientName.getValue());
            newClient.setSurName(clientSurName.getValue());
            newClient.setMidName(clientMidName.getValue());
            newClient.setPhone(clientPhone.getValue());
            newClient.setNewPassport(clientPassport.getValue());
            newClient.setData(clientDate.getValue());
            newClient.setOldPassport(clientOldPassport.getValue());

            if (newClient.getId() == null || newClient.getName() == null || newClient.getSurName() == null ||
                    newClient.getOldPassport() == null ||
                    newClient.getMidName() == null || newClient.getPhone() == null ||
                    newClient.getNewPassport() == null)
                Notification.show("Incorrect data for new client!");
            else {
                clientController.saveNewClient(newClient);
                clientGrid.setItems(clientController.getAllClients());
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

        clientGrid.setItems(clientController.getAllClients());

        List<Currency> namesCurrency = new ArrayList<>();
        namesCurrency.add(Currency.RUB);
        namesCurrency.add(Currency.USD);
        namesCurrency.add(Currency.EUR);
        ComboBox<Currency> boxCurrency = new ComboBox<>("Currency");
        boxCurrency.setEmptySelectionAllowed(false);
        boxCurrency.setItems(namesCurrency);
        boxCurrency.setValue(Currency.RUB);

        boxCurrency.setItemCaptionGenerator(Currency::toString);
        boxCurrency.addValueChangeListener(valueChangeEvent -> {
            if (!IdClientSelected.isEmpty()) {
                Integer id = Integer.parseInt(IdClientSelected.getValue());
                List<Credits> tempCredits = creditUpdate(creditController.getByClientID(id), boxCurrency.getValue());
                creditGrid.setItems(tempCredits);
            }
        });

        layoutClient.addComponents(сlientId, сlientName, clientSurName, clientMidName, clientPhone,
                clientPassport, clientDate, clientOldPassport);
        layoutCredit.addComponents(сreditLoan, creditPercent, creditPaidSum, creditWholeLoan, creditDate);
        horlayout2.addComponents(layoutClient, layoutCredit);
        horlayout.addComponents(buttonAddClient, buttonAddCredit, buttonDodjers, buttonNotDodjers,
                buttonAllClients, boxCurrency, IdClientSelected);
        layout.addComponents(horlayout, clientGrid, creditGrid, horlayout2);

        setContent(layout);
    }

    @WebServlet(urlPatterns = "/*", name = "MyUIServlet", asyncSupported = true)
    @VaadinServletConfiguration(ui = MyUI.class, productionMode = false)
    public class MyUIServlet extends VaadinServlet {
    }
}
