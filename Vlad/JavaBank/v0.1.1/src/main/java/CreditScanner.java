import java.io.File;
import java.util.*;

class CreditScanner {

    private short day;
    private short mouth;
    private short year;

    private File iFile = new File("C:\\AInOne\\progs\\Java\\Bank\\src\\main\\resources", "credits.omg");

    private Scanner fileScannerForCredits;
    private Scanner lineScannerForCredits;

    private String stringForCredits;

    CreditScanner(List<Credit>credits) {
        try {
            fileScannerForCredits = new Scanner(iFile);
            stringForCredits = fileScannerForCredits.nextLine();
        } catch (Exception e) {
            e.printStackTrace();
        }

        lineScannerForCredits = new Scanner(stringForCredits).useDelimiter("&Credit\\{|\\||,|%,|\\^|___|-");
        lineScannerForCredits.useLocale(Locale.US);

        while (lineScannerForCredits.hasNextInt()) {
            Credit credit = new Credit();
            credit.setId(lineScannerForCredits.nextInt());
            credit.setCashTotal(lineScannerForCredits.nextDouble());
            credit.setPercent(lineScannerForCredits.nextDouble());
            credit.setCashPaid(lineScannerForCredits.nextDouble());
            credit.setCastLeft(lineScannerForCredits.nextDouble());

            year = lineScannerForCredits.nextShort();
            mouth = lineScannerForCredits.nextShort();
            day = lineScannerForCredits.nextShort();
            Calendar cal = Calendar.getInstance();
            cal.set(year, mouth, day);
            Date d = cal.getTime();
            credit.setDeadline(d);

            credits.add(credit);
        }
    }
}
