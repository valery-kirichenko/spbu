import java.util.Arrays;
import java.util.List;

class __OldAssembler {
    int index;
    __OldAssembler(List<Client> clients, List<Credit> credits) {

        Integer ids[] = clients.stream().map(Client::getId).toArray(Integer[]::new);
        for (Credit credit : credits) {
            index = Arrays.binarySearch(ids, credit.getId());
            if (index > -1) {
                clients.get(index).getCredits().add(credit);
            }
        }
    }
}