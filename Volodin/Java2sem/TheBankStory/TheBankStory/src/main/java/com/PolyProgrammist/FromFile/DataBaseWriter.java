package com.PolyProgrammist.FromFile;

import com.PolyProgrammist.Customer;
import com.PolyProgrammist.TheBankStoryApp;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.dao.DataAccessException;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.PreparedStatementCallback;
import org.springframework.stereotype.Service;

import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

@Service
public class DataBaseWriter {

    private static void doThings() {
        FileBaseInterpreter rd = new FileBaseInterpreter("testcli.omg", "credits.omg");
        rd.interpret();
    }

    @Autowired
    JdbcTemplate template;

    private static final Logger log = LoggerFactory.getLogger(TheBankStoryApp.class);

    public void createDataBase(){
        doThings();
        customersInsert();
        creditsInsert();
        log.info("Done");
    }

    void customersInsert(){
        template.execute("DROP TABLE customers IF EXISTS");
        template.execute("CREATE TABLE customers(" +
                "id INTEGER PRIMARY KEY, name VARCHAR(255), family VARCHAR(255), father VARCHAR (255)," +
                " phone VARCHAR (255), passport VARCHAR (255), oldpas VARCHAR (255), birthdate DATE );");

        String query = "INSERT INTO customers (id, name, family, father, phone, passport, oldpas, birthdate)"+
                "VALUES (?, ?, ?, ?, ?, ?, ?, ?);";

        for (ClientInf cl :  ClientStorage.getClientList()) {
            template.execute(query, new PreparedStatementCallback<Object>() {
                @Override
                public Object doInPreparedStatement(PreparedStatement preparedStatement) throws SQLException, DataAccessException {
                    preparedStatement.setInt(1, cl.getId());
                    preparedStatement.setString(2, cl.getName());
                    preparedStatement.setString(3, cl.getFamily());
                    preparedStatement.setString(4, cl.getFather());
                    preparedStatement.setString(5, cl.getPhone());
                    preparedStatement.setString(6, cl.getPassport());
                    preparedStatement.setString(7, cl.getOldpas());
                    preparedStatement.setDate(8, new java.sql.Date(cl.getBirthDate().getTime()));

                    return preparedStatement.execute();
                }
            });
        }
    }

    void creditsInsert(){
        template.execute("DROP TABLE credits IF EXISTS");
        template.execute("CREATE TABLE credits(clientid INTEGER, sum DOUBLE , sumtopay DOUBLE , sumpaid DOUBLE , " +
                "percent DOUBLE , datetoclose DATE );");

        String query = "INSERT INTO credits (clientid, sum, sumtopay, sumpaid, percent, datetoclose)"+
                "VALUES (?, ?, ?, ?, ?, ?);";

        for (CreditInf cr :  ClientStorage.getCreditList()) {
            template.execute(query, new PreparedStatementCallback<Object>() {
                @Override
                public Object doInPreparedStatement(PreparedStatement preparedStatement) throws SQLException, DataAccessException {
                    preparedStatement.setInt(1, cr.getClientId());
                    preparedStatement.setDouble(2, cr.getSum());
                    preparedStatement.setDouble(3, cr.getSumToPay());
                    preparedStatement.setDouble(4, cr.getSumPaid());
                    preparedStatement.setDouble(5, cr.getPercent());
                    preparedStatement.setDate(6, new java.sql.Date(cr.getDateToClose().getTime()));

                    return preparedStatement.execute();
                }
            });
        }
    }

    void testDB(){
        log.info("Creating tables");

        template.execute("DROP TABLE customers IF EXISTS");
        template.execute("CREATE TABLE customers(" +
                "id SERIAL, first_name VARCHAR(255), last_name VARCHAR(255))");

        // Split up the array of whole names into an array of first/last names
        List<Object[]> splitUpNames = Arrays.asList("John Woo", "Jeff Dean", "Josh Bloch", "Josh Long").stream()
                .map(name -> name.split(" "))
                .collect(Collectors.toList());

        // Use a Java 8 stream to print out each tuple of the list
        splitUpNames.forEach(name -> log.info(String.format("Inserting customer record for %s %s", name[0], name[1])));

        // Uses JdbcTemplate's batchUpdate operation to bulk load data
        template.batchUpdate("INSERT INTO customers(first_name, last_name) VALUES (?,?)", splitUpNames);

        log.info("Querying for customer records where first_name = 'Josh':");
        template.query(
                "SELECT id, first_name, last_name FROM customers WHERE first_name = ?", new Object[] { "Josh" },
                (rs, rowNum) -> new Customer(rs.getLong("id"), rs.getString("first_name"), rs.getString("last_name"))
        ).forEach(customer -> log.info(customer.toString()));
    }
}
