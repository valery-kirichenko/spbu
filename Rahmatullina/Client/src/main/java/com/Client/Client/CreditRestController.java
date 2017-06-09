package com.Client.Client;

import java.util.List;

/**
 * Created by Я on 06.05.2017.
 */
public  interface CreditRestController {
    void saveNewCredit(Credits toCreate);
    void deleteCredit(String creditID);
}
