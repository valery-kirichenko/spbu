package com.NewDataBase;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.io.File;
import java.io.FileNotFoundException;
import java.net.URL;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


/**
 * Created by Я on 17.03.2017.
 */
@Service
public class GettingClientFromFileImpl implements GettingClientFromFile {

    @Autowired
    MergeClientAndCredit merge;
    @Autowired
    GetCreditFromFileImpl getListCredit;
    @Override
    public List<Clients> getClient() throws ParseException, FileNotFoundException {

        String str1;
        URL url = Thread.currentThread().getContextClassLoader().getResource("clients.omg");
        Scanner sc1 = new Scanner(new File(url.getPath()));
        List<Clients> listClients = new ArrayList<Clients>();
        while (sc1.hasNextLine()) {
            str1 = sc1.nextLine();
            String arr1[] = str1.split("->>>>|---|\\\\\\\\|~~~~|==|___");
            if (arr1.length == 8) {
                if(arr1[0]!=""&& arr1[1]!=""&& arr1[2]!=""&& arr1[3]!=""&& arr1[4]!=""&& arr1[5]!=""&& arr1[6]!=""&& arr1[7]!="") {
                    Clients client = new Clients(arr1[0], arr1[1], arr1[2], arr1[3], arr1[4], arr1[5], arr1[6], arr1[7]);
                    listClients.add(client);
                }
            }
            if (arr1.length == 7) {
                if(arr1[0]!=""&& arr1[1]!=""&& arr1[2]!=""&& arr1[3]!=""&& arr1[4]!=""&& arr1[5]!=""&& arr1[6]!="") {
                    Clients cl = new Clients(arr1[0], arr1[1], arr1[2], arr1[3], arr1[4], arr1[5], arr1[6], "");
                    listClients.add(cl);
                }
            }
        }
        merge.getMerge(listClients,getListCredit.getCredit());
        merge.getReplace(listClients);
        return listClients;
    }
}