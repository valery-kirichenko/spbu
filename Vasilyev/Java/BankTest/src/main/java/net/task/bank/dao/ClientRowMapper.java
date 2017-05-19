package net.task.bank.dao;

import net.task.bank.models.Client;
import org.springframework.jdbc.core.RowMapper;

import java.sql.ResultSet;
import java.sql.SQLException;


public class ClientRowMapper implements RowMapper<Client> {
    @Override
    public Client mapRow(ResultSet resultSet, int i) throws SQLException {
        Client client = new Client();
        client.setID(resultSet.getInt("ID"));
        client.setFirstName(resultSet.getString("firstName"));
        client.setMiddleName(resultSet.getString("middleName"));
        client.setLastName(resultSet.getString("lastName"));
        client.setPhone(resultSet.getString("phone"));
        client.setPassport(resultSet.getString("passport"));
        client.setOldPassport(resultSet.getString("oldPassport"));
        client.setBirthday(resultSet.getDate("birthDay").toLocalDate());

        return client;
    }
}
