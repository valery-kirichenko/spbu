package com.bank.starter.DataBaseSystem.ClientControllers;

import com.bank.starter.models.Client;
import javafx.print.Collation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.PreparedStatementCallback;
import org.springframework.stereotype.Controller;

import java.lang.reflect.Array;
import java.util.Collections;
import java.util.List;

/**
 * Created by gusef on 18.06.2017.
 */
@Controller
public class ClientControler implements DBClientControler {

    @Autowired
    private JdbcTemplate template;

    private final String CLIENTS_TABLE_NAME = "clients";
    private final String INSERT_QUERY = "INSERT INTO " + CLIENTS_TABLE_NAME +
            " (id, name, surName, lastName, phone, passport, oldPass, birthday)" +
            "VALUES (?,?,?,?,?,?,?,?);";

    @Override
    public void addNewClient(Client locCLient) {

        if (!Contains(locCLient)) {
            template.execute(INSERT_QUERY, (PreparedStatementCallback<Object>) preparedStatement -> {
                java.sql.Date sqlDate = java.sql.Date.valueOf(locCLient.getBirthDate());

                preparedStatement.setInt(1, locCLient.getNowId());
                preparedStatement.setString(2, locCLient.getName());
                preparedStatement.setString(3, locCLient.getSurName());
                preparedStatement.setString(4, locCLient.getLastName());
                preparedStatement.setString(5, locCLient.getPhone());
                preparedStatement.setInt(6, locCLient.getPass());
                if(locCLient.getOldPass() != -1)
                     preparedStatement.setInt(7, locCLient.getOldPass());
                preparedStatement.setDate(8, sqlDate);
                return preparedStatement.execute();
            });
        }
    }

    @Override
    public void deleteClient(Integer id) {

    }

    @Override
    public List<Client> getAllClients() {
        return null;
    }

    @Override
    public Client egtClient(Integer id) {
        return null;
    }

    @Override
    public void upadateClient(Client locClient) {

    }

    @Override
    public boolean Contains(Client locClinet) {
        return false;
    }
}
