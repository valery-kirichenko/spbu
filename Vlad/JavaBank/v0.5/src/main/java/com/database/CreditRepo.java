package com.database;

import com.database.Cells.Credit;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import java.util.List;

@RestController("/credit")
public class CreditRepo {

    @Autowired
    CreditsController controller;

    @RequestMapping(value = "/credit/", method = RequestMethod.POST)
    public void createCredit(@RequestBody Credit credit) {
        controller.saveNewCredit(credit);
    }

    @RequestMapping(value = "/credit/", method = RequestMethod.GET)
    public List<Credit> getAll() {
        return controller.getAllCredits();
    }

    @RequestMapping(value = "/credit/{id}", method = RequestMethod.DELETE)
    public void delete(@PathVariable(name = "id") Long creditId) {
        controller.deleteCredit(creditId);
    }

    @RequestMapping(value = "/credit/{id}", method = RequestMethod.GET)
    public Credit getById(@PathVariable(name = "id") Long id) {
        return controller.getById(id);
    }
}
