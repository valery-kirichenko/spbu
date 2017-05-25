package com.client;

import java.util.ArrayList;
import java.util.List;

public class Client {
    private int id;
    private String name;
    private String phoneNumber;
    private String birthday;
    private String passport;
    private String oldPassport;
    private List<Credit> credits = new ArrayList<>();

    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getPhoneNumber() {
        return phoneNumber;
    }
    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }
    public String getBirthday() {
        return birthday;
    }
    public void setBirthday(String birthday) {
        this.birthday = birthday;
    }
    public String getPassport() {
        return passport;
    }
    public void setPassport(String passport) {
        this.passport = passport;
    }
    public String getOldPassport() {
        return oldPassport;
    }
    public void setOldPassport(String oldPassport) {
        this.oldPassport = oldPassport;
    }
    public List<Credit> getCredits() {
        return credits;
    }
    public void setCredits(List<Credit> credits) {
        this.credits = credits;
    }

    @Override
    public String toString() {
        return "Client{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", phoneNumber='" + phoneNumber + '\'' +
                ", birthday='" + birthday + '\'' +
                ", passport=" + passport +
                ", oldPassport=" + oldPassport +
                '}';
    }
}

