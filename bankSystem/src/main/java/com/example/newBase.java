package com.example;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDate;
import java.util.ArrayList;

/**
 * Created by Lenovo on 17.03.2017.
 */
@Service
public class newBase {
    @Autowired
            Clients thisClient;
    ArrayList<Credits> thisCredit = new ArrayList<>();
    ArrayList<Credits> unpaidCredit = new ArrayList<>();

    public void setAll(Clients someClient) {
        thisClient = someClient;
        Credits anotherCredit= new Credits();
        thisCredit=anotherCredit.getById(someClient.getId());
        unPaid();
        ToPay();
    }
    public void addCredit(Credits someCredit)
    {
        thisCredit.add(someCredit);
    }

    public void setThisClient(Clients thisClient) {
        this.thisClient = thisClient;
    }

    public void setByCredit(Clients someClient, Credits someCredit)
    {
        thisClient = someClient;
        thisCredit.add(someCredit);
    }
    public void setNewId(int id)
    {
        thisClient.setId(id);
        for (int i=0; i<thisCredit.size(); i++)
        {
            thisCredit.get(i).setId(id);
        }
    }
    public Clients getClient()
    {
        return thisClient;
    }
    public ArrayList<Credits> getCredits()
    {
        return thisCredit;
    }
    public void ToPay()
    {
        for(int i = 0; i<unpaidCredit.size();i++)
        {
            thisClient.setToPay(unpaidCredit.get(i).getNeedToPay());
        }
    }
    public String getAll()
    {
        String list = new String();
        list = thisClient.getByString()+"\nCREDITS:\n";
        for (int i=0; i<thisCredit.size(); i++)
        {
            list+=thisCredit.get(i).getByString()+"\n";
        }
        return list;
    }
    public void addCredits(ArrayList<Credits> someCredits)
    {
        for (int i = 0; i<someCredits.size(); i++)
        {
            thisCredit.add(someCredits.get(i));
        }
    }
    public boolean checkForPaid()
    {
        for (int i =0; i<thisCredit.size(); i++) {
            String toParse = thisCredit.get(i).getDate();
            LocalDate to = LocalDate.from(LocalDate.parse(toParse));
            if (LocalDate.now().isAfter(to))
            {
                if (thisCredit.get(i).getSumToPay()>thisCredit.get(i).getSumYet()) {return false;
                }
            }
        }
        return true;
    }
    public void unPaid()
    {
        for (int i =0; i<thisCredit.size(); i++) {

            if (thisCredit.get(i).getSumToPay()>thisCredit.get(i).getSumYet())
            {
                unpaidCredit.add(thisCredit.get(i));
                thisCredit.get(i).setNeedToPay(thisCredit.get(i).getSumToPay()-thisCredit.get(i).getSumYet());
            }

        }
    }
    public String getUnPaidByString()
    {
        String list = new String();
        list = thisClient.getByString()+"\nONLY UNPAID CREDITS:\n";
        for (int i=0; i<unpaidCredit.size(); i++)
        {
            list+=unpaidCredit.get(i).getByString()+"\n";
        }
        list+="Sum to pay - "+Double.toString(thisClient.getToPay());
        return list;
    }

    public boolean checkForPaidNow()
    {
        if (!unpaidCredit.isEmpty()) return false;
        return true;
    }
}
