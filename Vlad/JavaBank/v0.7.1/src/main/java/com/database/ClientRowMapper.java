package com.database;

import com.database.Cells.Client;
import org.springframework.jdbc.core.RowMapper;
import java.sql.ResultSet;
import java.sql.SQLException;

public class ClientRowMapper implements RowMapper<Client> {

    @Override
    public Client mapRow(ResultSet resultSet, int i) throws SQLException {
        Client client = new Client();
        client.setId(resultSet.getInt("id"));
        client.setName(resultSet.getString("name"));
        client.setPhoneNumber(resultSet.getString("phoneNumber"));
        client.setBirthday(resultSet.getString("birthday"));
        client.setPassport(resultSet.getString("passport"));
        client.setOldPassport(resultSet.getString("oldPassport"));
        return client;
    }
}