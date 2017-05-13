package net.task.bank.dao;

import net.task.bank.models.Credit;

import java.util.List;

public interface DBCreditsController {
    void saveNewCredit(Credit toCreate);
    List<Credit> getAllCredits();
    void deleteCredit(int creditID);
    Credit getByID(int creditID);
    List<Credit> getByClientID(int clientID);
    void updateCredit(Credit toUpdate);
}