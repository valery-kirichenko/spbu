package net.bank;

import javax.xml.crypto.Data;
import java.time.Instant;
import java.util.ArrayList;
import java.util.List;

public class BankHelper implements ClientHelper {
    public static List<Credit> nullPointerCredits = new ArrayList<>();

    @Override
    public List<Client> getDebtors() {
        List<Client> debtors = new ArrayList<>();
        Instant now = Instant.now();

        for (Client client : DataStorage.clients)
            if (client.getCredits().size() > 0)
                for (Credit credit : client.getCredits())
                    if (now.isAfter(credit.getClosureDate().toInstant()) &&
                            (credit.getClientPaid() < credit.getClientHasToPay())) {
                        debtors.add(client);
                        break;
                    }

        return debtors;
    }

    @Override
    public List<Credit> getUnpaidCredits() {
        List<Credit> unpaidCredits = new ArrayList<>();
        Instant now = Instant.now();

        for (Credit credit : DataStorage.credits)
            if (now.isAfter(credit.getClosureDate().toInstant())
                    && (credit.getClientPaid() < credit.getClientHasToPay())) {
                unpaidCredits.add(credit);
            }

        return unpaidCredits;
    }

    @Override
    public List<Credit> getUnpaidCreditsForClient(int id) {
        for (Client client : DataStorage.clients)
            if (client.getID() == id)
                return client.getCredits();
        System.out.println("Client with id " + id + " does not exist!");
        return null;
    }

    @Override
    public float getTotalDebt(int id) {
        float debt = 0;

        for (Credit credit : DataStorage.credits)
            if (id == credit.getClientID())
                debt += credit.getClientPaid() - credit.getClientHasToPay();

        return debt;
    }
}
