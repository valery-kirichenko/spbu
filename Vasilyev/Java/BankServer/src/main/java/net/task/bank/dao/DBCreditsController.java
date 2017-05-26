package net.task.bank.dao;

import net.task.bank.models.Credit;

import java.util.List;

public interface DBCreditsController {
    void saveNewCredit(Credit toCreate);

    List<Credit> getAllCredits();

    void deleteCredit(Integer creditID);

    Credit getByID(Integer creditID);

    List<Credit> getByClientID(Integer clientID);

    void updateCredit(Credit toUpdate);

    boolean isContained(Credit credit);
}