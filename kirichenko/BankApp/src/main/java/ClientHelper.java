import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class ClientHelper implements ClientHelperInterface {
    public boolean isUnpaidCredit(Credit credit) {
        return (credit.getClosingDate().isBefore(LocalDate.now()) && (credit.getPaid() < credit.getPayable()));
    }

    public boolean isPaymentsNeeded(Credit credit) {
        return ((credit.getClosingDate().isAfter(LocalDate.now()) || credit.getClosingDate().isEqual(LocalDate.now()))
                && (credit.getPaid() < credit.getPayable()));
    }

    public ArrayList<Credit> getUnpaidCredits(Client client) {
        ArrayList<Credit> result = new ArrayList<>();
        for (Credit credit : client.getCredits()) {
            if (isUnpaidCredit(credit)) result.add(credit);
        }
        return result;
    }

    public List<Client> getClientsWithUnpaidCredits(List<Client> clients) {
        List<Client> result = new ArrayList<>();
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
