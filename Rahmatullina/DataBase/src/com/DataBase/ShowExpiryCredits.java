package com.DataBase;

import java.util.Date;
import java.util.List;

/**
 * Created by Я on 17.03.2017.
 */
class ShowExpiryCredits {
    void getCredits(List<Clients> listClient) {

        for (Clients client : listClient) {

            Date now;
            for (Credits credit : client.getCredit()) {
                now = new Date();
                float wholeLoan = Float.parseFloat(credit.getWholeLoan());
                float paidSumm = Float.parseFloat(credit.getPaidSum());
                if (now.after(credit.data) && paidSumm < wholeLoan)
                    System.out.println("Client id : " + credit.getId() + " .The whole loan : " + wholeLoan + " "
                            + " Client paid : " + paidSumm + ".The expity of date : " + credit.data);
            }
        }
    }
}
