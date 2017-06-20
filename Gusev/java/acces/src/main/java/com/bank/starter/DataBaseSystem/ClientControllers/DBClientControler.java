package com.bank.starter.DataBaseSystem.ClientControllers;

import com.bank.starter.models.Client;

import java.util.List;

/**
 * Created by gusef on 18.06.2017.
 */
public interface DBClientControler {
    void addNewClient(Client locCLient);
    void deleteClient(Integer id);
    List<Client> getAllClients();
    Client getClient(Integer id);
    void upadateClient(Client locClient);
    boolean Contains(Client locClinet);
}
