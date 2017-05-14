package com.database;

import com.database.Cells.Client;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.PreparedStatementCallback;
import org.springframework.stereotype.Controller;
import java.util.List;

@Controller
public class ClientsControllerClass implements ClientsController {

    @Autowired
    JdbcTemplate template;
    String cmd = "INSERT INTO clients (name, phoneNumber, birthday, passport, oldPassport) VALUES (?,?,?,?,?);";

    @Override
    public void saveNewClient(Client toCreate) {
        template.execute(cmd, (PreparedStatementCallback<Object>) preparedStatement -> {
            preparedStatement.setString(1, toCreate.getName());
            preparedStatement.setString(2, toCreate.getPhoneNumber());
            preparedStatement.setString(3, toCreate.getBirthday());
            preparedStatement.setInt(4, toCreate.getPassport());
            preparedStatement.setInt(5, toCreate.getOldPassport());
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
}
