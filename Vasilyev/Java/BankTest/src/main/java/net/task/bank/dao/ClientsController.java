package net.task.bank.dao;

import net.task.bank.models.Client;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.PreparedStatementCallback;
import org.springframework.stereotype.Controller;

import java.util.List;


@Controller
public class ClientsController implements DBClientsController {
    @Autowired
    private JdbcTemplate template;

    final String CLIENTS_TABLE_NAME = "clients";
    final String INSERT_QUERY = "INSERT INTO " + CLIENTS_TABLE_NAME + " (ID, firstName, middleName, lastName, phone, passport, oldPassport, birthday)" +
                   "VALUES (?,?,?,?,?,?,?,?);";

    @Override
    public void saveNewClient(Client toCreate) {
        template.execute(INSERT_QUERY, (PreparedStatementCallback<Object>) preparedStatement -> {
            java.sql.Date sqlDate = new java.sql.Date(toCreate.getBirthday().getTime());

            preparedStatement.setInt(1, toCreate.getID());
            preparedStatement.setString(2, toCreate.getFirstName());
            preparedStatement.setString(3, toCreate.getMiddleName());
            preparedStatement.setString(4, toCreate.getLastName());
            preparedStatement.setString(5, toCreate.getPhone());
            preparedStatement.setInt(6, toCreate.getPassport());
            preparedStatement.setInt(7, toCreate.getOldPassport());
            preparedStatement.setDate(8, sqlDate);
            return preparedStatement.execute();
        });
    }

    @Override
    public List<Client> getAllClients() {
        return template.query("SELECT * FROM " + CLIENTS_TABLE_NAME, new ClientRowMapper());
    }

    @Override
    public void deleteClient(int clientID) {
        template.execute("DELETE FROM " + CLIENTS_TABLE_NAME + " WHERE id = " + clientID);
    }

    @Override
    public Client getByID(int clientID) {
        return template.query("SELECT * FROM " + CLIENTS_TABLE_NAME + " WHERE id = " + clientID,
                new ClientRowMapper()).stream().findFirst().orElse(null);
    }

    @Override
    public void updateClient(Client toUpdate) {
        //template.update("UPDATE " + CLIENTS_TABLE_NAME + " SET  = " + toUpdate.getCredits() + " WHERE id = " + toUpdate.getID());
    }
}
