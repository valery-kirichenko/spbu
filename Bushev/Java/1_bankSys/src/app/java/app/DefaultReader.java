package app;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class DefaultReader {
    public final static String PATH = "C:\\Users\\w7uu\\IdeaProjects\\BSysJava\\src\\main\\resources\\";

    public static void readFromFiles(Storage storage) {
        File clientFile = new File(PATH + "clients.omg");
        File creditFile = new File(PATH + "credits.omg");

        ArrayList<Client> clients = new ArrayList<>();
        ArrayList<Credit> credits = new ArrayList<>();

        try {
            Scanner scan = new Scanner(clientFile);
            while (scan.hasNext()) {
                clients.add(new Client(scan.next().split("->>>>|---|\\\\\\\\|~~~~|==|___")));
            }
            scan.close();

            scan = new Scanner(creditFile).useDelimiter("&");
            while (scan.hasNext()) {
                credits.add(new Credit(scan.next().split("\\||%,|,|\\^|___")));
            }
            scan.close();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        clients = makingLinks(clients, credits);
        clients = mergeDuplicates(clients);
        // credits = clearUnused(clients, credits);

        storage.setClients(clients);
        storage.setCredits(credits);
    }

    public static ArrayList<Client> makingLinks(ArrayList<Client> clients, ArrayList<Credit> credits) {
        for (Client client : clients) {
            ArrayList<Credit> nCredits = new ArrayList<>();
            for (Credit credit : credits) {
                if (credit.id.equals(client.id)) {
                    nCredits.add(credit);
                }
            }
            client.credits = nCredits;
        }

        return clients;
    }

    public static ArrayList<Client> mergeDuplicates(ArrayList<Client> clients) {
        for (int i = 0; i < clients.size(); i++) {
            for (int j = i + 1; j < clients.size(); j++) {
                if (clients.get(i).id.equals(clients.get(j).id)
                        || clients.get(i).passport.equals(clients.get(j).passport)
                        || (!clients.get(i).oldPassport.isEmpty() &&
                        clients.get(i).oldPassport.equals(clients.get(j).passport)
                        || clients.get(i).passport.equals(clients.get(j).oldPassport))) {

                    // merge records
                    for (Credit credit : clients.get(j).credits){
                        clients.get(i).credits.add(credit);
                        credit.id = clients.get(i).id;
                    }

                    clients.remove(j);
                    j--;
                }
            }
        }

        return clients;
    }

    private static ArrayList<Credit> clearUnused(ArrayList<Client> clients, ArrayList<Credit> credits){
        boolean used;
        for(int i = 0; i < credits.size(); i++){
            used = false;

            for (Client client : clients){
                for(Credit innerCredit : client.credits){
                    if(credits.get(i) == innerCredit){
                        used = true;
                        break;
                    }
                }
            }

            if(!used){
                credits.remove(i);
                i--;
            }
        }

        return credits;
    }
}
