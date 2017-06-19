package app;

import java.time.LocalDate;

import static app.Algo.getInt;

public class Credit {
    public String id;   // int
    public String amount, percent, payed, needed;   //double

    LocalDate date;

    //Структура кредитов: ID клиента, сумма, процент, уже выплаченная сумма, сумма к выплате, дата закрытия.
    //app.Credit{727|515584.72710622626,5.0%,269089.711338759^541363.9634615376___2012-12-31&

    Credit(String[] data){
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
}
