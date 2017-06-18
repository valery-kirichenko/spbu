package com.bank.starter;

import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

/**
 * Created by gusef on 26.05.2017.
 */
public class MyBase {

    private HashMap<Integer,ArrayList<Credit>> mapOfCredits = new HashMap<>();
    private ArrayList<Client> listOfClients = new ArrayList<>();

    private static MyBase ourInstance = new MyBase();

    public static MyBase getInstance() {
        return ourInstance;
    }

    private MyBase() {
    }

    public ArrayList<Client> getListOfClients() {
        return listOfClients;
    }

    public void setListOfClients(ArrayList<Client> listOfClients) {
        this.listOfClients = listOfClients;
    }



    public void readCreditsFromFile(String name) throws IOException {
        String allFile = "";
        Scanner in = new Scanner(new File(name));
        while (in.hasNext())
            allFile += in.nextLine() + "\r\n";
        in.close();
        String[] creditsString = allFile.split("&");
        for (String str : creditsString
                ) {
            Credit cr = Credit.parse(str + "&");
            if (cr != null) {
                if (!mapOfCredits.containsKey(cr.getId()))
                    mapOfCredits.put(cr.getId(), new ArrayList<>());
                mapOfCredits.get(cr.getId()).add(cr);
            }
        }
    }

    void tryMerge(Client locClient){
        for (Client subClient: listOfClients
                ) {
            if(locClient.isEqualAndGreater(subClient)){
                listOfClients.remove(subClient);
                subClient.merge(locClient);
                locClient = subClient;
                break;
            }
        }
        for (Client subClient: listOfClients
             ) {
            if(subClient.isEqualAndGreater(locClient)){
                listOfClients.remove(subClient);
                locClient.merge(subClient);
                break;
            }
        }
        listOfClients.add(locClient);
        if(!mapOfCredits.containsKey(locClient.getNowId()))
            mapOfCredits.put(locClient.getNowId(),new ArrayList<>());
        for (Integer id: locClient.getOldId()
             ){
            if (!mapOfCredits.containsKey(id))
                mapOfCredits.put(id, new ArrayList<>());
        }
    }

    public int numberOfCredits(){
        int ans=0;
        for (ArrayList<Credit> subListOfCredits: mapOfCredits.values()
             ) {
            ans += subListOfCredits.size();
        }
        return ans;
    }

    public void readClientsFromFile(String name) throws IOException {
        String allFile = "";
        Scanner in = new Scanner(new File(name));
        while (in.hasNext()) {
            allFile = in.nextLine();
            Client locClient = Client.Parse(allFile);
            locClient.getName().replaceAll("ё","е");
            locClient.getName().replaceAll("Ё","Е");
            locClient.getLastName().replaceAll("ё","е");
            locClient.getLastName().replaceAll("Ё","Е");
            locClient.getSurName().replaceAll("ё","е");
            locClient.getSurName().replaceAll("Ё","Е");
            //listOfClients.add(locClient);
            tryMerge(locClient);
        }
        in.close();
    }

    public ArrayList<Credit> getListOfCredits(Client locClient){
        ArrayList<Credit> ans = new ArrayList<>();
        ans.addAll(mapOfCredits.get(locClient.getNowId()));
        for (int id: locClient.getOldId()
                ) {
            ans.addAll(mapOfCredits.get(id));
        }
        return ans;
    }

    public HashMap<Integer, ArrayList<Credit>> getMapOfCredits() {
        return mapOfCredits;
    }

    public void setMapOfCredits(HashMap<Integer, ArrayList<Credit>> mapOfCredits) {
        this.mapOfCredits = mapOfCredits;
    }
}
