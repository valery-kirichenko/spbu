package com.bank.starter.app;

import com.bank.starter.models.Client;
import com.bank.starter.workStorrage.ClientWorkPlace;
import com.bank.starter.MyDataBase.MyBase;
import org.junit.Test;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.ComponentScan;

import java.io.IOException;
import java.net.URL;

@ComponentScan({"com.bank.starter"})
@EnableAutoConfiguration
@SpringBootApplication
public class StarterApplication {

	public static void main(String[] args) {
		SpringApplication.run(StarterApplication.class, args);
	}

}
