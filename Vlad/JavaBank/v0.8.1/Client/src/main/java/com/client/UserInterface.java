package com.client;

import com.vaadin.server.VaadinRequest;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.*;
import org.springframework.beans.factory.annotation.Autowired;

@SpringUI
public class UserInterface extends UI {

    @Autowired
    RestClient restClient;

    @Override
    protected void init(VaadinRequest vaadinRequest) {
        Button doIt = new Button("JUST DO IT");
        doIt.setHeight("400px");
        doIt.setWidth("400px");
        AbsoluteLayout layout = new AbsoluteLayout();
        layout.addComponent(doIt, "left: 760px; top: 240px;");
        doIt.addClickListener(clickEvent -> {
           doIt.setEnabled(false);
           restClient.doBigBlast();
        });

        setContent(layout);
    }
}

