package com.database.Model.Files.Native.Readers;

import com.database.Model.CreditRecord;

import java.io.File;
import java.io.FileNotFoundException;
import java.sql.Date;
import java.util.ArrayList;
import java.util.Collection;
import java.util.LinkedList;
import java.util.Scanner;

/**
 * Created by Дмитрий on 17.03.2017.
 */

public class CreditsReader
{

    LinkedList<CreditRecord> credits = new LinkedList<>();

    public CreditsReader()
    {
        String line;

        try
        {
            File fileCredits = new File("src\\main\\java\\com\\" +
                    "database\\Model\\Files\\Native\\Input_files\\credits.omg");
            if (!fileCredits.exists())
            {System.out.print("Cant read native file with " + "credits.\n"); return;}

            Scanner scanner = new Scanner(fileCredits);

            while (scanner.hasNext())
            {
                line = scanner.next();

                String[] array = line.split("Credit");

                for (int j = 1; j<array.length; j++)
                {
                    credits.addLast(new CreditRecord());
                    String[] q = array[j].split("\\|");
                    credits.getLast().setId(Long.valueOf(q[0].substring
                            (1, q[0].length())));

                    String[] w = q[1].split(",");
                    credits.getLast().setSum(Double.valueOf(w[0]));
                    credits.getLast().setPercent(Double.valueOf(w[1].substring
                            (0, w[1].length() - 1)));
                    String[] e = w[2].split("\\^");
                    credits.getLast().setPaidUpSum(Double.valueOf(e[0]));
                    String[] r = e[1].split("___");
                    credits.getLast().setPaidSum(Double.valueOf(r[0]));

                    if (j == array.length - 1)
                        credits.getLast().setDate(Date.valueOf(r[1].substring
                            (0, r[1].length())));
                    else
                        credits.getLast().setDate(Date.valueOf(r[1].substring
                                (0, r[1].length()-1)));
                    reduce(credits.getLast());
                }
            }
        }
        catch (FileNotFoundException e)
        {
            System.out.print("Cant read file with " + "credits.\n");
        }
    }

    public Collection getCreditsRecords()
    {return credits;}

    private void reduce(CreditRecord creditRecord)
    {
        String[] arr;


        arr = String.valueOf(creditRecord.getPaidSum()).split("\\.");
        if (arr.length > 1)
        {
            if (arr[1].length() > 2)
            {
                creditRecord.setPaidSum(Double.valueOf(arr[0] + "." + arr[1].
                        substring(0, 2)));
            }
        }


        arr = String.valueOf(creditRecord.getPaidUpSum()).split("\\.");
        if (arr.length > 1)
        {
            if (arr[1].length() > 2)
            {
                creditRecord.setPaidUpSum(Double.valueOf(arr[0] + "." + arr[1].
                        substring(0, 2)));
            }
        }

        arr = String.valueOf(creditRecord.getSum()).split("\\.");
        if (arr.length > 1)
        {
            if (arr[1].length() > 2)
            {
                creditRecord.setSum(Double.valueOf(arr[0] + "." + arr[1].
                        substring(0, 2)));
            }
        }
    }
}
