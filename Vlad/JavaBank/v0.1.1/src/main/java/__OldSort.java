import java.util.List;

class __OldSort {
    __OldSort(List<Client> clients) {
        clients.sort((o1, o2) -> {
            if (o1.getId() > o2.getId()) return 1;
            else return -1;
        });
    }
}
