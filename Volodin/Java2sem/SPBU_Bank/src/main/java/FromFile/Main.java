package FromFile;

public class Main {
    public static void main(String[] args) {
        doThings();
    }

    private static void doThings() {
        System.out.println("ololollo");
        FileBaseInterpreter rd = new FileBaseInterpreter("testcli.omg", "credits.omg");
        rd.interpret();
//        ClientHelper ch = new ClientHelper();
//        ch.printLossUsers();
//        ch.printLossCredits();
//        ch.printRandomLosses();
        ExcelWriter ev = new ExcelWriter();
        ev.write();
    }
}
