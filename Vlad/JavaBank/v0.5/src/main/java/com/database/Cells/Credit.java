package com.database.Cells;

public class Credit {
    private int clientID;
    private double cashTotal;
    private double cashPaid;
    private double cashWithPercent;
    private double percent;
    private java.sql.Date deadline;

    public int getClientID() {return clientID;}
    public void setClientID(int clientID) {
        this.clientID = clientID;
    }
    public double getCashTotal() {
        return cashTotal;
    }
    public void setCashTotal(double cashTotal) {
        this.cashTotal = cashTotal;
    }
    public double getCashPaid() {
        return cashPaid;
    }
    public void setCashPaid(double cashPaid) {
        this.cashPaid = cashPaid;
    }
    public double getCashWithPercent() {
        return cashWithPercent;
    }
    public void setCashWithPercent(double cashWithPercent) {
        this.cashWithPercent = cashWithPercent;
    }
    public double getPercent() {
        return percent;
    }
    public void setPercent(double percent) {
        this.percent = percent;
    }
    public java.sql.Date getDeadline() {
        return deadline;
    }
    public void setDeadline(java.sql.Date deadline) {
        this.deadline = deadline;
    }
}

