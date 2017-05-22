package com.banksys.java.models;

import com.fasterxml.jackson.databind.annotation.JsonDeserialize;
import com.fasterxml.jackson.databind.annotation.JsonSerialize;
import com.fasterxml.jackson.databind.deser.std.DateDeserializers;
import com.fasterxml.jackson.databind.ser.std.DateSerializer;
import com.fasterxml.jackson.datatype.jsr310.deser.LocalDateDeserializer;

import java.time.LocalDate;

import static com.banksys.java.Algo.getInt;

public class Credit{
    public String id;   // int
    public String amount;
    public String percent;

    public String payed;
    public String needed;   //double

    @JsonDeserialize(using = LocalDateDeserializer.class)
    public LocalDate date;

    // Rest Deserialization
    public Credit(){
        super();
    }

    //Структура кредитов: ID клиента, сумма, процент, уже выплаченная сумма, сумма к выплате, дата закрытия.
    //app.Credit{727|515584.72710622626,5.0%,269089.711338759^541363.9634615376___2012-12-31&

    public Credit (Credit credit){
        id = credit.id;
        amount = credit.amount;
        percent = credit.percent;
        payed = credit.payed;
        needed = credit.needed;
        date = credit.date;
    }

    public Credit(String... data){
        id = getInt(data[0]);

        amount = data[1];
        percent = data[2];
        payed = data[3];
        needed = data[4];

        date =  LocalDate.from(LocalDate.parse(data[5]));
    }

    @Override
    public String toString() {
        return id + "-" + amount + "-" + percent + "-" + payed + "-" + needed + "-" + date.toString();
    }

    public String isOverdue(){
        return date.isBefore(LocalDate.now())
                && Double.parseDouble(payed) < Double.parseDouble(needed) ? "YES" : "NO";
    }

    public String getId() {
        return id;
    }

    public String getAmount() {
        return amount;
    }

    public void setAmount(String amount) {
        this.amount = amount;
    }

    public String getPercent() {
        return percent;
    }

    public void setPercent(String percent) {
        this.percent = percent;
    }

    public String getPayed() {
        return payed;
    }

    public void setPayed(String payed) {
        this.payed = payed;
    }

    public String getNeeded() {
        return needed;
    }

    public void setNeeded(String needed) {
        this.needed = needed;
    }

    public LocalDate getDate() {
        return date;
    }

    public void setDate(LocalDate date) {
        this.date = date;
    }
}
