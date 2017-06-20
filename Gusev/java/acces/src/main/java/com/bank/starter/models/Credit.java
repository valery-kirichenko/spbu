package com.bank.starter.models;

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
    private Double percent = new Double(-1), startSum = new Double(-1), paidSum = new Double(-1), allSum = new Double(-1);

    public Credit() {
    }

    //checker if this com.starter.bank.Credit paid or not
    public boolean isNotPaid() {
        return finishDate.isBefore(LocalDate.now()) && (paidSum < allSum);
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

    public void setPercent(Double percent) {
        this.percent = percent;
    }

    public void setStartSum(Double startSum) {
        this.startSum = startSum;
    }

    public void setPaidSum(Double paidSum) {
        this.paidSum = paidSum;
    }

    public void setAllSum(Double allSum) {
        this.allSum = allSum;
    }

    public double getPercent() { return percent;}

    public double getStartSum() { return startSum;}

    public double getPaidSum() { return paidSum;}

    public double getAllSum() { return allSum;}
}
