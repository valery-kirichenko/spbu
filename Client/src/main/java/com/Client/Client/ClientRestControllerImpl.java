package com.Client.Client;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.client.RestTemplate;


@Controller
public class ClientRestControllerImpl implements ClientRestController {
    private String urlClients = "http://localhost:8080/client/";

    @Autowired
    private RestTemplate restTemplate;

    @Override
    public void saveNewClient(Clients newClient) {
        restTemplate.postForEntity(urlClients, newClient, Clients.class);
    }
}
