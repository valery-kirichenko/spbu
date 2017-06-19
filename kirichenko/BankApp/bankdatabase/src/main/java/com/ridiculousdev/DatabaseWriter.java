package com.ridiculousdev;

import com.ridiculousdev.bank.Client;
import com.ridiculousdev.bank.Credit;
import com.ridiculousdev.bank.FileStorage;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.jdbc.core.BatchPreparedStatementSetter;
import org.springframework.jdbc.core.JdbcTemplate;

import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.SQLException;

@SpringBootApplication
public class DatabaseWriter implements CommandLineRunner {
    public static void main(String[] args) {
        SpringApplication.run(DatabaseWriter.class, args);
    }

    @Autowired
    JdbcTemplate template;

    @Autowired
    private FileStorage storage;

    @Override
    public void run(String... strings) throws Exception {
        System.out.println("Database writer started");
        System.out.println();
        String sql = "REPLACE INTO clients " +
                "(id, passport, firstName, lastName, middleName, phoneNumber, birthDate) VALUES (?, ?, ?, ?, ?, ?, ?)";

        template.batchUpdate(sql, new BatchPreparedStatementSetter() {
            @Override
            public void setValues(PreparedStatement insertUser, int i) throws SQLException {
                Client client = storage.clients.get(i);
                insertUser.setInt(1, client.getId());
                insertUser.setInt(2, client.getPassport());
                insertUser.setString(3, client.getFirstName());
                insertUser.setString(4, client.getLastName());
                insertUser.setString(5, client.getMiddleName());
                insertUser.setString(6, client.getPhoneNumber());
                insertUser.setDate(7, Date.valueOf(client.getBirthDate()));
            }

            @Override
            public int getBatchSize() {
                return storage.clients.size();
            }
        });

        template.update("DELETE FROM credits");
        sql = "INSERT INTO credits (clientId, total, rate, paid, payable, closingDate) VALUES (?, ?, ?, ?, ?, ?)";

        for (Client client : storage.clients) {
            template.batchUpdate(sql, new BatchPreparedStatementSetter() {
                @Override
                public void setValues(PreparedStatement insertCredit, int i) throws SQLException {
                    Credit credit = client.getCredits().get(i);
                    insertCredit.setInt(1, credit.getId());
                    insertCredit.setDouble(2, credit.getTotal());
                    insertCredit.setDouble(3, credit.getRate());
                    insertCredit.setDouble(4, credit.getPaid());
                    insertCredit.setDouble(5, credit.getPayable());
                    insertCredit.setDate(6, Date.valueOf(credit.getClosingDate()));
                }

                @Override
                public int getBatchSize() {
                    return client.getCredits().size();
                }
            });
        }

        System.out.println("Done!");

    }
}
