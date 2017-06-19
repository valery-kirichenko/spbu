package com.banksys.java.controllers;


import com.banksys.java.models.Client;
import com.banksys.java.models.Credit;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.Arrays;

@RestController
public class CreditController {
    @Autowired
    private DatabaseHandler database;

    @RequestMapping(value = "/credit", method = RequestMethod.POST)
    public String insertCredit(@RequestBody Credit credit) {
        database.insertCredits(new ArrayList<>(Arrays.asList(credit)));
        return "OK";
    }

    @RequestMapping(value = "/credits", method = RequestMethod.POST)
    public String insertCredits(@RequestBody ArrayList<Credit> credits){
        database.insertCredits(credits);
        return "OK";
    }

    @RequestMapping(value = "/credit/{id}", method = RequestMethod.DELETE)
    public String deleteCredit(@PathVariable(name = "id") int id) {
        database.deleteRecord(false, id);
        return "OK";
    }

    @RequestMapping(value = "/credit/{id}", method = RequestMethod.GET)
    public Credit getCredit(@PathVariable(name = "id") int id) {
        return database.selectCreditById(id);
    }

    @RequestMapping(value = "/credits", method = RequestMethod.GET)
    public ArrayList<Credit> getCredits() {
        return database.selectCredits();
    }
}
