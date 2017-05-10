package com.example;

import java.util.ArrayList;

/**
 * Created by Lenovo on 02.05.2017.
 */
public interface DataReaderInterface {
    public ArrayList<Clients> readTheClients();
    public void readTheCredits();
    public ArrayList<newBase> createNewBase();
    public void checkNewBase(ArrayList<newBase> BankBase);
}
