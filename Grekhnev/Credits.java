package com.example.CreditBase1;
public class Credits {
    private String id, sum, per, vyp, ost, date;

    public void setId(String id){
        this.id = id;
    }
    public void setSum(String sum){
        this.sum = sum;
    }
    public void setPer(String per){
        this.per = per;
    }
    public void setVyp(String vyp){
        this.vyp = vyp;
    }
    public void setOst(String ost){
        this.ost = ost;
    }
    public void setDate(String date){
        this.date = date;
    }

    public String getPer(){
        return per;
    }
    public String getVyp(){
        return vyp;
    }
    public String getId(){
        return id;
    }
    public String getOst(){return ost;}
    public String getDate(){
        return date;
    }
    public String getSum(){
        return sum;
    }
}
