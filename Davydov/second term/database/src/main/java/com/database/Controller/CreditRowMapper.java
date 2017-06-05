package com.database.Controller;

import com.database.Constants;
import com.database.Model.CreditRecord;
import org.springframework.jdbc.core.RowMapper;

import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * Created by Дмитрий on 12.05.2017.
 */
public class CreditRowMapper implements RowMapper<CreditRecord>
{
    @Override
    public CreditRecord mapRow(ResultSet resultSet, int i) throws SQLException {
        CreditRecord credit = new CreditRecord();
        credit.setId(resultSet.getLong(Constants.ID));
        credit.setSum(resultSet.getDouble(Constants.SUM));
        credit.setPaidSum(resultSet.getDouble(Constants.PAID_SUM));
        credit.setPaidUpSum(resultSet.getDouble(Constants.PAID_UP_SUM));
        credit.setDate(resultSet.getDate(Constants.DATE));
        credit.setPercent(resultSet.getDouble(Constants.PERCENT));

        return credit;
    }

}
