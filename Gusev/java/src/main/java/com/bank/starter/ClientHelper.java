package com.bank.starter;

import java.io.File;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by gusef on 27.05.2017.
 */
public interface ClientHelper {
    double allDebt(Client cl);
    ArrayList<Credit> debtCredits(Client cl);
    ArrayList<Credit> allNotPaidCredits();
}
