package net.task.bank;

import com.opencsv.CSVWriter;

import java.io.*;
import java.net.URL;
import java.net.URLDecoder;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Scanner;

import static net.task.bank.DataStore.countNull;


/**
 * Created by Vasar on 10.03.2017.
 */
public class Main {
    public static void main(String[] args) {
        System.setProperty("user.name", "\\xD0\\x92\\xD0\\xB0\\xD1\\x81\\xD0\\xB8\\xD0\\xBB\\xD0\\xB8\\xD0\\xB9");

        URL urlClients = Thread.currentThread().getContextClassLoader().getResource("clients.omg");
        URL urlCredits = Thread.currentThread().getContextClassLoader().getResource("credits.omg");

        try {
            urlClients = new URL(URLDecoder.decode(urlClients.toString(), "utf-8"));
            urlCredits = new URL(URLDecoder.decode(urlCredits.toString(), "utf-8"));
        } catch (Exception ex) {
            ex.printStackTrace();
        }

        File fileClients = new File(urlClients.getPath());
        File fileOutClients = new File("client_out.txt");
        File fileCredits = new File(urlCredits.getPath());
        File fileOutCredits = new File("credit_out.txt");
        File fileOut = new File("DataBase.xls");

        DataStore dataStore = new DataStore();
        DateFormat format = new SimpleDateFormat("yyyy-MM-dd");

        //934->>>>Елена---Водохлёбова\\\\Федоровна~~~~+79646546254==559253___1945-10-01==613027 (\n)
        //934  Елена  Водохлёбова  Федоровна  +79646546254  559253  1945-10-01  (not compulsory)613027

        //Credit{727|515584.72710622626,5.0%,269089.711338759^541363.9634615376___2012-12-31& (next credit)
        //727  515584.72710622626  5.0%  269089.711338759  541363.9634615376  2012-12-31

        try (Scanner scClients = new Scanner(fileClients);
             Scanner scCredits = new Scanner(fileCredits).useDelimiter("&");
             FileOutputStream outClients = new FileOutputStream(fileOutClients);
             FileOutputStream outCredits = new FileOutputStream(fileOutCredits);
             FileOutputStream outFile = new FileOutputStream(fileOut)
        ) {
            CSVWriter writerClients = new CSVWriter(new FileWriter("clients.csv"), ';');
            CSVWriter writerCredits = new CSVWriter(new FileWriter("credits.csv"), ';');
            while (scClients.hasNext()) {
                String temp = scClients.next();
                String[] userArr = temp.split("((->>>>)|(---)|(~~~~)|(\\\\\\\\)|(==)|(___))");
                Client client = new Client();
                client.setId(Integer.parseInt(userArr[0]));
                client.setName(userArr[1]);
                client.setLastname(userArr[2]);
                client.setMiddlename(userArr[3]);
                client.setPhone(userArr[4]);
                client.setPassport(Integer.parseInt(userArr[5]));
                client.setBirthday(format.parse(userArr[6]));
                if (userArr.length > 7) {
                    client.setOldPassport(Integer.parseInt(userArr[7]));
                }
                dataStore.clients.add(client);
            }
            while (scCredits.hasNext()) {
                String temp = scCredits.next();
                String[] userArr = temp.split("((\\|)|,|(\\^)|(___))");
                Credit credit = new Credit();
                credit.setId(Integer.parseInt(userArr[0].substring(7)));
                credit.setAmount(Double.parseDouble(userArr[1]));
                credit.setPercent(userArr[2]);
                credit.setPaidSum(Double.parseDouble(userArr[3]));
                credit.setNeedPaid(Double.parseDouble(userArr[4]));
                credit.setClosingDate(format.parse(userArr[5]));
                dataStore.credits.add(credit);
            }
            dataStore.mergeDuplicate();
            dataStore.changeName();
            dataStore.outDataToTxt(outClients, outCredits);
            dataStore.outDataToCsv(writerClients, writerCredits);
            dataStore.outDataToExcel(outFile);
            writerClients.close();
            writerCredits.close();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        System.out.println("Good job well done!");

        System.out.println("----------");

        for (Credit credit : dataStore.credits)
            dataStore.getNameFromId(credit.getId());
        System.out.println("Number of credits with null id: " + countNull);
        countNull = 0;

        BankHelper bankHelper = new BankHelper();

        System.out.println("----------");

        ArrayList<String> debtors = bankHelper.getListDebtors(dataStore);
        System.out.println("Number of debtors: " + debtors.size());
        for (String string : debtors)
            System.out.println(string);
        System.out.println("Number of unique clients with null id: " + countNull);

        ArrayList<Credit> unpaidCredits = bankHelper.getListUnpaidCredits(dataStore);
        System.out.println("Number of unpaid credits: " + unpaidCredits.size());
        for (Credit credit : unpaidCredits)
            System.out.println(credit.toString());

        System.out.println("----------");

        ArrayList<Credit> unpaidCreditsOfClient = bankHelper.getListUnpaidCreditsOfClient(dataStore, 993);
        System.out.println("Number of unpaid credits of client: " + unpaidCreditsOfClient.size());
        for (Credit credit : unpaidCreditsOfClient)
            System.out.println(credit.toString());

        System.out.println("----------");

        System.out.println(debtors.contains(993 + " " + dataStore.getNameFromId(993)));
        System.out.println(bankHelper.getTotalDebt(dataStore, 993));

        System.out.println("----------");

        if (!bankHelper.nullPointerCredits.isEmpty())
            System.out.println("There are " + bankHelper.nullPointerCredits.size() + " unpaid credits with null id!");

        System.out.println("----------");
    }
}
