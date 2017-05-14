package net.task.bank;

import com.opencsv.CSVWriter;

import java.io.*;
import java.net.URL;
import java.net.URLDecoder;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


/**
 * Created by Vasar on 10.03.2017.
 */
public class Main {
    public static void main(String[] args) {
        File fileOutClients = new File("client_out.txt");
        File fileOutCredits = new File("credit_out.txt");
        File fileOut = new File("DataBase.xls");

        try (FileOutputStream outClients = new FileOutputStream(fileOutClients);
             FileOutputStream outCredits = new FileOutputStream(fileOutCredits);
             FileOutputStream outFile = new FileOutputStream(fileOut)
        ) {
            CSVWriter writerClients = new CSVWriter(new FileWriter("clients.csv"), ';');
            CSVWriter writerCredits = new CSVWriter(new FileWriter("credits.csv"), ';');

            DataReader.readClients();
            DataReader.readCredits();

            DataStore.mergeDuplicate();
            DataStore.changeClientInfo();
            DataStore.outDataToTxt(outClients, outCredits);
            DataStore.outDataToCsv(writerClients, writerCredits);
            DataStore.outDataToExcel(outFile);
            writerClients.close();
            writerCredits.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }

        System.out.println("Files was reading. Processed information: ");

        BankHelper bankHelper = new BankHelper();

        System.out.println("----------");

        List<Client> debtors = bankHelper.getListDebtors();
        System.out.println("Number of debtors: " + debtors.size());
        for (Client client : debtors)
            System.out.println(client.toString());

        List<Credit> unpaidCredits = bankHelper.getListUnpaidCredits();
        System.out.println("Number of unpaid credits: " + unpaidCredits.size());
        for (Credit credit : unpaidCredits)
            System.out.println(credit.toString());

        System.out.println("----------");

        List<Credit> unpaidCreditsOfClient = bankHelper.getListUnpaidCreditsOfClient(993);
        System.out.println("Number of unpaid credits of client: " + unpaidCreditsOfClient.size());
        for (Credit credit : unpaidCreditsOfClient)
            System.out.println(credit.toString());

        System.out.println("----------");

        System.out.println(bankHelper.getTotalDebt(993));

        System.out.println("----------");

        if (!BankHelper.nullPointerCredits.isEmpty())
            System.out.println("There are " + BankHelper.nullPointerCredits.size() + " unpaid credits with null id!");

        System.out.println("----------");
        System.out.println("Good job well done!");
    }
}
