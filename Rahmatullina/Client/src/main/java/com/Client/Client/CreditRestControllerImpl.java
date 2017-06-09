package com.Client.Client;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.client.RestTemplate;

/**
 * Created by Я on 06.05.2017.
 */
@Controller
 class CreditRestControllerImpl implements CreditRestController {
    private String urlCredits = "http://localhost:8080/credit/";
   @Autowired
    RestTemplate restTemplate;


    @Override
    public void saveNewCredit(Credits toCreate) {
        restTemplate.postForEntity(urlCredits,toCreate,Credits.class);

    }

    @Override
    public void deleteCredit(String creditID) {
        restTemplate.delete(urlCredits+creditID);
    }
}
