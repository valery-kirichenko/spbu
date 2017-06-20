package com.bank.starter.models;

import com.bank.starter.MyDataBase.MyBase;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by gusef on 26.05.2017.
 */
public class Client {

    // id in old system
    private int nowId = -1;

    //name of client
    private String name, surName, lastName;

    // passport of the client
    int pass;
    private int oldPass = -1;

    //current phone of the client
    private String phone = "";

    private LocalDate birthDate = LocalDate.now();

    public boolean isEqualAndGreater(Client locClient){
        if(pass == locClient.getOldPass())
            return true;
        return false;
    }
    public boolean isEqual(Client locClinet){
        return pass == locClinet.getPass();
    }

    public Integer getOldPass() {
        return oldPass;
    }

    public String getName() {
        return name;
    }

    public String getSurName() {
        return surName;
    }

    public String getLastName() {
        return lastName;
    }

    public int getNowId() {
        return nowId;
    }

    public void setNowId(int nowId) {
        this.nowId = nowId;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSurName(String surName) {
        this.surName = surName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public int getPass() {
        return pass;
    }

    public String getPasstoString(){
        String ans = "";
        ans += pass;
        while(ans.length() < 6)
            ans = "0"+ans;
        return ans;
    }

    public void setPass(int pass) {
        this.pass = pass;
    }

    public void setOldPass(Integer oldPass) {
        this.oldPass = oldPass;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public LocalDate getBirthDate() {
        return birthDate;
    }

    public void setBirthDate(LocalDate birthDate) {
        this.birthDate = birthDate;
    }
}
