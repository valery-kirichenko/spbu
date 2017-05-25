package net.task.bank.config;

import net.task.bank.rsdata.DataReader;
import net.task.bank.rsdata.Reader;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;


@Configuration
public class BankTestAppConfig {
    @Bean
    public Reader getReader() {
        return new DataReader();
    }
}
