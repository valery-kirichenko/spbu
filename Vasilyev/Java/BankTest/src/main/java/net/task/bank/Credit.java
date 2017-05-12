package net.task.bank;

import java.util.Date;


public class Credit {
    //ID клиента, сумма, процент, уже выплаченная сумма, сумма к выплате, дата закрытия.
    private int id;
    private double amount, paidSum, needPaid;
    private String percent;
    private Date closingDate;

    Credit() {
    }

    void setId(int id) {
        this.id = id;
    }

    void setAmount(double amount) {
        this.amount = amount;
    }

    void setPercent(String percent) {
        this.percent = percent;
    }

    void setPaidSum(double paidSum) {
        this.paidSum = paidSum;
    }

    void setNeedPaid(double needPaid) {
        this.needPaid = needPaid;
    }

    void setClosingDate(Date closingDate) {
        this.closingDate = closingDate;
    }


    public int getId() {
        return this.id;
    }

    public double getAmount() {
        return this.amount;
    }

    public String getPercent() {
        return this.percent;
    }

    public double getPaidSum() {
        return this.paidSum;
    }

    public double getNeedPaid() {
        return this.needPaid;
    }

    public Date getClosingDate() {
        return this.closingDate;
    }

    @Override
    public String toString() {
        return this.getId() + " " + this.getAmount() + " " + this.getPercent() +
                " " + this.getPaidSum() + " " + this.getNeedPaid() + " " + this.getClosingDate();
    }
}
