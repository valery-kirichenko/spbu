package com.example.demo;

import DateBase.BaseReader;
import DateBase.Credit;
import DateBase.Information;
import DateBase.Client;
import com.vaadin.annotations.VaadinServletConfiguration;
import com.vaadin.server.VaadinRequest;
import com.vaadin.server.VaadinServlet;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.*;

import javax.servlet.annotation.WebServlet;
import javax.xml.soap.Text;
import java.util.IntSummaryStatistics;
import java.util.List;

@SpringUI
public class MyUI extends UI {

    @Override
    protected void init(VaadinRequest vaadinRequest) {
        Information inf = new Information(BaseReader.clientRead("clients.omg"));

        final VerticalLayout layout = new VerticalLayout();
        final HorizontalLayout addClient = new HorizontalLayout();
        final HorizontalLayout addCredit = new HorizontalLayout();

        final Grid<Client> outTableClients = new Grid<>();

        outTableClients.setWidth("1200px");
        outTableClients.setHeight("350px");
        outTableClients.addColumn(Client::getID).setCaption("ID").setWidth(150);
        outTableClients.addColumn(Client::getfName).setCaption("First Name");
        outTableClients.addColumn(Client::getsName).setCaption("Second Name");
        outTableClients.addColumn(Client::getftName).setCaption("Father Name");
        outTableClients.addColumn(Client::getPhoneNum).setCaption("Phone");
        outTableClients.addColumn(Client::getNewPass).setCaption("Passport");
        outTableClients.addColumn(Client::getOldPass).setCaption("Old Passport");
        outTableClients.addColumn(Client::getdate).setCaption("Birthday");
        outTableClients.getEditor().setEnabled(true);

        outTableClients.setItems(inf.clients);

        final TextField fName = new TextField();
        final TextField sName = new TextField();
        final TextField ftName = new TextField();
        final TextField phone = new TextField();
        final TextField newPass = new TextField();
        final TextField oldPass = new TextField();
        final TextField date = new TextField();

        fName.setCaption("First Name");
        sName.setCaption("Second Name");
        ftName.setCaption("Father Name");
        phone.setCaption("Phone");
        newPass.setCaption("Passport");
        oldPass.setCaption("Old Passport");
        date.setCaption("Birthday");

        Button addcl = new Button("Добавить");
        addcl.addClickListener(e -> {
            Client newCl = new Client(inf.clients.size(),Integer.parseInt(oldPass.getValue()),Integer.parseInt(newPass.getValue()),fName.getValue(),sName.getValue(),ftName.getValue(),phone.getValue(),date.getValue());
            inf.clients.add(newCl);
            layout.addComponent(new Label("Клиент успешно добавлен. ID: "+newCl.id));
        });

        addClient.addComponents(fName,sName,ftName,phone,newPass,oldPass,date);
        layout.addComponents(new Label("Добавление нового клиента: "),addClient,addcl);

        final TextField id = new TextField();
        final TextField sum = new TextField();
        final TextField paidSum = new TextField();
        final TextField nSum = new TextField();
        final TextField percent = new TextField();
        final TextField crDate = new TextField();

        id.setCaption("ID");
        sum.setCaption("Sum");
        paidSum.setCaption("Paid sum");
        nSum.setCaption("Need paid sum");
        percent.setCaption("Percent");
        crDate.setCaption("Date");

        Button addcr = new Button("Добавить");
        addcr.addClickListener(e -> {
            Credit newCr = new Credit(Integer.parseInt(id.getValue()),Double.parseDouble(sum.getValue()),Double.parseDouble(nSum.getValue()),Double.parseDouble(paidSum.getValue()),Double.parseDouble(percent.getValue()),crDate.getValue());
            inf.clients.get(Integer.parseInt(id.getValue())).credits.add(newCr);
            layout.addComponent(new Label("Кредит успешно записан на ID: "+newCr.getID()));
        });

        addCredit.addComponents(id,sum,nSum,paidSum,percent,crDate);
        layout.addComponents(new Label("Добавление кредита:"),addCredit,addcr);

        final TextField name = new TextField();
        name.setCaption("Введите ID пользователя для получения его кредитов:");

        Button button = new Button("Поиск");
        button.addClickListener( e -> {
            Grid<Credit> outTableCredits = makeCreditTable(inf.SearchID(Integer.parseInt(name.getValue())).credits);
            if (inf.SearchID(Integer.parseInt(name.getValue())).credits.size() == 0){
                Label msg = new Label();
                msg.setValue("No credits on ID "+name.getValue());
                layout.addComponent(msg);
            }
            else layout.addComponent(outTableCredits);
        });

        layout.addComponents(new Label("Список клиентов:"),outTableClients, name, button);

        setContent(layout);
    }

    public Grid<Credit> makeCreditTable(List<Credit> cr){
        final Grid<Credit> outTableCredit = new Grid<>();
        outTableCredit.setWidth("1200px");
        outTableCredit.setHeight(Integer.toString(38+cr.size()*38)+"px");
        outTableCredit.addColumn(Credit::getID).setCaption("ID").setWidth(150);
        outTableCredit.addColumn(Credit::getSum).setCaption("Sum");
        outTableCredit.addColumn(Credit::getPaySum).setCaption("Paid sum");
        outTableCredit.addColumn(Credit::getnSum).setCaption("Need paid sum");
        outTableCredit.addColumn(Credit::getPercent).setCaption("Percent");
        outTableCredit.addColumn(Credit::getDate).setCaption("Date");
        outTableCredit.getEditor().setEnabled(true);
        outTableCredit.setItems(cr);
        return outTableCredit;
    }

    @WebServlet(urlPatterns = "/*", name = "MyUIServlet", asyncSupported = true)
    @VaadinServletConfiguration(ui = MyUI.class, productionMode = false)
    public static class MyUIServlet extends VaadinServlet {
    }
}
