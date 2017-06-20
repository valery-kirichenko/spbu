package com.exam.Exam.Controllers;

import com.exam.Exam.Model.Person;
import com.google.gson.Gson;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;

import java.util.ArrayList;
import java.util.List;

@Controller
public class JControllerImpl implements JController{

    @Autowired RController rController;

    public Person getRandomPerson() {
        Gson gson = new Gson();
        return gson.fromJson(rController.getData(), Person.class);
    }

    public List<Person> getRandomPersonList(Integer size) {
        List<Person> list = new ArrayList<>();
        for (int i = 0; i < size; i++) {
            list.add(getRandomPerson());
        }
        return list;
    }
}
