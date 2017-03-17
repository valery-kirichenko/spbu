package MyBank;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Aspire on 17.03.2017.
 */
public interface ClientHelping {
    public List<Client> getLossUsers();
    public List<Credit> getLossCredits();
    public double sumLoss(Client cl);
}
