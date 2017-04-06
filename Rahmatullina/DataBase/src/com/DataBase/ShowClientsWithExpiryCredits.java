package com.DataBase;

import java.util.Date;
import java.util.List;

/**
 * Created by Я on 17.03.2017.
 */
class ShowClientsWithExpiryCredits {

    void getClients(List<Clients> listClient) {

        for (Clients client : listClient) {
            boolean have = false;
            System.out.println(client.getClientId() + " " + client.getName() + " " + client.getSurName() + " " + client.getMidName() +
                    " Passport : " + client.getNewPassport() + " His expiry credits : ");

            Date now;
            for (Credits credit : client.getCredit()) {
                now = new Date();
                float wholeLoan = Float.parseFloat(credit.getWholeLoan());
                float paidSumm = Float.parseFloat(credit.getPaidSum());
                if (now.after(credit.data) && paidSumm < wholeLoan) {
                    System.out.println(credit.data + ".He paid :" + paidSumm + " .His whole loan : " + wholeLoan);
                    have = true;
                }
            }
            if (!have) System.out.println(" This Client Doesn't have expiry credits !");
        }


    }
}
