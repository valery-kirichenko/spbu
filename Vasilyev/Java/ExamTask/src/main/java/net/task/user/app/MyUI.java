package net.task.user.app;

import javax.servlet.annotation.WebServlet;

import com.vaadin.annotations.Theme;
import com.vaadin.annotations.VaadinServletConfiguration;
import com.vaadin.server.VaadinRequest;
import com.vaadin.server.VaadinServlet;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.*;

import net.task.user.dao.DBUsersController;
import net.task.user.dao.RUsersController;
import net.task.user.models.Result;
import net.task.user.models.User;
import org.springframework.beans.factory.annotation.Autowired;


/**
 * This UI is the application entry point. A UI may either represent a browser window
 * (or tab) or some part of a html page where a Vaadin application is embedded.
 * <p>
 * The UI is initialized using {@link #init(VaadinRequest)}. This method is intended to be
 * overridden to add component to the user interface and initialize non-component functionality.
 */


/*
 {"results":[{"gender":"female","name":{"title":"mrs","first":"amanda","last":"robertson"},
 "location":{"street":"9157 the green","city":"loughrea","state":"kildare","postcode":30228},
 "email":"amanda.robertson@example.com",
 "login":{"username":"purplewolf642","password":"cat123","salt":"SL3FMf4I","md5":"367ce46a4fd9003528782db053250151",
 "sha1":"4d888fdbe861ec3ae774c60e366c55698542c051","sha256":"13348f993ceb7521bc69a0d85159ab80d2b53998bf717a0758fcbdff5753bcf5"},
 "dob":"1994-12-21 13:56:10","registered":"2006-09-16 23:16:14","phone":"071-850-6375",
 "cell":"081-957-1372","id":{"name":"PPS","value":"7794527T"},

 "picture":{"large":"https://randomuser.me/api/portraits/women/80.jpg",
 "medium":"https://randomuser.me/api/portraits/med/women/80.jpg",
 "thumbnail":"https://randomuser.me/api/portraits/thumb/women/80.jpg"},
 "nat":"IE"}],"info":{"seed":"139084404f388b85","results":1,"page":1,"version":"1.1"}}
 */

@SpringUI
@Theme("mytheme")
public class MyUI extends UI {
    @Autowired
    private DBUsersController usersController;

    @Autowired
    private RUsersController restUsersController;

    @Override
    protected void init(VaadinRequest vaadinRequest) {
        getPage().setTitle("Users RandomAPI");

        final VerticalLayout layout = new VerticalLayout();

        final Button veryImportantButton = new Button("JUST DO IT!");
        final Label copyright = new Label("© All rights reserved, V. V. Vasilyev; 2017");

        veryImportantButton.addClickListener(clickEvent -> {
            veryImportantButton.setEnabled(false);
            veryImportantButton.setCaption("WE DID IT!");

            Result result = restUsersController.getResult(100).getBody();

            for (User user : result.getResults()) {
                usersController.saveNewClient(user);
            }
        });

        layout.addComponents(veryImportantButton, copyright);

        setContent(layout);
    }


    @WebServlet(urlPatterns = "/*", name = "MyUIServlet", asyncSupported = true)
    @VaadinServletConfiguration(ui = MyUI.class, productionMode = false)
    public static class MyUIServlet extends VaadinServlet {
    }
}
