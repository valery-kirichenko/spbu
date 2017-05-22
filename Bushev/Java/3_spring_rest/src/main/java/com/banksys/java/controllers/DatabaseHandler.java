package com.banksys.java.controllers;

import com.banksys.java.models.Client;
import com.banksys.java.models.Credit;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.dao.DataAccessException;
import org.springframework.jdbc.core.BatchPreparedStatementSetter;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.PreparedStatementCallback;
import org.springframework.stereotype.Service;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static com.banksys.java.config.DBCfg.CLIENTS_TABLE;
import static com.banksys.java.config.DBCfg.CREDITS_TABLE;

@Service
public class DatabaseHandler {
    @Autowired
    JdbcTemplate template;

    public void insertClients(ArrayList<Client> clients) {
        template.batchUpdate("INSERT INTO " + CLIENTS_TABLE
                + " (id, name, surname, middlename, phone, passport, date, oldPassport)"
                + " VALUES (?, ?, ?, ?, ?, ?, ?, ?)", new BatchPreparedStatementSetter() {
            @Override
            public void setValues(PreparedStatement statement, int i) throws SQLException {
                Client client = clients.get(i);
                statement.setInt(1, Integer.parseInt(client.getId()));
                statement.setString(2, client.getName());
                statement.setString(3, client.getSurname());
                statement.setString(4, client.getMiddlename());
                statement.setString(5, client.getPhone());
                statement.setString(6, client.getPassport());
                statement.setString(7, client.getDate().toString());
                statement.setString(8, client.getOldPassport().isEmpty() ? "0" : client.getOldPassport());
            }

            @Override
            public int getBatchSize() {
                return clients.size();
            }
        });
    }

    public void insertCredits(ArrayList<Credit> credits) {
        template.batchUpdate("INSERT INTO " + CREDITS_TABLE
                        + " (id, amount, percent, payed, needed, date) VALUES (?, ?, ?, ?, ?, ?)",
                new BatchPreparedStatementSetter() {
                    @Override
                    public void setValues(PreparedStatement statement, int i) throws SQLException {
                        Credit credit = credits.get(i);
                        statement.setInt(1, Integer.parseInt(credit.id));
                        statement.setDouble(2, Double.parseDouble(credit.amount));
                        statement.setDouble(3, Double.parseDouble(credit.percent));
                        statement.setDouble(4, Double.parseDouble(credit.payed));
                        statement.setDouble(5, Double.parseDouble(credit.needed));
                        statement.setString(6, credit.date.toString());
                    }

                    @Override
                    public int getBatchSize() {
                        return credits.size();
                    }
                });
    }

    public Client selectClientById(int id) {
        return template.query("SELECT * FROM " + CLIENTS_TABLE + " WHERE id = " + id,
                this::clientRow).stream().findFirst().orElse(null);
    }

    public ArrayList<Client> selectClients() {
        return (ArrayList<Client>) template.query("SELECT * FROM " + CLIENTS_TABLE, this::clientRow);
    }

    public Credit selectCreditById(int id) {
        return template.query("SELECT * FROM " + CREDITS_TABLE + " WHERE id = " + id,
                this::creditRow).stream().findFirst().orElse(null);
    }

    public ArrayList<Credit> selectCredits() {
        return (ArrayList<Credit>) template.query("SELECT * FROM " + CREDITS_TABLE, this::creditRow);

    }

    public void deleteRecord(boolean isClient, int id){
        String table = isClient ? CLIENTS_TABLE : CREDITS_TABLE;
        template.execute("DELETE FROM " + table + " WHERE id = " + id);
    }

    public void rewriteData(ArrayList<Client> clients, ArrayList<Credit> credits) {
        template.execute("TRUNCATE TABLE " + CLIENTS_TABLE + "; TRUNCATE TABLE " + CREDITS_TABLE);
        insertClients(clients);
        insertCredits(credits);

        System.out.println("The data is rewrited");
    }

    private Client clientRow(ResultSet res, int i) throws SQLException {
        return new Client(res.getString("id"),
                res.getString("name"), res.getString("surname"), res.getString("middlename"),
                res.getString("phone"), res.getString("passport"),
                res.getString("date"), res.getString("oldPassport"));
    }

    private Credit creditRow(ResultSet res, int i) throws SQLException {
        return new Credit(res.getString("id"),
                res.getString("amount"), res.getString("percent"),
                res.getString("payed"), res.getString("needed"),
                res.getString("date"));
    }
}
