package com.bank.starter.MyDataBase;

import com.bank.starter.Curency.Currency;
import com.bank.starter.Curency.CurrencyService;
import com.bank.starter.DataBaseSystem.ClientControllers.DBClientControler;
import com.bank.starter.DataBaseSystem.CreditControllers.DBCreditControler;
import com.bank.starter.models.Client;
import com.bank.starter.models.Credit;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.net.URLDecoder;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

/**
 * Created by gusef on 26.05.2017.
 */
@Service
public class MyBase implements MyDataBase {

    @Autowired
    private CurrencyService currencyService;

    @Autowired
    private DBClientControler clientsController;

    @Autowired
    private DBCreditControler creditsController;

    private int maxUserId = -1;
    private HashMap<Integer, ArrayList<Credit>> mapOfCredits = new HashMap<>();
    private ArrayList<Client> listOfClients = new ArrayList<>();
    private ArrayList<Credit> creditsWithoutClients = new ArrayList<>();

    private boolean notReaded = true;

    @Override
    public ArrayList<Client> getListOfClients() {
        return listOfClients;
    }

    @Override
    public void setListOfClients(ArrayList<Client> listOfClients) {
        this.listOfClients = new ArrayList<>();
        maxUserId = -1;
        for (Client subClient : listOfClients
                ) {
            tryMerge(subClient);
            maxUserId = Math.max(maxUserId, subClient.getNowId());
        }
    }

    private boolean merge(Client cl1, Client cl2) {
        if (cl1.isEqualAndGreater(cl2)) {
            if (!mapOfCredits.containsKey(cl1.getNowId()))
                mapOfCredits.put(cl1.getNowId(), new ArrayList<>());
            for (Credit subCredit: mapOfCredits.get(cl2.getNowId())
                 ) {
                subCredit.setId(cl1.getNowId());
            }
            mapOfCredits.get(cl1.getNowId()).addAll(mapOfCredits.get(cl2.getNowId()));
            if (mapOfCredits.containsKey(cl2.getNowId()))
                mapOfCredits.remove(cl2.getNowId());
            cl1.setOldPass(cl2.getOldPass());
            return true;
        }
        return false;
    }

    private double toDouble(String stringToParse){
        if(!stringToParse.contains("."))
            stringToParse += ".0";
        Scanner sc = new Scanner(stringToParse.replace("."," "));
        double a = sc.nextDouble(),b = sc.nextDouble();
        while(b>1)
            b /= 10;
        return a+b;
    }

    private Credit creditParse(String stringToParse) {
        if (stringToParse.toCharArray()[0] != 'C')
            return null;
        Credit tmpCredit = new Credit();

        stringToParse = stringToParse.substring(stringToParse.indexOf("Credit{") + 7);
        tmpCredit.setId(new Scanner(stringToParse.substring(0, stringToParse.indexOf("|"))).nextInt());

        stringToParse = stringToParse.substring(stringToParse.indexOf("|") + 1);
        tmpCredit.setStartSum(toDouble(stringToParse.substring(0, stringToParse.indexOf(","))));

        stringToParse = stringToParse.substring(stringToParse.indexOf(",") + 1);
        tmpCredit.setPercent(toDouble(stringToParse.substring(0, stringToParse.indexOf("%,"))));

        stringToParse = stringToParse.substring(stringToParse.indexOf("%,") + 2);
        tmpCredit.setPaidSum(toDouble(stringToParse.substring(0, stringToParse.indexOf("^"))));

        stringToParse = stringToParse.substring(stringToParse.indexOf("^") + 1);
        tmpCredit.setAllSum(toDouble(stringToParse.substring(0, stringToParse.indexOf("___"))));

        stringToParse = stringToParse.substring(stringToParse.indexOf("___") + 3, stringToParse.indexOf("&"));
        tmpCredit.setFinishDate(LocalDate.parse(stringToParse));
        return tmpCredit;
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
            Credit cr = creditParse(str + "&");
            if (cr != null) {
                if (!mapOfCredits.containsKey(cr.getId()))
                    mapOfCredits.put(cr.getId(), new ArrayList<>());
                mapOfCredits.get(cr.getId()).add(cr);
            }
        }
    }

    private Client clientParse(String stringToParse) {
        if (stringToParse.toCharArray()[0] < '0' || stringToParse.toCharArray()[0] > '9')
            stringToParse = stringToParse.substring(1);
        Scanner sc2 = new Scanner(stringToParse.substring(0, stringToParse.indexOf("->>>>")));
        Client tmpClient = new Client();
        tmpClient.setNowId(sc2.nextInt());
        tmpClient.setName(stringToParse.substring(stringToParse.lastIndexOf("->>>>") + 5, stringToParse.indexOf("---")));
        tmpClient.setSurName(stringToParse.substring(stringToParse.lastIndexOf("---") + 3, stringToParse.indexOf("\\\\")));
        tmpClient.setLastName(stringToParse.substring(stringToParse.lastIndexOf("\\\\") + 2, stringToParse.indexOf("~~~~")));
        tmpClient.setPhone(stringToParse.substring(stringToParse.lastIndexOf("~~~~") + 4, stringToParse.indexOf("==")));
        tmpClient.setPass(Integer.parseInt(stringToParse.substring(stringToParse.indexOf("==") + 2, stringToParse.indexOf("___"))));
        stringToParse = stringToParse.substring(stringToParse.lastIndexOf("___") + 3);
        if (stringToParse.contains("==")) {
            tmpClient.setBirthDate(LocalDate.parse(stringToParse.substring(0, stringToParse.indexOf("=="))));
            tmpClient.setOldPass(Integer.parseInt(stringToParse.substring(stringToParse.indexOf("==") + 2)));
        } else
            tmpClient.setBirthDate(LocalDate.parse(stringToParse));
        return tmpClient;
    }

    @Override
    public void tryMerge(Client locClient) {
        if (!mapOfCredits.containsKey(locClient.getNowId()))
            mapOfCredits.put(locClient.getNowId(), new ArrayList<>());
        ArrayList<Client> al = new ArrayList<>();
        for (Client subClient : listOfClients
                ) {
            if (locClient.isEqualAndGreater(subClient) || locClient.isEqual(subClient)) {
                merge(locClient, subClient);
                al.add(subClient);
            }
        }
        for (Client subClient : listOfClients
                ) {
            if (subClient.isEqualAndGreater(locClient) || locClient.isEqual(subClient)) {
                al.add(subClient);
                merge(subClient, locClient);
                locClient = subClient;
            }
        }
        listOfClients.removeAll(al);
        listOfClients.add(locClient);
    }

    @Override
    public int numberOfCredits() {
        int ans = 0;
        for (ArrayList<Credit> subListOfCredits : mapOfCredits.values()
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
            Client locClient = clientParse(allFile);
            locClient.setName(locClient.getName().replaceAll("ё", "е"));
            locClient.setName(locClient.getName().replaceAll("Ё", "Е"));
            locClient.setLastName(locClient.getLastName().replaceAll("ё", "е"));
            locClient.setLastName(locClient.getLastName().replaceAll("Ё", "Е"));
            locClient.setSurName(locClient.getSurName().replaceAll("ё", "е"));
            locClient.setSurName(locClient.getSurName().replaceAll("Ё", "Е"));

            //listOfClients.add(locClient);
            tryMerge(locClient);
            maxUserId = Math.max(maxUserId, locClient.getNowId());
        }
        in.close();
    }

    @Override
    public ArrayList<Credit> getListOfCredits(Client locClient) {
        if(mapOfCredits.containsKey(locClient.getNowId()))
            return mapOfCredits.get(locClient.getNowId());
        return new ArrayList<>();
    }

    @Override
    public HashMap<Integer, ArrayList<Credit>> getMapOfCredits() {
        return mapOfCredits;
    }

    @Override
    public void setMapOfCredits(HashMap<Integer, ArrayList<Credit>> mapOfCredits) {
        this.mapOfCredits = mapOfCredits;
    }

    @Override
    public int getFreeId() {
        maxUserId++;
        return maxUserId;
    }

    private boolean existClientWithId(Integer id){
        for (Client cl:listOfClients
             ) {
            if(id == cl.getNowId())
                return true;
        }
        return false;
    }

    @Override
    public void insertFromFile() {
        if (notReaded) {
            URL urlClients = Thread.currentThread().getContextClassLoader().getResource("clients.omg");
            URL urlCredits = Thread.currentThread().getContextClassLoader().getResource("credits.omg");
            try {
                urlClients = new URL(URLDecoder.decode(urlClients.toString(), "utf-8"));
                urlCredits = new URL(URLDecoder.decode(urlCredits.toString(), "utf-8"));
            } catch (Exception ex) {
                ex.printStackTrace();
            }
            try {
                readCreditsFromFile(urlCredits.getPath());
                readClientsFromFile(urlClients.getPath());
            } catch (IOException exp) {
                System.out.println("File not found!\r\n" + exp.toString());
            }
            System.out.println(numberOfCredits() + " " + getListOfClients().size());
            System.out.println(allNotPaidCredits().size());
            notReaded = false;
        }
        ArrayList<Integer> al = new ArrayList<>();
         for(Integer subKey: mapOfCredits.keySet()
                ) {
            if(!existClientWithId(subKey)){
                creditsWithoutClients.addAll(mapOfCredits.get(subKey));
                al.add(subKey);
            }
        }
        System.out.println(creditsWithoutClients.size());
        for (Integer subKey: al
             ) {
            mapOfCredits.remove(subKey);
        }
        for (Client subClient:listOfClients
             ) {
            clientsController.addNewClient(subClient);
        }
        for (ArrayList<Credit> subListOfCredits : mapOfCredits.values()
                ) {
            for (Credit subCredit : subListOfCredits
                    ) {
                creditsController.addNewCredit(subCredit);
            }
        }//*/
    }

    @Override
    public void setCredits(ArrayList<Credit> listOfCredits) {
        mapOfCredits = new HashMap<>();
        for (Credit subCredit : listOfCredits
                ) {
            if (!mapOfCredits.containsKey(subCredit.getId()))
                mapOfCredits.put(subCredit.getId(), new ArrayList<>());
            mapOfCredits.get(subCredit.getId()).add(subCredit);
        }
    }

    private ArrayList<Credit> copyAll(ArrayList<Credit> credits){
        ArrayList<Credit> al = new ArrayList<>();
        for (Credit cr: credits
             ) {
            Credit locCredit = new Credit();
            locCredit.setStartSum(new Double(cr.getStartSum()));
            locCredit.setFinishDate(cr.getFinishDate());
            locCredit.setId(cr.getId());
            locCredit.setPercent(new Double(cr.getPercent()));
            locCredit.setPaidSum(new Double(cr.getPaidSum()));
            locCredit.setAllSum(new Double(cr.getAllSum()));
            al.add(locCredit);
        }
        return al;
    }

    @Override
    public ArrayList<Credit> getListOfCreditsWithChangedValues(Currency newCurrency, Integer id) {
        ArrayList<Credit> ans = new ArrayList<>(creditsController.getListOfCredits(id));
        if (!newCurrency.equals(Currency.RUB)) {
            Double multiplication = currencyService.getRate(Currency.RUB, newCurrency);
            for (Credit credit : ans) {
                credit.setStartSum(credit.getStartSum() * multiplication);
                credit.setAllSum(credit.getAllSum() * multiplication);
                credit.setPaidSum(credit.getPaidSum() * multiplication);
            }
        }

        return ans;
    }

    @Override
    public double allDebt(Client cl) {
        double ans = 0;
        for (Credit subCredit : mapOfCredits.get(cl.getNowId())
                ) {
            if (subCredit.getAllSum() < subCredit.getPaidSum())
                ans += subCredit.getAllSum() - subCredit.getPaidSum();
        }
        return ans;
    }

    @Override
    public ArrayList<Credit> debtCredits(Client cl) {
        ArrayList<Credit> ans = new ArrayList<>();
        if(mapOfCredits.containsKey(cl.getNowId())) {
            for (Credit subCredit : mapOfCredits.get(cl.getNowId())
                    ) {
                if (subCredit.isNotPaid())
                    ans.add(subCredit);
            }
        }
        return ans;
    }

    @Override
    public ArrayList<Credit> allNotPaidCredits() {
        ArrayList<Credit> ans = new ArrayList<>();
        for (ArrayList<Credit> subListOfCredits : mapOfCredits.values()
                ) {
            for (Credit subCredit : subListOfCredits
                    ) {
                if (subCredit.isNotPaid())
                    ans.add(subCredit);
            }
        }
        return ans;
    }
}
