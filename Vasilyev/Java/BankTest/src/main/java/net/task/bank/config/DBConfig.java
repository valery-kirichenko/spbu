package net.task.bank.config;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;


@Repository
public class DBConfig implements CommandLineRunner{
    @Autowired
    private JdbcTemplate template;

    @Override
    public void run(String... strings) throws Exception {
        template.execute("DROP TABLE IF EXISTS clients");
        template.execute("CREATE TABLE clients(ID INTEGER, firstName VARCHAR(255)," +
                         "middleName VARCHAR(255), lastName VARCHAR(255), phone VARCHAR(20), passport INTEGER," +
                         "oldPassport INTEGER, birthDay VARCHAR(20))");
        template.execute("DROP TABLE IF EXISTS credits");
        template.execute("CREATE TABLE credits(ID INTEGER AUTO_INCREMENT, clientID INTEGER, amount DOUBLE," +
                         "percent DOUBLE, paidSum DOUBLE, needPaid DOUBLE, closingDate DATE)");
        template.execute("ALTER TABLE credits ADD FOREIGN KEY (clientID) REFERENCES clients(ID)");
    }
}
