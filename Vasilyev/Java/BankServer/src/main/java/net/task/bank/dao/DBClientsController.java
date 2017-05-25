package net.task.bank.dao;

import net.task.bank.models.Client;

import java.util.List;

public interface DBClientsController {
    void saveNewClient(Client toCreate);

    List<Client> getAllClients();

    void deleteClient(int clientID);

    Client getByID(int clientID);

    void updateClient(Client toUpdate);

    boolean isExisted(Client client);
}