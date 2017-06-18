package com.bank.starter;

import com.vaadin.annotations.Theme;

import javax.servlet.annotation.WebServlet;

import com.vaadin.annotations.Theme;
import com.vaadin.annotations.VaadinServletConfiguration;
import com.vaadin.data.provider.DataProvider;
import com.vaadin.data.provider.DataProviderListener;
import com.vaadin.data.provider.ListDataProvider;
import com.vaadin.data.provider.Query;
import com.vaadin.server.VaadinRequest;
import com.vaadin.server.VaadinServlet;
import com.vaadin.shared.Registration;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.*;

import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.*;
import java.util.stream.Stream;

/**
 * Created by gusef on 17.06.2017.
 */

@SpringUI
@Theme("mytheme")
public class MyUI extends UI {

    private int curId = -1;
    private Client curClient;

    protected void init(VaadinRequest vaadinRequest){
        getPage().setTitle("Bank information storage");

        final VerticalLayout mainLayout = new VerticalLayout();
        final HorizontalLayout clientLayout = new HorizontalLayout();
        final HorizontalLayout creditLayout = new HorizontalLayout();

        final Grid<Client> clientGrid = new Grid();
        clientGrid.setWidth("1800px");
        clientGrid.setHeight("350px");
        clientGrid.addColumn(Client::getName).setCaption("name");
        clientGrid.addColumn(Client::getSurName).setCaption("middle name");
        clientGrid.addColumn(Client::getLastName).setCaption("last name");
        clientGrid.addColumn(Client::getPhone).setCaption("phone");
        clientGrid.addColumn(Client::getPasstoString).setCaption("passport");
        clientGrid.addColumn(Client::getBirthDate).setCaption("birthday");
        clientGrid.getEditor().setEnabled(true);
        clientGrid.setItems(MyBase.getInstance().getListOfClients());
        clientGrid.setStyleGenerator(client ->{
            ClientWorkPlace work = new ClientWorkPlace();
            return work.debtCredits(client).size()>0 ? "overdue" : null;
        });

        final TextField fieldName = new TextField("Name:");
        final TextField fieldSurName = new TextField("Middle name:");
        final TextField fieldLastName = new TextField("Last name:");
        final TextField fieldPhone = new TextField("Phone:");
        final TextField filedPass = new TextField("Passport:");
        final TextField fieldOldPass = new TextField("Old passport:");
        final DateField fieldBirthday = new DateField("Birthday:");
        clientLayout.addComponents(fieldName,fieldSurName,fieldLastName,fieldPhone,filedPass,fieldOldPass,fieldBirthday);

        Button buttonClient = new Button("add client");
        buttonClient.addClickListener(clickEvent -> {
            if(fieldName.getValue().isEmpty() || fieldSurName.getValue().isEmpty() || fieldLastName.getValue().isEmpty()||
                    fieldPhone.getValue().isEmpty() || filedPass.getValue().isEmpty() || fieldBirthday.isEmpty()){
                Notification.show("Incorrect data for new client!");
            }
            else{
                Client newClient = new Client();
                newClient.setName(fieldName.getValue());
                newClient.setSurName(fieldSurName.getValue());
                newClient.setLastName(fieldLastName.getValue());
                newClient.setPhone(fieldPhone.getValue());
                newClient.setPass(Integer.parseInt(filedPass.getValue()));
                newClient.setBirthDate(fieldBirthday.getValue());
                if(!fieldOldPass.getValue().isEmpty()){
                    ArrayList<Integer> al = new ArrayList<>();
                    al.add(Integer.parseInt(fieldOldPass.getValue()));
                    newClient.setOldPass(al);
                }
                MyBase.getInstance().tryMerge(newClient);

                Notification.show("Client " + newClient.getName() + "was added");
                clientGrid.setItems(MyBase.getInstance().getListOfClients());

                fieldName.clear();
                fieldSurName.clear();
                fieldLastName.clear();
                fieldPhone.clear();
                filedPass.clear();
                fieldOldPass.clear();
                fieldBirthday.clear();
            }
        });

        Grid<Credit> creditGrid = new Grid<>();
        creditGrid.setWidth("1800px");
        creditGrid.setHeight("300px");
        creditGrid.addColumn(Credit::getId).setCaption("user id");
        creditGrid.addColumn(Credit::getStartSum).setCaption("start sum");
        creditGrid.addColumn(Credit::getPaidSum).setCaption("paid sum");
        creditGrid.addColumn(Credit::getAllSum).setCaption("all sum");
        creditGrid.addColumn(Credit::getPercent).setCaption("persent");
        creditGrid.addColumn(Credit::getFinishDate).setCaption("finish date");
        creditGrid.getEditor().setEnabled(true);
        creditGrid.setStyleGenerator(credit->credit.isNotPaid() ? "overdue" : null);

        clientGrid.addSelectionListener(event->{
            Optional<Client> client = event.getFirstSelectedItem();
            client.ifPresent(client1 -> {
                creditGrid.setItems(MyBase.getInstance().getListOfCredits(client1));
                curId = client1.getNowId();
                curClient = client1;
            });
        });

        final TextField fieldStartSum = new TextField("Start sum:");
        final TextField fieldPaidSum = new TextField("Paid sum:");
        final TextField fieldAllSum = new TextField("All sum");
        final TextField fieldPersent = new TextField("Persent");
        final DateField fieldFinishDate = new DateField("FinishDate");
        creditLayout.addComponents(fieldStartSum,fieldPaidSum,fieldAllSum,fieldPersent,fieldFinishDate);

        Button buttonCredit = new Button("add credit");
        buttonCredit.addClickListener(clickEvent -> {
            if(fieldStartSum.getValue().isEmpty() || fieldPaidSum.getValue().isEmpty() ||
                    fieldAllSum.getValue().isEmpty() || fieldPersent.getValue().isEmpty() || fieldFinishDate.isEmpty()){
                Notification.show("Incorrect data fro credit!");
            }
            else if(curId == -1){
                Notification.show("Please choose client for adding credit");
            }
            else{
                Credit newCredit = new Credit();
                newCredit.setId(curId);
                newCredit.setAllSum(fieldAllSum.getValue());
                newCredit.setStartSum(fieldStartSum.getValue());
                newCredit.setFinishDate(fieldFinishDate.getValue());
                newCredit.setPaidSum(fieldPaidSum.getValue());
                newCredit.setPercent(fieldPersent.getValue());

                MyBase.getInstance().getMapOfCredits().get(curId).add(newCredit);
                creditGrid.setItems(MyBase.getInstance().getListOfCredits(curClient));
                Notification.show("Credit was added!");

                fieldAllSum.clear();
                fieldStartSum.clear();
                fieldFinishDate.clear();
                fieldPaidSum.clear();
                fieldPersent.clear();
            }
        });

        mainLayout.addComponents(clientGrid,clientLayout,buttonClient,creditGrid,creditLayout,buttonCredit);
        setContent(mainLayout);
    }


    @WebServlet(urlPatterns = "/*", name = "MyUIServlet", asyncSupported = true)
    @VaadinServletConfiguration(ui = MyUI.class, productionMode = false)
    public static class MyUIServlet extends VaadinServlet {
    }
}
