package com.banksys.java.controllers;

import com.banksys.java.models.Client;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.ArrayList;
import java.util.Arrays;

@RestController
public class ClientController {
    @Autowired
    private DatabaseHandler database;

    @RequestMapping(value = "/client", method = RequestMethod.POST)
    public String insertClient(@RequestBody Client client) {
        database.insertClients(new ArrayList<>(Arrays.asList(client)));
        return "OK";
    }

    @RequestMapping(value = "/clients", method = RequestMethod.POST)
    public String insertClients(@RequestBody ArrayList<Client> clients){
        database.insertClients(clients);
        return "OK";
    }

    @RequestMapping(value = "/client/{id}", method = RequestMethod.DELETE)
    public String deleteClient(@PathVariable(name = "id") int id) {
        database.deleteRecord(true, id);
        return "OK";
    }

    @RequestMapping(value = "/client/{id}", method = RequestMethod.GET)
    public Client getClient(@PathVariable(name = "id") int id) {
        return database.selectClientById(id);
    }

    @RequestMapping(value = "/clients", method = RequestMethod.GET)
    public ArrayList<Client> getClients() {
        return database.selectClients();
    }
}
