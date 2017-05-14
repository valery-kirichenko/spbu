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
    private Date data;
    private String data2;
    private List<Credits> credit;

    public Clients(String i, String nm, String surNm, String midNm, String ph, String newPas, String dt, String oldPas) throws ParseException {

        id = i;
        name = nm;
        surName = surNm;
        midName = midNm;
        phone = ph;
        oldPassport = oldPas;
        newPassport = newPas;
        credit = new ArrayList<Credits>();
        format = new SimpleDateFormat("yyyy-MM-dd");
        data = format.parse(dt);
        data2 = dt;
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

    public List<Credits> getCredit() {
        return credit;
    }

    public void setName(String nm) {
        name = nm;
    }

    public void setSurName(String surnm) {
        surName = surnm;
    }

    public void setId(String ids){ id = ids;}

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

}