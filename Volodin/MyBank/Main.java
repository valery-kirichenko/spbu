package MyBank;

/**
 * Created by Aspire on 10.03.2017.
 */
public class Main {
    public static void main(String[] args) {
        FileBaseInterpreter rd = new FileBaseInterpreter("clients.omg", "credits.omg");
        rd.interpret();
        ClientHelper ch = new ClientHelper();
        ch.printLossUsers();
        ch.printLossCredits();
        ch.printRandomLosses();
    }
}
