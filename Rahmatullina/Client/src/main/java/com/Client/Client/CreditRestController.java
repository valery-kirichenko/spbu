package com.Client.Client;


public  interface CreditRestController {
    void saveNewCredit(Credits toCreate);
    void deleteCredit(String creditID);
}
