package com.database;

import com.database.Cells.Client;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.PreparedStatementCallback;
import org.springframework.stereotype.Controller;

import java.sql.Date;
import java.sql.PreparedStatement;
import java.time.LocalDate;
import java.util.List;

@Controller
public class MainControllerClass implements MainController {

    @Autowired
    JdbcTemplate template;

    @Override
    public void createClient(String name, String phoneNumber, String birthday, String passport, String oldPassport) {
        List<Client> temp;
        temp = template.query("SELECT * FROM clients WHERE passport = '" + passport + "' LIMIT 1", new ClientRowMapper());
        if (temp.isEmpty()) {
            temp = template.query("SELECT * FROM clients WHERE oldPassport = '" + passport + "' LIMIT 1", new ClientRowMapper());
            if (temp.isEmpty()) {
                temp = template.query("SELECT * FROM clients WHERE passport = '" + oldPassport + "' LIMIT 1", new ClientRowMapper());
                if (temp.isEmpty()) {
                    template.execute("INSERT INTO clients (name, phoneNumber, birthday, passport, oldPassport) VALUES (?,?,?,?,?);",
                            (PreparedStatementCallback<Object>) preparedStatement -> {
                                preparedStatement.setString(1, name);
                                preparedStatement.setString(2, phoneNumber);
                                preparedStatement.setString(3, birthday);
                                preparedStatement.setString(4, passport);
                                preparedStatement.setString(5, oldPassport);
                                return preparedStatement.execute();
                            });
                }
                else throw new IllegalArgumentException("Client's Old Passport Coincides With Existed Passport");
            }
            else throw new IllegalArgumentException("Client's Passport Coincides With Existed Old Passport");
        }
        else throw new IllegalArgumentException("Client's Passport Coincides With Existed Passport");
    }

    @Override
    public void updateClient(Integer ID, String name, String phoneNumber, String birthday, String passport, String oldPassport) {
        template.execute("UPDATE clients SET name = ?, phoneNumber = ?, birthday = ?, passport = ?, oldPassport = ? WHERE id = '" + ID + "'",
                (PreparedStatementCallback<Object>) preparedStatement -> {
                    preparedStatement.setString(1, name);
                    preparedStatement.setString(2, phoneNumber);
                    preparedStatement.setString(3, birthday);
                    preparedStatement.setString(4, passport);
                    preparedStatement.setString(5, oldPassport);
                    return preparedStatement.execute();
                });
    }

    @Override
    public void createCredit(Integer clientID, Double creditWithoutPercent, Double cashPaid, Double creditWithPercent, Double percent, LocalDate deadline) throws org.springframework.dao.DataIntegrityViolationException{
        if (creditWithPercent > cashPaid) {
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
        else throw new IllegalArgumentException("Cash Paid Is Equal or Bigger Then Total Cash");
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
