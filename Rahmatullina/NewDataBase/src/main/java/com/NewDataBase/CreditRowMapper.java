package com.NewDataBase;


import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.ParseException;
import org.springframework.jdbc.core.RowMapper;

/**
 * Created by Я on 21.04.2017.
 */
public class CreditRowMapper  implements RowMapper<Credits> {
    @Override
    public Credits mapRow(ResultSet resultSet, int i) throws SQLException {
        Credits credit = null;
        try {
            credit = new Credits(resultSet.getString("client_id"),resultSet.getString("loan"),resultSet.getString("percent"),
                    resultSet.getString("paid_sum"),resultSet.getString("whole_loan"),resultSet.getString("dat"));
        } catch (ParseException e) {
            e.printStackTrace();
        }

        return credit;
    }


}
