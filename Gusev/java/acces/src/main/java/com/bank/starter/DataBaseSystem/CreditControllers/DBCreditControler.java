package com.bank.starter.DataBaseSystem.CreditControllers;

import com.bank.starter.models.Client;
import com.bank.starter.models.Credit;

import java.util.List;

/**
 * Created by gusef on 18.06.2017.
 */
public interface DBCreditControler {
    void addNewCredit(Credit locCredit);
    List<Credit> getListOfCredits(Client locClient);
    List<Credit> getListOfCredits(Integer id);
    List<Credit> getAllCredits();
    void updateCredit(Credit locCredit);
    Credit getCredit(Integer id);
    boolean isContained(Credit locCredit);
    void deletCredit(Integer id);
}
