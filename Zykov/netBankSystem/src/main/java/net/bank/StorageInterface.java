package net.bank;

import org.springframework.stereotype.Service;

import java.io.FileOutputStream;
import java.io.IOException;
import java.util.List;

@Service
public interface StorageInterface {
    void mergeDuplicate();
    void DataToText(FileOutputStream outClients, FileOutputStream outCredits) throws IOException;
    void correctClientName();
    String getNameFromId(int id);
    Client getClient(int id);
    void setClientList(List<Client> clientList);
    void setCreditList(List<Credit> creditList);
    List<Client> getClientList();
    List<Credit> getCreditList();
}
