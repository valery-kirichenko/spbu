package com.ridiculousdev.randoms;

import com.ridiculousdev.randoms.objects.ServiceAnswer;
import com.ridiculousdev.randoms.objects.User;
import com.vaadin.server.ExternalResource;
import com.vaadin.server.VaadinRequest;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.*;
import com.vaadin.ui.themes.ValoTheme;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.client.RestTemplate;

@SpringUI
public class MyUI extends UI {
    @Autowired
    RestTemplate restTemplate;

    @Override
    protected void init(VaadinRequest vaadinRequest) {
        ServiceAnswer answer = restTemplate.getForObject(
                "https://randomuser.me/api?results=10&nat=us&inc=name,picture", ServiceAnswer.class);

        final HorizontalLayout layout = new HorizontalLayout();
        layout.addStyleName(ValoTheme.LAYOUT_HORIZONTAL_WRAPPING);

        for (User user : answer.getResults()) {
            VerticalLayout profile = new VerticalLayout();
            Image picture = new Image();
            picture.setSource(new ExternalResource(user.getPicture().getLarge()));
            Label name = new Label(user.getName().toString());
            profile.addComponents(picture, name);
            layout.addComponent(profile);
        }
        setContent(layout);
    }
}
