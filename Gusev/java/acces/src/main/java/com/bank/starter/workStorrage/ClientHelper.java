package com.bank.starter.workStorrage;

import com.bank.starter.models.Client;
import com.bank.starter.models.Credit;

import java.util.ArrayList;

/**
 * Created by gusef on 27.05.2017.
 */
public interface ClientHelper {
    double allDebt(Client cl);
    ArrayList<Credit> debtCredits(Client cl);
    ArrayList<Credit> allNotPaidCredits();
}
