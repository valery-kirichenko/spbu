package com.banksys.java;

import com.vaadin.spring.annotation.SpringComponent;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.BatchPreparedStatementSetter;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Component;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.bind.annotation.RestController;

import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.ArrayList;

@Component
public class RestStorage {
    private static final String CLIENTS_TABLE = "BANK_CLIENTS";
    private static final String CREDITS_TABLE = "BANK_CREDITS";

    public ArrayList<Client> getClients() {
        return clients;
    }

    public void setClients(ArrayList<Client> clients) {
        this.clients = clients;
    }

    public ArrayList<Credit> getCredits() {
        return credits;
    }

    public void setCredits(ArrayList<Credit> credits) {
        this.credits = credits;
    }

    private ArrayList<Client> clients;
    private ArrayList<Credit> credits;

    @Autowired
    public JdbcTemplate template;

    public void init() {
        if (false) {
            //initClients();
            //initCredits();

            //DefaultReader.makingLinks(this.clients, this.credits);
        } else {
            DefaultReader.readFromFiles(this);

            // clients table
            String structure = "(id INT NOT NULL," +
                    "name TEXT NOT NULL," +
                    "surname TEXT NOT NULL," +
                    "middlename TEXT NOT NULL," +
                    "phone INT NOT NULL," +
                    "passport INT NOT NULL," +
                    "date TEXT NOT NULL," +
                    "oldPassport INT NOT NULL)";
            createTable(CLIENTS_TABLE, structure);

            // the credits one
            structure = "(id INT NOT NULL," +
                    "amount REAL NOT NULL," +
                    "percent REAL NOT NULL," +
                    "payed REAL NOT NULL," +
                    "needed REAL NOT NULL," +
                    "date TEXT NOT NULL)";
            createTable(CREDITS_TABLE, structure);

            insertClients();
            //insertCredits();

            System.out.println("Default data has been inserted");
        }
    }

    private void createTable(String name, String structure) {
        template.execute("CREATE TABLE IF NOT EXISTS " + name + structure);
    }

    private void insertClients() {
        template.batchUpdate("INSERT INTO " + CLIENTS_TABLE
                + " (id, name, surname, middlename, phone, passport, date, oldPassport)"
                + " VALUES (?, ?, ?, ?, ?, ?, ?, ?)", new BatchPreparedStatementSetter() {
            @Override
            public void setValues(PreparedStatement statement, int i) throws SQLException {
                Client client = clients.get(i);
                statement.setInt(1, Integer.parseInt(client.getId()));
                statement.setString(2, client.getName());
                statement.setString(3, client.getSurname());
                statement.setString(4, client.getMiddlename());
                statement.setLong(5, Long.parseLong(client.getPhone()));
                statement.setInt(6, Integer.parseInt(client.getPassport()));
                statement.setString(7, client.getDate().toString());
                statement.setInt(8, client.getOldPassport().isEmpty() ? 0 : Integer.parseInt(client.getOldPassport()));
            }

            @Override
            public int getBatchSize() {
                return clients.size();
            }
        });
    }

    private void insertCredits(Credit credit) throws Exception {
//        statement = connection.prepareStatement("INSERT INTO " + CREDITS_TABLE + " (id, amount, percent, payed, needed, date) VALUES (?, ?, ?, ?, ?, ?)");
//
//        statement.setInt(1, Integer.parseInt(credit.id));
//        statement.setDouble(2, Double.parseDouble(credit.amount));
//        statement.setDouble(3, Double.parseDouble(credit.percent));
//        statement.setDouble(4, Double.parseDouble(credit.payed));
//        statement.setDouble(5, Double.parseDouble(credit.needed));
//        statement.setString(6, credit.date.toString());
//        statement.executeUpdate();
    }
}
