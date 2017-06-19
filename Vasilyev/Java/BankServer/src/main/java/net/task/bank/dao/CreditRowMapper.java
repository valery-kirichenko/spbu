package net.task.bank.dao;

import net.task.bank.models.Credit;
import org.springframework.jdbc.core.RowMapper;

import java.sql.ResultSet;
import java.sql.SQLException;


public class CreditRowMapper implements RowMapper<Credit> {
    @Override
    public Credit mapRow(ResultSet resultSet, int i) throws SQLException {
        Credit credit = new Credit();
        credit.setClientID(resultSet.getInt("clientID"));
        credit.setAmount(resultSet.getDouble("amount"));
        credit.setPercent(resultSet.getDouble("percent"));
        credit.setPaidSum(resultSet.getDouble("paidSum"));
        credit.setNeedPaid(resultSet.getDouble("needPaid"));
        credit.setClosingDate(resultSet.getDate("closingDate").toLocalDate());

        return credit;
    }
}
