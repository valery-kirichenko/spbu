package com.bank.starter.DataBaseSystem.CreditControllers;

import com.bank.starter.models.Client;
import com.bank.starter.models.Credit;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.PreparedStatementCallback;
import org.springframework.stereotype.Controller;

import java.util.*;

/**
 * Created by gusef on 18.06.2017.
 */
@Controller
public class CreditControler implements DBCreditControler {

    @Autowired
    private JdbcTemplate template;

    private final String CREDITS_TABLE_NAME = "credits";
    private final String INSERT_QUERY = "INSERT INTO " + CREDITS_TABLE_NAME +
            " (clientId, startSum,  paidSum, allSum, percent, finishDate)" +
            "VALUES (?,?,?,?,?,?);";

    @Override
    public void addNewCredit(Credit locCredit) {
        if (!isContained(locCredit)) {
            template.execute(INSERT_QUERY, (PreparedStatementCallback<Object>) preparedStatement -> {
                java.sql.Date sqlDate = java.sql.Date.valueOf(locCredit.getFinishDate());

                preparedStatement.setInt(1, locCredit.getId());
                preparedStatement.setDouble(2, locCredit.getStartSum());
                preparedStatement.setDouble(3, locCredit.getPaidSum());
                preparedStatement.setDouble(4, locCredit.getAllSum());
                preparedStatement.setDouble(5, locCredit.getPercent());
                preparedStatement.setDate(6, sqlDate);
                return preparedStatement.execute();
            });
        }
    }

    @Override
    public List<Credit> getListOfCredits(Client locClient) {
        return getListOfCredits(locClient.getNowId());
    }

    @Override
    public List<Credit> getListOfCredits(Integer id) {
        return template.query("SELECT * FROM " + CREDITS_TABLE_NAME + " WHERE clientId = " + id,
                new CreditRowMapper());
    }

    @Override
    public List<Credit> getAllCredits() {
        return template.query("SELECT * FROM " + CREDITS_TABLE_NAME, new CreditRowMapper());
    }

    @Override
    public void updateCredit(Credit locCredit) {
        //not available in demo
    }

    @Override
    public Credit getCredit(Integer id) {
        return template.query("SELECT * FROM " + CREDITS_TABLE_NAME + " WHERE NewID = " + id,
                new CreditRowMapper()).stream().findFirst().orElse(null);
    }

    @Override
    public boolean isContained(Credit locCredit) {
        return (locCredit != null && getListOfCredits(locCredit.getId()).contains(locCredit));
    }

    @Override
    public void deletCredit(Integer id) {
        if (isContained(getCredit(id)))
            template.execute("DELETE FROM " + CREDITS_TABLE_NAME + " WHERE NewID = " + id);
    }
}
