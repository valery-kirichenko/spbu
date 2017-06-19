package com.bank.starter.Config;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.web.client.RestTemplate;

/**
 * Created by gusef on 19.06.2017.
 */
@Configuration
public class BankServerConfig {
    @Bean
    public RestTemplate restTemplate(){
        return new RestTemplate();
    }
}
