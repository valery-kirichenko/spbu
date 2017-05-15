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
    @Autowired
    GettingClientFromFile getListClient;

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

        for (Clients client : getListClient.getClient()) {
            template.execute(query, (PreparedStatementCallback<Object>) preparedStatement -> {
                preparedStatement.setString(1, client.getClientId());
                preparedStatement.setString(2, client.getName());
                preparedStatement.setString(3, client.getSurName());
                preparedStatement.setString(4, client.getMidName());
                preparedStatement.setString(5, client.getPhone());
                preparedStatement.setString(6, client.getNewPassport());
                preparedStatement.setString(7, client.getData2());
                preparedStatement.setString(8, client.getOldPassport());


                return preparedStatement.execute();
            });
        }
        for (Clients client : getListClient.getClient()) {
            for (Credits credit : client.getCredit()) {

                template.execute(query2, (PreparedStatementCallback<Object>) preparedStatement -> {
                    preparedStatement.setString(1, credit.getId());
                    preparedStatement.setString(2, credit.getLoan());
                    preparedStatement.setString(3, credit.getWholeLoan());
                    preparedStatement.setString(4, credit.getPaidSum());
                    preparedStatement.setString(5, credit.getPercent());
                    preparedStatement.setString(6, credit.getCrediitData2());

                    return preparedStatement.execute();
                });
            }
        }
    }
}
