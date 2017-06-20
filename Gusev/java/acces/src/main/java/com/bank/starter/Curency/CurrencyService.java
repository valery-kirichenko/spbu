package com.bank.starter.Curency;

import com.bank.starter.Curency.Currency;
import com.bank.starter.Curency.ServiceAnswer;
import com.bank.starter.Curency.iCurency;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;

/**
 * Created by gusef on 19.06.2017.
 */
@Service
public class CurrencyService implements iCurency {
    @Autowired
    RestTemplate template;

    private static final String API_PATH = "http://api.fixer.io/latest?base={base}&symbols={symbols}";

    @Override
    public Double getRate(Currency base, Currency to) {
        ServiceAnswer serviceAnswer = template.getForObject(API_PATH, ServiceAnswer.class, base, to);
        return serviceAnswer.getRates().get(to);
    }
}
