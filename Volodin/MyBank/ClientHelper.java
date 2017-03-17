package MyBank;

import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

/**
 * Created by Aspire on 17.03.2017.
 */
public class ClientHelper implements ClientHelping {
    @Override
    public List<Client> getLossUsers() {
        List<Client> res = new ArrayList<Client>();
        for (Client cl : ClientStorage.getClientList())
            for (Credit cr : cl.getCredits())
                if (cr.getSumPaid() < cr.getSumToPay()){
                    res.add(cl);
                    break;
                }
        return res;
    }

    @Override
    public List<Credit> getLossCredits() {
        List<Credit> res = new ArrayList<Credit>();
        for (Client cl : ClientStorage.getClientList())
            for (Credit cr : cl.getCredits())
                if (cr.getSumPaid() < cr.getSumToPay())
                    res.add(cr);
        return res;
    }

    @Override
    public double sumLoss(Client cl) {
        double sum = 0;
        for (Credit cr : cl.getCredits())
            if (cr.getSumPaid() < cr.getSumToPay())
                sum += cr.getSumToPay() - cr.getSumPaid();
        return sum;
    }

    public void printLossUsers(){
        System.out.println("Clients that haven't pay already: " + Integer.toString(getLossUsers().size()));
        for (Client cl : getLossUsers())
            printClient(cl);
    }

    public void printClient(Client cl){
        System.out.println(String.format("\tPassport: %d Name: %s %s %s Birthdate: ", cl.getPassport(), cl.getFamily(), cl.getName(),
                cl.getFather()) + (new SimpleDateFormat("dd.MM.yyyy")).format(cl.getBirthDate()));
    }

    public void printLossCredits(){
        System.out.println("Credits that aren't pay already: " + Integer.toString(getLossCredits().size()));
        for (Credit cr : getLossCredits())
            System.out.println(String.format("\tClientID: %d Sum: %.2f Remaining: %.2f CloseDate: ", cr.getClientId(), cr.getSum(),
                    cr.getSumToPay() - cr.getSumPaid()) +
                    (new SimpleDateFormat("dd.MM.yyyy")).format(cr.getDateToClose()));
    }

    public void printRandomLosses(){
        Random rnd = new Random(System.currentTimeMillis());
        System.out.println("Losses of Some Clients: ");
        for (int i = 0; i < 10; i++){
            Client cl = ClientStorage.getClientList().get(Math.abs(rnd.nextInt() % ClientStorage.getClientList().size()));
            printClient(cl);
            System.out.println("\tLoss: " + Double.toString(sumLoss(cl)));
        }
    }
}
