package com.DataBase;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * Created by Я on 17.03.2017.
 */
public class Credits {

     private String id;
     private String loan;
     private String percent;
     private String paidSum;
     private String wholeLoan;
     private DateFormat format;
     Date data;

     Credits(String i, String ln, String perc, String pSum, String whloan, String dt) throws ParseException {
        id = i;
        loan = ln;
        percent = perc;
        paidSum = pSum;
        wholeLoan = whloan;
        format = new SimpleDateFormat("yyyy-MM-dd");
        data = format.parse(dt);
    }

    String getId(){
         return id;
    }
    String getLoan(){
        return loan;
    }
    String getPercent(){
        return percent;
    }
    String getPaidSum(){
        return id;
    }
    String getWholeLoan(){
        return wholeLoan;
    }
    String getFormat(){
        return id;
    }
    Date getCrediitData(){
        return data;
    }
}

