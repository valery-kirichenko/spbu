package com.Client.Client;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.client.RestTemplate;

/**
 * Created by Я on 05.05.2017.
 */
@Controller
public class ClientRestControllerImpl implements ClientRestController {
    private String urlClients = "http://localhost:8080/client/";

    @Autowired
    RestTemplate restTemplate;

    @Override
    public void saveNewClient(Clients newClient) {
        restTemplate.postForEntity(urlClients, newClient, Clients.class);

    }

    @Override
    public void deleteClient(int client_id) {
        restTemplate.delete(urlClients + client_id);

    }

}
