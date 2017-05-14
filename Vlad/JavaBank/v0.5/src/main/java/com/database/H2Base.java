package com.database;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;

@Repository
public class H2Base implements CommandLineRunner{

    @Autowired
    JdbcTemplate template;

    @Override
    public void run(String... strings) throws Exception {
        template.execute("CREATE TABLE clients(id INTEGER AUTO_INCREMENT, name VARCHAR(255), phoneNumber VARCHAR(20), birthday VARCHAR(20), passport INTEGER, oldPassport INTEGER )");
        template.execute("CREATE TABLE credits(id INTEGER AUTO_INCREMENT, clientID INTEGER, cashTotal DOUBLE, cashPaid DOUBLE, cashWithPercent DOUBLE, percent DOUBLE, deadline DATE)");
        template.execute("ALTER TABLE credits ADD FOREIGN KEY (clientID) REFERENCES clients(id)");
    }
}
