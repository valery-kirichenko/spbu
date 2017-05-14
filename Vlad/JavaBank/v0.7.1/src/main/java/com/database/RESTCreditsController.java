package com.database;

import com.database.Cells.Credit;
import java.util.List;

public interface RESTCreditsController {
    void saveNewCredit(Credit toCreate);
    List<Credit> getAllCredits();
    void deleteCredit(Long customerId);
    Credit getById(Long customerId);
}
