package com.database;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.PreparedStatementCallback;
import org.springframework.stereotype.Repository;

import java.sql.Date;
import java.time.LocalDate;

@Repository
public class H2Base implements CommandLineRunner{

    @Autowired
    JdbcTemplate template;
    String query = "INSERT INTO clients (name, phoneNumber, birthday, passport, oldPassport) VALUES (?,?,?,?,?);";

    @Override
    public void run(String... strings) throws Exception {
        template.execute("CREATE TABLE clients(id INTEGER AUTO_INCREMENT, name VARCHAR(255), phoneNumber VARCHAR(20), birthday VARCHAR(20), passport VARCHAR(6), oldPassport VARCHAR(6))");
        template.execute("CREATE TABLE credits(id INTEGER AUTO_INCREMENT, clientID INTEGER, cashTotal DOUBLE, cashPaid DOUBLE, cashWithPercent DOUBLE, percent DOUBLE, deadline DATE)");
        template.execute("ALTER TABLE credits ADD FOREIGN KEY (clientID) REFERENCES clients(id);");

        template.execute("INSERT INTO clients (name, phoneNumber, birthday, passport, oldPassport) VALUES (?,?,?,?,?);", (PreparedStatementCallback<Object>) preparedStatement -> {
            preparedStatement.setString(1, "Mike");
            preparedStatement.setString(2, "+79814444444");
            preparedStatement.setString(3, "25.08.1952");
            preparedStatement.setInt(4, 666666);
            preparedStatement.setInt(5, 555555);
            return preparedStatement.execute();
        });
        template.execute("INSERT INTO clients (name, phoneNumber, birthday, passport, oldPassport) VALUES (?,?,?,?,?);", (PreparedStatementCallback<Object>) preparedStatement -> {
            preparedStatement.setString(1, "Dan");
            preparedStatement.setString(2, "+79814545444");
            preparedStatement.setString(3, "25.08.1957");
            preparedStatement.setInt(4, 666876);
            preparedStatement.setInt(5, 786555);
            return preparedStatement.execute();
        });
        template.execute("INSERT INTO credits (clientID, cashTotal, cashPaid, cashWithPercent, percent, deadline) VALUES (?,?,?,?,?,?);", (PreparedStatementCallback<Object>) preparedStatement -> {
            preparedStatement.setInt(1, 1);
            preparedStatement.setDouble(2, 10000);
            preparedStatement.setDouble(3, 2000);
            preparedStatement.setDouble(4, 15000);
            preparedStatement.setDouble(5, 50);
            preparedStatement.setDate(6, Date.valueOf(LocalDate.now()));
            return preparedStatement.execute();
        });
        template.execute("INSERT INTO credits (clientID, cashTotal, cashPaid, cashWithPercent, percent, deadline) VALUES (?,?,?,?,?,?);", (PreparedStatementCallback<Object>) preparedStatement -> {
            preparedStatement.setInt(1, 1);
            preparedStatement.setDouble(2, 12000);
            preparedStatement.setDouble(3, 3000);
            preparedStatement.setDouble(4, 18000);
            preparedStatement.setDouble(5, 75);
            preparedStatement.setDate(6, Date.valueOf(LocalDate.now()));
            return preparedStatement.execute();
        });
    }
}
