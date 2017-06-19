package dopusk.dopusk;

import org.springframework.stereotype.Service;

import java.time.LocalDate;

/**
 * Created by USER on 18.06.2017.
 */
@Service
public class ExpiryCreditsImpl implements ExpiryCredits {
    @Override
    public boolean getExpiryCredits(Credits credit) {
        boolean expired = false;
        LocalDate now = LocalDate.now();
        float wholeLoan = Float.parseFloat(credit.getWholeLoan());
        float paidSum = Float.parseFloat(credit.getPaidSum());

        LocalDate date = LocalDate.parse(credit.getDataString());
        if (now.isAfter(date) && paidSum < wholeLoan) {
            expired = true;
        }

        return expired;
    }
}
