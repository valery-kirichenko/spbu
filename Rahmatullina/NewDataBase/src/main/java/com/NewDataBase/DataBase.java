package com.NewDataBase;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.context.annotation.Configuration;
import org.springframework.dao.DataAccessException;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.PreparedStatementCallback;
import org.springframework.stereotype.Repository;

import java.sql.PreparedStatement;
import java.sql.SQLException;

/**
 * Created by Я on 05.05.2017.
 */
@Configuration
public class DataBase implements CommandLineRunner {
    @Autowired
    JdbcTemplate template;


    String query = "INSERT INTO clients (id,first_name, last_name, mid_name,phone,new_passport,dat,old_passport) VALUES (?,?,?,?,?,?,?,?);";
    String query2 = "INSERT INTO credits (client_id,loan,whole_loan,paid_sum,percent,dat) VALUES (?,?,?,?,?,?);";

    @Override
    public void run(String... strings) throws Exception {

        template.execute("DROP TABLE IF EXISTS clients");
        template.execute("CREATE TABLE   clients(" +
                "id VARCHAR(255), first_name VARCHAR(255), last_name VARCHAR(255)," +
                " mid_name VARCHAR(255),phone VARCHAR(255), new_passport VARCHAR(255)," +
                "dat VARCHAR(255) , old_passport VARCHAR(255))");
        template.execute("DROP TABLE IF EXISTS credits");
        template.execute("CREATE TABLE credits(" +
                "client_id VARCHAR(255),loan VARCHAR(255), whole_loan VARCHAR(255), paid_sum VARCHAR(255)," +
                "percent VARCHAR(255), dat VARCHAR(255))");
        template.execute("ALTER TABLE credits ADD FOREIGN KEY ( client_id ) REFERENCES clients( id ) ;");



    }
}
