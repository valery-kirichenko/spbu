package com.NewDataBase;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Service;

import java.util.Date;

/**
 * Created by Я on 17.03.2017.
 */
@Service
public class ShowExpiryCreditImpl implements ShowExpiryCredit{

    @Override
    public boolean getExpiryCredits(Credits credit){

            boolean expired = false;
            Date now = new Date();
            float wholeLoan = Float.parseFloat(credit.getWholeLoan());
            float paidSumm = Float.parseFloat(credit.getPaidSum());
            if (now.after(credit.getCreditData()) && paidSumm < wholeLoan) {
                    expired = true;
                }

            return expired;
        }
    }

