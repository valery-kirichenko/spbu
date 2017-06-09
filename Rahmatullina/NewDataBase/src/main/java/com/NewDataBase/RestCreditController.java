package com.NewDataBase;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;


@RestController("/credit/")
public class RestCreditController {
    @Autowired
    private CreditController creditController;

    @RequestMapping(value = "/credit/", method = RequestMethod.POST)
    public void createCredit(@RequestBody Credits credit) {
        creditController.saveNewCredit(credit);
    }

    @RequestMapping(value = "/credit/", method = RequestMethod.GET)
    List<Credits> getAll() {
        return creditController.getAllCredits();
    }

    @RequestMapping(value = "/credit/{id}", method = RequestMethod.DELETE)
    void delete(@PathVariable(name = "id") Integer creditID) {
        creditController.deleteCredit(creditID);
    }


    @RequestMapping(value = "/credit/{id}", method = RequestMethod.GET)
    List<Credits> getByClientId(@PathVariable(name = "id") Integer ID) {
        return creditController.getByClientID(ID);
    }
}
