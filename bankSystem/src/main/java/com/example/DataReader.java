package com.example;

import org.springframework.stereotype.Service;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by Lenovo on 02.05.2017.
 */
@Service
public class DataReader implements DataReaderInterface{
    public ArrayList<Clients> readTheClients()
    {
        File clients = new File("C:/Users/Lenovo/IdeaProjects/BankBigData/src/resources/clients.omg");
        Scanner scanClient = null;
        try {
            scanClient = new Scanner(clients);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        ArrayList<Clients> clientsArray = new ArrayList<>();
        while (scanClient.hasNext()) {
            String line = scanClient.nextLine();
            line = line.replace('ё', 'e');
            Clients Another = new Clients();
            Another.setAll(line);
            clientsArray.add(Another);
        }
        return clientsArray;
    };
    public void readTheCredits()
    {
        File credits = new File("C:/Users/Lenovo/IdeaProjects/BankBigData/src/resources/credits.omg");
        Scanner scanCredit = null;
        try {
            scanCredit = new Scanner(credits);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        String line = scanCredit.nextLine();
        String[] lineArray = line.split("Credit\\{");
        for (int i = 1; i < lineArray.length; i++) {
            Credits Another = new Credits();
            lineArray[i] = lineArray[i].replace('ё', 'e');
            Another.setOne(lineArray[i]);
        }
    };
    public ArrayList<newBase> createNewBase()
    {
        this.readTheCredits();
        ArrayList<Clients> clientsArray = this.readTheClients();
        ArrayList<newBase> BankBase = new ArrayList<>();
        for (int i = 0; i < clientsArray.size(); i++) {
            newBase Another = new newBase();
            Another.setAll(clientsArray.get(i));
            BankBase.add(Another);
        }
        checkNewBase(BankBase);
        for(int i = 0; i<BankBase.size(); i++)
        {
            BankBase.get(i).setNewId(i);
        }
        return BankBase;
    }
    public void checkNewBase(ArrayList<newBase> BankBase)
    {
        for (int i=0; i<BankBase.size();i++)
        {
            for (int j=i+1; j<BankBase.size();j++)
            {
                if (BankBase.get(i).thisClient.getPas()==BankBase.get(j).thisClient.getPas())
                {
                    for (int g=0; g<BankBase.get(j).thisCredit.size();g++)
                    {
                        BankBase.get(j).thisCredit.get(g).setId(BankBase.get(i).thisClient.getId());
                    }
                    BankBase.get(i).addCredits(BankBase.get(j).thisCredit);
                    BankBase.remove(j);
                }
                else
                if (BankBase.get(i).thisClient.firstPas==BankBase.get(j).thisClient.pas||BankBase.get(i).thisClient.pas==BankBase.get(j).thisClient.firstPas)
                {
                    for (int g=0; g<BankBase.get(j).thisCredit.size();g++)
                    {
                        BankBase.get(j).thisCredit.get(g).setId(BankBase.get(i).thisClient.getId());
                    }
                    BankBase.get(i).addCredits(BankBase.get(j).thisCredit);
                    BankBase.remove(j);
                }
            }
        }
    }
}
