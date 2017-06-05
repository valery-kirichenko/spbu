package com.ridiculousdev.bank;

import java.util.List;

public interface DataStorage {
    void readData();

    List<Client> getClients();

    List<Credit> getCredits();

    void addClient(Client client);

    void addCredit(Credit credit);
}
