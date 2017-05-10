package com.example;

import java.util.ArrayList;

/**
 * Created by Lenovo on 13.04.2017.
 */
public interface CreditInterface {
    public void setNeedToPay(double needToPay);
    public double getNeedToPay();
    public  void setOne (String line);
    public String getByString();
    public String getDate();

    public double getSumToPay();

    public double getSumYet();

    public ArrayList<Credits> getById(int id);
}
