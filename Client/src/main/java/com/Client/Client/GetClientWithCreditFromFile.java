package com.Client.Client;

import java.io.FileNotFoundException;
import java.util.List;


public interface GetClientWithCreditFromFile {
    List<Clients> getClient() throws FileNotFoundException;

    List<Credits> getCredit() throws FileNotFoundException;

    void getMerge(List<Clients> listClient, List<Credits> listCredit);

    String getNameFromID(Integer ID, List<Clients> clients);

    void getReplace();

    void mainMerge() throws FileNotFoundException;

    List<Clients> getClientsList();
    List<Credits> getCreditsList();
}
