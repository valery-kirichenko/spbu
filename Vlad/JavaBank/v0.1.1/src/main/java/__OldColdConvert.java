import java.util.Arrays;
import java.util.List;

class __OldColdConvert {

    private boolean isOver;
    private int i;
    private int index;

    __OldColdConvert(List<Client> clients) {

        clients.sort((o1, o2) -> {
            if (o1.getPassport() > o2.getPassport()) return 1;
            else return -1;
        });

        isOver = false;
        i = 0;
        while(!isOver) {
            try {
                recursion(clients, i);
                i++;
            }
            catch (Exception e) {
                isOver = true;
            }
        }

        Integer passports[] = clients.stream().map(Client::getPassport).toArray(Integer[]::new);
        for (i = 0; i < clients.size(); i++) {
            index = Arrays.binarySearch(passports, clients.get(i).getOldPassport());
            if (index > -1) {
                clients.get(index).getCredits().addAll(clients.get(i).getCredits());
                clients.remove(i);
            }
        }

    }
    private void recursion (List<Client> clients, int number) {
        if (clients.get(number).getPassport() == clients.get(number + 1).getPassport()) {
            clients.get(number + 1).getCredits().addAll(clients.get(number).getCredits());
            clients.remove(number);
            recursion(clients, number);
        }
    }
}
