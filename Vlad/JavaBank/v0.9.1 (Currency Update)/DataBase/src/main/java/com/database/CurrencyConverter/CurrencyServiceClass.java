package com.database.CurrencyConverter;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;

@Service
public class CurrencyServiceClass implements CurrencyService {

    private static final String API_PATH = "http://api.fixer.io/latest?base={base}&symbols={symbols}";

    @Autowired
    RestTemplate template;

    @Override
    public Double getRate(Currency base, Currency to) {
        ServiceAnswer serviceAnswer = template.getForObject(API_PATH, ServiceAnswer.class, base, to);
        return serviceAnswer.getRates().get(to);
    }
}
