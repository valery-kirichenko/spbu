package com.database;

import com.database.Cells.Credit;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.PreparedStatementCallback;
import org.springframework.stereotype.Controller;

import java.util.List;

@Controller
public class CreditsControllerClass implements CreditsController{

    @Autowired
    JdbcTemplate template;
    String cmd = "INSERT INTO credits (clientID, cashTotal, cashPaid, cashWithPercent, percent, deadline) VALUES (?,?,?,?,?,?);";

    @Override
    public void saveNewCredit(Credit toCreate) {
        template.execute(cmd, (PreparedStatementCallback<Object>) preparedStatement -> {
            preparedStatement.setInt(1, toCreate.getClientID());
            preparedStatement.setDouble(2, toCreate.getCashTotal());
            preparedStatement.setDouble(3, toCreate.getCashPaid());
            preparedStatement.setDouble(4, toCreate.getCashWithPercent());
            preparedStatement.setDouble(5, toCreate.getPercent());
            preparedStatement.setDate(6, toCreate.getDeadline());
            return preparedStatement.execute();
        });
    }

    @Override
    public List<Credit> getAllCredits() {
        return template.query("SELECT * FROM credits", new CreditRowMapper());
    }

    @Override
    public void deleteCredit(Long creditId) {
        template.execute("DELETE FROM credits WHERE id =" + creditId);
    }

    @Override
    public Credit getById(Long creditId) {
        return template.query("SELECT * FROM credits WHERE id =" + creditId, new CreditRowMapper()).stream().findFirst().orElse(null);
    }
}
