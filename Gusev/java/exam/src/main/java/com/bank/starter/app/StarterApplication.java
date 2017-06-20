package com.bank.starter.app;

import com.bank.starter.MyDataBase.MyBase;
import com.bank.starter.models.User;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.ComponentScan;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

@ComponentScan({"com.bank.starter"})
@SpringBootApplication
public class StarterApplication {

	public static void main(String[] args) {
		SpringApplication.run(StarterApplication.class, args);

		MyBase data = new MyBase();
		data.getRandomUsers(10);

		System.out.println(data.getArrayListOfUsers().get(0).getLocation().getPostcode() + " " + data.getArrayListOfUsers().size());

		DateFormat dateFormat = new SimpleDateFormat("HH-mm-ss");
		Date date = new Date();


		File newFile = new File(dateFormat.format(date) + ".xls");

		try {
			if (!newFile.exists())
				newFile.createNewFile();
		}
		catch(IOException exp){
			System.out.println("Error during Creating file\r\n" + exp.getMessage());
		}

		try{
			FileOutputStream outFile = new FileOutputStream(newFile);
			data.outDataToExcel(outFile);
		}
		catch(IOException exp){
			System.out.println("Error during Opening file\r\n" + exp.getMessage());
		}

		System.exit(0);

	}

}
