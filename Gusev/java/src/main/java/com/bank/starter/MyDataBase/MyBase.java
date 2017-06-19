package com.bank.starter.MyDataBase;

import com.bank.starter.Curency.Currency;
import com.bank.starter.Curency.CurrencyService;
import com.bank.starter.models.Client;
import com.bank.starter.models.Credit;
import com.bank.starter.workStorrage.ClientWorkPlace;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Service;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

/**
 * Created by gusef on 26.05.2017.
 */
@Service
public class MyBase implements SingletonDataBase {

    @Autowired
    private JdbcTemplate template;

    @Autowired
    private CurrencyService currencyService;

    private int maxUserId = -1;
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
        this.listOfClients = new ArrayList<>();
        maxUserId = -1;
        for (Client subClient: listOfClients
             ) {
            tryMerge(subClient);
            maxUserId = Math.max(maxUserId,subClient.getNowId());
        }
    }


    @Override
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

    @Override
    public void tryMerge(Client locClient){
        if(!mapOfCredits.containsKey(locClient.getNowId()))
            mapOfCredits.put(locClient.getNowId(),new ArrayList<>());
        ArrayList<Client> al = new ArrayList<>();
        for (Client subClient: listOfClients
                ) {
            if(locClient.isEqualAndGreater(subClient) || locClient.isEqual(subClient)){
                locClient.merge(subClient);
                al.add(subClient);
            }
        }
        for (Client subClient: listOfClients
             ) {
            if(subClient.isEqualAndGreater(locClient) || locClient.isEqual(subClient)){
                al.add(subClient);
                subClient.merge(locClient);
                locClient = subClient;
            }
        }
        listOfClients.removeAll(al);
        listOfClients.add(locClient);
    }

    @Override
    public int numberOfCredits(){
        int ans=0;
        for (ArrayList<Credit> subListOfCredits: mapOfCredits.values()
             ) {
            ans += subListOfCredits.size();
        }
        return ans;
    }

    @Override
    public void readClientsFromFile(String name) throws IOException {
        String allFile;
        Scanner in = new Scanner(new File(name));
        while (in.hasNext()) {
            allFile = in.nextLine();
            Client locClient = Client.Parse(allFile);
            locClient.setName(locClient.getName().replaceAll("ё","е"));
            locClient.setName(locClient.getName().replaceAll("Ё","Е"));
            locClient.setLastName(locClient.getLastName().replaceAll("ё","е"));
            locClient.setLastName(locClient.getLastName().replaceAll("Ё","Е"));
            locClient.setSurName(locClient.getSurName().replaceAll("ё","е"));
            locClient.setSurName(locClient.getSurName().replaceAll("Ё","Е"));

            //listOfClients.add(locClient);
            tryMerge(locClient);
            maxUserId = Math.max(maxUserId,locClient.getNowId());
        }
        in.close();
    }

    @Override
    public ArrayList<Credit> getListOfCredits(Client locClient){
        return mapOfCredits.get(locClient.getNowId());
    }

    public HashMap<Integer, ArrayList<Credit>> getMapOfCredits() {
        return mapOfCredits;
    }

    public void setMapOfCredits(HashMap<Integer, ArrayList<Credit>> mapOfCredits) {
        this.mapOfCredits = mapOfCredits;
    }

    public int getFreeId(){
        maxUserId++;
        return maxUserId;
    }

    private boolean notReaded =true;

    public void insertFromFile(){
        if(notReaded) {
            URL urlClients = Thread.currentThread().getContextClassLoader().getResource("clients.omg");
            URL urlCredits = Thread.currentThread().getContextClassLoader().getResource("credits.omg");
            try {
                readCreditsFromFile(urlCredits.getPath());
                readClientsFromFile(urlClients.getPath());
            } catch (IOException exp) {
                System.out.println("File not found!\r\n" + exp.toString());
            }
            System.out.println(MyBase.getInstance().numberOfCredits() + " " + MyBase.getInstance().getListOfClients().size());
            ClientWorkPlace work = new ClientWorkPlace();
            System.out.println(work.allNotPaidCredits().size());
            notReaded = false;
        }
    }

    public void setCredits(ArrayList<Credit> listOfCredits){
        mapOfCredits = new HashMap<>();
        for (Credit subCredit:listOfCredits
             ) {
            if(!mapOfCredits.containsKey(subCredit.getId()))
                mapOfCredits.put(subCredit.getId(),new ArrayList<>());
            mapOfCredits.get(subCredit.getId()).add(subCredit);
        }
    }

    public ArrayList<Credit> getListOfCreditsWithChangedValues(Currency newCurrency, Integer Id){
        ArrayList<Credit> ans = mapOfCredits.get(Id);
        if(ans != null){
            if (!newCurrency.equals(Currency.RUB)){
                Double multiplication = currencyService.getRate(Currency.RUB, newCurrency);
                for (Credit credit : ans) {
                    credit.setStartSum(Double.toString(credit.getStartSum() * multiplication));
                    credit.setAllSum(Double.toString(credit.getAllSum() * multiplication));
                    credit.setPaidSum(Double.toString(credit.getPaidSum() * multiplication));
                }
            }
        }
        else
            ans = new ArrayList<>();
        return ans;
    }
}
