package dopusk.exam;

import java.util.List;

public interface CreditControl {
    void saveNewCredit(Credits toCreate);
    List<Credits> getAllCredits();
    void deleteCredit(Integer creditID);
    Credits getFirstByID(Integer creditID);
    List<Credits> getByClientID(Integer clientID);
    void updateCredit(Credits toUpdate);
}
