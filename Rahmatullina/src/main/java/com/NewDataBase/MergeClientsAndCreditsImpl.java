package com.NewDataBase;

import org.springframework.stereotype.Service;

import java.util.List;
import java.util.Vector;

/**
 * Created by Я on 17.03.2017.
 */
@Service
public class MergeClientsAndCreditsImpl implements MergeClientAndCredit {
    @Override
   public void getMerge(List<Clients> listClient, List<Credits> listCredit) {

        for (Clients client : listClient) {
            for (Credits credit : listCredit)
                if (client.getClientId().equals(credit.getId()))
                    client.getCredit().add(credit);


        }
        Vector<Integer> indexMass = new Vector();
        Integer clientIndex = 0;
        for (Clients client1 : listClient) {
            for (Clients client2 : listClient) {
                if ((client1.getClientId().equals(client2.getClientId()) != true) && client1.getNewPassport().equals(client2.getNewPassport())) {
                    client1.getCredit().addAll(client2.getCredit());
                    indexMass.add(clientIndex);
                }
                clientIndex++;
            }
            clientIndex = 0;
        }
        for (Integer clieIndex : indexMass)
            listClient.remove(clieIndex);

        indexMass.clear();
        clientIndex = 0;
        for (Clients client1 : listClient) {
            for (Clients client2 : listClient) {
                if (client1.getOldPassport().equals(client2.getNewPassport())) {
                    client1.getCredit().addAll(client2.getCredit());
                    indexMass.add(clientIndex);
                }
                clientIndex++;
            }
            clientIndex = 0;
        }
        for (Integer clieIndex : indexMass)
            listClient.remove(clieIndex);
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
