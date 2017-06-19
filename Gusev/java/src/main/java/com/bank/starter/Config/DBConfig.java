package com.bank.starter.Config;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.context.annotation.Configuration;
import org.springframework.jdbc.core.JdbcTemplate;

/**
 * Created by gusef on 19.06.2017.
 */
@Configuration
public class DBConfig implements CommandLineRunner {
    @Autowired
    private JdbcTemplate template;

    @Override
    public void run(String... strings) throws Exception {
        template.execute("CREATE TABLE IF NOT EXISTS clients(id INTEGER, name VARCHAR(255)," +
                "surName VARCHAR(255), lastName VARCHAR(255), phone VARCHAR(20), passport INTEGER," +
                "oldPass INTEGER, birthday VARCHAR(20))");
        template.execute("CREATE TABLE IF NOT EXISTS credits(NewID INTEGER AUTO_INCREMENT, id INTEGER, startSum DOUBLE," +
                "paidSum DOUBLE, allSum DOUBLE, percent DOUBLE, finishDate DATE)");
        template.execute("ALTER TABLE credits ADD FOREIGN KEY (id) REFERENCES clients(id)");
    }

}
