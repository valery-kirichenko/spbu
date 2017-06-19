package DateBase;

import java.util.List;

/**
 * Created by Пользователь on 18.06.2017.
 */
public interface ClientHelper {
    List<Client> GetDepters();
    List<Credit> GetUnpaidCredits();
    float GetCreditSum();
}
