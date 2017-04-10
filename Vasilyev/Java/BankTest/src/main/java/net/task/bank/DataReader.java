package net.task.bank;

import java.io.File;
import java.net.URL;
import java.net.URLDecoder;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Scanner;


public final class DataReader {

    public static void readClients() {
        URL urlClients = Thread.currentThread().getContextClassLoader().getResource("clients.omg");

        try {
            urlClients = new URL(URLDecoder.decode(urlClients.toString(), "utf-8"));
        } catch (Exception ex) {
            ex.printStackTrace();
        }

        File fileClients = new File(urlClients.getPath());

        DateFormat format = new SimpleDateFormat("yyyy-MM-dd");

        //934->>>>Елена---Водохлёбова\\\\Федоровна~~~~+79646546254==559253___1945-10-01==613027 (\n)
        //934  Елена  Водохлёбова  Федоровна  +79646546254  559253  1945-10-01  (not compulsory)613027

        try (Scanner scClients = new Scanner(fileClients)) {
            while (scClients.hasNext()) {
                String temp = scClients.next();
                String[] userArr = temp.split("((->>>>)|(---)|(~~~~)|(\\\\\\\\)|(==)|(___))");
                Client client = new Client();
                client.setId(Integer.parseInt(userArr[0]));
                client.setName(userArr[1]);
                client.setLastName(userArr[2]);
                client.setMiddleName(userArr[3]);
                client.setPhone(userArr[4]);
                client.setPassport(Integer.parseInt(userArr[5]));
                client.setBirthday(format.parse(userArr[6]));
                if (userArr.length > 7) {
                    client.setOldPassport(Integer.parseInt(userArr[7]));
                }
                DataStore.clients.add(client);
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    public static void readCredits() {
        URL urlCredits = Thread.currentThread().getContextClassLoader().getResource("credits.omg");

        try {
            urlCredits = new URL(URLDecoder.decode(urlCredits.toString(), "utf-8"));
        } catch (Exception ex) {
            ex.printStackTrace();
        }

        File fileCredits = new File(urlCredits.getPath());

        DateFormat format = new SimpleDateFormat("yyyy-MM-dd");

        //Credit{727|515584.72710622626,5.0%,269089.711338759^541363.9634615376___2012-12-31& (next credit)
        //727  515584.72710622626  5.0%  269089.711338759  541363.9634615376  2012-12-31

        try (Scanner scCredits = new Scanner(fileCredits).useDelimiter("&")) {
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
                DataStore.credits.add(credit);
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }
}
