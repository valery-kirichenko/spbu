package dopuskToExam;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.time.LocalDate;
import java.util.List;

/**
 * Created by Alena on 17.06.2017.
 */
@Service
public class ShowClientWithExpiryCreditImpl implements ShowClientWithExpiryCredit {
    @Autowired
    private CreditController creditController;

    @Override
    public boolean checkClient(Clients client) {
        List<Credits> listCredit = creditController.getByClientID(client.getId());

        boolean haveExpiryCredit = false;
        LocalDate now = LocalDate.now();

        for (Credits credit : listCredit) {
            LocalDate date = LocalDate.parse(credit.getDataString());
            float wholeLoan = Float.parseFloat(credit.getWholeLoan());
            float paidSum = Float.parseFloat(credit.getPaidSum());
            if (now.isAfter(date) && paidSum < wholeLoan) {
                haveExpiryCredit = true;
            }
        }
        return haveExpiryCredit;
    }
}
