package MyBank;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Aspire on 10.03.2017.
 */
public class ClientStorage {
    private static List<Client> clientList = new ArrayList<Client>();

    public static List<Client> getClientList() {
        return clientList;
    }

    public static void setClientList(List<Client> clientList) {
        ClientStorage.clientList = clientList;
    }
}
