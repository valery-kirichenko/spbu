package com.database.Model;

import java.io.Serializable;
import java.sql.Date;
import java.time.Instant;
import java.time.LocalDate;

public class CreditRecord implements Serializable
{
    private Long id;
    private Double sum;
    private Double percent;
    private Double paidUpSum;
    private Double paidSum;

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public Double getSum() {
        return sum;
    }

    public void setSum(Double sum) {
        this.sum = sum;
    }

    public Double getPercent() {
        return percent;
    }

    public void setPercent(Double percent) {
        this.percent = percent;
    }

    public Double getPaidUpSum() {
        return paidUpSum;
    }

    public void setPaidUpSum(Double paidUpSum) {
        this.paidUpSum = paidUpSum;
    }

    public Double getPaidSum() {
        return paidSum;
    }

    public void setPaidSum(Double paidSum) {
        this.paidSum = paidSum;
    }

    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    private Date date;

    public int getStatus() {return creditStatus();}

    private int creditStatus()
    {
        //0 - overdue credit
        //1 - active credit
        //2 - paid up credit

        Date currentTime = Date.valueOf(LocalDate.now());

        if (!getPaidSum().equals(getPaidUpSum()))
        {
            if (date.before(currentTime)) {return 0;}
            return 1;
        }
        return 2;
    }


    public String getString()
    {
        String line = "";
        line += "Id : " + id + "\n";
        line += "Sum : " + sum + "\n";
        line += "Per cent : " + percent + "\n";
        line += "Paid up sum : " + paidUpSum + "\n";
        line += "Paid sum : " + paidSum + "\n";
        line += "Date : " + date + "\n";
        line += "--------------------------------------------------------------------------------------\n";
        return line;
    }

    public String getStringWithoutId()
    {
        String line = "";
        line += "Sum : " + sum + "\n";
        line += "Per cent : " + percent + "\n";
        line += "Paid up sum : " + paidUpSum + "\n";
        line += "Paid sum : " + paidSum + "\n";
        line += "Date : " + date + "\n";
        return line;
    }
}
