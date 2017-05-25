package com.database.Controller;

import com.database.Constants;
import com.database.Model.ClientRecord;
import com.database.Model.Files.Writing;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.PreparedStatementCallback;
import org.springframework.stereotype.Controller;

import java.util.Collection;

/**
 * Created by Дмитрий on 05.05.2017.
 */

@Controller
public class ClientsController implements ClientsControllerInterface
{
    @Autowired
    private JdbcTemplate template;

    @Autowired
    private CreditsControllerInterface creditsController;

    final String INSERT_QUERY = "INSERT INTO " + Constants.CLIENTS_TABLE_NAME +
            " (" + Constants.ID + ", " + Constants.NAME + ", " + Constants.FAMILY +
            ", " + Constants.PATRONYMIC  + ", " + Constants.PHONE + ", " +
            Constants.PASSPORT + ", " + Constants.OLD_PASSPORT + ", " +
            Constants.DATE + ", " + Constants.DEBT_STATUS + ")VALUES (?,?,?,?,?,?,?,?,?);";

    public void saveNewClient(ClientRecord clientRecord)
    {
        template.execute(INSERT_QUERY, (PreparedStatementCallback<Object>)
                preparedStatement ->
        {
            preparedStatement.setLong(1, clientRecord.getId());
            preparedStatement.setString(2, clientRecord.getName());
            preparedStatement.setString(3, clientRecord.getFamily());
            preparedStatement.setString(4, clientRecord.getPatronymic());
            preparedStatement.setString(5, clientRecord.getPhone());
            preparedStatement.setString(6, clientRecord.getPassport());
            preparedStatement.setString(7, clientRecord.getOldPassport());
            preparedStatement.setString(8, clientRecord.getDate());
            preparedStatement.setInt(9, clientRecord.getDebtStatus());
            return preparedStatement.execute();
        });
    }

    public Collection <ClientRecord> getAllClients()
    {
        return template.query("SELECT * FROM " + Constants.CLIENTS_TABLE_NAME,
                new ClientsRowMapper());
    }

    public void deleteClient(Long Id) {
        template.execute("DELETE FROM " + Constants.CLIENTS_TABLE_NAME +
                " WHERE id = " + Id);
    }

    public ClientRecord getByID(Long Id) {
        ClientRecord clientRecord = template.query("SELECT * FROM " +
                        Constants.CLIENTS_TABLE_NAME + " WHERE id = " + Id,
                new ClientsRowMapper()).stream().findFirst().orElse(null);
        if (clientRecord == null) return null;

        clientRecord.addCredits(creditsController.getByID(clientRecord.getId()));
        return clientRecord;
    }
}
