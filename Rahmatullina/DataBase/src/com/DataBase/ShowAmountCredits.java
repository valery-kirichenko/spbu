package com.DataBase;

import java.util.List;

/**
 * Created by Я on 17.03.2017.
 */
class ShowAmountCredits {
    void getAmountCredits(List<Clients> listClient) {

        for (Clients client : listClient) {
            System.out.println(client.getName() + " " + client.getSurName() + "  Passport : " +
                    client.getNewPassport());
            System.out.println("This Client has " + client.getCredit().size() + "credits ");
        }
    }

}
