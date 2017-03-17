import java.io.File;
import java.io.FileNotFoundException;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class DataReader {
    List<Client> readClients(URL url) {
        List<Client> clients = new ArrayList<>();
        try (Scanner sc = new Scanner(new File(url.getPath()))) {
            while (sc.hasNextLine()) {
                String line = sc.nextLine();
                String[] splitted = line.split("(->>>>)|(---)|(\\\\\\\\)|(~~~~)|(==)|(___)");
                Client t = new Client();
                int i = 0;
                for (String token : splitted) {
                    switch (i) {
                        case 0:
                            t.setId(Integer.parseInt(token));
                            break;
                        case 1:
                            t.setFirstName(token);
                            break;
                        case 2:
                            t.setLastName(token);
                            break;
                        case 3:
                            t.setMiddleName(token);
                            break;
                        case 4:
                            t.setPhoneNumber(token);
                            break;
                        case 5:
                            t.setPassport(Integer.parseInt(token));
                            break;
                        case 6:
                            t.setBirthdate(token);
                            break;
                        case 7:
                            t.setOldPassport(Integer.parseInt(token));
                            break;
                    }
                    i++;
                }
                clients.add(t);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        return clients;
    }

    List<Credit> readCredits(URL url) {
        List<Credit> credits = new ArrayList<>();

        try (Scanner sc = new Scanner(new File(url.getPath())).useDelimiter("\\Z")) {
            String fileData = sc.next();
            String[] splittedData = fileData.replaceAll("&|%", "")
                    .replaceFirst("Credit\\{", "").split("Credit\\{", 0);
            for (String entry : splittedData) {
                String[] data = entry.split("(\\|)|(,)|(\\^)|(___)");
                Credit t = new Credit();
                int i = 0;
                for (String token : data) {
                    switch (i) {
                        case 0:
                            t.setId(Integer.parseInt(token));
                            break;
                        case 1:
                            t.setTotal(Double.parseDouble(token));
                            break;
                        case 2:
                            t.setRate(Double.parseDouble(token));
                            break;
                        case 3:
                            t.setPaid(Double.parseDouble(token));
                            break;
                        case 4:
                            t.setPayable(Double.parseDouble(token));
                            break;
                        case 5:
                            t.setClosingDate(token);
                            break;
                    }
                    i++;
                }
                credits.add(t);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        return credits;
    }

}
