package com.bank.starter.MyDataBase;

import com.bank.starter.models.Client;
import com.bank.starter.models.Credit;

import java.io.IOException;
import java.util.ArrayList;

/**
 * Created by gusef on 18.06.2017.
 */
public interface SingletonDataBase {
    void readCreditsFromFile(String name)throws IOException;
    void tryMerge(Client locClient);
    int numberOfCredits();
    void readClientsFromFile(String name) throws IOException;
    ArrayList<Credit> getListOfCredits(Client locClient);
}
