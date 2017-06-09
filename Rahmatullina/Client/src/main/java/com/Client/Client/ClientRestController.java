package com.Client.Client;

import java.util.List;

/**
 * Created by Я on 05.05.2017.
 */
public interface ClientRestController {
    void saveNewClient(Clients newClient);
    void deleteClient(int client_id);
}
