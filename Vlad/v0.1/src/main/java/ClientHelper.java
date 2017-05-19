import java.util.List;

interface ClientHelper {
    void getListOfDebtors(List<Client> clients);
    void getListOfCredits(List<Client> clients);
    void getFullDebtOfClt(List<Client> clients, int ID);
}
