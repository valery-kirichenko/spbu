package com.banksys.java.interfaces;

import com.banksys.java.models.Client;
import com.banksys.java.models.Credit;

import java.util.ArrayList;

public interface Storage {
    ArrayList<Client> getClients();
    ArrayList<Credit> getCredits();

    void rewriteData();
}
