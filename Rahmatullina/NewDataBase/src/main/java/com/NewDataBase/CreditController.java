package com.NewDataBase;

import java.util.List;

/**
 * Created by Я on 06.05.2017.
 */
public  interface  CreditController {
    void saveNewCredit(Credits toCreate);
    List<Credits> getAllCredits();
    void deleteCredit(String creditID);
    Credits getFirstByID(String creditID);
    List<Credits> getByClientID(String clientID);
    void updateCredit(Credits toUpdate);
}
