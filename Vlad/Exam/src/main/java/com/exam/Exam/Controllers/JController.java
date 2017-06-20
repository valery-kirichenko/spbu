package com.exam.Exam.Controllers;

import com.exam.Exam.Model.Person;

import java.util.List;

public interface JController {
    Person getRandomPerson();
    List<Person> getRandomPersonList(Integer size);
}
