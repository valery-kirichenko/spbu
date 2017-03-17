import java.util.ArrayList;

public interface ClientHelperInterface {
    public boolean isUnpaidCredit(Credit credit);
    public ArrayList<Credit> getUnpaidCredits(Client client);
    public ArrayList<Client> getClientsWithUnpaidCredits(ArrayList<Client> clients);
    public double getClientDebt(Client client);
}
