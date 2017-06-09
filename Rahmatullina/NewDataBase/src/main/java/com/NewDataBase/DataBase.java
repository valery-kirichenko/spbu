package com.NewDataBase;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.context.annotation.Configuration;
import org.springframework.jdbc.core.JdbcTemplate;



@Configuration
public class DataBase implements CommandLineRunner {
    @Autowired
    private JdbcTemplate template;

    String query = "INSERT INTO clients (id, first_name, last_name, mid_name,phone, new_passport, dat, old_passport) VALUES (?,?,?,?,?,?,?,?);";
    String query2 = "INSERT INTO credits (client_id, loan, whole_loan, paid_sum, percent, dat) VALUES (?,?,?,?,?,?);";

    @Override
    public void run(String... strings) throws Exception {
        template.execute("CREATE TABLE IF NOT EXISTS  clients(" +
                "id INTEGER, first_name VARCHAR(255), last_name VARCHAR(255)," +
                " mid_name VARCHAR(255),phone VARCHAR(255), new_passport VARCHAR(255)," +
                "dat VARCHAR(255) , old_passport VARCHAR(255))");
        template.execute("CREATE TABLE IF NOT EXISTS credits(" +
                "client_id INTEGER,loan VARCHAR(255), whole_loan VARCHAR(255), paid_sum VARCHAR(255)," +
                "percent VARCHAR(255), dat VARCHAR(255))");
        template.execute("ALTER TABLE credits ADD FOREIGN KEY (client_id) REFERENCES clients(id) ;");
    }
}
