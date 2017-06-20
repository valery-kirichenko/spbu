package com.bank.starter.DataBaseSystem.ClientControllers;

import com.bank.starter.models.Client;
import org.springframework.jdbc.core.RowMapper;

import java.awt.*;
import java.sql.Array;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

/**
 * Created by gusef on 18.06.2017.
 */
public class ClientRowMapper implements RowMapper<Client> {
    @Override
    public Client mapRow(ResultSet resultSet, int i) throws SQLException {
        Client locClinet = new Client();
        locClinet.setName(resultSet.getString("name"));
        locClinet.setSurName(resultSet.getString("surName"));
        locClinet.setLastName(resultSet.getString("lastName"));
        locClinet.setNowId(resultSet.getInt("id"));
        locClinet.setPass(resultSet.getInt("passport"));
        locClinet.setPhone(resultSet.getString("phone"));
        locClinet.setOldPass(resultSet.getInt("oldPass"));
        locClinet.setBirthDate(resultSet.getDate("birthday").toLocalDate());
        return locClinet;
    }
}
