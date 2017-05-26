package com.PolyProgrammist;

import com.PolyProgrammist.FromFile.ClientInf;
import com.PolyProgrammist.FromFile.ClientStorage;
import com.PolyProgrammist.FromFile.CreditInf;
import com.vaadin.annotations.Theme;
import com.vaadin.server.VaadinRequest;
import com.vaadin.spring.annotation.SpringUI;
import com.vaadin.ui.*;
import com.vaadin.ui.components.grid.ItemClickListener;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.web.client.RestTemplate;

@SpringBootApplication
public class TheBankStoryApp{

	public static void main(String[] args) {
		SpringApplication.run(TheBankStoryApp.class, args);
	}

	@Theme("valo")
	@SpringUI(path = "")
	public static class VaadinUI extends UI{

		private final VerticalLayout layout = new VerticalLayout();

		private void addNewClient(){
			VerticalLayout vl = new VerticalLayout();
			TextField name = new TextField("Name");
			Button b = new Button("OK");
			b.addClickListener(new Button.ClickListener() {
				@Override
				public void buttonClick(Button.ClickEvent clickEvent) {
					if (name.getValue().equals(""))
						return;
					ClientInf cl = new ClientInf();
					cl.setName(name.getValue());
					System.out.println(cl.getName());
					layout.removeComponent(vl);
				}
			});


			vl.addComponent(name);
			vl.addComponent(b);
			layout.addComponent(vl, 1);
		}

		@Override
		protected void init(VaadinRequest vaadinRequest) {
			fillClientStorage();

			layout.setSizeFull();
			
			layout.addComponent(new Label(Double.toString(getFromAPI(1000.12))));
			System.out.println("lol");

			Grid<ClientInf> grClients = new Grid<>();

			grClients.addColumn(ClientInf::getId).setCaption("ID");
			grClients.addColumn(ClientInf::getName).setCaption("Name");
			grClients.addColumn(ClientInf::getFamily).setCaption("Family");
			grClients.addColumn(ClientInf::getFather).setCaption("Father");
			grClients.addColumn(ClientInf::getPassport).setCaption("Passport");
			grClients.addColumn(ClientInf::getPhone).setCaption("Phone");

			Grid<CreditInf> grCredits = new Grid<>();

			grCredits.addColumn(CreditInf::getClientId).setCaption("ClientID");
			grCredits.addColumn(CreditInf::getSum).setCaption("Sum");
			grCredits.addColumn(CreditInf::getSumToPay).setCaption("Sum to pay");
			grCredits.addColumn(CreditInf::getSumPaid).setCaption("Sum paid");
			grCredits.addColumn(CreditInf::getPercent).setCaption("Percent");
			grCredits.addColumn(CreditInf::getDateToClose).setCaption("Date to close");

			grClients.setItems(ClientStorage.getClientList());
			grCredits.setItems(ClientStorage.getCreditList());

//			Button bNewClient = new Button("New Client");
//			bNewClient.addClickListener(new Button.ClickListener() {
//				@Override
//				public void buttonClick(Button.ClickEvent clickEvent) {
//					addNewClient();
//				}
//			});
//			layout.addComponent(bNewClient);

			TabSheet ts = new TabSheet();
			layout.addComponent(ts);
			ts.addTab(grClients, "Clients");
			ts.addTab(grCredits, "Credits");
			//ts.addTab(grNowUser, "NowClient");
			grClients.setSizeFull();
			grCredits.setSizeFull();
			grClients.addItemClickListener((ItemClickListener<ClientInf>) itemClick -> {
                grCredits.setItems(itemClick.getItem().getCredits());
                ts.setSelectedTab(grCredits);
            });

			setContent(layout);
		}

		private double getFromAPI(double v) {
			RestTemplate restTemplate = new RestTemplate();

			return v * restTemplate.getForObject("http://api.fixer.io/latest?base=RUB&symbols=USD", ServiceAnswerDTO.class).getRates().get("USD");
		}

		@Autowired
		JdbcTemplate template;

		private void fillClientStorage() {
			ClientStorage.setClientList(template.query("SELECT * FROM customers", (rs, rownum)-> new ClientInf(
				rs.getInt("id"), rs.getString("passport"), true, rs.getString("oldpas"),
					rs.getDate("birthdate"), rs.getString("name"), rs.getString("family"),
					rs.getString("father"), rs.getString("phone")
			)));
			ClientStorage.getClientList().forEach((cl)->cl.setCredits(template.query(
					"SELECT * FROM credits WHERE clientid=?", new Object[] {cl.getId()},
					(rs, rownum) -> new CreditInf(rs.getInt("clientid"), rs.getDouble("sum"),
							rs.getDouble("sumtopay"), rs.getDouble("sumpaid"),
							rs.getDouble("percent"), rs.getDate("datetoclose"))
			)));
		}
	}
}
