package net.task.bank;

import com.sun.istack.internal.Nullable;

import java.time.Instant;
import java.util.ArrayList;
import java.util.List;


public class BankHelper implements ClientHelper {
    public static List<Credit> nullPointerCredits = new ArrayList<>();

    @Override
    public List<Client> getListDebtors() {
        List<Client> debtors = new ArrayList<>();
        Instant now = Instant.now();

        for (Client client : DataStore.clients)
            if (client.getCredits().size() > 0)
                for (Credit credit : client.getCredits())
                    if (now.isAfter(credit.getClosingDate().toInstant()) &&
                            (credit.getPaidSum() < credit.getNeedPaid())) {
                        debtors.add(client);
                        break;
                    }

        return debtors;
    }

    @Override
    public List<Credit> getListUnpaidCredits() {
        List<Credit> unpaidCredits = new ArrayList<>();
        Instant now = Instant.now();

        for (Credit credit : DataStore.credits)
            if (now.isAfter(credit.getClosingDate().toInstant())
                    && (credit.getPaidSum() < credit.getNeedPaid())) {
                unpaidCredits.add(credit);
            }

        return unpaidCredits;
    }

    @Override
    @Nullable
    public List<Credit> getListUnpaidCreditsOfClient(int id) {
        for (Client client : DataStore.clients)
            if (client.getId() == id)
                return client.getCredits();
        System.out.println("Client with id " + id + " doesn't exist!");
        return null;
    }

    @Override
    public double getTotalDebt(int id) {
        double debt = 0;

        for (Credit credit : DataStore.credits)
            if (id == credit.getId())
                debt += credit.getNeedPaid() - credit.getPaidSum();

        return debt;
    }
}
