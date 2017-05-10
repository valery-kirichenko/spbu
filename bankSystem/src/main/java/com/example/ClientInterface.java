package com.example;


/**
 * Created by Lenovo on 13.04.2017.
 */
public interface ClientInterface {
    public void setAll(String line);
    public void setToPay(double toPay);
    public double getToPay();
    public String getByString();
    public String getName();
    public String getFatherName();
    public String getSurName();
    public String getNum();
    public String getDate();
    public int getFirstPas();
    public int getId();
    public int getPas();
}
