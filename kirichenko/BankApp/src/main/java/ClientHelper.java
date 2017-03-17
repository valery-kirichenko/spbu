import java.time.LocalDate;
import java.util.ArrayList;

/**
 * Created by valera5505 on 17.03.17.
 */
public class ClientHelper implements ClientHelperInterface {
    public boolean isUnpaidCredit(Credit credit) {
        return (credit.getClosingDate().isBefore(LocalDate.now()) && (credit.getPaid() < credit.getPayable()));
    }

    public ArrayList<Credit> getUnpaidCredits(Client client) {
        ArrayList<Credit> result = new ArrayList<>();
        for (Credit credit : client.getCredits()) {
            if (isUnpaidCredit(credit)) result.add(credit);
        }
        return result;
    }

    public ArrayList<Client> getClientsWithUnpaidCredits(ArrayList<Client> clients) {
        ArrayList<Client> result = new ArrayList<>();
        for (Client client : clients) {
            for (Credit credit : client.getCredits()) {
                if (isUnpaidCredit(credit)) {
                    result.add(client);
                    break;
                }
            }
        }
        return result;
    }

    public double getClientDebt(Client client) {
        double debt = 0;
        for (Credit credit : client.getCredits()) {
            if (credit.getPaid() < credit.getPayable()) {
                debt += credit.getPayable() - credit.getPaid();
            }
        }
        return debt;
    }
}
