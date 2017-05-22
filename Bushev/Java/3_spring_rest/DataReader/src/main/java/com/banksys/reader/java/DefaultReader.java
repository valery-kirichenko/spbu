package com.banksys.reader.java;

import com.banksys.java.models.Client;
import com.banksys.java.models.Credit;
import org.springframework.stereotype.Service;

import java.io.File;
import java.io.FileNotFoundException;
import java.net.URL;
import java.net.URLDecoder;
import java.util.ArrayList;
import java.util.Scanner;

import static com.banksys.java.ClientHelper.makeLinks;

@Service
public class DefaultReader {
    public static void readFromFiles(NetworkController storage) {
        URL urlClients = Thread.currentThread().getContextClassLoader().getResource("clients.omg");
        URL urlCredits = Thread.currentThread().getContextClassLoader().getResource("credits.omg");

        try {
            urlClients = new URL(URLDecoder.decode(urlClients.toString(), "utf-8"));
            urlCredits = new URL(URLDecoder.decode(urlCredits.toString(), "utf-8"));
        } catch (Exception ex) {
            ex.printStackTrace();
        }

        File clientFile = new File(urlClients.getPath());
        File creditFile = new File(urlCredits.getPath());

        ArrayList<Client> clients = new ArrayList<>();
        ArrayList<Credit> credits = new ArrayList<>();

        try {
            Scanner scan = new Scanner(clientFile);
            while (scan.hasNext()) {
                clients.add(new Client(scan.next().split("->>>>|---|\\\\\\\\|~~~~|==|___")));
            }
            scan.close();

            scan = new Scanner(creditFile).useDelimiter("&");
            while (scan.hasNext()) {
                credits.add(new Credit(scan.next().split("\\||%,|,|\\^|___")));
            }
            scan.close();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        clients = makeLinks(clients, credits);
        clients = mergeDuplicates(clients);
        credits = clearUnused(clients, credits);

        storage.setClients(clients);
        storage.setCredits(credits);
    }

    private static ArrayList<Client> mergeDuplicates(ArrayList<Client> clients) {
        for (int i = 0; i < clients.size(); i++) {
            for (int j = i + 1; j < clients.size(); j++) {
                if (clients.get(i).getId().equals(clients.get(j).getId())
                        || clients.get(i).getPassport().equals(clients.get(j).getPassport())
                        || (!clients.get(i).getOldPassport().isEmpty() &&
                        clients.get(i).getOldPassport().equals(clients.get(j).getPassport())
                        || clients.get(i).getPassport().equals(clients.get(j).getOldPassport()))) {

                    // merge records
                    for (Credit credit : clients.get(j).getCredits()){
                        clients.get(i).getCredits().add(credit);
                        credit.id = clients.get(i).getId();
                    }

                    clients.remove(j);
                    j--;
                }
            }
        }

        return clients;
    }

    private static ArrayList<Credit> clearUnused(ArrayList<Client> clients, ArrayList<Credit> credits){
        boolean used;
        for(int i = 0; i < credits.size(); i++){
            used = false;

            for (Client client : clients){
                for(Credit innerCredit : client.getCredits()){
                    if(credits.get(i) == innerCredit){
                        used = true;
                        break;
                    }
                }
            }

            if(!used){
                credits.remove(i);
                i--;
            }
        }

        return credits;
    }
}
