package com.database;

import com.database.Cells.Client;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.PreparedStatementCallback;
import org.springframework.stereotype.Controller;

import java.sql.Date;
import java.time.LocalDate;
import java.util.List;

@Controller
public class MainControllerClass implements MainController {

    @Autowired
    JdbcTemplate template;

    @Override
    public void createClient(String name, String phoneNumber, String birthday, String passport, String oldPassport) {

        List<Client> temp = template.query("SELECT * FROM clients WHERE passport = '" + passport + "' LIMIT 1", new ClientRowMapper());

        if (temp.isEmpty())
        template.execute("INSERT INTO clients (name, phoneNumber, birthday, passport, oldPassport) VALUES (?,?,?,?,?);",
                (PreparedStatementCallback<Object>) preparedStatement -> {

            preparedStatement.setString(1, name);
            preparedStatement.setString(2, phoneNumber);
            preparedStatement.setString(3, birthday);
            preparedStatement.setString(4, passport);
            preparedStatement.setString(5, oldPassport);
            return preparedStatement.execute();
        });
        else throw new IllegalArgumentException();
    }

    @Override
    public void createCredit(Integer clientID, Double creditWithoutPercent, Double cashPaid, Double creditWithPercent, Double percent, LocalDate deadline) {

        //
        //

        template.execute("INSERT INTO credits (clientID, cashTotal, cashPaid, cashWithPercent, percent, deadline) VALUES (?,?,?,?,?,?);",
                (PreparedStatementCallback<Object>) preparedStatement -> {

            preparedStatement.setInt(1, clientID);
            preparedStatement.setDouble(2, creditWithoutPercent);
            preparedStatement.setDouble(3, cashPaid);
            preparedStatement.setDouble(4, creditWithPercent);
            preparedStatement.setDouble(5, percent);
            preparedStatement.setDate(6, Date.valueOf(deadline));
            return preparedStatement.execute();

        });
    }

    @Override
    public void deleteClient(Integer clientID) {
        template.execute("DELETE FROM credits WHERE clientID =" + clientID);
        template.execute("DELETE FROM clients WHERE id =" + clientID);
    }

    @Override
    public void deleteCredit(Integer creditID) {
        template.execute("DELETE FROM credits WHERE id =" + creditID);
    }
}
