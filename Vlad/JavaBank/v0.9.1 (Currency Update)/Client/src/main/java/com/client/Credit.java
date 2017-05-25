package com.client;

import com.fasterxml.jackson.databind.annotation.JsonDeserialize;
import com.fasterxml.jackson.databind.annotation.JsonSerialize;
import com.fasterxml.jackson.datatype.jsr310.deser.LocalDateDeserializer;
import com.fasterxml.jackson.datatype.jsr310.ser.LocalDateSerializer;
import java.time.LocalDate;

public class Credit {
    private int clientID;
    private double cashTotal;
    private double cashPaid;
    private double cashWithPercent;
    private double percent;
    private LocalDate deadline;

    public int getClientID() {
        return clientID;
    }
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
    @JsonDeserialize(using = LocalDateDeserializer.class)
    public LocalDate getDeadline() {
        return deadline;
    }
    @JsonSerialize(using = LocalDateSerializer.class)
    public void setDeadline(LocalDate deadline) {
        this.deadline = deadline;
    }

    public boolean isOverdue() {
        LocalDate now = LocalDate.now();
        return now.isAfter(getDeadline());
    }
}

