package net.bank;

import org.springframework.stereotype.Service;

import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.time.Instant;

/**
 * Created by st056673 on 17.03.2017.
 */
@Service
public class DataStorage implements StorageInterface {
    public static List<Client> clients;
    public static List<Credit> credits;
    public List<Credit> nullCreditList = new ArrayList<>();
    public static int countNull = 0;

    DataStorage(){
    }

    DataStorage(List<Client> clientsList, List<Credit> creditsList) {
        clients = clientsList;
        credits = creditsList;
    }

    @Override
    public void mergeDuplicate() {
        int countDups = 0, countMistakes = 0;

        for (Client client1 : clients) {
            for (Client client2 : clients) {
                if (!client1.equals(client2) && !client1.isDeleted && !client2.isDeleted) {
                    if (client1.getIdNumber() == client2.getIdNumber()) {
                        for (Credit credit2 : credits) {
                            if (credit2.getClientID() == client2.getID()) {
                                credit2.setClientID(client1.getID());
                            }
                        }
                        countDups++;
                        client2.isDeleted = true;
                        break;
                    } else if (client1.getOldIdNumber() == client2.getIdNumber()) {
                        for (Credit credit2 : credits) {
                            if (credit2.getClientID() == client2.getID()) {
                                credit2.setClientID(client1.getID());
                            }
                        }
                        countMistakes++;
                        client2.isDeleted = true;
                        break;
                    }
                }
            }
        }
        System.out.println("Number of duplicates: " + countDups + " real duplicates + " + countMistakes + " passport mistakes.");
        List<Client> newClients = new ArrayList<>();
        for (Client client : clients)
            if (!client.isDeleted)
                newClients.add(client);
        clients = newClients;

        Instant now = Instant.now();
        int count = 0;

        List<Credit> newCredits = new ArrayList<>();
        for (Credit credit : credits) {
            if (getNameFromId(credit.getClientID()) != null)
                newCredits.add(credit);
            if (now.isAfter(credit.getClosureDate().toInstant()) &&
                    (credit.getClientPaid() < credit.getClientHasToPay())) {
                if (getNameFromId(credit.getClientID()) == null) {
                    nullCreditList.add(credit);
                    count++;
                    System.out.println("A new unpaid credit with null id has been found! (" + count + ")");
                }
            }
        }
        credits = newCredits;

        for (Client client : clients)
            for (Credit credit : credits)
                if (credit.getClientID() == client.getID())
                    client.addCredit(credit);
    }

    @Override
    public void correctClientName() {
        for (Client client : clients) {
            if (client.getFirstName().contains("ё"))
                client.setFirstName((client.getFirstName().replace('ё', 'е')));
            if (client.getMiddleName().contains("ё"))
                client.setMiddleName(client.getMiddleName().replace('ё', 'е'));
            if (client.getLastName().contains("ё"))
                client.setLastName(client.getLastName().replace('ё', 'е'));
        }
    }

    @Override
    public String getNameFromId(int id) {
        String result = null;
        boolean isFound = false;
        for (Client client : clients)
            if (id == client.getID()) {
                result = client.getFirstName() + " " + client.getMiddleName() + " " + client.getLastName();
                isFound = true;
            }
        if (isFound)
            countNull++;
        return result;
    }

    @Override
    public void DataToText(FileOutputStream clientOut, FileOutputStream creditOut) throws IOException {
        for (Client client : clients)
            clientOut.write((client.toString() + "\n").getBytes());

        for (Credit credit : credits)
            creditOut.write((credit.toString() + "\n").getBytes());
    }

    public String getNameFromID(int id){
        for(Client client : clients)
            if (id == client.getID())
                return (client.getFirstName() + " " + client.getMiddleName() + " " + client.getLastName());
        countNull++;
        return null;
    }

    @Override
    public Client getClient(int id) {
        Client Result = new Client();
        for (Client client : clients)
            if (id == client.getID())
                Result = client;
        return Result;
    }

    @Override
    public void setClientList(List<Client> clientList) {
        clients = clientList;
    }

    @Override
    public void setCreditList(List<Credit> creditList) {
        credits = creditList;
    }

    @Override
    public List<Client> getClientList() {
        return clients;
    }
    @Override
    public List<Credit> getCreditList() {
        return credits;
    }
}