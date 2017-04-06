package com.DataBase;

import java.io.File;
import java.io.FileNotFoundException;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


/**
 * Created by Я on 17.03.2017.
 */
class GettingClientsFromFile {


    List<Clients> getClient() throws ParseException, FileNotFoundException {


        String str1;
        Scanner sc1 = new Scanner(new File("clients.omg"));
        List<Clients> listClients = new ArrayList<Clients>();
        while (sc1.hasNextLine()) {
            str1 = sc1.nextLine();
            String arr1[] = str1.split("->>>>|---|\\\\\\\\|~~~~|==|___");
            if (arr1.length == 8) {
                Clients cl = null;
                cl = new Clients(arr1[0], arr1[1], arr1[2], arr1[3], arr1[4], arr1[5], arr1[6], arr1[7]);
                listClients.add(cl);
            }
            if (arr1.length == 7) {
                Clients cl = new Clients(arr1[0], arr1[1], arr1[2], arr1[3], arr1[4], arr1[5], arr1[6], "");
                listClients.add(cl);
            }
        }


        return listClients;
    }
}


