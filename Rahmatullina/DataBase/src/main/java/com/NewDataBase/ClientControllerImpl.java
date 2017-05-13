package com.NewDataBase;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.dao.DataAccessException;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.PreparedStatementCallback;
import org.springframework.stereotype.Controller;

import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.List;

/**
 * Created by Я on 05.05.2017.
 */
@Controller
public class ClientControllerImpl implements ClientController {

    @Autowired
    JdbcTemplate template;

    String query = "INSERT INTO clients (id,first_name, last_name, mid_name,phone,new_passport,dat,old_passport) VALUES (?,?,?,?,?,?,?,?);";

    @Override
    public void saveNewClient(Clients newClient) {
        template.execute(query, new PreparedStatementCallback<Object>() {
            @Override
            public Object doInPreparedStatement(PreparedStatement
                                                        preparedStatement) throws SQLException, DataAccessException {
                preparedStatement.setString(1, newClient.getClientId());
                preparedStatement.setString(2, newClient.getName());
                preparedStatement.setString(3, newClient.getSurName());
                preparedStatement.setString(4, newClient.getMidName());
                preparedStatement.setString(5, newClient.getPhone());
                preparedStatement.setString(6, newClient.getNewPassport());
                preparedStatement.setString(7, newClient.getData2());
                preparedStatement.setString(8, newClient.getOldPassport());


                return preparedStatement.execute();
            }
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
