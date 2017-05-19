package com.database;

import com.database.Cells.Client;
import java.util.List;

public interface RESTClientsController {
    void saveNewClient(Client toCreate);
    List<Client> getAllClients();
    void deleteClient(Long customerId);
    Client getById(Long customerId);
    Integer getMaxID();
}
