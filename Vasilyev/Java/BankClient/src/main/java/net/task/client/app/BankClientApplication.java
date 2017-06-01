package net.task.client.app;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.ComponentScan;


@ComponentScan({"net.task.client"})
@SpringBootApplication
public class BankClientApplication {

	public static void main(String[] args) {
		SpringApplication.run(BankClientApplication.class, args);
	}
}
