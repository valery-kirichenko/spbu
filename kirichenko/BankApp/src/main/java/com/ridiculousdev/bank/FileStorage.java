package com.ridiculousdev.bank;

import org.springframework.stereotype.Service;

import javax.xml.crypto.Data;
import java.net.URL;
import java.util.List;


@Service
public class FileStorage implements DataStorage {

    List<Client> clients;
    List<Credit> credits;

    public void readData() {
        URL clientsUrl = Thread.currentThread().getContextClassLoader().getResource("clients.omg");
        URL creditsUrl = Thread.currentThread().getContextClassLoader().getResource("credits.omg");
        DataReader reader = new DataReader();
        clients = reader.readClients(clientsUrl);
        credits = reader.readCredits(creditsUrl);
        DataProcessor processor = new DataProcessor(clients, credits);
        processor.removeDuplicates();
        processor.replaceLetters();
        processor.assignCredits();
    }

    public List<Client> getClients() {
        return clients;
    }

    public List<Credit> getCredits() {
        return credits;
    }

    public void addClient(Client client) {
        clients.add(client);
    }

    public void addCredit(Credit credit) {
        credits.add(credit);
    }
}
