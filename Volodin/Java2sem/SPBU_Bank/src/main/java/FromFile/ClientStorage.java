package FromFile;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Aspire on 10.03.2017.
 */
public class ClientStorage {
    private static List<ClientInf> clientList = new ArrayList<ClientInf>();

    public static List<ClientInf> getClientList() {
        return clientList;
    }

    public static void setClientList(List<ClientInf> clientList) {
        ClientStorage.clientList = clientList;
    }

    public static List<CreditInf> getCreditList(){
        List<CreditInf> lcf = new ArrayList<>();
        for (ClientInf cl : clientList)
            lcf.addAll(cl.getCredits());
        return lcf;
    }
}
