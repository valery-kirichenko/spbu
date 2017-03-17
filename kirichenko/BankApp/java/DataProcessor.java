import java.util.ArrayList;

class DataProcessor {
    private ArrayList<Client> clients;
    private ArrayList<Credit> credits;

    DataProcessor(ArrayList<Client> cl, ArrayList<Credit> cr) {
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

    void assignCredits() {
        for (Credit credit : credits) {
            int id = credit.getId();
            for (Client client : clients) {
                if (client.getId() == id) {
                    client.addCredit(credit);
                    break;
                }
            }
        }
    }
}
