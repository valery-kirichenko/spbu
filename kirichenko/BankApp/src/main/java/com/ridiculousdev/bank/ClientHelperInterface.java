package com.ridiculousdev.bank;

import java.util.List;

public interface ClientHelperInterface {
    boolean isUnpaidCredit(Credit credit);

    boolean isPaymentsNeeded(Credit credit);

    List<Credit> getUnpaidCredits(Client client);

    List<Client> getClientsWithUnpaidCredits(List<Client> clients);

    double getClientDebt(Client client);
}
