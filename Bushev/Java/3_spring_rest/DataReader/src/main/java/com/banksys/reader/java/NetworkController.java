package com.banksys.reader.java;

import com.banksys.java.models.Client;
import com.banksys.java.models.Credit;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.client.RestTemplate;

import java.util.ArrayList;

@RestController
public class NetworkController {
    ArrayList<Client> clients;
    ArrayList<Credit> credits;

    @Autowired
    DefaultReader reader;

    @RequestMapping("/")
    private String dataInsertion() {
        reader.readFromFiles(this);

        RestTemplate template = new RestTemplate();
        String answerClients = template.postForObject("http://localhost:8080/clients", clients, String.class);
        String answerCredits = template.postForObject("http://localhost:8080/credits", credits, String.class);

        return "Default data is sent, clients and credits are inserted.<br>Clients answer: "
                + answerClients + ".<br>Credits answer: " + answerCredits + ".";
    }

    public void setClients(ArrayList<Client> clients) {
        this.clients = clients;
    }

    public void setCredits(ArrayList<Credit> credits) {
        this.credits = credits;
    }
}
