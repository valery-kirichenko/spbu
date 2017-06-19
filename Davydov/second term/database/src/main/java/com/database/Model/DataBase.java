package com.database.Model;

import com.database.Model.Files.Reading;

import java.util.ArrayList;
import java.util.Collection;
import java.util.LinkedList;

/**
 * Created by Дмитрий on 10.03.2017.
 */

public class DataBase
{
    private ArrayList <ClientRecord> clients = new ArrayList<>();
    private ArrayList <CreditRecord> credits = new ArrayList<>();

    public DataBase()
    {
        this.start();
    }

    private void start()
    {
        //ClientsReader clientsReader = new ClientsReader();
        //CreditsReader creditsReader = new CreditsReader();

        Reading reading = new Reading();

        clients = reading.readClients();
        credits = reading.readCredits();

        setClientsStatus(clients, credits);
        eraseEqual(clients);
        eraseWithChangedPassport(clients);

        for (ClientRecord clientRecord : clients)
        {
            clientRecord.replaceE();
        }
    }

    public Collection <ClientRecord> getClientsRecords()
    {
        return clients;
    }

    public Collection <CreditRecord> getCreditsRecords()
    {
        return credits;
    }


    private static void setClientsStatus(Collection<ClientRecord> clients,
                                            Collection<CreditRecord> credits)
    {
        LinkedList <CreditRecord> creditRecords = new LinkedList<>();

        for (ClientRecord clientRecord : clients)
        {
            for (CreditRecord creditRecord : credits)
            {
                if (creditRecord.getId().equals(clientRecord.getId()))
                {
                    creditRecords.addLast(creditRecord);
                }
            }
            clientRecord.setDebtStatus(creditRecords);
            creditRecords.clear();
        }
    }

    private static void eraseEqual(ArrayList<ClientRecord> clients)
    {
        LinkedList<Integer> numbers = new LinkedList<Integer>();
        for (int i=0; i<clients.size()-1; i++)
        {
            for (int j=i+1; j<clients.size(); j++)
            {
                if (clients.get(i).getPassport().equals(clients.get(j).getPassport()))
                {
                    numbers.addLast(new Integer(j));
                }
            }
        }

        for (Integer integer : numbers)
        {
            clients.remove(integer);
        }

        System.out.print("Number of clients with different id: " + String.valueOf(numbers.size()) + "\n");
    }
    private static void eraseWithChangedPassport(ArrayList<ClientRecord> clients)
    {
        LinkedList<Integer> numbers = new LinkedList<Integer>();
        ClientRecord clientRecord1;
        ClientRecord clientRecord2;

        for (int i=0; i<clients.size()-1; i++)
        {
            for (int j=i+1; j<clients.size(); j++)
            {
                clientRecord1 = clients.get(i);
                clientRecord2 = clients.get(j);

                if (clientRecord2.getOldPassport() != null)
                {
                    if (clientRecord1.getPassport().equals(clientRecord2.getOldPassport()))
                    {
                        clientRecord2.addCredits((LinkedList<CreditRecord>)
                                clientRecord1.getCredits());
                        numbers.addLast(new Integer(i));
                    }
                }
                if (clientRecord1.getOldPassport() != null)
                {
                    if (clientRecord1.getOldPassport().equals(clientRecord2.getPassport()))
                    {
                        clientRecord1.addCredits((LinkedList<CreditRecord>)
                                clientRecord2.getCredits());
                        numbers.addLast(new Integer(j));
                    }
                }
            }
        }

        for (Integer integer : numbers)
        {
            clients.remove(integer);
        }
        System.out.print("Number of clients, who changed passport: " + String.valueOf(numbers.size()) + "\n");
    }



    private static void printClientsWithCredits(ArrayList<ClientRecord> clients)
    {
        for (ClientRecord r : clients)
        {
            System.out.print(r.getStringWithCredits());
        }
    }
    private static void printClients(ArrayList<ClientRecord> clients)
    {
        for (ClientRecord r : clients)
        {
            System.out.print(r.getString());
        }
    }
    private static void printCredits(ArrayList<CreditRecord> credits)
    {
        for (CreditRecord creditRecord : credits)
        {
            System.out.print(creditRecord.getString());
        }
    }
    private static void uniteClientsCredits(ArrayList<ClientRecord> clients,
                                            ArrayList<CreditRecord> credits)
    {
        for (int i = 0; i < credits.size(); i++)
        {
            for (int j = 0; j < clients.size(); j++)
            {
                if (credits.get(i).getId().equals(clients.get(j).getId()))
                {
                    clients.get(j).addCredit(credits.get(i));
                }
            }
        }
    }
}