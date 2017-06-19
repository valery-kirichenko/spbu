package com.Client.Client;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.client.RestTemplate;


@Controller
public class CreditRestControllerImpl implements CreditRestController {
    private String urlCredits = "http://localhost:8080/credit/";

    @Autowired
    private RestTemplate restTemplate;

    @Override
    public void saveNewCredit(Credits toCreate) {
        restTemplate.postForEntity(urlCredits, toCreate, Credits.class);
    }

}

