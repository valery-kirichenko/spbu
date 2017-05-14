package com.ridiculousdev.bank;

import org.springframework.jdbc.core.RowMapper;

import java.sql.ResultSet;
import java.sql.SQLException;


public class ClientRowMapper implements RowMapper<Client> {

    @Override
    public Client mapRow(ResultSet resultSet, int i) throws SQLException {
        Client client = new Client();
        client.setId(resultSet.getInt("id"));
        client.setPassport(resultSet.getInt("passport"));
        client.setFirstName(resultSet.getString("firstName"));
        client.setLastName(resultSet.getString("lastName"));
        client.setMiddleName(resultSet.getString("middleName"));
        client.setPhoneNumber(resultSet.getString("phoneNumber"));
        client.setBirthDate(resultSet.getDate("birthDate").toLocalDate());
        return client;
    }

}
