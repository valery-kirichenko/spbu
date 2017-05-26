package net.bank;

import org.springframework.stereotype.Service;

import java.io.File;
import java.util.List;

@Service
public interface ReaderInterface {
    List<Client> readClients(File fileClients);
    List<Credit> readCredits(File fileCredits);
}