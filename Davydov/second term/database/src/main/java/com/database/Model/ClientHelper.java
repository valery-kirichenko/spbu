package com.database.Model;

import java.util.Collection;

/**
 * Created by Дмитрий on 17.03.2017.
 */
public interface ClientHelper
{
    Collection getListDebtors(Collection<ClientRecord> clients);
    Collection getListCreditsByCredits(Collection<CreditRecord> credits);
    Collection getListCreditsByClients(Collection<ClientRecord> clients);
    Collection getDebtClient(ClientRecord clientRecord);
}
