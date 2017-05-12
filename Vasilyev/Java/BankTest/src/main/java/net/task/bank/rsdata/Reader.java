package net.task.bank.rsdata;

import net.task.bank.models.Client;
import net.task.bank.models.Credit;

import java.io.File;
import java.util.List;


public interface Reader {
    List<Client> readClients(File fileClients);
    List<Credit> readCredits(File fileCredits);
}
