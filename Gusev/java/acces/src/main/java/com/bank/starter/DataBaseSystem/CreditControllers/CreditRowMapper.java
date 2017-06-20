package com.bank.starter.DataBaseSystem.CreditControllers;

import com.bank.starter.models.Credit;

import org.springframework.jdbc.core.RowMapper;

import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * Created by gusef on 18.06.2017.
 */
public class CreditRowMapper implements RowMapper<Credit> {
    @Override
    public Credit mapRow(ResultSet resultSet, int i) throws SQLException{
        Credit locCredit = new Credit();
        locCredit.setId(resultSet.getInt("clientId"));
        locCredit.setStartSum((resultSet.getDouble("startSum")));
        locCredit.setPaidSum((resultSet.getDouble("paidSum")));
        locCredit.setAllSum((resultSet.getDouble("allSum")));
        locCredit.setPercent((resultSet.getDouble("percent")));
        locCredit.setFinishDate(resultSet.getDate("finishDate").toLocalDate());
        return locCredit;
    }
}
