package com.example.CreditBase1;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import java.util.Locale;


public class ClientHelperRealization implements ClientHelper {
    @Override
    public void clientsList(List<Credits> credits, List<Clients> clients) {
        Locale local = new Locale("ru", "RU");
        DateFormat df = DateFormat.getDateInstance(DateFormat.DEFAULT, local);
        Date currentDate = new Date();
        System.out.println("currentDate = " + df.format(currentDate));

        SimpleDateFormat format = new SimpleDateFormat();
        format.applyPattern("dd.MM.yyyy");

        Date date = new Date();

        int k;

        System.out.println("\nСписок пользователей с невыплаченными кредитами:\n");

        for (int i = 0; i < clients.size(); i++) {
            k = 0;
            for (int j = 0; j < clients.get(i).getCreditsList().size(); j++) {
                try {
                    date = format.parse(clients.get(i).getCreditsList().get(j).getDate());
                } catch (ParseException ex) {
                    System.out.println("Это не должно произойти");
                }

                if (Double.parseDouble(clients.get(i).getCreditsList().get(j).getVyp()) <
                        Double.parseDouble(clients.get(i).getCreditsList().get(j).getOst()) &&
                        currentDate.compareTo(date) == -1) {
                    k++;
                }
            }
            if (k > 0)
                System.out.println(clients.get(i).getId() + " " + clients.get(i).getName() + " " +
                        clients.get(i).getOt() + " " + clients.get(i).getFam() + " " + clients.get(i).getSot() +
                        " " + clients.get(i).getPas1() + " " + clients.get(i).getDate() + " " +
                        clients.get(i).getPas2() + " ");
        }
    }

    @Override
    public void creditsList(List<Credits> credits, List<Clients> clients) {

        System.out.println("Список невыплаченных кредитов пользователей:");
        Locale local = new Locale("ru", "RU");
        DateFormat df = DateFormat.getDateInstance(DateFormat.DEFAULT, local);
        Date currentDate = new Date();
        System.out.println("currentDate = " + df.format(currentDate));

        SimpleDateFormat format = new SimpleDateFormat();
        format.applyPattern("dd.MM.yyyy");

        Date date = new Date();

        int k;


        for (int i = 0; i < clients.size(); i++) {
            k = 0;
            System.out.println(clients.get(i).getId() + " " + clients.get(i).getName() + " " + clients.get(i).getOt() +
                    " " + clients.get(i).getFam() + " " + clients.get(i).getSot() + " " + clients.get(i).getPas1() +
                    " " + clients.get(i).getDate() + " " + clients.get(i).getPas2() + " ");
            System.out.println("Не выплатил(а):\n");
            for (int j = 0; j < clients.get(i).getCreditsList().size(); j++) {
                try {
                    date = format.parse(clients.get(i).getCreditsList().get(j).getDate());
                } catch (ParseException ex) {
                    System.out.println("Это не должно произойти");
                }
                if (Double.parseDouble(clients.get(i).getCreditsList().get(j).getVyp()) <
                        Double.parseDouble(clients.get(i).getCreditsList().get(j).getOst())
                        && currentDate.compareTo(date) == -1) {
                    System.out.println(clients.get(i).getCreditsList().get(j).getId() + " "
                            + clients.get(i).getCreditsList().get(j).getSum() + " " +
                            clients.get(i).getCreditsList().get(j).getPer() + " "
                            + clients.get(i).getCreditsList().get(j).getVyp() + " "
                            + clients.get(i).getCreditsList().get(j).getOst() + "\n");
                    k++;
                }
            }
            if (k == 0)
                System.out.println("---------------------------\n");
        }
    }


    @Override
    public void total(List<Credits> credits, List<Clients> clients) {
        System.out.println("Общая сумма задолжности пользователей перед банком:\n");
        Locale local = new Locale("ru", "RU");
        DateFormat df = DateFormat.getDateInstance(DateFormat.DEFAULT, local);
        Date currentDate = new Date();
        System.out.println("currentDate = " + df.format(currentDate));

        SimpleDateFormat format = new SimpleDateFormat();
        format.applyPattern("dd.MM.yyyy");

        Date date = new Date();

        double k;


        for (int i = 0; i < clients.size(); i++) {
            k = 0;
            System.out.println(clients.get(i).getId() + " " + clients.get(i).getName() + " " +
                    clients.get(i).getOt() + " " + clients.get(i).getFam() + " " + clients.get(i).getSot() + " " +
                    clients.get(i).getPas1() + " " + clients.get(i).getDate() + " " + clients.get(i).getPas2() + " ");
            System.out.println("Должен(на) банку:\n");
            for (int j = 0; j < clients.get(i).getCreditsList().size(); j++) {
                try {
                    date = format.parse(clients.get(i).getCreditsList().get(j).getDate());
                } catch (ParseException ex) {
                    System.out.println("Это не должно произойти");
                }
                if (Double.parseDouble(clients.get(i).getCreditsList().get(j).getVyp()) <
                        Double.parseDouble(clients.get(i).getCreditsList().get(j).getOst())
                        && currentDate.compareTo(date) == -1) {
                    k += (Double.parseDouble(clients.get(i).getCreditsList().get(j).getOst()) -
                            Double.parseDouble(clients.get(i).getCreditsList().get(j).getVyp()));
                }
            }
            if (k == 0)
                System.out.println("0 рублей\n");
            else
                System.out.println(k + " рублей\n");
        }
    }
}
