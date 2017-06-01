package com.Client.Client;

import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Vector;


@Service
public class MergeClientsAndCreditsImpl implements MergeClientAndCredit {
    @Override
    public void getMerge(List<Clients> listClient, List<Credits> listCredit) {

        for (Clients client : listClient) {
            for (Credits credit : listCredit)
                if (client.getClientId().equals(credit.getId()))
                    client.getCredit().add(credit);
        }

        Vector<Integer> MassiveOfIndexes = new Vector();
        Integer clientIndex1 = 0;
        for (Clients client1 : listClient) {
            for (Clients client2 : listClient) {
                if ((!client1.getClientId().equals(client2.getClientId())) && client1.getOldPassport().equals(client2.getNewPassport())) {
                    client1.getCredit().addAll(client2.getCredit());
                    MassiveOfIndexes.add(clientIndex1);
                }
                clientIndex1++;
            }
            clientIndex1 = 0;
        }
        listClient.removeAll(MassiveOfIndexes);

        MassiveOfIndexes.clear();
        clientIndex1 = 0;

        for (Clients client1 : listClient) {
            for (Clients client2 : listClient) {
                if (client1.getOldPassport().equals(client2.getNewPassport())) {
                    client1.getCredit().addAll(client2.getCredit());
                    MassiveOfIndexes.add(clientIndex1);
                }
                clientIndex1++;
            }
            clientIndex1 = 0;
        }
        listClient.removeAll(MassiveOfIndexes);
    }

    public void getReplace(List<Clients> listClient) {
        for (Clients client : listClient) {
            if (client.getName().contains("ё"))
                client.setName(client.getName().replace("ё", "е"));
            if (client.getSurName().contains("ё"))
                client.setSurName(client.getSurName().replace("ё", "е"));
        }


    }

}
