package com.DataBase;

import jdk.nashorn.internal.runtime.regexp.joni.Regex;
import com.DataBase.MergeClientsAndCredits.*;
import com.DataBase.ReplaceWords.*;
import com.DataBase.ShowClientsWithExpiryCredits.*;
import com.DataBase.ShowExpiryCredits.*;
import com.DataBase.ClientsDebts.*;
import com.DataBase.ShowAmountCredits.*;
import com.DataBase.Clients.*;
import com.DataBase.GettingClientsFromFile.*;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

import static jdk.nashorn.internal.runtime.regexp.joni.constants.AsmConstants.S;

/**
 * Created by Я on 10.03.2017.
 */
public class DataBase {

    static List<Credits> listCredit;
    static List<Clients> listClient;

    public static void main(String[] args) throws FileNotFoundException, ParseException {


        GettingClientsFromFile getListClient = new GettingClientsFromFile();
        listClient = getListClient.getClient();

        GetCreditFromFile getListCredit = new GetCreditFromFile();
        listCredit = getListCredit.getCredit();

        MergeClientsAndCredits merge = new MergeClientsAndCredits();
        merge.getMerge(listClient, listCredit);

        ReplaceWords replace = new ReplaceWords();
        replace.getReplace(listClient);

        int temp = 0;
        System.out.println("Press 1 - to show the list clients who has debt ");
        System.out.println("Press 2 - to show the list credits who has debt ");
        System.out.println("Press 3 - to show the clients and their sum of debt ");
        System.out.println("Press 4 - to show the clients and their credits ");
        Scanner in = new Scanner(System.in);
        temp = in.nextInt();
        switch (temp) {
            case 1: {
                ShowClientsWithExpiryCredits showClients = new ShowClientsWithExpiryCredits();
                showClients.getClients(listClient);
                break;
            }
            case 2: {
                ShowExpiryCredits showCredits = new ShowExpiryCredits();
                showCredits.getCredits(listClient);
                break;
            }
            case 3: {
                ClientsDebts clientsDebts = new ClientsDebts();
                clientsDebts.getDebts(listClient);
                break;
            }
            case 4: {
                ShowAmountCredits amountCredits = new ShowAmountCredits();
                amountCredits.getAmountCredits(listClient);
                break;
            }
        }


    }
}




