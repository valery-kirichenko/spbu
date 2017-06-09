package com.NewDataBase;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
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
    private Date data;
    private DateFormat format;
    private String dataString;

    public Credits(String id, String loan, String percent, String paidSum, String wholeLoan, String date) throws ParseException {
        this.id = id;
        this.loan = loan;
        this.percent = percent;
        this.paidSum = paidSum;
        this.wholeLoan = wholeLoan;
        this.format = new SimpleDateFormat("yyyy-MM-dd");
        this.data = format.parse(date);
        this.dataString = date;
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
        return dataString;
    }

    public Date getCreditData(){ return data; }

    public String toString() {
        return "Credits{" +
                "id = " + id +
                " loan" + loan + '\'' +" , Percent = " + percent +
                '}';
    }
}