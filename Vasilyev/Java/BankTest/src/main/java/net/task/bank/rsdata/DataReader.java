package net.task.bank.rsdata;

import net.task.bank.models.Client;
import net.task.bank.models.Credit;

import java.io.File;
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;


public class DataReader implements Reader {
    public List<Client> readClients(File fileClients) {
        List<Client> clients = new ArrayList<>();

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MMM-dd");
        formatter = formatter.withLocale(Locale.getDefault());

        //934->>>>Елена---Водохлёбова\\\\Федоровна~~~~+79646546254==559253___1945-10-01==613027 (\n)
        //934  Елена  Водохлёбова  Федоровна  +79646546254  559253  1945-10-01  (not compulsory)613027

        try (Scanner scClients = new Scanner(fileClients)) {
            while (scClients.hasNext()) {
                String temp = scClients.next();
                String[] userArr = temp.split("((->>>>)|(---)|(~~~~)|(\\\\\\\\)|(==)|(___))");
                Client client = new Client();
                client.setID(Integer.parseInt(userArr[0]));
                client.setFirstName(userArr[1]);
                client.setLastName(userArr[2]);
                client.setMiddleName(userArr[3]);
                client.setPhone(userArr[4]);
                client.setPassport(userArr[5]);
                client.setBirthday(LocalDate.parse(userArr[6]));
                if (userArr.length > 7) {
                    client.setOldPassport(userArr[7]);
                }
                clients.add(client);
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }

        return clients;
    }

    public List<Credit> readCredits(File fileCredits) {
        List<Credit> credits = new ArrayList<>();

        DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MMM-dd");
        formatter = formatter.withLocale(Locale.getDefault());

        //Credit{727|515584.72710622626,5.0%,269089.711338759^541363.9634615376___2012-12-31& (next credit)
        //727  515584.72710622626  5.0%  269089.711338759  541363.9634615376  2012-12-31

        try (Scanner scCredits = new Scanner(fileCredits).useDelimiter("&")) {
            while (scCredits.hasNext()) {
                String temp = scCredits.next();
                String[] userArr = temp.split("((\\|)|,|(\\^)|(___))");
                Credit credit = new Credit();
                credit.setClientId(Integer.parseInt(userArr[0].substring(7)));
                credit.setAmount(Double.parseDouble(userArr[1]));
                credit.setPercent(Double.parseDouble(userArr[2].substring(0, userArr[2].length() - 2)));
                credit.setPaidSum(Double.parseDouble(userArr[3]));
                credit.setNeedPaid(Double.parseDouble(userArr[4]));
                credit.setClosingDate(LocalDate.parse(userArr[5]));
                credits.add(credit);
            }
        } catch (Exception ex) {
            ex.printStackTrace();
        }

        return credits;
    }
}
