
package DataBase;

import java.util.List;


public interface ClientHelpClass {
    List<Client> GetDebters();
    List<Credit> GetUnpaidCredits();
    float GetCreditSum();
}
