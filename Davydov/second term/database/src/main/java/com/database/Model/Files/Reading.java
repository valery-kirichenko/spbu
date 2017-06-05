package com.database.Model.Files;

import com.database.Model.ClientRecord;
import com.database.Model.CreditRecord;

import java.io.FileInputStream;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import java.util.Collection;

/**
 * Created by Дмитрий on 25.05.2017.
 */
public class Reading
{
    public static ArrayList <ClientRecord> readClients()
    {
        try
        {
            FileInputStream fis = new FileInputStream
                    ("src\\main\\java\\com\\database\\Model\\Files\\clients.txt");
            ObjectInputStream oin = new ObjectInputStream(fis);
            try {
                ArrayList<ClientRecord> collection =
                        (ArrayList<ClientRecord>) oin.readObject();
                return collection;
            }catch (ClassNotFoundException classNotFoundException) {}
        }catch (IOException ioException)
        {System.out.print("Reading file with clients failed.\n");}
        return null;
    }

    public static ArrayList <CreditRecord> readCredits()
    {
        try
        {
            FileInputStream fis = new FileInputStream
                    ("src\\main\\java\\com\\database\\Model\\Files\\credits.txt");
            ObjectInputStream oin = new ObjectInputStream(fis);
            try {
                ArrayList<CreditRecord> collection =
                        (ArrayList<CreditRecord>) oin.readObject();
                return collection;
            }catch (ClassNotFoundException classNotFoundException) {}
        }catch (IOException ioException)
        {System.out.print("Reading file with credits failed.\n");}
        return null;
    }
}
