package net.task.bank.dao;

import net.task.bank.models.Credit;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.PreparedStatementCallback;
import org.springframework.stereotype.Controller;

import java.util.List;


@Controller
public class CreditsController implements DBCreditsController{
    @Autowired
    private JdbcTemplate template;

    final String CREDITS_TABLE_NAME = "credits";
    final String INSERT_QUERY = "INSERT INTO " + CREDITS_TABLE_NAME +
                 " (clientID, amount, percent, paidSum, needPaid, closingDate)" +
                 "VALUES (?,?,?,?,?,?);";

    @Override
    public void saveNewCredit(Credit toCreate) {
        template.execute(INSERT_QUERY, (PreparedStatementCallback<Object>) preparedStatement -> {
            java.sql.Date sqlDate = new java.sql.Date(toCreate.getClosingDate().getTime());

            preparedStatement.setInt(1, toCreate.getClientID());
            preparedStatement.setDouble(2, toCreate.getAmount());
            preparedStatement.setDouble(3, toCreate.getPercent());
            preparedStatement.setDouble(4, toCreate.getPaidSum());
            preparedStatement.setDouble(5, toCreate.getNeedPaid());
            preparedStatement.setDate(6, sqlDate);
            return preparedStatement.execute();
        });
    }

    @Override
    public List<Credit> getAllCredits() {
        return template.query("SELECT * FROM " + CREDITS_TABLE_NAME, new CreditRowMapper());
    }

    @Override
    public void deleteCredit(int creditID) {
        template.execute("DELETE FROM " + CREDITS_TABLE_NAME + " WHERE id =" + creditID);
    }

    @Override
    public List<Credit> getByClientID(int clientID) {
        return template.query("SELECT * FROM " + CREDITS_TABLE_NAME + " WHERE clientID =" + clientID,
                new CreditRowMapper());
    }

    @Override
    public Credit getByID(int creditID) {
        return template.query("SELECT * FROM " + CREDITS_TABLE_NAME + " WHERE id =" + creditID,
                new CreditRowMapper()).stream().findFirst().orElse(null);
    }

    @Override
    public void updateCredit(Credit toUpdate) {

    }
}