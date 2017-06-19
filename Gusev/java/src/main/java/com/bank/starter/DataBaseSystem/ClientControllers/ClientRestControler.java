package com.bank.starter.DataBaseSystem.ClientControllers;

import com.bank.starter.models.Client;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;

/**
 * Created by gusef on 19.06.2017.
 */
@RestController("/client/")
public class ClientRestControler {
    @Autowired
    private DBClientControler controller;

    @RequestMapping(value = "/client/", method = RequestMethod.POST)
    public void createClient(@RequestBody Client client) {
        controller.addNewClient(client);
    }

    @RequestMapping(value = "/client/", method = RequestMethod.GET)
    public List<Client> getAll() {
        return controller.getAllClients();
    }

    @RequestMapping(value = "/client/{id}", method = RequestMethod.DELETE)
    public void delete(@PathVariable(name = "id") Integer clientID) {
        controller.deleteClient(clientID);
    }

    @RequestMapping(value = "/client/{id}", method = RequestMethod.GET)
    public Client getById(@PathVariable(name = "id") Integer ID) {
        return controller.egtClient(ID);
    }
}
