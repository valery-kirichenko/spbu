package net.task.bank.config;

import javax.annotation.PostConstruct;
import javax.sql.DataSource;

import net.task.bank.rsdata.DataReader;
import net.task.bank.rsdata.Reader;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.jdbc.core.namedparam.NamedParameterJdbcTemplate;


@Configuration
public class BankTestAppConfig {
    @Bean
    public Reader getReader() {
        return new DataReader();
    }

    @Qualifier("dataSource")
    @Autowired
    private DataSource dataSource;

    @Bean
    public NamedParameterJdbcTemplate getNamedParameterJdbcTemplate() {
        return new NamedParameterJdbcTemplate(dataSource);
    }

    /*@PostConstruct
    public void startDBManager() {
        //h2
        DatabaseManagerSwing.main(new String[] { "--url", "jdbc:h2:mem:testdb", "--user", "sa", "--password", "" });
    }*/
}
