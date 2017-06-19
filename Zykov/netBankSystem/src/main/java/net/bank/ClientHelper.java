package net.bank;

import java.util.List;

public interface ClientHelper {
    List<Client> getDebtors();
    List<Credit> getUnpaidCredits();
    List<Credit> getUnpaidCreditsForClient(int id);
    float getTotalDebt(int id);
}
