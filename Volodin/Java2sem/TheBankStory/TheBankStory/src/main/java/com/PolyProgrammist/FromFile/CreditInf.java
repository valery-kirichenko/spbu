package com.PolyProgrammist.FromFile;

import java.util.Date;

/**
 * Created by Aspire on 10.03.2017.
 */
public class CreditInf {
    private int clientId;
    private double sum;
    private double sumToPay;
    private double sumPaid;
    private double percent;
    private Date dateToClose;

    public CreditInf(int clientId, double sum, double sumToPay, double sumPaid, double percent, Date dateToClose) {
        this.clientId = clientId;
        this.sum = sum;
        this.sumToPay = sumToPay;
        this.sumPaid = sumPaid;
        this.percent = percent;
        this.dateToClose = dateToClose;
    }

    public CreditInf() {
    }

    public int getClientId() {
        return clientId;
    }

    public void setClientId(int clientId) {
        this.clientId = clientId;
    }

    public double getSum() {
        return sum;
    }

    public void setSum(double sum) {
        this.sum = sum;
    }

    public double getSumToPay() {
        return sumToPay;
    }

    public void setSumToPay(double sumToPay) {
        this.sumToPay = sumToPay;
    }

    public double getSumPaid() {
        return sumPaid;
    }

    public void setSumPaid(double sumPaid) {
        this.sumPaid = sumPaid;
    }

    public double getPercent() {
        return percent;
    }

    public void setPercent(double percent) {
        this.percent = percent;
    }

    public Date getDateToClose() {
        return dateToClose;
    }

    public void setDateToClose(Date dateToClose) {
        this.dateToClose = dateToClose;
    }
}
