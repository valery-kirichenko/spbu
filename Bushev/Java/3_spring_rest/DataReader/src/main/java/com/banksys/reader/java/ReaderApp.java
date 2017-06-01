package com.banksys.reader.java;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
public class ReaderApp {
    public static void main(String[] args) {
        SpringApplication.run(ReaderApp.class, args);
        System.out.println("Data reader is started");
    }
}
