package com.MyProj.MyProj;
import com.vaadin.annotations.Theme;
import com.vaadin.server.VaadinRequest;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.Grid;
import com.vaadin.ui.UI;
import com.vaadin.ui.VerticalLayout;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.EnableAutoConfiguration;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.annotation.Bean;
import org.springframework.web.client.RestTemplate;
@SpringBootApplication
@EnableAutoConfiguration
public class MyProjApplication {
	public static void main(String[] args) {
		SpringApplication.run(MyProjApplication.class, args);
	}
	@Theme("mytheme")
	@SpringUI()
	public static class MyUI extends UI {

		private final VerticalLayout layout = new VerticalLayout();
		@Autowired
		UserRandom userrandom;
		@Override
		protected void init(VaadinRequest vaadinRequest) {
			layout.setSizeFull();
			Grid<User> grid = new Grid<>();
			grid.setSizeFull();
			grid.addColumn(User::getUsername).setCaption("Login");
			grid.addColumn(User::getPassword).setCaption("Password");
			grid.setItems(userrandom.getAllUsers());
			layout.addComponent(grid);
			setContent(layout);
		}
	}
	@Bean
	public RestTemplate restTemplate(){
		return new RestTemplate();
	}
}
