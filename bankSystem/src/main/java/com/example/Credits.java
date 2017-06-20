package com.example;

import org.springframework.stereotype.Service;

import java.util.ArrayList;

/**
 * Created by Lenovo on 16.03.2017.
 */
@Service
public class Credits implements CreditInterface {
    int id;
    double sum,proc,sumYet,sumToPay,needToPay;
    String date;
    public static ArrayList<Credits> CreditsArray = new ArrayList();
   /* public void setAll (String line)
    {
        while(!line.isEmpty()) {
            line = line.replaceFirst("Credit\\{","");
            Credits someCredit = new Credits();
            someCredit.setOne(line);
            CreditsArray.add(someCredit);
            line = line.replace(line.substring(0, line.indexOf('&')+1), "");
       }
        System.out.println("DONE CREDITS!\n");
    }*/

    public void setDate(String date) {
        this.date = date;
    }

    public void setId(int id) {
        this.id = id;
    }
    public void setSum(int sum) {this.sum = sum;}

    public void setProc(double proc) {
        this.proc = proc;
    }

    public void setSumToPay(double sumToPay) {
        this.sumToPay = sumToPay;
    }

    public void setSumYet(double sumYet) {
        this.sumYet = sumYet;
    }


    public void setNeedToPay(double needToPay) {
        this.needToPay = needToPay;
    }

    public int getId() {
        return id;
    }

    public double getProc() {
        return proc;
    }

    public double getSum() {
        return sum;
    }

    public double getNeedToPay() {
        return needToPay;
    }

    public  void setOne (String line)
    {
        id = Integer.parseInt(line.substring(0, line.indexOf('|')));
        line = line.replace(line.substring(0, line.indexOf('|')+1), "");
        sum = Double.parseDouble(line.substring(0, line.indexOf(',')));
        line = line.replace(line.substring(0, line.indexOf(',') + 1), "");
        proc = Double.parseDouble(line.substring(0, line.indexOf(',')-1));
        line = line.replace(line.substring(0, line.indexOf(',') + 1), "");
        sumYet = Double.parseDouble(line.substring(0, line.indexOf('^')));
        line = line.replace(line.substring(0, line.indexOf('^')+1), "");
        sumToPay = Double.parseDouble(line.substring(0, line.indexOf('_')));
        line = line.replace(line.substring(0, line.indexOf('_')+3), "");
        date = new String();
        date = line.substring(0, line.indexOf('&'));
        line = line.replace(line.substring(0, line.indexOf('&') + 1), "");
        addCredit(this);
    }
    public void addCredit(Credits someCredit)
    {
        CreditsArray.add(someCredit);
    }
    public String getByString()
    {
        return new String(id+" "+sum+" "+proc+" Zaplacheno "+sumYet+" Ostaloc' "+sumToPay+" "+date);
    }

    public String getDate() {
        return date;
    }

    public double getSumToPay() {
        return sumToPay;
    }

    public double getSumYet() {
        return sumYet;
    }

    public ArrayList<Credits> getById(int id)
    {
        ArrayList<Credits> someArray = new ArrayList<>();
        for (int i = 0; i<CreditsArray.size(); i++)
        {
            if (CreditsArray.get(i).id==id)
            {
                someArray.add(CreditsArray.get(i));
            }
        }
        return someArray;
    }
}
