package com.bank.starter.ExamTaskControllers;

import com.bank.starter.models.User;
import com.bank.starter.models.ServerAnswer;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;

import java.util.List;

/**
 * Created by gusef on 20.06.2017.
 */
@Service
public class RandomUserService {
    @Autowired
    RestTemplate template;

    private static final String API_PATH = "https://randomuser.me/api";

    public List<User> getUsers(int number){
        ServerAnswer serverAnswer = template.getForObject(API_PATH,ServerAnswer.class);
        return serverAnswer.getResults();
    }

}
