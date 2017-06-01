package com.NewDataBase;

import java.util.List;

/**
 * Created by Я on 06.05.2017.
 */
public  interface  CreditController {
    void saveNewCredit(Credits toCreate);
    List<Credits> getAllCredits();
    void deleteCredit(Integer creditID);
    Credits getFirstByID(Integer creditID);
    List<Credits> getByClientID(Integer clientID);
    void updateCredit(Credits toUpdate);
}
