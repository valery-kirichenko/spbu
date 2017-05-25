package net.task.bank.models;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;


public class Client {
    //ID в старой системе, Имя, Отчество, Фамилия, телефон, номер паспорта, номер старого паспорта(если есть), дата рождения в формате ISO
    private int ID;
    private String firstName, lastName, middleName, phone, passport, oldPassport;
    private LocalDate birthday;
    public boolean isDeleted = false;
    private List<Credit> credits = new ArrayList<>();

    public Client() {
    }

    public void setID(int ID) {
        this.ID = ID;
    }

    public void setFirstName(String name) {
        this.firstName = name;
    }

    public void setMiddleName(String middleName) {
        this.middleName = middleName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public void setPassport(String passport) {
        this.passport = passport;
    }

    public void setOldPassport(String oldPassport) {
        this.oldPassport = oldPassport;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public void setBirthday(LocalDate birthday) {
        this.birthday = birthday;
    }

    public void addCredit(Credit credit) {
        this.credits.add(credit);
    }

    public void setCredits(List<Credit> credits) {
        this.credits = credits;
    }

    public boolean isDebtor() {
        for (Credit credit : this.credits)
            if (credit.isOverdue())
                return true;
        return false;
    }

    public boolean isMayBeDebtor() {
        for (Credit credit : this.credits)
            if (credit.isMayBeOverdue())
                return true;
        return false;
    }


    public int getID() {
        return this.ID;
    }

    public String getFirstName() {
        return this.firstName;
    }

    public String getMiddleName() {
        return this.middleName;
    }

    public String getLastName() {
        return this.lastName;
    }

    public String getPassport() {
        return this.passport;
    }

    public String getOldPassport() {
        return this.oldPassport;
    }

    public String getPhone() {
        return this.phone;
    }

    public LocalDate getBirthday() {
        return this.birthday;
    }

    public List<Credit> getCredits() {
        return credits;
    }


    @Override
    public String toString() {
        if (this.getOldPassport() != null) {
            return (this.getID() + " " + this.getFirstName() + " " + this.getMiddleName() + " " +
                    this.getLastName() + " " + this.getPhone() + " " + this.getPassport() + " " +
                    this.getBirthday());
        } else {
            return (this.getID() + " " + this.getFirstName() + " " + this.getMiddleName() + " " +
                    this.getLastName() + " " + this.getPhone() + " " + this.getPassport() + " " +
                    this.getBirthday() + " " + this.getOldPassport());
        }
    }
}
