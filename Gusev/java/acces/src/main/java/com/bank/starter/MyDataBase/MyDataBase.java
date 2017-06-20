package com.bank.starter.MyDataBase;

import com.bank.starter.Curency.Currency;
import com.bank.starter.models.Client;
import com.bank.starter.models.Credit;

import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

/**
 * Created by gusef on 18.06.2017.
 */
public interface MyDataBase {
    void readCreditsFromFile(String name)throws IOException;
    void tryMerge(Client locClient);
    int numberOfCredits();
    void readClientsFromFile(String name) throws IOException;
    ArrayList<Credit> getListOfCredits(Client locClient);
    ArrayList<Client> getListOfClients();
    void setListOfClients(ArrayList<Client> listOfClients);
    HashMap<Integer, ArrayList<Credit>> getMapOfCredits();
    void setMapOfCredits(HashMap<Integer, ArrayList<Credit>> mapOfCredits);
    int getFreeId();
    void insertFromFile();
    void setCredits(ArrayList<Credit> listOfCredits);
    ArrayList<Credit> getListOfCreditsWithChangedValues(Currency newCurrency, Integer Id);
    double allDebt(Client cl);
    ArrayList<Credit> debtCredits(Client cl);
    ArrayList<Credit> allNotPaidCredits();
}
