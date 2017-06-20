package dopusk.dopusk;

import java.util.List;

/**
 * Created by USER on 18.06.2017.
 */
public interface CreditController {
    void saveNewCredit(Credits toCreate);
    List<Credits> getAllCredits();
    void deleteCredit(Integer creditID);
    Credits getFirstByID(Integer creditID);
    List<Credits> getByClientID(Integer clientID);
    void updateCredit(Credits toUpdate);
}
