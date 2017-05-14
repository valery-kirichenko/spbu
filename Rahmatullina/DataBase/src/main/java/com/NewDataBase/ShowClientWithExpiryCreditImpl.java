package com.NewDataBase;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Date;
import java.util.List;

/**
 * Created by Я on 17.03.2017.
 */
@Service
public class ShowClientWithExpiryCreditImpl implements ShowClientWithExpiryCredit{


    @Autowired
    CreditController creditController;

    @Override
    public boolean checkClient(Clients client) {

    List<Credits> listCredit = creditController.getByClientID(client.getClientId());

            boolean haveExpiryCredit = false;
            Date now = new Date();
            for(Credits credit : listCredit){
                float wholeLoan = Float.parseFloat(credit.getWholeLoan());
                float paidSumm = Float.parseFloat(credit.getPaidSum());
                if (now.after(credit.getCreditData()) && paidSumm < wholeLoan) {
                    haveExpiryCredit =  true;
                }
            }
            return haveExpiryCredit;
    }
}