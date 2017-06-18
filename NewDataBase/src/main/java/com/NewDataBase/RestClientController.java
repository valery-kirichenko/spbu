package com.NewDataBase;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;


@RestController("/client/")
public class RestClientController {
    @Autowired
    private ClientController clientController;

    @RequestMapping(value = "/client/", method = RequestMethod.POST)
    public void createClient(@RequestBody Clients client) {
        clientController.saveNewClient(client);
    }

    @RequestMapping(value = "/client/", method = RequestMethod.GET)
    public List<Clients> getAll() {
        return clientController.getAllClients();
    }

    @RequestMapping(value = "/client/{id}", method = RequestMethod.DELETE)
    public void delete(@PathVariable(name = "id") Integer clientID) {
        clientController.deleteClient(clientID);
    }

    @RequestMapping(value = "/client/{id}", method = RequestMethod.GET)
    public Clients getById(@PathVariable(name = "id") Integer ID) {
        return clientController.getByID(ID);
    }
}
