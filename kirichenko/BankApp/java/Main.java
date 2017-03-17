import java.net.URL;
import java.util.ArrayList;
import java.util.Comparator;

public class Main {
    public static void main(String[] args) {
        DataReader reader = new DataReader();
        URL clientsUrl = Thread.currentThread().getContextClassLoader().getResource("clients.omg");
        URL creditsUrl = Thread.currentThread().getContextClassLoader().getResource("credits.omg");

        ArrayList<Client> clients = reader.readClients(clientsUrl);
        ArrayList<Credit> credits = reader.readCredits(creditsUrl);

        DataProcessor processor = new DataProcessor(clients, credits);
        processor.removeDuplicates();
        clients.sort(Comparator.comparing(Client::getId));
        processor.replaceLetters();
        processor.assignCredits();

        ClientHelper helper = new ClientHelper();

        for (Client client : clients) {
            System.out.println(client.getLastName() + " " + client.getFirstName() + " " + client.getMiddleName() + ": "
                    + helper.getClientDebt(client));
            for (Credit credit : client.getCredits()) {
                System.out.println(credit);
            }
        }


    }
}
