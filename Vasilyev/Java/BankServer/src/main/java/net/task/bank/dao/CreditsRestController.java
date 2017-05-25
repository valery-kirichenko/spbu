package net.task.bank.dao;

import net.task.bank.models.Credit;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;


@RestController("/credit/")
public class CreditsRestController {

    @Autowired
    private DBCreditsController controller;

    @RequestMapping(value = "/credit/", method = RequestMethod.POST)
    public void createCredit(@RequestBody Credit credit) {
        controller.saveNewCredit(credit);
    }

    @RequestMapping(value = "/credit/", method = RequestMethod.GET)
    public List<Credit> getAll() {
        return controller.getAllCredits();
    }

    @RequestMapping(value = "/credit/{id}", method = RequestMethod.DELETE)
    public void delete(@PathVariable(name = "id") int creditID) {
        controller.deleteCredit(creditID);
    }

    @RequestMapping(value = "/credit/{id}", method = RequestMethod.GET)
    public Credit getById(@PathVariable(name = "id") int ID) {
        return controller.getByID(ID);
    }
}
