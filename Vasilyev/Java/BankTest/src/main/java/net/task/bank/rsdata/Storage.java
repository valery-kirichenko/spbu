package net.task.bank.rsdata;

import net.task.bank.models.Client;
import net.task.bank.models.Credit;

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
