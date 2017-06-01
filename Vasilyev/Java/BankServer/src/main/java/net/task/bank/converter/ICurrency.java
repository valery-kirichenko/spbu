package net.task.bank.converter;


public interface ICurrency {
    Double getRate(Currency from, Currency to);
}
