package com.example;

import org.springframework.stereotype.Service;

/**
 * Created by Lenovo on 10.03.2017.
 */
@Service
public class Clients implements ClientInterface{
    public String getName() {
        return name;
    }

    public String getFatherName() {
        return fatherName;
    }

    public String getSurName() {
        return surName;
    }

    public String getNum() {
        return num;
    }

    public String getDate() {
        return date;
    }

    public int getFirstPas() {
        return firstPas;
    }

    public int getId() {
        return id;
    }

    public int getPas() {
        return pas;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setDate(String date) {
        this.date = date;
    }

    public void setFatherName(String fatherName) {
        this.fatherName = fatherName;
    }

    public void setFirstPas(int firstPas) {
        this.firstPas = firstPas;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setNum(String num) {
        this.num = num;
    }

    public void setPas(int pas) {
        this.pas = pas;
    }

    public void setSurName(String surName) {
        this.surName = surName;
    }

    String name, surName,fatherName,num,date;
    int id,pas,firstPas; double toPay;
    public void setAll (String line)
    {
        id = Integer.parseInt(line.substring(0,line.indexOf('-')));
        line = line.replaceFirst(line.substring(0,line.lastIndexOf('>')+1),"");
        name = new String();
        name = line.substring(0,line.indexOf('-'));
        line =line.replace(line.substring(0,line.indexOf('-')+3),"");
        surName = new String();
        surName = line.substring(0,line.indexOf('\\'));
        line =line.replace(line.substring(0,line.indexOf('\\')+2),"");
        fatherName = new String();
        fatherName = line.substring(0,line.indexOf('+')-4);
        line =line.replace(line.substring(0,line.indexOf('+')),"");
        num = new String();
        num = line.substring(0,line.indexOf('='));
        line = line.replace(line.substring(0,line.indexOf('=')+2),"");
        pas = Integer.parseInt(line.substring(0,line.indexOf('_')));
        line = line.replace(line.substring(0,line.indexOf('_')+3),"");
        date = new String();
        if (line.indexOf('=')>3) {
            date = line.substring(0, line.indexOf('='));
            line = line.replace(line.substring(0, line.indexOf('=') + 2), "");
            firstPas = Integer.parseInt(line);
        }
        else
        {
            date = line;
            firstPas=0;
        }
    }

    public void setToPay(double toPay) {
        this.toPay += toPay;
    }
    public double getToPay()
    {
        return toPay;
    }

    public String getByString()
    {
        return new String(id+" "+name+" "+surName+" "+fatherName+" "+num+" "+pas+" "+firstPas);
    }
}
