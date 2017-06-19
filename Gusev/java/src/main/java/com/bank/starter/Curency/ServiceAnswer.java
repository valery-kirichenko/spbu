package com.bank.starter.Curency;

import java.util.Map;

/**
 * Created by gusef on 19.06.2017.
 */
public class ServiceAnswer {
    Currency base;
    Map<Currency, Double> rates;

    public Currency getBase() {
        return base;
    }

    public void setBase(Currency base) {
        this.base = base;
    }

    public Map<Currency, Double> getRates() {
        return rates;
    }

    public void setRates(Map<Currency, Double> rates) {
        this.rates = rates;
    }
}
