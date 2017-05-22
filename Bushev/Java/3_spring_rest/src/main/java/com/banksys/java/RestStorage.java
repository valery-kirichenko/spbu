package com.banksys.java;

import com.banksys.java.controllers.DatabaseHandler;
import com.banksys.java.interfaces.Storage;
import com.banksys.java.models.Client;
import com.banksys.java.models.Credit;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.ArrayList;

@Service
public class RestStorage implements Storage {
    private ArrayList<Client> clients;
    private ArrayList<Credit> credits;

    @Override
    public ArrayList<Client> getClients() {
        return clients;
    }

    @Override
    public ArrayList<Credit> getCredits() {
        return credits;
    }

    @Autowired
    DatabaseHandler database;

    public void init() {
        clients = database.selectClients();
        credits = database.selectCredits();

        ClientHelper.makeLinks(clients, credits);   // client[i].credits = someCredits
        System.out.println("Table data is loaded");
    }

    @Override
    public void rewriteData(){
        database.rewriteData(clients, credits);
    }
}
