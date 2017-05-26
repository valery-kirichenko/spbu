package com.client;

import org.springframework.stereotype.Service;

import java.io.File;
import java.net.URL;
import java.time.LocalDate;
import java.util.*;

@Service
public class Machine {

    private List<Client> allClients;
    private List<Client> oldCl;
    private List<Credit> oldCr;

    public List<Client> getAllClients() {
        allClients = new ArrayList<>();
        oldCl = getClientList();
        oldCr = getCreditsList();
        sort(oldCl);
        assembler(oldCl, oldCr);
        hotConvert(allClients);
        sort(allClients);
        return allClients;
    }


    private void recursion(List<Client> clients, int number) {
        if (Objects.equals(clients.get(number).getPassport(), clients.get(number + 1).getPassport())) {
            clients.get(number + 1).getCredits().addAll(clients.get(number).getCredits());
            clients.remove(number);
            recursion(clients, number);
        }
    }

    private void hotConvert(List<Client> clients) {
        Integer index;
        boolean isOver = false;
        int i;
        clients.sort((o1, o2) -> {
            if (Integer.parseInt(o1.getPassport()) > Integer.parseInt(o2.getPassport())) return 1;
            else return -1;
        });
        i = 0;
        while (!isOver) {
            try {
                recursion(clients, i);
                i++;
            } catch (Exception e) {
                isOver = true;
            }
        }
        List<Integer> passportsList = new ArrayList<>();
        for (Client client : clients) {
            passportsList.add(Integer.parseInt(client.getPassport()));
        }

        Integer passports[] = new Integer[passportsList.size()];
        passports = passportsList.toArray(passports);

        for (i = 0; i < clients.size(); i++) {
            if (!clients.get(i).getOldPassport().equals("NULL")) {
                index = Arrays.binarySearch(passports, Integer.parseInt(clients.get(i).getOldPassport()));
                if (index > -1) {
                    clients.get(index).getCredits().addAll(clients.get(i).getCredits());
                    clients.remove(i);
                }
            }

        }

    }

    private void sort(List<Client> clients) {
        clients.sort((o1, o2) -> {
            if (o1.getId() > o2.getId()) return 1;
            else return -1;
        });
    }

    private void assembler(List<Client> clients, List<Credit> credits) {
        Integer index;
        allClients.addAll(clients);
        Integer ids[] = allClients.stream().map(Client::getId).toArray(Integer[]::new);
        for (Credit credit : credits) {
            index = Arrays.binarySearch(ids, credit.getClientID());
            if (index > -1) {
                allClients.get(index).getCredits().add(credit);
            }
        }
    }

    private List<Client> getClientList() {
        List<Client> clients = new ArrayList<>();
        URL PATH = Thread.currentThread().getContextClassLoader().getResource("clients.omg");
        File fileClients = new File(PATH.getPath());
        Scanner fileScannerForClients = null;
        Scanner lineScannerForClients;
        String stringForClients;
        String name;
        Integer tempPassport;

        try {
            fileScannerForClients = new Scanner(fileClients);
        }
        catch (Exception e) {e.printStackTrace();}
        while (fileScannerForClients.hasNextLine()) {
            stringForClients = fileScannerForClients.nextLine();
            lineScannerForClients = new Scanner(stringForClients).useDelimiter("->>>>|---|~~~~|==|___|\\\\\\\\");
            Client client = new Client();
            client.setId(lineScannerForClients.nextInt());
            name = lineScannerForClients.next();
            name = name + " " + lineScannerForClients.next();
            name = name + " " + lineScannerForClients.next();
            client.setName(name);
            client.setPhoneNumber(lineScannerForClients.next());
            tempPassport = lineScannerForClients.nextInt();
            client.setPassport(tempPassport.toString());
            client.setBirthday(lineScannerForClients.next().replace('-', '.'));
            if (lineScannerForClients.hasNextInt()) {
                tempPassport = lineScannerForClients.nextInt();
                client.setOldPassport(tempPassport.toString());
            }
            else client.setOldPassport("NULL");
            clients.add(client);
        }
        return clients;
    }

    private List<Credit> getCreditsList() {
        List<Credit> credits = new ArrayList<>();
        URL PATH = Thread.currentThread().getContextClassLoader().getResource("credits.omg");
        File fileCredits = new File(PATH.getPath());
        Scanner fileScannerForCredits = null;
        Scanner lineScannerForCredits;
        String stringForCredits;
        short day;
        short mouth;
        short year;

        try {
            fileScannerForCredits = new Scanner(fileCredits);
        }
        catch (Exception e) {e.printStackTrace();}
        stringForCredits = fileScannerForCredits.nextLine();
        lineScannerForCredits = new Scanner(stringForCredits).useDelimiter("&Credit\\{|\\||,|%,|\\^|___|-");
        lineScannerForCredits.useLocale(Locale.US);
        while (lineScannerForCredits.hasNextInt()) {
            Credit credit = new Credit();
            credit.setClientID(lineScannerForCredits.nextInt());
            credit.setCashTotal(lineScannerForCredits.nextDouble());
            credit.setPercent(lineScannerForCredits.nextDouble());
            credit.setCashPaid(lineScannerForCredits.nextDouble());
            credit.setCashWithPercent(lineScannerForCredits.nextDouble());
            year = lineScannerForCredits.nextShort();
            mouth = lineScannerForCredits.nextShort();
            day = lineScannerForCredits.nextShort();
            LocalDate d = LocalDate.of(year, mouth, day);
            credit.setDeadline(d);

            credits.add(credit);
        }
        return credits;
    }

}
