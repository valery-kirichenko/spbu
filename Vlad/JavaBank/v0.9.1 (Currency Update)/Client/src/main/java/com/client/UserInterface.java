package com.client;

import com.vaadin.annotations.Theme;
import com.vaadin.server.ExternalResource;
import com.vaadin.server.FileResource;
import com.vaadin.server.VaadinRequest;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.*;
import org.springframework.beans.factory.annotation.Autowired;

import java.io.File;
import java.net.URL;

@Theme("mytheme")
@SpringUI
public class UserInterface extends UI {

    @Autowired
    RestClient restClient;

    @Override
    protected void init(VaadinRequest vaadinRequest) {
        Button doIt = new Button("JUST DO IT");
        doIt.setHeight("100px");
        doIt.setWidth("400px");
        doIt.setStyleName("button", true);

        AbsoluteLayout layout = new AbsoluteLayout();
        layout.addComponent(doIt, "left: 760px; top: 750px;");
        doIt.addClickListener(clickEvent -> {
           doIt.setEnabled(false);
           restClient.doBigBlast();
        });

        URL VIDEOPATH = Thread.currentThread().getContextClassLoader().getResource("justdoit.mp4");
        FileResource fileResource = new FileResource(new File(VIDEOPATH.getPath()));
        Video vd = new Video();
        vd.setWidth("1280px");
        vd.setHeight("720px");
        vd.setAutoplay(true);
        vd.setSource(fileResource);
        layout.addComponent(vd, "left: 320px; top: 10px");

        setContent(layout);
    }
}

