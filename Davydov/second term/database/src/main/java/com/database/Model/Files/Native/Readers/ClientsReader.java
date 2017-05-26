package com.database.Model.Files.Native.Readers;

import com.database.Model.ClientRecord;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Collection;
import java.util.LinkedList;
import java.util.Scanner;

/**
 * Created by Дмитрий on 11.03.2017.
 */

public class ClientsReader
{
    LinkedList<ClientRecord> clientsRecords = new LinkedList<>();

    public ClientsReader()
    {
        String line;
        int i;

        String id;
        String name;
        String family;
        String patronymic;
        String phone;
        String passport;
        String date;
        String oldpassport;

        try
        {

            File fileClients = new File("src\\main\\java\\com\\" +
                        "database\\Model\\Files\\Native\\Input_files\\clients.omg");

            if (!fileClients.exists())
            {System.out.print("Cant read native file with " + "clients.\n"); return;}

            Scanner scanner = new Scanner(fileClients);

            while (scanner.hasNext())
            {
                clientsRecords.addLast(new ClientRecord());
                line = "";
                id = "";
                name = "";
                family = "";
                patronymic = "";
                phone = "";
                passport = "";
                date = "";
                oldpassport = "";

                line = scanner.next();
                i = 0;

                    while (Count.isCount(line.charAt(i)))
                    {
                        id = id + line.substring(i, i+1);
                        i++;
                    }
                    clientsRecords.getLast().setId(Long.valueOf(id));

                    while (!Letter.isRussianLetter(line.charAt(i)))
                    {
                        i++;
                    }

                    while (Letter.isRussianLetter(line.charAt(i)))
                    {
                        name = name + line.substring(i, i+1);
                        i++;
                    }
                    clientsRecords.getLast().setName(name);

                    while (!Letter.isRussianLetter(line.charAt(i)))
                    {
                        i++;
                    }

                    while (Letter.isRussianLetter(line.charAt(i)))
                    {
                        family = family + line.substring(i, i+1);
                        i++;
                    }
                    clientsRecords.getLast().setFamily(family);

                    while (!Letter.isRussianLetter(line.charAt(i)))
                    {
                        i++;
                    }

                    while (Letter.isRussianLetter(line.charAt(i)))
                    {
                        patronymic = patronymic + line.substring(i, i+1);
                        i++;
                    }
                    clientsRecords.getLast().setPatronymic(patronymic);

                    while (!Count.isCount(line.charAt(i)))
                    {
                        i++;
                    }

                    //if (line.charAt(i) == '7') {phone = "+7";}
                    phone = "+7"; i++;

                    while (Count.isCount(line.charAt(i)))
                    {
                        phone = phone + line.substring(i, i+1);
                        i++;
                    }
                    clientsRecords.getLast().setPhone(phone);

                    while (!Count.isCount(line.charAt(i)))
                    {
                        i++;
                    }

                    while (Count.isCount(line.charAt(i)))
                    {
                        passport = passport + line.substring(i, i+1);
                        i++;
                    }
                    clientsRecords.getLast().setPassport(passport);

                    {
                        while (!Count.isCount(line.charAt(i))) {
                            i++;
                        }

                        while (Count.isCount(line.charAt(i))) {
                            date = date + line.substring(i, i + 1);
                            i++;
                        }
                        date = date + DEFAULT_DATE_SEPARATOR;

                        while (!Count.isCount(line.charAt(i))) {
                            i++;
                        }

                        while (Count.isCount(line.charAt(i))) {
                            date = date + line.substring(i, i + 1);
                            i++;
                        }
                        date = date + DEFAULT_DATE_SEPARATOR;

                        while (!Count.isCount(line.charAt(i))) {
                            i++;
                        }

                        while (Count.isCount(line.charAt(i))) {
                            date = date + line.substring(i, i + 1);
                            if (i < line.length() - 1) i++;
                            else break;
                        }
                    }
                    clientsRecords.getLast().setDate(date);

                    if (i < line.length()-1)
                    {
                        while (!Count.isCount(line.charAt(i))) {
                            i++;
                        }

                        while (Count.isCount(line.charAt(i))) {
                            oldpassport = oldpassport + line.substring(i, i + 1);
                            if (i < line.length() - 1) i++;
                            else break;
                        }
                        clientsRecords.getLast().setOldPassport(oldpassport);
                    }
                    else clientsRecords.getLast().setOldPassport("no information");
                }
        }
        catch (FileNotFoundException e)
        {System.out.print("Cant read native file with " + "clients.\n");}
    }

    public Collection getClientsRecords()
    {
        return clientsRecords;
    }

    /*
    public Collection getClientsRecords()
    {
        String fileName = DEFAULT_CLIENTS_FILE;
        String line;
        int i;

        String id;
        String name;
        String family;
        String patronymic;
        String phone;
        String passport;
        String date;
        String oldpassport;

        try
        {
            File file = new File(fileName);
            if (!file.exists()) {System.out.print("Cant read file with " +
                    "clients.\n");}

            Scanner scanner = new Scanner(file);

            while (scanner.hasNext())
            {
                clientsRecords.addLast(new ClientRecord());
                line = "";
                id = "";
                name = "";
                family = "";
                patronymic = "";
                phone = "";
                passport = "";
                date = "";
                oldpassport = "";

                line = scanner.next();
                i = 0;

                while (Count.isCount(line.charAt(i)))
                {
                    id = id + line.substring(i, i+1);
                    i++;
                }
                clientsRecords.getLast().setId(id);

                while (!Letter.isRussianLetter(line.charAt(i)))
                {
                    i++;
                }

                while (Letter.isRussianLetter(line.charAt(i)))
                {
                    name = name + line.substring(i, i+1);
                    i++;
                }
                clientsRecords.getLast().setName(name);

                while (!Letter.isRussianLetter(line.charAt(i)))
                {
                    i++;
                }

                while (Letter.isRussianLetter(line.charAt(i)))
                {
                    family = family + line.substring(i, i+1);
                    i++;
                }
                clientsRecords.getLast().setFamily(family);

                while (!Letter.isRussianLetter(line.charAt(i)))
                {
                    i++;
                }

                while (Letter.isRussianLetter(line.charAt(i)))
                {
                    patronymic = patronymic + line.substring(i, i+1);
                    i++;
                }
                clientsRecords.getLast().setPatronymic(patronymic);

                while (!Count.isCount(line.charAt(i)))
                {
                    i++;
                }

                //if (line.charAt(i) == '7') {phone = "+7";}
                phone = "+7"; i++;

                while (Count.isCount(line.charAt(i)))
                {
                    phone = phone + line.substring(i, i+1);
                    i++;
                }
                clientsRecords.getLast().setPhone(phone);

                while (!Count.isCount(line.charAt(i)))
                {
                    i++;
                }

                while (Count.isCount(line.charAt(i)))
                {
                    passport = passport + line.substring(i, i+1);
                    i++;
                }
                clientsRecords.getLast().setPassport(passport);

                {
                    while (!Count.isCount(line.charAt(i))) {
                        i++;
                    }

                    while (Count.isCount(line.charAt(i))) {
                        date = date + line.substring(i, i + 1);
                        i++;
                    }
                    date = date + DEFAULT_DATE_SEPARATOR;

                    while (!Count.isCount(line.charAt(i))) {
                        i++;
                    }

                    while (Count.isCount(line.charAt(i))) {
                        date = date + line.substring(i, i + 1);
                        i++;
                    }
                    date = date + DEFAULT_DATE_SEPARATOR;

                    while (!Count.isCount(line.charAt(i))) {
                        i++;
                    }

                    while (Count.isCount(line.charAt(i))) {
                        date = date + line.substring(i, i + 1);
                        if (i < line.length() - 1) i++;
                        else break;
                    }
                }
                clientsRecords.getLast().setDate(date);

                if (i < line.length()-1)
                {
                    while (!Count.isCount(line.charAt(i))) {
                        i++;
                    }

                    while (Count.isCount(line.charAt(i))) {
                        oldpassport = oldpassport + line.substring(i, i + 1);
                        if (i < line.length() - 1) i++;
                        else break;
                    }
                    clientsRecords.getLast().setOldPassport(oldpassport);
                }
                else clientsRecords.getLast().setOldPassport("no information");
            }
        }
        catch (FileNotFoundException e)
        {
            e.printStackTrace();
        }

        return clientsRecords;
    }*/

    public static final String DEFAULT_CLIENTS_FILE = "D:\\Programm" +
            "\\Java\\_programms\\intellij idea\\Data Base\\src\\main" +
            "\\java\\com\\vaadin\\Model\\Input_files\\clients.omg";
    public static final String DEFAULT_DATE_SEPARATOR = ".";
}
