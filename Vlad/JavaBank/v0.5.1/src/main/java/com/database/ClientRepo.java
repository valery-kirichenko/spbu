package com.database;

import com.database.Cells.Client;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;
import java.util.List;

@RestController("/client")
public class ClientRepo {

    @Autowired
    ClientsController controller;

    @RequestMapping(value = "/client/", method = RequestMethod.POST)
    public void createCustomer(@RequestBody Client client) {
        controller.saveNewClient(client);
    }

    @RequestMapping(value = "/client/", method = RequestMethod.GET)
    public List<Client> getAll() {
        return controller.getAllClients();
    }

    @RequestMapping(value = "/client/{id}", method = RequestMethod.DELETE)
    public void delete(@PathVariable(name = "id") Long clientId) {
        controller.deleteClient(clientId);
    }

    @RequestMapping(value = "/client/{id}", method = RequestMethod.GET)
    public Client getById(@PathVariable(name = "id") Long id) {
        return controller.getById(id);
    }
}