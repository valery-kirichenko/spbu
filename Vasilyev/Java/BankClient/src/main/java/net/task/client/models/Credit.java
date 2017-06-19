package net.task.client.models;

import com.fasterxml.jackson.databind.annotation.JsonDeserialize;
import com.fasterxml.jackson.databind.annotation.JsonSerialize;
import com.fasterxml.jackson.datatype.jsr310.deser.LocalDateDeserializer;
import com.fasterxml.jackson.datatype.jsr310.ser.LocalDateSerializer;

import java.time.LocalDate;


public class Credit {
    //ID клиента, сумма, процент, уже выплаченная сумма, сумма к выплате, дата закрытия.
    private Integer clientID;
    private Double amount;
    private Double paidSum;
    private Double needPaid;
    private Double percent;
    private LocalDate closingDate;

    public Credit() {
    }

    public void setClientID(Integer clientID) {
        this.clientID = clientID;
    }

    public void setAmount(Double amount) {
        this.amount = amount;
    }

    public void setPercent(Double percent) {
        this.percent = percent;
    }

    public void setPaidSum(Double paidSum) {
        this.paidSum = paidSum;
    }

    public void setNeedPaid(Double needPaid) {
        this.needPaid = needPaid;
    }

    @JsonSerialize(using = LocalDateSerializer.class)
    public void setClosingDate(LocalDate closingDate) {
        this.closingDate = closingDate;
    }


    public Integer getClientID() {
        return this.clientID;
    }

    public Double getAmount() {
        return this.amount;
    }

    public Double getPercent() {
        return this.percent;
    }

    public Double getPaidSum() {
        return this.paidSum;
    }

    public Double getNeedPaid() {
        return this.needPaid;
    }

    @JsonDeserialize(using = LocalDateDeserializer.class)
    public LocalDate getClosingDate() {
        return this.closingDate;
    }

    public Boolean isOverdue() {
        LocalDate now = LocalDate.now();
        return now.isAfter(this.getClosingDate()) &&
                (this.getPaidSum() < this.getNeedPaid());
    }

    public Boolean isMayBeOverdue() {
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
