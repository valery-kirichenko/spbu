package net.task.client.dao;

import net.task.client.models.Client;

public interface ClientsController {
    void createClient(Client client);

    void deleteClient(int id);

    int requestMaxID();
}
