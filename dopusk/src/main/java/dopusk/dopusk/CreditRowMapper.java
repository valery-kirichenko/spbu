package dopusk.dopusk;

import org.springframework.jdbc.core.RowMapper;

import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * Created by USER on 18.06.2017.
 */
public class CreditRowMapper implements RowMapper<Credits> {
    @Override
    public Credits mapRow(ResultSet resultSet, int i) throws SQLException {
        Credits credit = new Credits();
        credit.setClientId(resultSet.getInt("client_id"));
        credit.setLoan(resultSet.getString("loan"));
        credit.setPercent(resultSet.getString("percent"));
        credit.setPaidSum(resultSet.getString("paid_sum"));
        credit.setWholeLoan(resultSet.getString("whole_loan"));
        credit.setDataString(resultSet.getString("dat"));
        credit.setCreditId(resultSet.getString("credit_id"));

        return credit;
    }
}
