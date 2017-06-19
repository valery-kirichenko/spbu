package com.banksys.java;

import com.banksys.java.models.Client;
import com.banksys.java.models.Credit;

import java.util.ArrayList;

import static com.banksys.java.Algo.getInt;

public class ClientHelper {
    public static ArrayList<Client> makeLinks(ArrayList<Client> clients, ArrayList<Credit> credits) {
        for (Client client : clients) {
            ArrayList<Credit> nCredits = new ArrayList<>();
            for (Credit credit : credits) {
                if (credit.id.equals(client.getId())) {
                    nCredits.add(credit);
                }
            }

            client.setCredits(nCredits);
        }

        return clients;
    }

    public static int getCurrentId(ArrayList<Client> clients){
        int max = -1;
        for(Client client : clients){
            max = Math.max(max, Integer.parseInt(client.getId()));
        }

        return max;
    }

    public static ArrayList<Client> clientSearch(ArrayList<Client> clients, String key){
        if(key.trim().isEmpty()) return clients;

        ArrayList<Client> newClients = new ArrayList<>();
        for(Client client : clients){
            if(client.getId().contains(key) || client.getName().contains(key)
                    || client.getSurname().contains(key) || client.getMiddlename().contains(key)
                    || client.getPassport().contains(key) || client.getPhone().contains(key)
                    || client.getDate().toString().contains(key) || client.getOldPassport().contains(key)){
                newClients.add(client);
            }
        }

        return newClients;
    }
}
