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

    private final String CLIENTS_TABLE_NAME = "clients";
    private final String INSERT_QUERY = "INSERT INTO " + CLIENTS_TABLE_NAME +
            " (ID, firstName, middleName, lastName, phone, passport, oldPassport, birthday)" +
            "VALUES (?,?,?,?,?,?,?,?);";

    @Override
    public void saveNewClient(Client toCreate) {
        if (!isExisted(toCreate)) {
            template.execute(INSERT_QUERY, (PreparedStatementCallback<Object>) preparedStatement -> {
                java.sql.Date sqlDate = java.sql.Date.valueOf(toCreate.getBirthday());

                preparedStatement.setInt(1, toCreate.getID());
                preparedStatement.setString(2, toCreate.getFirstName());
                preparedStatement.setString(3, toCreate.getMiddleName());
                preparedStatement.setString(4, toCreate.getLastName());
                preparedStatement.setString(5, toCreate.getPhone());
                preparedStatement.setString(6, toCreate.getPassport());
                preparedStatement.setString(7, toCreate.getOldPassport());
                preparedStatement.setDate(8, sqlDate);
                return preparedStatement.execute();
            });
        }
    }

    @Override
    public List<Client> getAllClients() {
        return template.query("SELECT * FROM " + CLIENTS_TABLE_NAME, new ClientRowMapper());
    }

    @Override
    public void deleteClient(int clientID) {
        if (isExisted(getByID(clientID)))
            template.execute("DELETE FROM " + CLIENTS_TABLE_NAME + " WHERE ID = " + clientID);
    }

    @Override
    public Client getByID(int clientID) {
        return template.query("SELECT * FROM " + CLIENTS_TABLE_NAME + " WHERE ID = " + clientID,
                new ClientRowMapper()).stream().findFirst().orElse(null);
    }

    @Override
    public void updateClient(Client toUpdate) {
        //template.update("UPDATE " + CLIENTS_TABLE_NAME + " SET  = " + toUpdate.getCredits() +
        // " WHERE ID = " + toUpdate.getID());
        // work in progress
    }

    @Override
    public boolean isExisted(Client client) {
        return (client != null && getByID(client.getID()) != null);
    }
}
