package com.NewDataBase;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.PreparedStatementCallback;
import org.springframework.stereotype.Controller;

import java.util.List;


@Controller
public class ClientControllerImpl implements ClientController {
    @Autowired
    private JdbcTemplate template;

    String query = "INSERT INTO clients (id, first_name, last_name, mid_name, phone, new_passport, dat, old_passport) VALUES (?,?,?,?,?,?,?,?);";

    @Override
    public void saveNewClient(Clients newClient) {
        System.out.println(newClient.getId());
        template.execute(query, (PreparedStatementCallback<Object>) preparedStatement -> {
            preparedStatement.setInt(1, newClient.getId());
            preparedStatement.setString(2, newClient.getName());
            preparedStatement.setString(3, newClient.getSurName());
            preparedStatement.setString(4, newClient.getMidName());
            preparedStatement.setString(5, newClient.getPhone());
            preparedStatement.setString(6, newClient.getNewPassport());
            preparedStatement.setString(7, newClient.getData());
            preparedStatement.setString(8, newClient.getOldPassport());

            return preparedStatement.execute();
        });
    }

    @Override
    public List<Clients> getAllClients() {
        return template.query("SELECT * FROM clients ", new ClientRowMapper());
    }

    @Override
    public void deleteClient(int client_id) {
        template.execute("DELETE FROM clients WHERE id = " + client_id);
    }

    @Override
    public Clients getByID(int client_id) {
        return template.query("SELECT * FROM clients  WHERE id = " + client_id,
                new ClientRowMapper()).stream().findFirst().orElse(null);
    }

    @Override
    public void updateClient(Clients clientUpdate) {

    }
}
