package com.NewDataBase;

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
    private Date data;
    private String data2;

    public Credits(String i, String ln, String perc, String pSum, String whloan, String dt) throws ParseException {
        id = i;
        loan = ln;
        percent = perc;
        paidSum = pSum;
        wholeLoan = whloan;
        format = new SimpleDateFormat("yyyy-MM-dd");
        data = format.parse(dt);
        data2 = dt;
    }

    public String getId() { return id; }

    public String getLoan() {
        return loan;
    }

    public String getPercent() {
        return percent;
    }

    public String getPaidSum() {
        return paidSum;
    }

    public String getWholeLoan() {
        return wholeLoan;
    }

    public String getCrediitData2() {
        return data2;
    }

    public Date getCreditData(){ return data; }

    public String toString() {
        return "Credits{" +
                "id = " + id +
                " loan" + loan + '\'' +" , Percent = " + percent +
                '}';
    }
}