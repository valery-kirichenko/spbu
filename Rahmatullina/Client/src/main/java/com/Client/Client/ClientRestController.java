package com.Client.Client;


public interface ClientRestController {
    void saveNewClient(Clients newClient);
    void deleteClient(Integer client_id);
}
