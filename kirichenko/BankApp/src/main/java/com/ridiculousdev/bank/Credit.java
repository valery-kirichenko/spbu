package com.ridiculousdev.bank;

import java.time.LocalDate;

public class Credit {
    // ID клиента, сумма, процент, уже выплаченная сумма, сумма к выплате, дата закрытия.
    private int id;
    private double total, rate, paid, payable;
    private LocalDate closingDate;
    private Client parent;
    private int databaseId;

    public Credit() {
    }

    public int getId() {
        return id;
    }

    public double getTotal() {
        return total;
    }

    public double getRate() {
        return rate;
    }

    public double getPaid() {
        return paid;
    }

    public double getPayable() {
        return payable;
    }

    public LocalDate getClosingDate() {
        return closingDate;
    }

    public String getTotalString() {
        return Double.toString(total);
    }

    public String getRateString() {
        return Double.toString(rate);
    }

    public String getPaidString() {
        return Double.toString(paid);
    }

    public int getDatabaseId() {
        return databaseId;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setTotal(double total) {
        this.total = total;
        this.payable = this.total * (1 + this.rate / 100);
        if (this.parent != null) this.parent.updateStatus();
    }

    public void setTotal(String total) {
        this.setTotal(Double.parseDouble(total));
    }

    public void setRate(double rate) {
        this.rate = rate;
        this.payable = this.total * (1 + this.rate / 100);
        if (this.parent != null) this.parent.updateStatus();
    }

    public void setRate(String rate) {
        this.setRate(Double.parseDouble(rate));
    }

    public void setPaid(double paid) {
        this.paid = paid;
        if (this.parent != null) this.parent.updateStatus();
    }

    public void setPaid(String paid) {
        this.paid = Double.parseDouble(paid);
    }

    public void setPayable(double payable) {
        this.payable = payable;
        if (this.parent != null) this.parent.updateStatus();
    }

    public void setClosingDate(LocalDate closingDate) {
        this.closingDate = closingDate;
        if (this.parent != null) this.parent.updateStatus();
    }

    public void setClosingDate(String closingDate) {
        this.setClosingDate(LocalDate.parse(closingDate));
    }

    public void setParent(Client parent) {
        this.parent = parent;
    }

    public void setDatabaseId(int databaseId) {
        this.databaseId = databaseId;
    }

    @Override
    public String toString() {
        return id + " | " + total + " | " + rate + " | " + paid + " | " + payable + " | " +
                closingDate.getDayOfMonth() + "." + closingDate.getMonthValue() + "." + closingDate.getYear();
    }

    public boolean isPaid() {
        return paid >= payable;
    }

    public boolean isDodger() {
        return !isPaid() && getClosingDate().isBefore(LocalDate.now());
    }

}
