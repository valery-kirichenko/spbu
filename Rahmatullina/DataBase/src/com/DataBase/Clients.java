package com.DataBase;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * Created by Я on 17.03.2017.
 */
class Clients {
    private String id;
    private String name;
    private String surName;
    private String midName;
    private String phone;
    private String newPassport;
    private String oldPassport;
    private DateFormat format;
    private Date data;
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
    }

    String getClientId() {
        return id;
    }

    String getName() {
        return name;
    }

    String getSurName() {
        return surName;
    }

    String getMidName() {
        return midName;
    }

    String getPhone() {
        return phone;
    }

    String getNewPassport() {
        return newPassport;
    }

    String getOldPassport() {
        return oldPassport;
    }

    List<Credits> getCredit() {
        return credit;
    }

    void setName(String nm) {
        name = nm;
    }

    void setSurName(String surnm) {
        surName = surnm;
    }

}
