package net.task.client.dao;

import net.task.client.models.Client;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.client.RestTemplate;


@Controller
public class RestClientsController implements ClientsController {

    private String urlClients = "http://localhost:8080/client/";

    @Autowired
    private RestTemplate restTemplate;

    @Override
    public void createClient(Client client) {
        restTemplate.postForEntity(urlClients, client, Client.class);
    }

    @Override
    public void deleteClient(Integer ID) {
        restTemplate.delete(urlClients + ID);
    }
}
