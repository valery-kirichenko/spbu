package MyBank;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Random;

/**
 * Created by Aspire on 17.03.2017.
 */
public class ClientHelper implements ClientHelping {
    Singleton sn;

    public ClientHelper (Singleton sn){
        this.sn = sn;
    }

    @Override
    public ArrayList<Client> getLossUsers() {
        ArrayList<Client> res = new ArrayList<Client>();
        for (Client cl : sn.aclient)
            for (Credit cr : cl.credits)
                if (cr.sumPaid < cr.sumToPay){
                    res.add(cl);
                    break;
                }
        return res;
    }

    @Override
    public ArrayList<Credit> getLossCredits() {
        ArrayList<Credit> res = new ArrayList<Credit>();
        for (Client cl : sn.aclient)
            for (Credit cr : cl.credits)
                if (cr.sumPaid < cr.sumToPay)
                    res.add(cr);
        return res;
    }

    @Override
    public double sumLoss(Client cl) {
        double sum = 0;
        for (Credit cr : cl.credits)
            if (cr.sumPaid < cr.sumToPay)
                sum += cr.sumToPay - cr.sumPaid;
        return sum;
    }

    public void printLossUsers(){
        System.out.println("Clients that haven't pay already: " + Integer.toString(getLossUsers().size()));
        for (Client cl : getLossUsers())
            printClient(cl);
    }

    public void printClient(Client cl){
        System.out.println(String.format("\tPassport: %d Name: %s %s %s Birthdate: ", cl.passport, cl.family, cl.name,
                cl.father) + (new SimpleDateFormat("dd.MM.yyyy")).format(cl.birthDate));
    }

    public void printLossCredits(){
        System.out.println("Clients that haven't pay already: " + Integer.toString(getLossCredits().size()));
        for (Credit cr : getLossCredits())
            System.out.println(String.format("\tClientID: %d Sum: %.2f Remaining: %.2f CloseDate: ", cr.clientId, cr.sum,
                    cr.sumToPay - cr.sumPaid) +
                    (new SimpleDateFormat("dd.MM.yyyy")).format(cr.dateToClose));
    }

    public void printRandomLosses(){
        Random rnd = new Random(System.currentTimeMillis());
        System.out.println("Losses of Some Clients: ");
        for (int i = 0; i < 10; i++){
            Client cl = sn.aclient.get(Math.abs(rnd.nextInt() % sn.aclient.size()));
            printClient(cl);
            System.out.println("\tLoss: " + Double.toString(sumLoss(cl)));
        }
    }
}
