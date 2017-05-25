package com.database;

import com.database.Cells.Credit;
import java.util.List;

public interface CreditsController {
    public void saveNewCredit(Credit toCreate);
    public List<Credit> getAllCredits();
    public void deleteCredit(Long customerId);
    public Credit getById(Long customerId);
}
