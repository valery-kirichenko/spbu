package net.task.bank;

import com.sun.istack.internal.Nullable;

import java.time.Instant;
import java.util.ArrayList;

import static net.task.bank.DataStore.countNull;


public class BankHelper implements ClientHelper {
    public ArrayList<Credit> nullPointerCredits = new ArrayList<>();

    @Override
    @Nullable
    public ArrayList<String> getListDebtors(DataStore dataStore) {
        ArrayList<String> debtors = new ArrayList<>();
        ArrayList<Integer> idDebtors = new ArrayList<>();
        Instant now = Instant.now();
        boolean isEmpty = true;
        int count = 0;

        for (Credit credit : dataStore.credits)
            if (now.isAfter(credit.getClosingDate().toInstant()) &&
                    (credit.getPaidSum() < credit.getNeedPaid()) &&
                    !idDebtors.contains(credit.getId())) {
                String nameFromId = dataStore.getNameFromId(credit.getId());
                if (nameFromId != null) {
                    debtors.add(credit.getId() + " " + nameFromId);
                    idDebtors.add(credit.getId());
                    isEmpty = false;
                } else if (!nullPointerCredits.contains(credit)) {
                    boolean check = true;
                    for (Credit creditNull : nullPointerCredits)
                        if (credit.getId() == creditNull.getId())
                            check = false;
                    nullPointerCredits.add(credit);
                    count++;
                    System.out.println(count + ") Found new unpaid credits with null id!");
                    if (!check)
                        countNull--;
                }
            }

        return isEmpty ? null : debtors;
    }

    @Override
    @Nullable
    public ArrayList<Credit> getListUnpaidCredits(DataStore dataStore) {
        ArrayList<Credit> unpaidCredits = new ArrayList<>();
        Instant now = Instant.now();
        boolean isEmpty = true;

        for (Credit credit : dataStore.credits)
            if (now.isAfter(credit.getClosingDate().toInstant())
                    && (credit.getPaidSum() < credit.getNeedPaid())) {
                unpaidCredits.add(credit);
                isEmpty = false;
            }

        return isEmpty ? null : unpaidCredits;
    }

    @Override
    @Nullable
    public ArrayList<Credit> getListUnpaidCreditsOfClient(DataStore dataStore, int id) {
        for (Client client : dataStore.clients)
            if (client.getId() == id)
                return client.getCredits();

        return null;
    }

    @Override
    public double getTotalDebt(DataStore dataStore, int id) {
        double debt = 0;

        for (Credit credit : dataStore.credits)
            if (id == credit.getId())
                debt += credit.getNeedPaid() - credit.getPaidSum();

        return debt;
    }
}
