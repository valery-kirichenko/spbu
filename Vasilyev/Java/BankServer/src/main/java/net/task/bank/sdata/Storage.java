package net.task.bank.sdata;

import net.task.bank.converter.Currency;
import net.task.bank.models.Client;
import net.task.bank.models.Credit;

import java.io.FileOutputStream;
import java.io.IOException;
import java.util.List;


public interface Storage {
    void mergeDuplicate();

    void outDataToTxt(FileOutputStream outClients, FileOutputStream outCredits) throws IOException;

    void changeClientInfo();

    String getNameFromId(Integer ID);

    Client getClient(Integer ID);

    void setClientList(List<Client> clientList);

    void setCreditList(List<Credit> creditList);

    List<Client> getClientList();

    List<Credit> getCreditList();

    List<Credit> creditUpdate(Currency newCurrency, Integer ID);
}
