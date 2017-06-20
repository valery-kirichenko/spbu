package com.exam.Exam.View;

import com.exam.Exam.Controllers.JController;
import com.exam.Exam.Model.Person;
import com.exam.Exam.Model.Result;
import com.vaadin.server.VaadinRequest;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.Grid;
import com.vaadin.ui.UI;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.ArrayList;
import java.util.List;

@SpringUI
public class View extends UI{

    @Autowired
    JController jController;

    @Override
    protected void init(VaadinRequest vaadinRequest) {

        List<Person> people = jController.getRandomPersonList(50);
        List<Result> results = new ArrayList<>();

        for (Person person : people) {
            results.add(person.getResults().get(0));
        }

        Grid<Result> grid = new Grid<>();
        grid.setItems(results);
        grid.addColumn(Result::toString).setCaption("Human Being");
        setContent(grid);
    }
}
