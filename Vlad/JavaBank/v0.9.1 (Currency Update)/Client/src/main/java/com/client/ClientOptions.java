package com.client;

import java.time.LocalDate;
import java.util.List;

public interface ClientOptions {
    void createClient(String name, String phoneNumber, String birthday, String passport, String oldPassport);
    void createCredit(int id, double cashTotal, double cashPaid, double cashWithPercent, double percent, LocalDate deadline);
    void deleteClient(int id);
    void deleteCredit(int id);
    void doBigBlast();
    int requestMaxID();
}
