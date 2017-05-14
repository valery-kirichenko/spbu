package com.database;

import com.database.Cells.Client;
import java.util.List;

public interface ClientsController {
    public void saveNewClient(Client toCreate);
    public List<Client> getAllClients();
    public void deleteClient(Long customerId);
    public Client getById(Long customerId);
}
