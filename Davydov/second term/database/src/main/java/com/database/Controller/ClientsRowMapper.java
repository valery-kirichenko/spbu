package com.database.Controller;

import com.database.Constants;
import com.database.Model.ClientRecord;

import java.sql.ResultSet;
import java.sql.SQLException;

/**
 * Created by Дмитрий on 12.05.2017.
 */
public class ClientsRowMapper implements org.springframework.jdbc.core.RowMapper<ClientRecord>
{
    public ClientRecord mapRow(ResultSet resultSet, int i) throws SQLException
    {
        ClientRecord clientRecord = new ClientRecord();
        clientRecord.setId(Long.valueOf(resultSet.getString(Constants.ID)));
        clientRecord.setName(resultSet.getString(Constants.NAME));
        clientRecord.setFamily(resultSet.getString(Constants.FAMILY));
        clientRecord.setPatronymic(resultSet.getString(Constants.PATRONYMIC));
        clientRecord.setPhone(resultSet.getString(Constants.PHONE));
        clientRecord.setPassport(resultSet.getString(Constants.PASSPORT));
        clientRecord.setDate(resultSet.getString(Constants.DATE));
        clientRecord.setOldPassport(resultSet.getString(Constants.OLD_PASSPORT));
        clientRecord.setDebtStatus(Integer.valueOf(resultSet.getString
                (Constants.DEBT_STATUS)));

        return clientRecord;
    }
}
