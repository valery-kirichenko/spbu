package com.example.CreditBase1;
import java.util.ArrayList;
import java.util.List;

public class Clients{
    private String name, ot, fam, id, pas1, pas2, sot, date;
    private List<Credits> creditsList = new ArrayList<>();

    public void setCreditsList( List<Credits> creditsList){this.creditsList=creditsList;}
    public List<Credits> getCreditsList(){return creditsList;}

    public void setId(String id){
        this.id = id;
    }
    public void setName(String name){
        this.name = name;
    }
    public void setOt(String ot){
        this.ot = ot;
    }
    public void setFam(String fam){
        this.fam = fam;
    }
    public void setPas1(String pas1){
        this.pas1 = pas1;
    }
    public void setDate(String date){
        this.date = date;
    }
    public void setPas2(String pas2) {this.pas2 = pas2;}
    public void setSot(String sot){
        this.sot = sot;
    }

    public String getName(){
        return name;
    }
    public String getOt(){
        return ot;
    }
    public String getId(){
        return id;
    }
    public String getFam(){
        return fam;
    }
    public String getPas1(){
        return pas1;
    }
    public String getPas2(){
        return pas2;
    }
    public String getDate(){
        return date;
    }
    public String getSot(){
        return sot;
    }
}
