package net.task.bank;

import java.util.ArrayList;
import java.util.Date;


public class Client {
    //ID в старой системе, Имя, Отчество, Фамилия, телефон, номер паспорта, номер старого паспорта(если есть), дата рождения в формате ISO
    private int id, passport, oldPassport;
    private String name, lastname, middlename, phone;
    private Date birthday;
    public boolean isDeleted = false;
    private ArrayList<Credit> credits = new ArrayList<>();

    Client() {
    }

    void setId(int id) {
        this.id = id;
    }

    void setName(String name) {
        this.name = name;
    }

    void setMiddlename(String middlename) {
        this.middlename = middlename;
    }

    void setLastname(String lastname) {
        this.lastname = lastname;
    }

    void setPassport(int passport) {
        this.passport = passport;
    }

    void setOldPassport(int oldPassport) {
        this.oldPassport = oldPassport;
    }

    void setPhone(String phone) {
        this.phone = phone;
    }

    void setBirthday(Date birthday) {
        this.birthday = birthday;
    }

    void addCredit(Credit credit) {
        this.credits.add(credit);
    }


    public int getId() {
        return this.id;
    }

    public String getName() {
        return this.name;
    }

    public String getMiddlename() {
        return this.middlename;
    }

    public String getLastname() {
        return this.lastname;
    }

    public int getPassport() {
        return this.passport;
    }

    public int getOldPassport() {
        return this.oldPassport;
    }

    public String getPhone() {
        return this.phone;
    }

    public Date getBirthday() {
        return this.birthday;
    }

    public ArrayList<Credit> getCredits() {
        return credits;
    }


    @Override
    public String toString() {
        if (this.getOldPassport() == 0) {
            return (this.getId() + " " + this.getName() + " " + this.getMiddlename() + " " +
                    this.getLastname() + " " + this.getPhone() + " " + this.getPassport() + " "
                    + this.getBirthday());
        } else {
            return (this.getId() + " " + this.getName() + " " + this.getMiddlename() + " " +
                    this.getLastname() + " " + this.getPhone() + " " + this.getPassport() + " "
                    + this.getBirthday() + " " + this.getOldPassport());
        }
    }
}
