package net.bank;

import org.springframework.stereotype.Service;

import java.io.File;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

@Service
public class DataReader implements ReaderInterface {
    @Override
    public List<Client> readClients(File ClientsFile){
        List<Client> clientList = new ArrayList<>();

        DateFormat format = new SimpleDateFormat("yyyy-MM-dd");

        try(Scanner scanClients = new Scanner(ClientsFile);){
            scanClients.useDelimiter("\\n");
            while(scanClients.hasNext()){
                String temp = scanClients.next();
                String[] userArr = temp.split("((->>>>)|(---)|(~~~~)|(\\\\\\\\)|(==)|(___))");
                Client client = new Client();
                client.setID(Integer.parseInt(userArr[0]));
                client.setFirstName(userArr[1]);
                client.setLastName(userArr[2]);
                client.setMiddleName(userArr[3]);
                client.setPhoneNumber(userArr[4]);
                client.setIdNumber(Integer.parseInt(userArr[5]));
                client.setBirthDate(format.parse(userArr[6]));
                if (userArr.length > 7) {
                    client.setOldIdNumber(Integer.parseInt(userArr[7]));
                }
                clientList.add(client);
            }
        }catch(Exception ex){
            ex.printStackTrace();
        }

        return clientList;
    }

    @Override
    public List<Credit> readCredits(File CreditsFile){
        List<Credit> creditList = new ArrayList<>();

        DateFormat format = new SimpleDateFormat("yyyy-MM-dd");

        try (Scanner scanCredits = new Scanner(CreditsFile).useDelimiter("&")){
            while(scanCredits.hasNext()){
                String temp = scanCredits.next();
                String[] userArr = temp.split("((\\|)|,|(\\^)|(___))");
                Credit credit = new Credit();
                credit.setClientID(Integer.parseInt(userArr[0].substring(7)));
                credit.setCreditAmount(Float.parseFloat(userArr[1]));
                credit.setPercent(Float.parseFloat(userArr[2].substring(0, userArr[2].length() - 2)));
                credit.setClientPaid(Float.parseFloat(userArr[3]));
                credit.setClientHasToPay(Float.parseFloat(userArr[4]));
                credit.setClosureDate(format.parse(userArr[5]));
                creditList.add(credit);
            }
        } catch (Exception ex){
            ex.printStackTrace();
        }

        return  creditList;
    }
}
