package com.database.Model.Files;

import com.database.Model.ClientRecord;
import com.database.Model.CreditRecord;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.Collection;

/**
 * Created by Дмитрий on 25.05.2017.
 */
public class Writing
{
    public static void writeClients(Collection <ClientRecord> clientRecords)
    {
        try
        {
            FileOutputStream fos = new FileOutputStream
                ("src\\main\\java\\com\\database\\Model\\Files\\clients.txt");
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(clientRecords);
            oos.flush();
            oos.close();
        } catch (IOException ioException)
        {
            System.out.print("Witing clients failed.\n");
        }
    }

    public static void writeCredits(Collection <CreditRecord> creditRecords)
    {
        try
        {
            FileOutputStream fos = new FileOutputStream
                    ("src\\main\\java\\com\\database\\Model\\Files\\credits.txt");
            ObjectOutputStream oos = new ObjectOutputStream(fos);
            oos.writeObject(creditRecords);
            oos.flush();
            oos.close();
        } catch (IOException ioException)
        {
            System.out.print("Witing credits failed.\n");
        }
    }
}
