package net.task.bank.sdata;

import net.task.bank.models.Client;
import net.task.bank.models.Credit;
import org.springframework.stereotype.Service;

import java.io.FileOutputStream;
import java.io.IOException;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;


@Service
public class DataStore implements Storage {
    //Пользователи содержат битые записи. Может быть несколько записей с одинаковым номером паспорта и именем фамилией.
    //Результат повторного заведения одних и тех же пользователей.
    //Может быть несколько пользователей у которых новый паспорт и старый паспорт совпадает
    //(пользователь сменил паспорт, завели новый аккаунт, притом может даже поменяться фамилия).
    private List<Client> clients;
    private List<Credit> credits;
    public List<Credit> nullPointerCredits = new ArrayList<>();
    public int countNull = 0;

    DataStore() {
    }

    DataStore(List<Client> listClients, List<Credit> listCredits) {
        clients = listClients;
        credits = listCredits;
    }

    @Override
    public void mergeDuplicate() {
        int countDup = 0, countError = 0;

        for (Client client1 : clients) {
            for (Client client2 : clients) {
                if (!client1.equals(client2) && !client1.isDeleted && !client2.isDeleted) {
                    if (Objects.equals(client1.getPassport(), client2.getPassport())) {
                        for (Credit credit2 : client2.getCredits()) {
                            credit2.setClientID(client1.getID());
                        }
                        countDup++;
                        client2.isDeleted = true;
                        break;
                    } else if (Objects.equals(client1.getOldPassport(), client2.getPassport())) {
                        for (Credit credit2 : client2.getCredits()) {
                            credit2.setClientID(client1.getID());
                        }
                        countError++;
                        client2.isDeleted = true;
                        break;
                    }
                }
            }
        }
        System.out.println("Number of duplicates: " + countDup + " real duplicates, " +
                countError + " confusion with passports.");
        List<Client> newClients = new ArrayList<>();
        for (Client client : clients)
            if (!client.isDeleted)
                newClients.add(client);
        clients = newClients;

        LocalDate now = LocalDate.now();
        int count = 0;
        int cred = 0;
        int addcred = 0;
        int cout = 0;
        int co = 0;

        List<Credit> newCredits = new ArrayList<>();
        for (Credit credit : credits) {
            cred++;
            if (getNameFromId(credit.getClientID()) != null) {
                newCredits.add(credit);
                addcred++;
            }
            else
                co++;
            if (now.isAfter(credit.getClosingDate()) &&
                    (credit.getPaidSum() < credit.getNeedPaid())) {
                if (getNameFromId(credit.getClientID()) == null) {
                    nullPointerCredits.add(credit);
                    count++;
                    System.out.println(count + ") Found new unpaid credit with null id!");
                }
                cout++;
            }
        }
        System.out.println("Cred = " + cred);
        System.out.println("AddCred = " + addcred);
        System.out.println("cout = " + cout);
        System.out.println("count = " + count);
        System.out.println("co = " + co);
        credits = newCredits;

        for (Client client : clients)
            for (Credit credit : credits)
                if (credit.getClientID() == client.getID())
                    client.addCredit(credit);
    }

    @Override
    public void outDataToTxt(FileOutputStream outClients, FileOutputStream outCredits) throws IOException {
        for (Client client : clients)
            outClients.write((client.toString() + "\n").getBytes());

        for (Credit credit : credits)
            outCredits.write((credit.toString() + "\n").getBytes());
    }

    @Override
    public void changeClientInfo() {
        for (Client client : clients) {
            if (client.getFirstName().contains("ё"))
                client.setFirstName(client.getFirstName().replace('ё', 'е'));
            if (client.getMiddleName().contains("ё"))
                client.setMiddleName(client.getMiddleName().replace('ё', 'е'));
            if (client.getLastName().contains("ё"))
                client.setLastName(client.getLastName().replace('ё', 'е'));
        }
    }

    @Override
    public String getNameFromId(int id) {
        String result = null;
        boolean isFound = false;
        for (Client client : clients)
            if (id == client.getID()) {
                result = client.getFirstName() + " " + client.getMiddleName() + " " + client.getLastName();
                isFound = true;
            }
        if (isFound)
            countNull++; // Счётчик кредитов, у которых нет id среди клиентов.
        return result;
    }

    @Override
    public Client getClient(int id) {
        Client clientResult = new Client();
        for (Client client : clients)
            if (id == client.getID())
                clientResult = client;
        return clientResult;
    }

    @Override
    public void setClientList(List<Client> clientList) {
        clients = clientList;
    }

    @Override
    public void setCreditList(List<Credit> creditList) {
        credits = creditList;

        if (clients != null) {
            for (Client client : clients) {
                for (Credit credit : credits) {
                    if (credit.getClientID() == client.getID()) {
                        client.addCredit(credit);
                    }
                }
            }
        }
    }

    @Override
    public List<Client> getClientList() {
        return clients;
    }

    @Override
    public List<Credit> getCreditList() {
        return credits;
    }
}
