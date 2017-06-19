package net.task.bank.app;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.ComponentScan;


@ComponentScan({"net.task.bank"})
//@EnableAutoConfiguration
@SpringBootApplication
public class BankServerApplication {
    public static void main(String[] args) {
        SpringApplication.run(BankServerApplication.class, args);
    }
}
