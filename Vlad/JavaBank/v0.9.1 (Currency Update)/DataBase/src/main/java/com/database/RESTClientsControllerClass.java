package com.database;

import com.database.Cells.Client;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.PreparedStatementCallback;
import org.springframework.jdbc.core.RowMapper;
import org.springframework.stereotype.Controller;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;

@Controller
public class RESTClientsControllerClass implements RESTClientsController {

    @Autowired
    JdbcTemplate template;
    String cmd = "INSERT INTO clients (name, phoneNumber, birthday, passport, oldPassport) VALUES (?,?,?,?,?);";

    @Override
    public void saveNewClient(Client toCreate) {
        template.execute(cmd, (PreparedStatementCallback<Object>) preparedStatement -> {
            preparedStatement.setString(1, toCreate.getName());
            preparedStatement.setString(2, toCreate.getPhoneNumber());
            preparedStatement.setString(3, toCreate.getBirthday());
            preparedStatement.setString(4, toCreate.getPassport());
            preparedStatement.setString(5, toCreate.getOldPassport());
            return preparedStatement.execute();
        });
    }

    @Override
    public List<Client> getAllClients() {
        return template.query("SELECT * FROM clients", new ClientRowMapper());
    }

    @Override
    public void deleteClient(Long clientId) {
        template.execute("DELETE FROM clients WHERE id = " + clientId);
    }

    @Override
    public Client getById(Long clientId) {
        return template.query("SELECT * FROM clients WHERE id = " + clientId, new ClientRowMapper()).stream().findFirst().orElse(null);
    }

    @Override
    public Integer getMaxID() {
        List<Integer> IDs = template.query("SELECT * FROM clients", (resultSet, i) -> resultSet.getInt("id"));
        if (IDs.isEmpty())
            return 0;
        else
            return IDs.stream().max(Integer::compareTo).get();
    }
}
