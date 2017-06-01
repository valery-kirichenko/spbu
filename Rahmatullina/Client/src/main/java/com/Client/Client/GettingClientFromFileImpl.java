package com.Client.Client;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.io.File;
import java.io.FileNotFoundException;
import java.net.URL;
import java.net.URLDecoder;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


@Service
public class GettingClientFromFileImpl implements GettingClientFromFile {

    @Autowired
    MergeClientAndCredit merge;
    @Autowired
    GetCreditFromFileImpl getListCredit;

    @Override
    public List<Clients> getClient() throws FileNotFoundException {

        String str1;
        URL url = Thread.currentThread().getContextClassLoader().getResource("clients.omg");
        try {
            url = new URL(URLDecoder.decode(url.toString(), "utf-8"));
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        Scanner sc1 = new Scanner(new File(url.getPath()));
        List<Clients> listClients = new ArrayList<Clients>();
        while (sc1.hasNextLine()) {
            str1 = sc1.nextLine();
            String arr1[] = str1.split("->>>>|---|\\\\\\\\|~~~~|==|___");
            if (arr1.length == 8) {
                Clients client = new Clients();
                client.setId(Integer.parseInt(arr1[0]));
                client.setName(arr1[1]);
                client.setSurName(arr1[2]);
                client.setMidName(arr1[3]);
                client.setPhone(arr1[4]);
                client.setNewPassport(arr1[5]);
                client.setData(arr1[6]);
                client.setOldPassport(arr1[7]);
                listClients.add(client);
            }
            if (arr1.length == 7) {
                Clients client = new Clients();
                client.setId(Integer.parseInt(arr1[0]));
                client.setName(arr1[1]);
                client.setSurName(arr1[2]);
                client.setMidName(arr1[3]);
                client.setPhone(arr1[4]);
                client.setNewPassport(arr1[5]);
                client.setData(arr1[6]);
                client.setOldPassport("");
                listClients.add(client);
            }

        }
        merge.getMerge(listClients, getListCredit.getCredit());
        merge.getReplace(listClients);
        return listClients;
    }
}