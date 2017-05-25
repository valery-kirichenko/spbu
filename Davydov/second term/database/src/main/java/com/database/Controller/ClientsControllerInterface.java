package com.database.Controller;

import com.database.Model.ClientRecord;

import java.util.Collection;

/**
 * Created by Дмитрий on 12.05.2017.
 */

public interface ClientsControllerInterface
{
    void saveNewClient(ClientRecord clientRecord);
    Collection<ClientRecord> getAllClients();
    ClientRecord getByID(Long Id);
    void deleteClient(Long Id);
}
