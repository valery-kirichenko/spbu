package com.ridiculousdev.randoms;

import com.ridiculousdev.randoms.objects.ServiceAnswer;
import com.ridiculousdev.randoms.objects.User;
import com.vaadin.server.ExternalResource;
import com.vaadin.server.VaadinRequest;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.*;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.client.RestTemplate;

import java.util.LinkedList;
import java.util.List;

@SpringUI
public class MyUI extends UI {
    @Autowired
    RestTemplate restTemplate;

    @Override
    protected void init(VaadinRequest vaadinRequest) {
        ServiceAnswer answer = restTemplate.getForObject(
                "https://randomuser.me/api?results=10&nat=us&inc=name,picture", ServiceAnswer.class);

        final VerticalLayout layout = new VerticalLayout();
        HorizontalLayout row1 = new HorizontalLayout();
        HorizontalLayout row2 = new HorizontalLayout();
        int i = 0;
        for (User user : answer.getResults()) {
            VerticalLayout profile = new VerticalLayout();
            Image picture = new Image();
            picture.setSource(new ExternalResource(user.getPicture().getLarge()));
            Label name = new Label(user.getName().toString());
            profile.addComponents(picture, name);
            if (i < 5) row1.addComponent(profile);
            else row2.addComponent(profile);
            i++;
        }
        layout.addComponents(row1, row2);

        setContent(layout);
    }
}
