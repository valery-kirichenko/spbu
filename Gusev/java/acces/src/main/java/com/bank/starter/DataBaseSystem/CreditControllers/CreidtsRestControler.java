package com.bank.starter.DataBaseSystem.CreditControllers;

import com.bank.starter.models.Credit;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

/**
 * Created by gusef on 18.06.2017.
 */
@RestController("/credit/")
public class CreidtsRestControler {
    @Autowired
    private DBCreditControler controller;

    @RequestMapping(value = "/credit/", method = RequestMethod.POST)
    public void createCredit(@RequestBody Credit credit) {
        controller.addNewCredit(credit);
    }

    @RequestMapping(value = "/credit/", method = RequestMethod.GET)
    public List<Credit> getAll() {
        return controller.getAllCredits();
    }

    @RequestMapping(value = "/credit/{id}", method = RequestMethod.DELETE)
    public void delete(@PathVariable(name = "id") Integer creditID) {
        controller.deletCredit(creditID);
    }

    @RequestMapping(value = "/credit/{id}", method = RequestMethod.GET)
    public Credit getById(@PathVariable(name = "id") Integer ID) {
        return controller.getCredit(ID);
    }
}
