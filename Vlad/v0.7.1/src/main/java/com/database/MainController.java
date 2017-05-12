package com.database;

import java.time.LocalDate;

public interface MainController {
    void createClient(String name, String phoneNumber, String birthday, String passport, String oldPassport);
    void createCredit(Integer clientID, Double creditWithoutPercent, Double cashPaid, Double creditWithPercent, Double percent, LocalDate deadline);
    void deleteClient(Integer clientID);
    void deleteCredit(Integer creditID);
}
