import java.util.List;

public interface ClientHelperInterface {
    public boolean isUnpaidCredit(Credit credit);
    public boolean isPaymentsNeeded(Credit credit);
    public List<Credit> getUnpaidCredits(Client client);
    public List<Client> getClientsWithUnpaidCredits(List<Client> clients);
    public double getClientDebt(Client client);
}
