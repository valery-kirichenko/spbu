import java.io.File;
import java.util.*;

class ClientScanner {

    private File iFile = new File("C:\\AInOne\\progs\\Java\\Bank\\src\\main\\resources", "clients.omg");
    private Scanner fileScannerForClients;
    private Scanner lineScannerForClients;
    private String stringForClients;

    private String name;

    ClientScanner(List<Client> clients) {

        try {
            fileScannerForClients = new Scanner(iFile);
        } catch (Exception e) {
            e.printStackTrace();
        }

        while (fileScannerForClients.hasNextLine()) {
            stringForClients = fileScannerForClients.nextLine();
            lineScannerForClients = new Scanner(stringForClients).useDelimiter("->>>>|---|~~~~|==|___|\\\\\\\\");

            Client client = new Client();
            client.setId(lineScannerForClients.nextInt());
            name = lineScannerForClients.next();
            name = name + " " + lineScannerForClients.next();
            name = name + " " + lineScannerForClients.next();
            client.setName(name);
            client.setPhoneNumber(lineScannerForClients.next());
            client.setPassport(lineScannerForClients.nextInt());
            client.setBirthday(lineScannerForClients.next().replace('-', '.'));
            if (lineScannerForClients.hasNextInt())
                client.setOldPassport(lineScannerForClients.nextInt());
            else client.setOldPassport(0);

            clients.add(client);
        }
    }
}
