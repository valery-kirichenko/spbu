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
        locCredit.setId(resultSet.getInt("id"));
        locCredit.setStartSum(Double.toString(resultSet.getDouble("startSum")));
        locCredit.setPaidSum(Double.toString(resultSet.getDouble("paidSum")));
        locCredit.setAllSum(Double.toString(resultSet.getDouble("allSum")));
        locCredit.setPercent(Double.toString(resultSet.getDouble("percent")));
        locCredit.setFinishDate(resultSet.getDate("finishDate").toLocalDate());
        return locCredit;
    }
}
