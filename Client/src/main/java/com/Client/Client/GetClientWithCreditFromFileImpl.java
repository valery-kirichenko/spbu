package com.Client.Client;


import org.springframework.stereotype.Service;

import java.io.File;
import java.io.FileNotFoundException;
import java.net.URL;
import java.net.URLDecoder;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Scanner;


@Service
public class GetClientWithCreditFromFileImpl implements GetClientWithCreditFromFile {
    private List<Clients> clientsList = new ArrayList<>();
    private List<Credits> creditsList = new ArrayList<>();


    @Override
    public List<Credits> getCredit() throws FileNotFoundException {
        String str2;
        URL url = Thread.currentThread().getContextClassLoader().getResource("credits.omg");
        try {
            url = new URL(URLDecoder.decode(url.toString(), "utf-8"));
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        Scanner sc2 = new Scanner(new File(url.getPath())).useDelimiter("&");
        List<Credits> listCredits = new ArrayList<>();
        while (sc2.hasNext()) {
            str2 = sc2.next();
            String arr2[] = str2.split("Credit\\{|\\||,|%,|\\^|___");//длина = 7 arr2[0] - пустой
            Credits credit = new Credits();
            credit.setId(Integer.parseInt(arr2[1]));
            credit.setLoan(arr2[2]);
            credit.setPercent(arr2[3]);
            credit.setPaidSum(arr2[4]);
            credit.setWholeLoan(arr2[5]);
            credit.setDataString(arr2[6]);
            credit.setCreditId("");
            listCredits.add(credit);
        }

        return listCredits;
    }

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
        List<Clients> listClients = new ArrayList<>();
        while (sc1.hasNextLine()) {
            str1 = sc1.nextLine();
            String arr1[] = str1.split("->>>>|---|\\\\\\\\|~~~~|==|___");
            Clients client = new Clients();
            client.setId(Integer.parseInt(arr1[0]));
            client.setName(arr1[1]);
            client.setSurName(arr1[2]);
            client.setMidName(arr1[3]);
            client.setPhone(arr1[4]);
            client.setNewPassport(arr1[5]);
            client.setData(arr1[6]);
            if (arr1.length == 8) {
                client.setOldPassport(arr1[7]);
            } else {
                client.setOldPassport("");
            }
            listClients.add(client);

        }
        return listClients;
    }

    @Override
    public void getMerge(List<Clients> clients, List<Credits> credits) {
        for (Clients client1 : clients) {
            for (Clients client2 : clients) {
                if (!client1.equals(client2) && !client1.isDeleted && !client2.isDeleted) {
                    if (Objects.equals(client1.getNewPassport(), client2.getNewPassport())) {
                        for (Credits credit2 : client2.getCredits()) {
                            credit2.setId(client1.getId());
                        }
                        client2.isDeleted = Boolean.TRUE;
                        break;
                    } else if (Objects.equals(client1.getOldPassport(), client2.getNewPassport())) {
                        for (Credits credit2 : client2.getCredits()) {
                            credit2.setId(client1.getId());
                        }
                        client2.isDeleted = Boolean.TRUE;
                        break;
                    }
                }
            }
        }

        List<Clients> newClients = new ArrayList<>();
        for (Clients client : clients)
            if (!client.isDeleted)
                newClients.add(client);
        clients = newClients;


        List<Credits> newCredits = new ArrayList<>();

        for (Credits credit : credits) {
            if (getNameFromID(credit.getId(), clients) != null)
                newCredits.add(credit);

        }
        credits = newCredits;

        for (Clients client : clients)
            for (Credits credit : credits)
                if (Objects.equals(credit.getId(), client.getId()))
                    client.addCredit(credit);
        clientsList = clients;
        creditsList = credits;
    }

    public void getReplace() {
        for (Clients client : clientsList) {
            if (client.getName().contains("ё"))
                client.setName(client.getName().replace("ё", "е"));
            if (client.getSurName().contains("ё"))
                client.setSurName(client.getSurName().replace("ё", "е"));
            if (client.getMidName().contains("ё"))
                client.setMidName(client.getMidName().replace("ё", "е"));
        }
    }

    @Override
    public String getNameFromID(Integer ID, List<Clients> clients) {
        String result = null;
        for (Clients client : clients)
            if (Objects.equals(ID, client.getId())) {
                result = client.getName() + " " + client.getMidName() + " " + client.getSurName();
            }
        return result;
    }

    @Override
    public void mainMerge() throws FileNotFoundException {
        getMerge(getClient(), getCredit());
        getReplace();
    }

    @Override
    public List<Clients> getClientsList() {
        return clientsList;
    }

    @Override
    public List<Credits> getCreditsList() {
        return creditsList;
    }
}