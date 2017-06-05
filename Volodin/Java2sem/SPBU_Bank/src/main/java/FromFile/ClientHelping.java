package FromFile;

import java.util.List;

/**
 * Created by Aspire on 17.03.2017.
 */
public interface ClientHelping {
    public List<ClientInf> getLossUsers();
    public List<CreditInf> getLossCredits();
    public double sumLoss(ClientInf cl);
}
