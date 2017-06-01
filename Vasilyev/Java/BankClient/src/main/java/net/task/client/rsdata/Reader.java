package net.task.client.rsdata;

import net.task.client.models.Client;
import net.task.client.models.Credit;

import java.io.File;
import java.util.List;


public interface Reader {
    List<Client> readClients(File fileClients);

    List<Credit> readCredits(File fileCredits);
}
