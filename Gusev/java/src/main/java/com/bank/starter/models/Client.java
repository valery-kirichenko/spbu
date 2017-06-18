package com.bank.starter.models;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by gusef on 26.05.2017.
 */
public class Client {

    // id in old system
    private int nowId;
    private List<Integer> oldId = new ArrayList<>();

    //name of client
    private String name, surName, lastName;

    // passport of the client
    int pass;
    private List<Integer> oldPass = new ArrayList<>();

    //current phone of the client
    private String phone = "";

    private LocalDate birthDate = LocalDate.now();

    // list of the credits
    private List<Credit> credits = new ArrayList<>();

    public static Client Parse(String stringToParse){
        if(stringToParse.toCharArray()[0] < '0' || stringToParse.toCharArray()[0] > '9')
            stringToParse = stringToParse.substring(1);
        Scanner sc2 = new Scanner(stringToParse.substring(0,stringToParse.indexOf("->>>>")));
        Client tmpClient = new Client();
        tmpClient.setNowId(sc2.nextInt());
        tmpClient.setName(stringToParse.substring(stringToParse.lastIndexOf("->>>>")+5,stringToParse.indexOf("---")));
        tmpClient.setSurName(stringToParse.substring(stringToParse.lastIndexOf("---")+3,stringToParse.indexOf("\\\\")));
        tmpClient.setLastName(stringToParse.substring(stringToParse.lastIndexOf("\\\\")+2,stringToParse.indexOf("~~~~")));
        tmpClient.setPhone(stringToParse.substring(stringToParse.lastIndexOf("~~~~")+4,stringToParse.indexOf("==")));
        tmpClient.setPass(Integer.parseInt(stringToParse.substring(stringToParse.indexOf("==")+2,stringToParse.indexOf("___"))));
        stringToParse = stringToParse.substring(stringToParse.lastIndexOf("___")+3);
        if(stringToParse.contains("==")) {
            tmpClient.setBirthDate(LocalDate.parse(stringToParse.substring(0,stringToParse.indexOf("=="))));
            tmpClient.getOldPass().add(Integer.parseInt(stringToParse.substring(stringToParse.indexOf("==")+2)));
        }
        else
            tmpClient.setBirthDate(LocalDate.parse(stringToParse));
        return tmpClient;
    }

    public boolean isEqualAndGreater(Client locClient){
        if(pass == locClient.getPass())
            return true;
        for (int subPass:
             locClient.getOldPass()) {
            if(pass == subPass)
                return true;
        }
        return false;
    }

    public boolean merge(Client cl){
        if(isEqualAndGreater(cl)){
            oldId.add(cl.getNowId());
            oldPass.add(cl.getPass());
            oldPass.addAll(cl.getOldPass());
            oldId.addAll(cl.getOldId());
            return true;
        }
        return false;
    }

    public List<Credit> getCredits() {
        return credits;
    }

    public List<Integer> getOldId() {
        return oldId;
    }

    public List<Integer> getOldPass() {
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

    public void setOldId(List<Integer> oldId) {
        this.oldId = oldId;
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

    public void setOldPass(List<Integer> oldPass) {
        this.oldPass = oldPass;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public void setCredits(List<Credit> credits) {
        this.credits = credits;
    }

    public LocalDate getBirthDate() {
        return birthDate;
    }

    public void setBirthDate(LocalDate birthDate) {
        this.birthDate = birthDate;
    }
}
