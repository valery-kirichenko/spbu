package net.task.bank.sdata;

import net.task.bank.converter.Currency;
import net.task.bank.converter.CurrencyService;
import net.task.bank.dao.CreditRowMapper;
import net.task.bank.models.Client;
import net.task.bank.models.Credit;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Service;

import java.io.FileOutputStream;
import java.io.IOException;
import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;


@Service
public class DataStore implements Storage {
    @Autowired
    private JdbcTemplate template;

    @Autowired
    private CurrencyService currencyService;

    //Пользователи содержат битые записи. Может быть несколько записей с одинаковым номером паспорта и именем фамилией.
    //Результат повторного заведения одних и тех же пользователей.
    //Может быть несколько пользователей у которых новый паспорт и старый паспорт совпадает
    //(пользователь сменил паспорт, завели новый аккаунт, притом может даже поменяться фамилия).
    private List<Client> clients;
    private List<Credit> credits;
    public List<Credit> nullPointerCredits = new ArrayList<>();
    public Integer countNull = 0;

    DataStore() {
    }

    DataStore(List<Client> listClients, List<Credit> listCredits) {
        clients = listClients;
        credits = listCredits;
    }

    @Override
    public void mergeDuplicate() {
        Integer countDup = 0, countError = 0;

        for (Client client1 : clients) {
            for (Client client2 : clients) {
                if (!client1.equals(client2) && !client1.isDeleted && !client2.isDeleted) {
                    if (Objects.equals(client1.getPassport(), client2.getPassport())) {
                        for (Credit credit2 : client2.getCredits()) {
                            credit2.setClientID(client1.getID());
                        }
                        countDup++;
                        client2.isDeleted = Boolean.TRUE;
                        break;
                    } else if (Objects.equals(client1.getOldPassport(), client2.getPassport())) {
                        for (Credit credit2 : client2.getCredits()) {
                            credit2.setClientID(client1.getID());
                        }
                        countError++;
                        client2.isDeleted = Boolean.TRUE;
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
        Integer count = 0;

        List<Credit> newCredits = new ArrayList<>();
        for (Credit credit : credits) {
            if (getNameFromId(credit.getClientID()) != null)
                newCredits.add(credit);
            if (now.isAfter(credit.getClosingDate()) &&
                    (credit.getPaidSum() < credit.getNeedPaid())) {
                if (getNameFromId(credit.getClientID()) == null) {
                    nullPointerCredits.add(credit);
                    count++;
                    System.out.println(count + ") Found new unpaid credit with null id!");
                }
            }
        }
        credits = newCredits;

        for (Client client : clients)
            for (Credit credit : credits)
                if (Objects.equals(credit.getClientID(), client.getID()))
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
    public String getNameFromId(Integer id) {
        String result = null;
        Boolean isFound = Boolean.FALSE;
        for (Client client : clients)
            if (Objects.equals(id, client.getID())) {
                result = client.getFirstName() + " " + client.getMiddleName() + " " + client.getLastName();
                isFound = Boolean.TRUE;
            }
        if (isFound)
            countNull++; // Счётчик кредитов, у которых нет id среди клиентов.
        return result;
    }

    @Override
    public Client getClient(Integer id) {
        Client clientResult = new Client();
        for (Client client : clients)
            if (Objects.equals(id, client.getID()))
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
                    if (Objects.equals(credit.getClientID(), client.getID())) {
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

    @Override
    public List<Credit> creditUpdate(Currency newCurrency, Integer ID) {
        List<Credit> creditUpdatedList = template.query("SELECT * FROM credits WHERE clientID = " + ID,
                new CreditRowMapper());
        if (!newCurrency.equals(Currency.RUB)) {
            Double multiplication = currencyService.getRate(Currency.RUB, newCurrency);
            for (Credit credit : creditUpdatedList) {
                credit.setAmount(credit.getAmount() * multiplication);
                credit.setNeedPaid(credit.getNeedPaid() * multiplication);
                credit.setPaidSum(credit.getPaidSum() * multiplication);
            }
        }
        return creditUpdatedList;
    }
}
