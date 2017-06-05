package com.database.Model;


import java.util.Collection;
import java.util.LinkedList;

/**
 * Created by Дмитрий on 24.03.2017.
 */
public class BankHelper implements ClientHelper
{
    public Collection getListDebtors(Collection<ClientRecord> clients)
    {
        LinkedList<ClientRecord> debtors = new LinkedList<ClientRecord>();

        for (ClientRecord ptr : clients)
        {
            for (CreditRecord creditRecord : ptr.getCredits())
            {
                if (!creditRecord.getPaidUpSum().equals(creditRecord.getPaidSum()))
                {
                    debtors.addLast(ptr);
                    break;
                }
            }
        }
        return debtors;
    }
    public Collection getListCreditsByCredits(Collection<CreditRecord> credits)
    {
        LinkedList<CreditRecord> debts = new LinkedList<>();

        for (CreditRecord creditRecord : credits)
        {
            if (!creditRecord.getPaidUpSum().equals(creditRecord.getPaidSum()))
            {
                debts.add(creditRecord);
            }
        }
        return debts;
    }
    public Collection getListCreditsByClients(Collection<ClientRecord> clients)
    {
        LinkedList<CreditRecord> debts = new LinkedList<>();

        for (ClientRecord clientRecord : clients)
        {
            for (CreditRecord creditRecord : clientRecord.getCredits())
            {
                if (!creditRecord.getPaidUpSum().equals(creditRecord.getPaidSum()))
                {
                    debts.add(creditRecord);
                    break;
                }
            }
        }
        return debts;
    }
    public Collection getDebtClient(ClientRecord clientRecord)
    {
        LinkedList<CreditRecord> debts = new LinkedList<>();

        for (CreditRecord creditRecord : clientRecord.getCredits())
        {
            if (!creditRecord.getPaidUpSum().equals(creditRecord.getPaidSum()))
            {
                debts.addLast(creditRecord);
            }
        }
        return debts;
    }
    public CreditRecord getCreditRecord (Collection<CreditRecord> credits,
                                         CreditRecord creditRecord)
    {
        for (CreditRecord ptr : credits)
        {
            if (ptr.equals(creditRecord))
                return ptr;
        }
        return null;
    }

    public Collection getClientsByString
            (Collection<ClientRecord> clients, String line)
    {
        LinkedList <ClientRecord> clientRecords = new LinkedList<ClientRecord>();

        for (ClientRecord ptr : clients)
        {
            if (String.valueOf(ptr.getId()).contains(String.valueOf(line.toLowerCase()))
            || (ptr.getName().toLowerCase().contains(line.toLowerCase()))
            || (ptr.getFamily().toLowerCase().contains(line.toLowerCase()))
            || (ptr.getPatronymic().toLowerCase().contains(line.toLowerCase()))
            || (ptr.getPassport().toLowerCase().contains(line.toLowerCase()))
            || (ptr.getPhone().toLowerCase().contains(line.toLowerCase()))
            || (ptr.getOldPassport().toLowerCase().contains(line.toLowerCase()))
            || (ptr.getDate().toLowerCase().contains(line.toLowerCase())))
                clientRecords.addLast(ptr);
        }

        return clientRecords;
    }

    public Collection getClientsByFields
            (Collection<ClientRecord> clients,
             ClientRecord clientRecord)
    {
        LinkedList <ClientRecord> clientRecords = new LinkedList<ClientRecord>();

            for (ClientRecord ptr : clients)
            {
                if (searchCondition(ptr, clientRecord))
                  clientRecords.addLast(ptr);
            }

        return clientRecords;
    }
    private boolean searchCondition(ClientRecord clientRecord,
                                    ClientRecord condition)
    {
        ClientRecord ptr = clientRecord;
        if (condition.getId() != (null))
            if (!String.valueOf(ptr.getId()).contains(String.valueOf
                    (condition.getId())))
                return false;
        if (!condition.getName().isEmpty())
            if (!ptr.getName().toLowerCase().contains(condition.
                    getName().toLowerCase()))
                return false;
        if (!condition.getFamily().isEmpty())
            if (!ptr.getFamily().toLowerCase().contains(condition.
                    getFamily().toLowerCase()))
                return false;
        if (!condition.getPatronymic().isEmpty())
            if (!ptr.getPatronymic().toLowerCase().contains(condition.
                    getPatronymic().toLowerCase()))
                return false;
        if (!condition.getPassport().isEmpty())
            if (!ptr.getPassport().toLowerCase().contains(condition.
                    getPassport().toLowerCase()))
                return false;
        if (!condition.getPhone().isEmpty())
            if (!ptr.getPhone().toLowerCase().contains(condition.
                    getPhone().toLowerCase()))
                return false;
        if (!condition.getOldPassport().isEmpty())
            if (!ptr.getOldPassport().toLowerCase().contains(condition.
                    getOldPassport().toLowerCase()))
                return false;
        if (!condition.getDate().isEmpty())
            if (!ptr.getDate().toLowerCase().contains(condition.
                    getDate().toLowerCase()))
                return false;

        return true;
    }


    public ClientRecord getClientRecord (Collection<ClientRecord> clients,
                                         ClientRecord clientRecord)
    {
        for (ClientRecord ptr : clients)
        {
            if (ptr.getId().equals(clientRecord.getId()))
                return ptr;
        }
        return null;
    }
}
