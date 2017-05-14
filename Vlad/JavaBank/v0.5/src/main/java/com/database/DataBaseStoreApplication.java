package com.database;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

@SpringBootApplication
public class DataBaseStoreApplication {
	public static void main(String[] args) {
        new AnnotationConfigApplicationContext(DataBaseStoreApplicationConfig.class);
		SpringApplication.run(DataBaseStoreApplication.class, args);
	}
}
