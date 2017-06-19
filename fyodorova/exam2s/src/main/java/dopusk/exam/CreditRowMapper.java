package dopusk.exam;

import org.springframework.jdbc.core.RowMapper;

import java.sql.ResultSet;
import java.sql.SQLException;

public class CreditRowMapper implements RowMapper<Credits> {
    @Override
    public Credits mapRow(ResultSet resultSet, int i) throws SQLException {
        Credits credit = new Credits();
        credit.setClId(resultSet.getInt("client_id"));
        credit.setLoan(resultSet.getString("loan"));
        credit.setPercent(resultSet.getString("percent"));
        credit.setPaidSum(resultSet.getString("paid_sum"));
        credit.setWholeLoan(resultSet.getString("whole_loan"));
        credit.setDataString(resultSet.getString("dat"));
        credit.setCredId(resultSet.getString("credit_id"));

        return credit;
    }
}
