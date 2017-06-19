package com.NewDataBase;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.PreparedStatementCallback;
import org.springframework.stereotype.Controller;

import java.util.List;


@Controller
public class CreditControllerImpl implements CreditController {
    @Autowired
    private JdbcTemplate template;

    String query = "INSERT INTO credits (client_id,loan,whole_loan,paid_sum,percent,dat) VALUES (?,?,?,?,?,?);";

    @Override
    public void saveNewCredit(Credits toCreate) {
        template.execute(query, (PreparedStatementCallback<Object>) preparedStatement -> {
            preparedStatement.setInt(1, toCreate.getId());
            preparedStatement.setString(2, toCreate.getLoan());
            preparedStatement.setString(3, toCreate.getWholeLoan());
            preparedStatement.setString(4, toCreate.getPaidSum());
            preparedStatement.setString(5, toCreate.getPercent());
            preparedStatement.setString(6, toCreate.getDataString());
            return preparedStatement.execute();
        });

    }

    @Override
    public List<Credits> getAllCredits() {
        return template.query("SELECT * FROM credits " , new CreditRowMapper());
    }

    @Override
    public void deleteCredit(Integer credit_id) {
        template.execute("DELETE FROM credits WHERE credit_id =" + credit_id);
    }

    @Override
    public Credits getFirstByID(Integer clientID) {

        return template.query("SELECT * FROM credits WHERE client_id =" + clientID,
                new CreditRowMapper()).stream().findFirst().orElse(null);

    }

    @Override
    public List<Credits> getByClientID(Integer clientID) {
        return template.query("SELECT * FROM credits WHERE client_id =" + clientID,
                new CreditRowMapper());
    }

    @Override
    public void updateCredit(Credits toUpdate) {

    }
}
