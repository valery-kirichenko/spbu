package net.task.bank;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;


public class Client {
    //ID в старой системе, Имя, Отчество, Фамилия, телефон, номер паспорта, номер старого паспорта(если есть), дата рождения в формате ISO
    private int id, passport, oldPassport;
    private String name, lastName, middleName, phone;
    private Date birthDay;
    public boolean isDeleted = false;
    private List<Credit> credits = new ArrayList<>();

    Client() {
    }

    void setId(int id) {
        this.id = id;
    }

    void setName(String name) {
        this.name = name;
    }

    void setMiddleName(String middlename) {
        this.middleName = middlename;
    }

    void setLastName(String lastname) {
        this.lastName = lastname;
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
        this.birthDay = birthday;
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

    public String getMiddleName() {
        return this.middleName;
    }

    public String getLastName() {
        return this.lastName;
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

    public Date getBirthDay() {
        return this.birthDay;
    }

    public List<Credit> getCredits() {
        return credits;
    }


    @Override
    public String toString() {
        if (this.getOldPassport() == 0) {
            return (this.getId() + " " + this.getName() + " " + this.getMiddleName() + " " +
                    this.getLastName() + " " + this.getPhone() + " " + this.getPassport() + " "
                    + this.getBirthDay());
        } else {
            return (this.getId() + " " + this.getName() + " " + this.getMiddleName() + " " +
                    this.getLastName() + " " + this.getPhone() + " " + this.getPassport() + " "
                    + this.getBirthDay() + " " + this.getOldPassport());
        }
    }
}
