package net.bank;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ConfigurableApplicationContext;

@SpringBootApplication
public class BankApp{

    public static void main(String[] args) {
        ConfigurableApplicationContext ctx = SpringApplication.run(BankApp.class, args);
    }
}