package com.client;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;

import java.time.LocalDate;
import java.util.List;

@Service
public class RestClient implements ClientOptions {

    String urlForClient = "http://localhost:777/api/client";
    String urlForCredit = "http://localhost:777/api/credit";

    @Autowired
    RestTemplate restTemplate;
    @Autowired
    Machine machine;

    @Override
    public void doBigBlast() {
        int inc = 1;
        int max = requestMaxID();
        for (Client client : machine.getAllClients()) {
            createClient(
                    client.getName(),
                    client.getPhoneNumber(),
                    client.getBirthday(),
                    client.getPassport(),
                    client.getOldPassport()
            );
            if (!client.getCredits().isEmpty()) {
                for (int i = 0; i < client.getCredits().size(); i++) {
                    createCredit(
                            max + inc,
                            client.getCredits().get(i).getCashTotal(),
                            client.getCredits().get(i).getCashPaid(),
                            client.getCredits().get(i).getCashWithPercent(),
                            client.getCredits().get(i).getPercent(),
                            client.getCredits().get(i).getDeadline()
                    );
                }
            }
            inc++;
        }
    }

    @Override
    public int requestMaxID() {
        ResponseEntity<Integer> id = restTemplate.getForEntity(urlForClient + "/maxid", Integer.class);
        return id.getBody();
    }

    @Override
    public void createClient(String name, String phoneNumber, String birthday, String passport, String oldPassport) {
        Client c = new Client();
        c.setName(name);
        c.setPhoneNumber(phoneNumber);
        c.setBirthday(birthday);
        c.setPassport(passport);
        c.setOldPassport(oldPassport);
        restTemplate.postForEntity(urlForClient, c, Client.class);
    }

    @Override
    public void createCredit(int id, double cashTotal, double cashPaid, double cashWithPercent, double percent, LocalDate deadline) {
        Credit c = new Credit();
        c.setClientID(id);
        c.setCashTotal(cashTotal);
        c.setCashPaid(cashPaid);
        c.setCashWithPercent(cashWithPercent);
        c.setPercent(percent);
        c.setDeadline(deadline);
        restTemplate.postForEntity(urlForCredit, c, Credit.class);
    }

    @Override
    public void deleteClient(int id) {
        restTemplate.delete(urlForClient + "/"+id);
    }

    @Override
    public void deleteCredit(int id) {
        restTemplate.delete(urlForCredit + "/"+id);
    }

}
