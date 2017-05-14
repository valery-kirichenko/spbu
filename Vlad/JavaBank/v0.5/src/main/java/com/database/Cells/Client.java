package com.database.Cells;

public class Client {
    private int id;
    private String name;
    private String phoneNumber;
    private String birthday;
    private int passport;
    private int oldPassport;

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
    public int getPassport() {
        return passport;
    }
    public void setPassport(int passport) {
        this.passport = passport;
    }
    public int getOldPassport() {
        return oldPassport;
    }
    public void setOldPassport(int oldPassport) {
        this.oldPassport = oldPassport;
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

