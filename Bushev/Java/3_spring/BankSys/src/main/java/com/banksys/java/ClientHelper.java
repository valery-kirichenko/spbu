package com.banksys.java;

import java.io.IOException;
import java.lang.reflect.Array;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Date;

import static com.banksys.java.Algo.getInt;

public class ClientHelper {
    public static void showOverdue(ArrayList<Client> clients, boolean showUsers){
        int counter = 0;
        for(Client client : clients){
            for(Credit credit : client.credits){
                if(credit.isOverdue().equals("YES")){
                    counter++;
                    if(showUsers) break;
                }
            }
        }

        System.out.println("Total unpayed " + (showUsers ? "users" : "credits") + " >>> " + counter);
    }

    public static void showDebt(ArrayList<Client> clients, int id){
        Client currentClient = null;
        for(Client client : clients){
            if(id == Integer.parseInt(getInt(client.getId()))){
                currentClient = client;
                break;
            }
        }

        if(currentClient == null){
            System.out.println("Client with this id was not found!");
            return;
        }

        double debt = 0;
        for(Credit credit : currentClient.credits){
            if(credit.isOverdue().equals("YES")){
                debt += Double.parseDouble(credit.needed) - Double.parseDouble(credit.payed);
            }
        }

        System.out.println("Client #" + id + ": " + debt);
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
