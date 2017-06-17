package com.bank.starter;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import java.io.IOException;

@SpringBootApplication
public class StarterApplication {

	public static void main(String[] args) {
		SpringApplication.run(StarterApplication.class, args);
		try {
			MyBase.getInstance().readCreditsFromFile("credits.omg");
			MyBase.getInstance().readClientsFromFile("clients.omg");
		} catch (IOException exp) {
			System.out.println("File not found!\r\n" + exp.toString());
		}
		System.out.println(MyBase.getInstance().numberOfCredits() + " " + MyBase.getInstance().getListOfClients().size());
		ClientWorkPlace work = new ClientWorkPlace();
		System.out.println(work.allNotPaidCredits().size());
	}
}
