package com.NewDataBase;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;


public class Clients {
    private Integer id;
    private String name;
    private String surName;
    private String midName;
    private String phone;
    private String newPassport;
    private String oldPassport;
    private List<Credits> credit;
    private String data;

    public Clients() {

    }

    public Integer getClientId() {
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

    public String getData() {
        return data;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSurName(String surName) {
        this.surName = surName;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public void setMidName(String midName) {
        this.midName = midName;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public void setNewPassport(String newPassport) {
        this.newPassport = newPassport;
    }

    public void setData(String data) {
        this.data = data;
    }

    public void setOldPassport(String oldPassport) {
        this.oldPassport = oldPassport;
    }

    @Override
    public String toString() {
        return (this.getClientId() + " " + this.getName() + " " + this.getSurName() + " " +
                this.getMidName() + " " + this.getPhone() + " " + this.getNewPassport() + " " +
                this.getData() + " " + this.getOldPassport());
    }

    public List<Credits> getCredit() {
        return credit;
    }

    public void setCredit(List<Credits> credit) {
        this.credit = credit;
    }
}