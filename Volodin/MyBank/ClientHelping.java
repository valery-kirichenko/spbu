package MyBank;

import java.util.ArrayList;

/**
 * Created by Aspire on 17.03.2017.
 */
public interface ClientHelping {
    public ArrayList<Client> getLossUsers();
    public ArrayList<Credit> getLossCredits();
    public double sumLoss(Client cl);
}
