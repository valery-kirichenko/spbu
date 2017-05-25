package com.banksys.java;

import java.time.LocalDate;
import java.util.ArrayList;

import static com.banksys.java.Algo.getInt;

public class Client {
    ArrayList<Credit> credits = new ArrayList<>();

    private String id;
    private String phone;
    private String passport;

    private String oldPassport; // as int
    private String name, surname, middlename;
    private LocalDate date;

    // 934->>>>Елена---Водохлёбова\\Федоровна~~~~+79646546254==559253___1945-10-01==613027
    // ID в старой системе, Имя, Фам, Отчество, телефон, номер паспорта, дата рождения в формате ISO, old pass
    Client(String... data){
        id = getInt(data[0]);

        name = data[1].replaceAll("ё", "е");
        surname = data[2].replaceAll("ё", "е");
        middlename = data[3].replaceAll("ё", "е");

        phone = getInt(data[4]);
        passport = getInt(data[5]);

        date = LocalDate.from(LocalDate.parse(data[6]));

        if(data.length > 7) {
            oldPassport = getInt(data[7]);
        }else oldPassport = "";
    }

    @Override
    public String toString() {
        return id + "-" + name + "-" + surname + "-" + middlename + "-"
                + phone + "-" + passport + "-" + date.toString() + "-" + oldPassport;
    }

    public String isDebtor(){
        for(Credit credit : this.credits){
            if(credit.isOverdue().equals("YES")){
                return "YES";
            }
        }
        return "NO";
    }

    private static boolean hasOverdue(Client client){
        return true;
    }

    public String getId() {
        return id;
    }

    public String getPhone() {
        return phone;
    }

    public String getPassport() {
        return passport;
    }

    public String getOldPassport() {
        return oldPassport;
    }

    public String getName() {
        return name;
    }

    public String getSurname() {
        return surname;
    }

    public String getMiddlename() {
        return middlename;
    }

    public LocalDate getDate() {
        return date;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public void setPassport(String passport) {
        this.passport = passport;
    }

    public void setOldPassport(String oldPassport) {
        this.oldPassport = oldPassport;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSurname(String surname) {
        this.surname = surname;
    }

    public void setMiddlename(String middlename) {
        this.middlename = middlename;
    }

    public void setDate(LocalDate date) {
        this.date = date;
    }
}
