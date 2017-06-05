package com.client;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;
import org.springframework.web.client.RestTemplate;

@SpringBootApplication
public class ClientApplication implements CommandLineRunner {

    @Autowired
    RestClient restClient;

    public static void main(String[] args) {
        SpringApplication.run(ClientApplication.class);
    }

    @Override
    public void run(String... strings) throws Exception {

    }

    @Bean
    public RestTemplate restTemplate(){
        return new RestTemplate();
    }
}
