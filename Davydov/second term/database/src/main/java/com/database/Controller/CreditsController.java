package com.database.Controller;

import com.database.Constants;
import com.database.Model.CreditRecord;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.PreparedStatementCallback;
import org.springframework.stereotype.Controller;

import java.util.Collection;

/**
 * Created by Дмитрий on 05.05.2017.
 */
@Controller
public class CreditsController implements CreditsControllerInterface {
    @Autowired
    private JdbcTemplate template;

    final String CREDITS_TABLE_NAME = Constants.CREDITS_TABLE_NAME;
    final String INSERT_QUERY = "INSERT INTO " + CREDITS_TABLE_NAME +
            " (" + Constants.ID + ", " +  Constants.SUM + ", " +
            Constants.PAID_SUM + ", " + Constants.PAID_UP_SUM + ", " +
            Constants.DATE + ", " + Constants.PERCENT +")" + "VALUES (?,?,?,?,?,?);";

    public void saveNewCredit(CreditRecord creditRecord) {
        template.execute(INSERT_QUERY, (PreparedStatementCallback<Object>)
                preparedStatement -> {
                    preparedStatement.setLong(1, creditRecord.getId());
                    preparedStatement.setDouble(2,
                            creditRecord.getSum());
                    preparedStatement.setDouble(3,
                            creditRecord.getPaidSum());
                    preparedStatement.setDouble(4,
                            creditRecord.getPaidUpSum());
                    preparedStatement.setDate(5, creditRecord.getDate());
                    preparedStatement.setDouble(6,
                            creditRecord.getPercent());
                    return preparedStatement.execute();
                });
    }

    public Collection<CreditRecord> getAllCredits() {
        return template.query("SELECT * FROM " + CREDITS_TABLE_NAME,
                new CreditRowMapper());
    }

    public void deleteCredit(CreditRecord creditRecord)
    {
        template.execute("DELETE FROM " + CREDITS_TABLE_NAME +
        " WHERE " + Constants.ID + " = " + String.valueOf(creditRecord.getId()) +
        " AND " + Constants.SUM + " = " + creditRecord.getSum() +
        " AND " + Constants.PAID_SUM + " = " + creditRecord.getPaidSum() +
        " AND " + Constants.PAID_UP_SUM + " = " + creditRecord.getPaidUpSum() +
        //" AND " + Constants.DATE + " = " + creditRecord.getDate() +
        " AND " + Constants.PERCENT + " = " + creditRecord.getPercent()
        );
    }

    public Collection <CreditRecord> getByID(Long id) {
        return template.query("SELECT * FROM " + CREDITS_TABLE_NAME +
                        " WHERE id =" + id, new CreditRowMapper());
    }
}
