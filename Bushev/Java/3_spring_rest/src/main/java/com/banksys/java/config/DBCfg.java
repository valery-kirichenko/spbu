package com.banksys.java.config;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.context.annotation.Configuration;
import org.springframework.jdbc.core.JdbcTemplate;

@Configuration
public class DBCfg implements CommandLineRunner {
    public static final String CLIENTS_TABLE = "BANK_CLIENTS";
    public static final String CREDITS_TABLE = "BANK_CREDITS";

    @Autowired
    JdbcTemplate template;

    @Override
    public void run(String... strings) throws Exception {
        // clients table
        String structure = "(id INT NOT NULL," +
                "name TEXT NOT NULL," +
                "surname TEXT NOT NULL," +
                "middlename TEXT NOT NULL," +
                "phone TEXT NOT NULL," +
                "passport TEXT NOT NULL," +
                "date TEXT NOT NULL," +
                "oldPassport TEXT NOT NULL," +
                "PRIMARY KEY (id))";
        createTable(CLIENTS_TABLE, structure);

        // the credits one
        structure = "(id INT NOT NULL," +
                "amount REAL NOT NULL," +
                "percent REAL NOT NULL," +
                "payed REAL NOT NULL," +
                "needed REAL NOT NULL," +
                "date TEXT NOT NULL)";
        createTable(CREDITS_TABLE, structure);
    }

    private void createTable(String name, String structure) {
        template.execute("CREATE TABLE IF NOT EXISTS " + name + structure);
    }
}
