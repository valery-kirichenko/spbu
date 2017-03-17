package MyBank;

/**
 * Created by Aspire on 10.03.2017.
 */
public class Main {
    public static void main(String[] args) {
        Singleton sn = new Singleton();
        FileBaseInterpreter rd = new FileBaseInterpreter("clients.omg", "credits.omg", sn);
        rd.interpret();
        ClientHelper ch = new ClientHelper(sn);
        ch.printLossUsers();
        ch.printLossCredits();
        ch.printRandomLosses();
    }
}
