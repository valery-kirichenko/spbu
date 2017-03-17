package net.task.bank;


import java.util.ArrayList;

public interface ClientHelper {
    ArrayList<String> getListDebtors(DataStore dataStore);

    ArrayList<Credit> getListUnpaidCredits(DataStore dataStore);

    ArrayList<Credit> getListUnpaidCreditsOfClient(DataStore dataStore, int id);

    double getTotalDebt(DataStore dataStore, int id);
}
