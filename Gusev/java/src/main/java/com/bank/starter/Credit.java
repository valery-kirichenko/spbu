package com.bank.starter;

import java.math.BigInteger;
import java.time.LocalDate;
import java.util.Scanner;

/**
 * Created by gusef on 26.05.2017.
 */
public class Credit {

    // class of com.starter.bank.Credit
    private LocalDate finishDate = LocalDate.now();

    private int id;

    /*
    percent - percent of com.starter.bank.Credit
    startSum - sum of money which was taken
    paidSum - sum of money which was paid
    allSum - sum of money which should be paid
     */
    private String percent = "", startSum = "", paidSum = "", allSum = "";


    public Credit() {
    }

    //constructor from String
    static Credit parse(String stringToParse) {
        if(stringToParse.toCharArray()[0] != 'C')
            return null;
        Credit tmpCredit = new Credit();

        stringToParse = stringToParse.substring(stringToParse.indexOf("Credit{") + 7);
        tmpCredit.setId(new Scanner(stringToParse.substring(0, stringToParse.indexOf("|"))).nextInt());

        stringToParse = stringToParse.substring(stringToParse.indexOf("|") + 1);
        tmpCredit.setStartSum(stringToParse.substring(0, stringToParse.indexOf(",")));

        stringToParse = stringToParse.substring(stringToParse.indexOf(",") + 1);
        tmpCredit.setPercent(stringToParse.substring(0, stringToParse.indexOf("%,")));

        stringToParse = stringToParse.substring(stringToParse.indexOf("%,") + 2);
        tmpCredit.setPaidSum(stringToParse.substring(0, stringToParse.indexOf("^")));

        stringToParse = stringToParse.substring(stringToParse.indexOf("^") + 1);
        tmpCredit.setAllSum(stringToParse.substring(0, stringToParse.indexOf("___")));

        stringToParse = stringToParse.substring(stringToParse.indexOf("___") + 3, stringToParse.indexOf("&"));
        tmpCredit.setFinishDate(LocalDate.parse(stringToParse));
        return tmpCredit;
    }

    //checker if this com.starter.bank.Credit paid or not
    public boolean isNotPaid() {
       double as = toDouble(allSum), ps = toDouble(paidSum);
        return finishDate.isBefore(LocalDate.now()) && (ps < as);
    }

    private double toDouble(String stringToParse){
        if(!stringToParse.contains("."))
            stringToParse += ".0";
        Scanner sc = new Scanner(stringToParse.replace("."," "));
        double a = sc.nextDouble(),b = sc.nextDouble();
        while(b>1)
            b /= 10;
        return a+b;
    }

    public void setFinishDate(LocalDate finishDate) {
        this.finishDate = finishDate;
    }

    public void setId(int id) {
        this.id = id;
    }

    public LocalDate getFinishDate() {
        return finishDate;
    }

    public int getId() {
        return id;
    }

    public void setPercent(String percent) {
        this.percent = percent;
    }

    public void setStartSum(String startSum) {
        this.startSum = startSum;
    }

    public void setPaidSum(String paidSum) {
        this.paidSum = paidSum;
    }

    public void setAllSum(String allSum) {
        this.allSum = allSum;
    }

    public double getPercent() { return toDouble(percent);}

    public double getStartSum() { return toDouble(startSum);}

    public double getPaidSum() { return toDouble(paidSum);}

    public double getAllSum() { return toDouble(allSum);}
}
