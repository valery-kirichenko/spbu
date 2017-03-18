package com.DataBase;

import java.util.Date;
import java.util.List;

/**
 * Created by Я on 17.03.2017.
 */
class ClientsDebts {
    void getDebts(List<Clients> listClient) {

        for (Clients client : listClient) {
            Date now;
            float debt = 0;
            for (Credits credit : client.getCredit()) {
                now = new Date();
                float wholeLoan = Float.parseFloat(credit.getWholeLoan());
                float paidSumm = Float.parseFloat(credit.getPaidSum());
                if (now.after(credit.data) && paidSumm < wholeLoan)
                    debt += wholeLoan - paidSumm;
            }
            System.out.println(client.getName() + " " + client.getSurName() + " has debt : " + debt + "!");
        }
    }
}
