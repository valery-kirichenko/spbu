package net.task.bank.converter;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;

@Service
public class CurrencyService implements ICurrency {
    @Autowired
    RestTemplate template;

    private static final String API_PATH = "http://api.fixer.io/latest?base={base}&symbols={symbols}";

    @Override
    public Double getRate(Currency base, Currency to) {
        ServiceAnswer serviceAnswer = template.getForObject(API_PATH, ServiceAnswer.class, base, to);
        return serviceAnswer.getRates().get(to);
    }
}
