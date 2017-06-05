package com.DataBase;

import jdk.nashorn.internal.runtime.regexp.joni.Regex;

import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

/**
 * Created by Я on 10.03.2017.
 */
public class DataBase {
    public static final String FILE_PATH1 = "C:\\Users\\Я\\Desktop\\Emiliya\\SPbU\\Rahmatullina\\ExamplesSPBU\\src\\main\\resources\\clients.omg";
    public static final String FILE_PATH2 = "C:\\Users\\Я\\Desktop\\Emiliya\\SPbU\\Rahmatullina\\ExamplesSPBU\\src\\main\\resources\\credits.omg";
    public static String str1, str2;

    public static void merge(List<Clients> listClient, List<Credits> listCredit) {

        int N = listClient.size();
        int K = listCredit.size();
        for (int j = 0; j < N; j++)
            for (int i = 0; i < K; i++) {
                if (listClient.get(j).id.equals(listCredit.get(i).id)) {
                    listClient.get(j).credit.add(listCredit.get(i));
                }
            }

        for (int j = 0; j < N; j++)
            for (int i = 0; i < N ; i++) {
                if (i!=j && listClient.get(j).newPassport.equals(listClient.get(i).newPassport)) {
                    int count = listClient.get(i).credit.size();
                    for (int t = 0; t < count; t++)
                        listClient.get(j).credit.add(listClient.get(i).credit.get(t));
                    listClient.remove(i);
                    if(i<j)j--;
                    N--;
                }
            }

        for (int j = 0; j < N; j++)
            for (int i = 0; i < N; i++) {
                if (listClient.get(j).oldPassport.equals(listClient.get(i).newPassport)) {
                    int count = listClient.get(i).credit.size();
                    for (int t = 0; t < count; t++)
                        listClient.get(j).credit.add(listClient.get(i).credit.get(t));
                    listClient.remove(i);
                    if(i<j) j--;
                    N--;
                }

            }

    }

    public static void replace(List<Clients> listClient) {
        int N = listClient.size();
        for (int i = 0; i < N; i++) {
            if (listClient.get(i).name.contains("ё"))
                listClient.get(i).name = listClient.get(i).name.replace("ё", "е");
            if (listClient.get(i).surName.contains("ё"))
                listClient.get(i).surName = listClient.get(i).surName.replace("ё", "е");
        }

    }

    public static void show(List<Clients> listClient) {
        int N = listClient.size();
        for (int i = 0; i < N; i++) {
            int k = listClient.get(i).credit.size();
            System.out.println(listClient.get(i).name + " " + listClient.get(i).surName + "  Passport : " +
            listClient.get(i).newPassport);
            System.out.println("This Client has " + k + "credits ");
        }
    }

    public static void expiryOfCredit1(List<Clients> listClient) {
        int N = listClient.size();
        for (int i = 0; i < N; i++) {
            boolean have = false;
            System.out.println( listClient.get(i).id + " "+ listClient.get(i).name + " " +
                    listClient.get(i).surName + " " + listClient.get(i).midName +
                    " Passport : " + listClient.get(i).newPassport + " His expiry credits : " );
            int k = listClient.get(i).credit.size();
            Date now;
            for (int t = 0; t < k; t++) {
                now = new Date();
                float wholeLoan = Float.parseFloat(listClient.get(i).credit.get(t).wholeloan);
                float paidSumm = Float.parseFloat(listClient.get(i).credit.get(t).paidSum);
                if (now.after(listClient.get(i).credit.get(t).data) && paidSumm < wholeLoan) {
                    System.out.println(listClient.get(i).credit.get(t).data +
                            ".He paid :" + paidSumm + " .His whole loan : " + wholeLoan);
                    have = true;
                }
            }
            if(have == false) System.out.println(" This Client Doesn't have expiry credits !");
        }



    }
    public static void expiryOfCredit2(List<Clients> listClient){
        int N = listClient.size();
        for (int i = 0; i < N; i++) {
            int k = listClient.get(i).credit.size();
            Date now;
            for (int t = 0; t < k; t++) {
                now = new Date();
                float wholeLoan = Float.parseFloat(listClient.get(i).credit.get(t).wholeloan);
                float paidSumm = Float.parseFloat(listClient.get(i).credit.get(t).paidSum);
                if (now.after(listClient.get(i).credit.get(t).data) && paidSumm < wholeLoan)
                    System.out.println(listClient.get(i).credit.get(t).id + " .The whole loan : " + wholeLoan
                            + " .Client paid : " + paidSumm + ".The expity of date : " + listClient.get(i).credit.get(t).data);
            }
        }
    }
    public static void expiryOfCredit3(List<Clients> listClient){
        int N = listClient.size();
        for (int i = 0; i < N; i++) {
            int k = listClient.get(i).credit.size();
            Date now;
            float debt = 0;
            for (int t = 0; t < k; t++) {
                now = new Date();
                float wholeLoan = Float.parseFloat(listClient.get(i).credit.get(t).wholeloan);
                float paidSumm = Float.parseFloat(listClient.get(i).credit.get(t).paidSum);
                if (now.after(listClient.get(i).credit.get(t).data) && paidSumm < wholeLoan)
                    debt+=wholeLoan-paidSumm;
            }
            System.out.println(listClient.get(i).name + " " + listClient.get(i).surName + " has debt : " + debt + "!");
            }
        }

    public static void main(String[] args) throws ParseException {
        try {
            Scanner sc1 = new Scanner(new File(FILE_PATH1));
            List<Clients> listClient = new ArrayList<Clients>();
            while (sc1.hasNextLine()) {
                str1 = sc1.nextLine();
                String arr1[] = str1.split("->>>>|---|\\\\\\\\|~~~~|==|___");
                if (arr1.length == 8) {
                    Clients cl = new Clients(arr1[0], arr1[1], arr1[2], arr1[3], arr1[4], arr1[5], arr1[6], arr1[7]);
                    listClient.add(cl);
                }
                if (arr1.length == 7) {
                    Clients cl = new Clients(arr1[0], arr1[1], arr1[2], arr1[3], arr1[4], arr1[5], arr1[6], "");
                    listClient.add(cl);
                }
            }



        ////////////////////////////////////created client dataBase/////////////////////////////////////
            Scanner sc2 = new Scanner(new File(FILE_PATH2)).useDelimiter("&");
            List<Credits> listCredit = new ArrayList<Credits>();
            while (sc2.hasNext()) {
                str2 = sc2.next();
                String arr2[] = str2.split("Credit\\{|\\||,|%,|\\^|___");//длина = 7 arr2[0] - пустой
                Credits cr = new Credits(arr2[1], arr2[2], arr2[3], arr2[4], arr2[5], arr2[6]);
                listCredit.add(cr);
            }

            merge(listClient, listCredit);
            replace(listClient);
            int temp=0;
            System.out.println("Press 1 - to show the list clients who has debt ");
            System.out.println("Press 2 - to show the list credits who has debt ");
            System.out.println("Press 3 - to show the clients and their sum of debt ");
            System.out.println("Press 4 - to show the clients and their credits ");
            Scanner in = new Scanner(System.in);
            temp = in.nextInt();
            switch(temp) {
                case 1 :{
                    expiryOfCredit1(listClient);
                    //show(listClient);
                    break;
                }
                case 2 :{
                    expiryOfCredit2(listClient);
                    break;
                }
                case 3 :{
                    expiryOfCredit3(listClient);
                    break;
                }
                case 4 :{
                    show(listClient);
                    break;
                }
            }


        } catch (FileNotFoundException e) {
            e.printStackTrace();
            System.out.println("Error");
        }
    }

    private static class Clients {
        public String id;
        public String name;
        public String surName;
        public String midName;
        public String phone;
        public String newPassport;
        public String oldPassport;
        public DateFormat format;
        public Date data;
        public List<Credits> credit;

        public Clients(String i, String nm, String surNm, String midNm, String ph, String newPas, String dt, String oldPas) throws ParseException {

            id = i;
            name = nm;
            surName = surNm;
            midName = midNm;
            phone = ph;
            oldPassport = oldPas;
            newPassport = newPas;
            credit = new ArrayList<Credits>();
            format = new SimpleDateFormat("yyyy-MM-dd");
            data = format.parse(dt);
        }

    }

    private static class Credits {
        public String id;
        public String loan;
        public String percent;
        public String paidSum;
        public String wholeloan;
        public DateFormat format;
        public Date data;

        public Credits(String i, String ln, String perc, String pSum, String whloan, String dt) throws ParseException {
            id = i;
            loan = ln;
            percent = perc;
            paidSum = pSum;
            wholeloan = whloan;
            format = new SimpleDateFormat("yyyy-MM-dd");
            data = format.parse(dt);
        }
    }
}
