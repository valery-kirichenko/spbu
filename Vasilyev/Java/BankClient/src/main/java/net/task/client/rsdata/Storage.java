package net.task.client.rsdata;

import net.task.client.models.Client;
import net.task.client.models.Credit;

import java.io.FileOutputStream;
import java.io.IOException;
import java.util.List;


public interface Storage {
    void mergeDuplicate();

    void outDataToTxt(FileOutputStream outClients, FileOutputStream outCredits) throws IOException;

    void changeClientInfo();

    String getNameFromId(int id);

    Client getClient(int id);

    void setClientList(List<Client> clientList);

    void setCreditList(List<Credit> creditList);

    List<Client> getClientList();

    List<Credit> getCreditList();
}
