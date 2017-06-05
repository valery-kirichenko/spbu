package com.ridiculousdev.bank;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Service;

import java.util.List;

@Service
public class DatabaseStorage implements DataStorage {
    List<Client> clients;
    List<Credit> credits;

    @Autowired
    JdbcTemplate template;

    public void readData() {
        clients = template.query("SELECT * FROM clients", new ClientRowMapper());
        credits = template.query("SELECT * FROM credits", new CreditRowMapper());
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
