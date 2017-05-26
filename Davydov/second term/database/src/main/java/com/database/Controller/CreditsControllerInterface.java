package com.database.Controller;

import com.database.Model.CreditRecord;

import java.util.Collection;

/**
 * Created by Дмитрий on 12.05.2017.
 */
public interface CreditsControllerInterface
{
    void saveNewCredit(CreditRecord creditRecord);
    Collection <CreditRecord> getAllCredits();
    void deleteCredit(CreditRecord creditRecord);
    Collection <CreditRecord> getByID(Long id);
}
