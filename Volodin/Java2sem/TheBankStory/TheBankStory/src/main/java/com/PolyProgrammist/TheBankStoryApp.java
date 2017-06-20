package com.PolyProgrammist;

import com.vaadin.annotations.Theme;
import com.vaadin.server.VaadinRequest;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.Grid;
import com.vaadin.ui.UI;
import com.vaadin.ui.VerticalLayout;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;
import org.springframework.web.client.RestTemplate;

@SpringBootApplication
@EnableAutoConfiguration
public class TheBankStoryApp implements CommandLineRunner{

	public static void main(String[] args) {
		SpringApplication.run(TheBankStoryApp.class, args);
	}

	@Override
	public void run(String... strings) throws Exception {}

	@Theme("valo")
	@SpringUI(path = "")
	public static class VaadinUI extends UI{

		private final VerticalLayout layout = new VerticalLayout();

		private final int usersCount = 4;

		@Autowired
		RandomUserInfos randomUserInfos;

		@Override
		protected void init(VaadinRequest vaadinRequest) {
			layout.setSizeFull();

			Grid<UserInfo> gr = new Grid<>();
			gr.addColumn(UserInfo::getUsername).setCaption("Login");
			gr.addColumn(UserInfo::getPassword).setCaption("Password");
			gr.setItems(randomUserInfos.updateAndGetUsers());

			layout.addComponent(gr);
			setContent(layout);
		}
	}

	@Bean
	public RestTemplate restTemplate(){
		return new RestTemplate();
	}
}