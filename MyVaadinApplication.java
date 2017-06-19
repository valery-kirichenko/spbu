package com.example.CreditBase1;


import com.vaadin.annotations.Theme;
import com.vaadin.annotations.VaadinServletConfiguration;
import com.vaadin.event.MouseEvents;
import com.vaadin.server.VaadinRequest;
import com.vaadin.server.VaadinServlet;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.*;
import com.vaadin.ui.Button;
import com.vaadin.ui.TextField;
import javafx.scene.control.*;
import javafx.scene.control.Label;
import org.springframework.beans.factory.annotation.Autowired;

import javax.servlet.annotation.WebServlet;
import javax.swing.*;
import javax.swing.plaf.TableUI;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * This UI is the application entry point. A UI may either represent a browser window
 * (or tab) or some part of a html page where a Vaadin application is embedded.
 * <p>
 * The UI is initialized using {@link #init(VaadinRequest)}. This method is intended to be
 * overridden to add component to the user interface and initialize non-component functionality.
 */

@SpringUI
@Theme("mytheme")
public class MyVaadinApplication extends UI {
    @Autowired
    private Opens opens;

    @Override
    public void init(VaadinRequest request) {

        List<Clients> clients = new ArrayList<Clients>() {
        };
        List<Credits> credits = new ArrayList<Credits>() {
        };

        try {
            opens.start(credits, clients);
        } catch (IOException ex) {
            ex.printStackTrace();
        }

        VerticalLayout layout = new VerticalLayout();



        Grid<Clients> grid = new Grid<>();
        grid.setWidth("1200");
        grid.setHeight("600");
        grid.addColumn(Clients::getId).setCaption("ID").setWidth(150);
        grid.addColumn(Clients::getName).setCaption("Name");
        grid.addColumn(Clients::getFam).setCaption("Surname");
        grid.addColumn(Clients::getOt).setCaption("Patronymic");
        grid.addColumn(Clients::getSot).setCaption("Phone number");
        grid.addColumn(Clients::getPas1).setCaption("Passport");
        grid.addColumn(Clients::getDate).setCaption("Date");
        grid.addColumn(Clients::getPas2).setCaption("Old passport");
        TextField name = new TextField("Введите ID клиента");
        Button greetButton = new Button("OK");
        com.vaadin.ui.Label newClient = new com.vaadin.ui.Label("New client");
        com.vaadin.ui.Label newCredit = new com.vaadin.ui.Label("New credit");
        Button create1 = new Button("Добавить");
        grid.getEditor().setEnabled(true);
        grid.setItems(clients);





            greetButton.addClickListener(
                    e -> {
                            Grid<Credits> grid2 = new Grid<>();
                            grid2.setWidth("1200");
                            grid2.setHeight("500");
                            grid2.addColumn(Credits::getSum).setCaption("Sum").setWidth(150);
                            grid2.addColumn(Credits::getPer).setCaption("Percent");
                            grid2.addColumn(Credits::getVyp).setCaption("Vyp");
                            grid2.addColumn(Credits::getOst).setCaption("Ost");
                            grid2.addColumn(Credits::getDate).setCaption("Date");
                            grid2.getEditor().setEnabled(true);
                            int nom=find(clients, Integer.parseInt(name.getValue()));
                            if (nom!=-1) {
                                grid2.setItems(clients.get(nom).getCreditsList());
                                layout.addComponent(grid2);
                                setContent(layout);
                            }

                    }
            );

        TextField name2 = new TextField("Name");
        TextField surname = new TextField("Surname");
        TextField patronymic = new TextField("Patronymic");
        TextField phone_number = new TextField("Phone number");
        TextField passport = new TextField("Passport");
        TextField date = new TextField("Date");
        TextField old_passport = new TextField("Old passport");
        Button create = new Button("Добавить");

            create.addClickListener(
                    e->{
                        if (name2.getValue()!="" && surname.getValue()!="" && phone_number.getValue()!="" && date.getValue()!="" && passport.getValue()!="" && old_passport.getValue()!="" && patronymic.getValue()!="") {
                            Clients neww = new Clients();
                            neww.setName(name2.getValue());
                            neww.setFam(surname.getValue());
                            neww.setOt(patronymic.getValue());
                            neww.setSot(phone_number.getValue());
                            neww.setDate(date.getValue());
                            neww.setPas1(passport.getValue());
                            neww.setPas2(old_passport.getValue());
                            neww.setId(Integer.toString(clients.size()+73));
                            clients.add(neww);
                        }
                    });
        TextField id2 = new TextField("ID");
        TextField sum = new TextField("Sum");
        TextField per = new TextField("Percent");
        TextField vyp = new TextField("Vyp");
        TextField ost = new TextField("Ost");
        TextField date2 = new TextField("Date");

        create1.addClickListener(
                e->{
                    if (sum.getValue()!="" && per.getValue()!="" && vyp.getValue()!="" && ost.getValue()!="" && date2.getValue()!="" && id2.getValue()!="") {
                        Credits neww = new Credits();
                        neww.setSum(sum.getValue());
                        neww.setPer(per.getValue());
                        neww.setVyp(vyp.getValue());
                        neww.setOst(ost.getValue());
                        neww.setDate(date2.getValue());
                        neww.setId(id2.getValue());
                        int u = find(clients, Integer.parseInt(id2.getValue()));
                        clients.get(u).getCreditsList().add(neww);
                    }
                });

        layout.addComponents(grid, name, greetButton, newClient, name2, surname, patronymic, phone_number, passport, date, old_passport, create, newCredit, id2, sum, per, vyp, ost, date2, create1);
        setContent(layout);
    }


    int find(List<Clients> list, int ind) {
        for (int i = 0; i < list.size(); i++) {
            if (ind == Integer.parseInt(list.get(i).getId()))
                return i;
        }
        return -1;
    }




    @WebServlet(urlPatterns = "/*", name = "MyUIServlet", asyncSupported = true)
    @VaadinServletConfiguration(ui = MyVaadinApplication.class, productionMode = false)
    public static class MyUIServlet extends VaadinServlet {
    }
}
