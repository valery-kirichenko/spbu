package com.Client.Client;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.client.RestTemplate;


@Controller
public class ClientRestControllerImpl implements ClientRestController {
    private String urlClients = "http://localhost:8080/client/";

    @Autowired
    RestTemplate restTemplate;

    @Override
    public void saveNewClient(Clients newClient) {
        System.out.println(newClient.getClientId());
        restTemplate.postForEntity(urlClients, newClient, Clients.class);
    }

    @Override
    public void deleteClient(Integer client_id) {
        restTemplate.delete(urlClients + client_id);
    }

}
