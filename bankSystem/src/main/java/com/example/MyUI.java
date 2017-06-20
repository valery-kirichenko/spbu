package com.example;

import com.vaadin.server.VaadinRequest;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.*;
import com.vaadin.ui.components.grid.ItemClickListener;
import org.springframework.beans.factory.annotation.Autowired;

import java.awt.geom.Arc2D;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;
import java.util.Scanner;

/**
 * Created by Lenovo on 13.04.2017.
 */
@SpringUI
public class MyUI extends UI {
    @Autowired
    DataReader dataReader;

    @Override
    protected void init(VaadinRequest vaadinRequest) {
        ArrayList<newBase> BankBase =dataReader.createNewBase();
        //clienthelper.getUnPaid(BankBase);
        //clienthelper.getUnPaidYet(BankBase);

        //UI
        ArrayList<Clients> someClients = new ArrayList<>();
        final HorizontalLayout Hlayout = new HorizontalLayout();
        final VerticalLayout layout = new VerticalLayout();
        final HorizontalLayout layoutForAdd = new HorizontalLayout();
        final VerticalLayout layoutForAddTextClient = new VerticalLayout();
        final VerticalLayout layoutForAddTextCredit = new VerticalLayout();
        final TextField Tname = new TextField("Name");
        final TextField TsurName = new TextField("SurName");
        final TextField TfatherName = new TextField("FatherName");
        final TextField Tnum = new TextField("Phone");
        final DateField Tdate = new DateField("Date");
        final TextField Tpas = new TextField("Pasport");
        final TextField TfirstPas = new TextField("FirstPas");
        layoutForAddTextClient.addComponents(Tname,TsurName,TfatherName,Tnum,Tdate,Tpas,TfirstPas);
        final TextField Tsum = new TextField("Sum");
        final TextField Tid = new TextField("Id(only if you want to add a credit to existing client)");
        final TextField Tproc = new TextField("Proc");
        final TextField TsumYet = new TextField("SumYet");
        final TextField TsumToPay = new TextField("sumToPay");
        final DateField TdateForCr = new DateField("Date");
        Button add = new Button("Add");
        layoutForAddTextCredit.addComponents(Tid,Tsum,Tproc,TsumYet,TsumToPay,TdateForCr,add);
        Grid<Clients> grid = new Grid<>(Clients.class);
        add.addClickListener(clickEvent ->
        {
            Credits SomeCredit = new Credits();
            Clients SomeClient= new Clients();
            newBase Another = new newBase();
            if (!Tsum.isEmpty()) {
                SomeCredit.setDate(TdateForCr.getValue().toString());
                SomeCredit.setSum(Integer.parseInt(Tsum.getValue()));
                SomeCredit.setSumToPay(Integer.parseInt(TsumToPay.getValue()));
                SomeCredit.setProc(Double.parseDouble(Tproc.getValue()));
                if(Tid.isEmpty()) {
                    SomeCredit.setId(BankBase.size());
                    SomeClient.setName(Tname.getValue());
                    SomeClient.setSurName(TsurName.getValue());
                    SomeClient.setFatherName(TfatherName.getValue());
                    SomeClient.setNum(Tnum.getValue());
                    SomeClient.setDate(Tdate.getValue().toString());
                    SomeClient.setPas(Integer.parseInt(Tpas.getValue()));
                    if (!TfirstPas.isEmpty()) SomeClient.setFirstPas(Integer.parseInt(TfirstPas.getValue()));
                    SomeClient.setId(BankBase.size());
                    Another.setByCredit(SomeClient,SomeCredit);
                    BankBase.add(Another);
                    someClients.add(SomeClient);
                    grid.setItems(someClients);
                    layout.removeComponent(grid);
                    layout.addComponentAsFirst(grid);
                }
                else
                {
                    SomeCredit.setId(Integer.parseInt(Tid.getValue()));
                    BankBase.get(Integer.parseInt(Tid.getValue())).addCredit(SomeCredit);
                }
            }

            else
            {
                SomeClient.setName(Tname.getValue());
                SomeClient.setSurName(TsurName.getValue());
                SomeClient.setFatherName(TfatherName.getValue());
                SomeClient.setNum(Tnum.getValue());
                SomeClient.setDate(Tdate.getValue().toString());
                SomeClient.setPas(Integer.parseInt(Tpas.getValue()));
                if (!TfirstPas.isEmpty()) SomeClient.setFirstPas(Integer.parseInt(TfirstPas.getValue()));
                SomeClient.setId(BankBase.size());
                Another.setThisClient(SomeClient);
                BankBase.add(Another);
                someClients.add(SomeClient);
                grid.setItems(someClients);
                layout.removeComponent(grid);
                layout.addComponentAsFirst(grid);
            }




        });
        for (int i = 0; i < BankBase.size(); i++)
        {
            someClients.add(BankBase.get(i).getClient());
        }
        grid.removeAllColumns();
        grid.setItems(someClients);
        grid.addColumn(Clients::getId).setCaption("Id");//"id","Name","SurName","FatherName","num","date");
        grid.addColumn(Clients::getName).setCaption("Name");
        grid.addColumn(Clients::getSurName).setCaption("SurName");
        grid.addColumn(Clients::getFatherName).setCaption("FatherName");
        grid.addColumn(Clients::getNum).setCaption("Phone");
        grid.addColumn(Clients::getDate).setCaption("Date");
        grid.addColumn(Clients::getPas).setCaption("Pasport");
        grid.addColumn(Clients::getFirstPas).setCaption("PrevPas");
        grid.setSizeFull();
        Grid<Credits> CreditsGrid = new Grid<>();
        CreditsGrid.addColumn(Credits::getId).setCaption("Id");//"id","Name","SurName","FatherName","num","date");
        CreditsGrid.addColumn(Credits::getSum).setCaption("Sum");
        CreditsGrid.addColumn(Credits::getProc).setCaption("Proc");
        CreditsGrid.addColumn(Credits::getSumYet).setCaption("SumYet");
        CreditsGrid.addColumn(Credits::getSumToPay).setCaption("SumToPay");
        CreditsGrid.addColumn(Credits::getNeedToPay).setCaption("NeedToPay");
        CreditsGrid.addColumn(Credits::getDate).setCaption("Date");
        CreditsGrid.setSizeFull();
        layout.addComponent(CreditsGrid);
        grid.addSelectionListener(event -> {
            Optional<Clients> selected = event.getFirstSelectedItem();
            if (selected.isPresent())
            {
                CreditsGrid.setItems(BankBase.get(selected.get().getId()).getCredits());
            }

        });
        layoutForAdd.addComponents(layoutForAddTextClient,layoutForAddTextCredit);
        layout.addComponents(grid,CreditsGrid);
        Hlayout.addComponentsAndExpand(layout,layoutForAdd);
        setContent(Hlayout);
    }


}
