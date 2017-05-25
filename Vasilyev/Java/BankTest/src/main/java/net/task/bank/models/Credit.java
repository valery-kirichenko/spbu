package net.task.bank.models;

import java.time.LocalDate;


public class Credit {
    //ID клиента, сумма, процент, уже выплаченная сумма, сумма к выплате, дата закрытия.
    private int clientID;
    private double amount, paidSum, needPaid, percent;
    private LocalDate closingDate;

    public Credit() {
    }

    public void setClientId(int clientID) {
        this.clientID = clientID;
    }

    public void setAmount(double amount) {
        this.amount = amount;
    }

    public void setPercent(double percent) {
        this.percent = percent;
    }

    public void setPaidSum(double paidSum) {
        this.paidSum = paidSum;
    }

    public void setNeedPaid(double needPaid) {
        this.needPaid = needPaid;
    }

    public void setClosingDate(LocalDate closingDate) {
        this.closingDate = closingDate;
    }


    public int getClientID() {
        return this.clientID;
    }

    public double getAmount() {
        return this.amount;
    }

    public double getPercent() {
        return this.percent;
    }

    public double getPaidSum() {
        return this.paidSum;
    }

    public double getNeedPaid() {
        return this.needPaid;
    }

    public LocalDate getClosingDate() {
        return this.closingDate;
    }

    public boolean isOverdue() {
        LocalDate now = LocalDate.now();
        return now.isAfter(this.getClosingDate()) &&
                (this.getPaidSum() < this.getNeedPaid());
    }

    public boolean isMayBeOverdue() {
        LocalDate now = LocalDate.now();
        return now.isBefore(this.getClosingDate()) &&
                (this.getPaidSum() < this.getNeedPaid());
    }

    @Override
    public String toString() {
        return this.getClientID() + " " + this.getAmount() + " " + this.getPercent() + " " +
                this.getPaidSum() + " " + this.getNeedPaid() + " " + this.getClosingDate();
    }
}
