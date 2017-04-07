package app;

import java.io.IOException;
import java.lang.reflect.Array;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Date;

import static app.Algo.getInt;

public class ClientHelper {
    public static void showUnpaid(ArrayList<Client> clients, boolean showUsers){
        int counter = 0;
        for(Client client : clients){
            for(Credit credit : client.credits){
                if(credit.date.isBefore(LocalDate.now())
                        && Double.parseDouble(credit.payed) < Double.parseDouble(credit.needed)){
                    counter++;
                    if(showUsers) break;
                }
            }
        }

        System.out.println("Total unpayed " + (showUsers ? "users" : "credits") + " >>> " + counter);
    }

    public static void showDebt(ArrayList<Client> clients, int id){
        Client currentClient = null;
        for(Client client : clients){
            if(id == Integer.parseInt(getInt(client.id))){
                currentClient = client;
                break;
            }
        }

        if(currentClient == null){
            System.out.println("Client with this id was not found!");
            return;
        }

        double debt = 0;
        for(Credit credit : currentClient.credits){
            if(Double.parseDouble(credit.payed) < Double.parseDouble(credit.needed)){
                debt += Double.parseDouble(credit.needed) - Double.parseDouble(credit.payed);
            }
        }

        System.out.println("Client #" + id + ": " + debt);
    }
}
