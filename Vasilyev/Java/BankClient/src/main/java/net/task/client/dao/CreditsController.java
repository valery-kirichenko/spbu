package net.task.client.dao;

import net.task.client.models.Credit;


public interface CreditsController {
    void createCredit(Credit credit);

    void deleteCredit(Integer id);
}
