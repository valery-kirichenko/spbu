package com.database;

/**
 * Created by Дмитрий on 05.05.2017.
 */
import com.database.Controller.ClientsControllerInterface;
import com.database.Controller.CreditsControllerInterface;
import com.database.Model.DataBase;
import com.database.Model.ClientRecord;
import com.database.Model.CreditRecord;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.LinkedList;

@Repository
public class DBConfiguration implements CommandLineRunner
{
    @Autowired
    private JdbcTemplate template;

    @Autowired
    private ClientsControllerInterface ClientsController;

    @Autowired
    private CreditsControllerInterface CreditsController;

    @Override
    public void run(String... strings) throws Exception
    {
        template.execute("DROP TABLE IF EXISTS " + Constants.CLIENTS_TABLE_NAME);
        template.execute("CREATE TABLE "  + Constants.CLIENTS_TABLE_NAME  +
                "("  + Constants.ID + " INTEGER , " +
                Constants.NAME + " VARCHAR(255), " +
                Constants.FAMILY + " VARCHAR(255), " +
                Constants.PATRONYMIC + " VARCHAR(255), " +
                Constants.PHONE + " VARCHAR(20), " +
                Constants.PASSPORT + " VARCHAR(255), " +
                Constants.OLD_PASSPORT +" VARCHAR(255), " +
                Constants.DATE + " VARCHAR(20), " +
                Constants.DEBT_STATUS + " INTEGER)");

        template.execute("DROP TABLE IF EXISTS " + Constants.CREDITS_TABLE_NAME);
        template.execute("CREATE TABLE " + Constants.CREDITS_TABLE_NAME +
                "(" + Constants.ID + " INTEGER , " +
                Constants.SUM  + " DOUBLE ," +
                Constants.PAID_SUM + " DOUBLE, " +
                Constants.PAID_UP_SUM + " DOUBLE, " +
                Constants.DATE + " DATE," +
                Constants.PERCENT + " DOUBLE)");

        DataBase dataBase = new DataBase();
        ArrayList <ClientRecord> clientsRecords = (ArrayList<ClientRecord>)
                dataBase.getClientsRecords();
        ArrayList <CreditRecord> creditSRecords = (ArrayList<CreditRecord>)
                dataBase.getCreditsRecords();

        for (CreditRecord creditRecord : creditSRecords)
        {
            CreditsController.saveNewCredit(creditRecord);
        }

        for (ClientRecord clientRecord : clientsRecords)
        {
            ClientsController.saveNewClient(clientRecord);
        }
    }
}
