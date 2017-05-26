package net.task.bank.dao;

import net.task.bank.models.Client;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.*;

import java.util.List;


@RestController("/client/")
public class ClientsRestController {

    @Autowired
    private DBClientsController controller;

    @RequestMapping(value = "/client/", method = RequestMethod.POST)
    public void createClient(@RequestBody Client client) {
        controller.saveNewClient(client);
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
        return controller.getByID(ID);
    }
}