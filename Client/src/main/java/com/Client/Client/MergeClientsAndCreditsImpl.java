package com.Client.Client;

import org.springframework.stereotype.Service;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;


@Service
public class MergeClientsAndCreditsImpl implements MergeClientAndCredit {
    //Пользователи содержат битые записи. Может быть несколько записей с одинаковым номером паспорта и именем фамилией.
    //Результат повторного заведения одних и тех же пользователей.
    //Может быть несколько пользователей у которых новый паспорт и старый паспорт совпадает
    //(пользователь сменил паспорт, завели новый аккаунт, притом может даже поменяться фамилия).
    public List<Credits> nullPointerCredits = new ArrayList<>();
    public Integer countNull = 0;

    @Override
    public void getMerge(List<Clients> clients, List<Credits> credits) {
        Integer countDup = 0, countError = 0;

        for (Clients client1 : clients) {
            for (Clients client2 : clients) {
                if (!client1.equals(client2) && !client1.isDeleted && !client2.isDeleted) {
                    if (Objects.equals(client1.getNewPassport(), client2.getNewPassport())) {
                        for (Credits credit2 : client2.getCredits()) {
                            credit2.setId(client1.getId());
                        }
                        countDup++;
                        client2.isDeleted = Boolean.TRUE;
                        break;
                    } else if (Objects.equals(client1.getOldPassport(), client2.getNewPassport())) {
                        for (Credits credit2 : client2.getCredits()) {
                            credit2.setId(client1.getId());
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
        List<Clients> newClients = new ArrayList<>();
        for (Clients client : clients)
            if (!client.isDeleted)
                newClients.add(client);
        clients = newClients;

        LocalDate now = LocalDate.now();
        Integer count = 0;

        List<Credits> newCredits = new ArrayList<>();
        for (Credits credit : credits) {
            if (getNameFromID(credit.getId(), clients) != null)
                newCredits.add(credit);
            if (now.isAfter(LocalDate.parse(credit.getDataString())) &&
                    (Float.parseFloat(credit.getPaidSum()) < Float.parseFloat(credit.getWholeLoan()))) {
                if (getNameFromID(credit.getId(), clients) == null) {
                    nullPointerCredits.add(credit);
                    count++;
                    System.out.println(count + ") Found new unpaid credit with null id!");
                }
            }
        }
        credits = newCredits;

        for (Clients client : clients)
            for (Credits credit : credits)
                if (Objects.equals(credit.getId(), client.getId()))
                    client.addCredit(credit);
    }

    public void getReplace(List<Clients> listClient) {
        for (Clients client : listClient) {
            if (client.getName().contains("ё"))
                client.setName(client.getName().replace("ё", "е"));
            if (client.getSurName().contains("ё"))
                client.setSurName(client.getSurName().replace("ё", "е"));
            if (client.getMidName().contains("ё"))
                client.setMidName(client.getMidName().replace("ё", "е"));
        }
    }

    @Override
    public String getNameFromID(Integer ID, List<Clients> clients) {
        String result = null;
        Boolean isFound = Boolean.FALSE;
        for (Clients client : clients)
            if (Objects.equals(ID, client.getId())) {
                result = client.getName() + " " + client.getMidName() + " " + client.getSurName();
                isFound = Boolean.TRUE;
            }
        if (isFound)
            countNull++; // Счётчик кредитов, у которых нет ID среди клиентов.
        return result;
    }
}
