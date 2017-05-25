package com.ridiculousdev.bank;

import org.springframework.jdbc.core.RowMapper;

import java.sql.ResultSet;
import java.sql.SQLException;


public class CreditRowMapper implements RowMapper<Credit> {

    @Override
    public Credit mapRow(ResultSet resultSet, int i) throws SQLException {
        Credit credit = new Credit();
        credit.setId(resultSet.getInt("clientId"));
        credit.setDatabaseId(resultSet.getInt("id"));
        credit.setTotal(resultSet.getDouble("total"));
        credit.setRate(resultSet.getDouble("rate"));
        credit.setPaid(resultSet.getDouble("paid"));
        credit.setPayable(resultSet.getDouble("payable"));
        credit.setClosingDate(resultSet.getDate("closingDate").toLocalDate());
        return credit;
    }
}
