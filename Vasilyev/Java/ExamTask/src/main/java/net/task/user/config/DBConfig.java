package net.task.user.config;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.context.annotation.Configuration;
import org.springframework.jdbc.core.JdbcTemplate;


@Configuration
public class DBConfig implements CommandLineRunner {
    @Autowired
    private JdbcTemplate template;

    @Override
    public void run(String... strings) throws Exception {
        template.execute("DROP TABLE IF EXISTS users");
        template.execute("CREATE TABLE IF NOT EXISTS users(" +
                "gender VARCHAR(20), " +
                "title VARCHAR(255), first VARCHAR(255), last VARCHAR(255), " +
                "street VARCHAR(255), city VARCHAR(255), state VARCHAR(255), postcode VARCHAR(255)," +
                "email VARCHAR(255), " +
                "dob VARCHAR(255), " +
                "phone VARCHAR(255), " +
                "username VARCHAR(255), password VARCHAR(255), salt VARCHAR(255), md5 VARCHAR(255), sha1 VARCHAR(255), sha256 VARCHAR(255)," +
                "registered VARCHAR(255), " +
                "cell VARCHAR(255), " +
                "name VARCHAR(255), value VARCHAR(255), " +
                "large VARCHAR(255), medium VARCHAR(255), thumbnail VARCHAR(255), " +
                "nat VARCHAR(20))");
    }
}
