package dopuskToExam;

import org.springframework.stereotype.Service;

import java.time.LocalDate;

/**
 * Created by Alena on 17.06.2017.
 */
@Service
public class ShowExpiryCreditImpl implements ShowExpiryCredit {
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
