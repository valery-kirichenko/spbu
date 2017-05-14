import java.util.ArrayList;
import java.util.List;

class MainClass {
    public static void main(String[] args) {
        List<Client>clients = new ArrayList<>();
        List<Credit>credits = new ArrayList<>();
        new ClientScanner(clients);
        new CreditScanner(credits);
        new Stuff(clients, credits);
    }
}

