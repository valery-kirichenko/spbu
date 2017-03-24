import com.sun.istack.internal.Nullable;

import java.util.ArrayList;
import java.util.List;

class DataProcessor {
    private List<Client> clients;
    private List<Credit> credits;

    DataProcessor(List<Client> cl, List<Credit> cr) {
        clients = cl;
        credits = cr;
    }

    void removeDuplicates() {
        for (int i = 0; i < clients.size(); i++) {
            Client origin = clients.get(i);
            for (int j = 0; j < clients.size(); j++) {
                Client duplicate = clients.get(j);
                if (origin.getId() == duplicate.getId()) continue;

                if ((origin.getPassport() == duplicate.getPassport() &&
                        origin.getFirstName().equals(duplicate.getFirstName()) &&
                        origin.getLastName().equals(duplicate.getLastName())) ||
                        (origin.getOldPassport() == duplicate.getPassport())) {
                    for (Credit credit : credits) {
                        if (credit.getId() == duplicate.getId()) {
                            credit.setId(origin.getId());
                        }
                    }
                    clients.remove(duplicate);
                }
            }
        }

    }

    void replaceLetters() {
        for (Client client : clients) {
            client.setLastName(client.getLastName().replace("ё", "е"));
            client.setFirstName(client.getFirstName().replace("ё", "е"));
            client.setMiddleName(client.getMiddleName().replace("ё", "е"));
        }
    }

    @Nullable
    List<Credit> assignCredits() {
        List<Credit> creditsWithoutClients = new ArrayList<>();
        for (Credit credit : credits) {
            boolean set = false;
            int id = credit.getId();
            for (Client client : clients) {
                if (client.getId() == id) {
                    client.addCredit(credit);
                    set = true;
                    break;
                }
            }
            if (!set) {
                creditsWithoutClients.add(credit);
            }
        }
        return creditsWithoutClients.size() != 0 ? creditsWithoutClients : null;
    }
}
