package com.NewDataBase;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * Created by Я on 17.03.2017.
 */
public class Clients {
    private String id;
    private String name;
    private String surName;
    private String midName;
    private String phone;
    private String newPassport;
    private String oldPassport;
    private DateFormat format;
    private List<Credits> credit;
    private Date data;
    private String data2;

    public Clients(String id, String name, String surName, String midName, String phone, String newPassport, String date, String oldPassport) throws ParseException {

        this.id = id;
        this.name = name;
        this.surName = surName;
        this.midName = midName;
        this.phone = phone;
        this.credit= new ArrayList();
        this.oldPassport = oldPassport;
        this.newPassport = newPassport;
        this.format = new SimpleDateFormat("yyyy-MM-dd");
        this.data = format.parse(date);
        this.data2 = date;
    }

    public String getClientId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public String getSurName() {
        return surName;
    }

    public String getMidName() {
        return midName;
    }

    public String getPhone() {
        return phone;
    }

    public String getNewPassport() {
        return newPassport;
    }

    public String getOldPassport() {
        return oldPassport;
    }

    public String getData2(){ return data2; }

    public void setName(String name) {
        this.name = name;
    }

    public void setSurName(String surName) {
        this.surName = surName;
    }

    public void setId(String id){ this.id = id;}

    public void setMidName(String midName) {
        this.midName = midName;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public void setNewPassport(String newPassport) {
        this.newPassport = newPassport;
    }

    public void setData(String data) throws ParseException {
        format = new SimpleDateFormat("yyyy-MM-dd");
        this.data = format.parse(data);
    }

    public void setOldPassport(String oldPassport) {
        this.oldPassport = oldPassport;
    }
    public String toString() {
        return "Clients{" +
                "Name = " + name +
                " , id=" + id +" , SurName = " + surName + '\'' +" , MidName = " + midName +
                '}';
    }

    public List<Credits> getCredit() {
        return credit;
    }

    public void setCredit(List<Credits> credit) {
        this.credit = credit;
    }
}