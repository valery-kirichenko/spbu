package net.task.bank;

import java.util.List;

public interface ClientHelper {
    List<Client> getListDebtors();

    List<Credit> getListUnpaidCredits();

    List<Credit> getListUnpaidCreditsOfClient(int id);

    double getTotalDebt(int id);
}
