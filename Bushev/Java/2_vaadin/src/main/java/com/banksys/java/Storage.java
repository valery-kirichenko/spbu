package com.banksys.java;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.ArrayList;
import java.util.List;

public class Storage {
    private static final String CLIENTS_TABLE = "BANK_CLIENTS";
    private static final String CREDITS_TABLE = "BANK_CREDITS";

    public ArrayList<Client> getClients() {
        return clients;
    }

    public void setClients(ArrayList<Client> clients) {
        this.clients = clients;
    }

    public ArrayList<Credit> getCredits() {
        return credits;
    }

    public void setCredits(ArrayList<Credit> credits) {
        this.credits = credits;
    }

    private ArrayList<Client> clients;
    private ArrayList<Credit> credits;

    // sql logic
    private Connection connection = null;
    private PreparedStatement statement = null;

    // constructors
    Storage() {
        openConnection();

        if (tableExist(CLIENTS_TABLE, CREDITS_TABLE)) {
            initClients();
            initCredits();

            DefaultReader.makingLinks(this.clients, this.credits);
            System.out.println("Data was loaded");
        } else {
            DefaultReader.readFromFiles(this);

            // clients table
            String structure = "(id INT PRIMARY KEY NOT NULL," +
                    "name TEXT NOT NULL," +
                    "surname TEXT NOT NULL," +
                    "middlename TEXT NOT NULL," +
                    "phone INT NOT NULL," +
                    "passport INT NOT NULL," +
                    "date TEXT NOT NULL," +
                    "oldPassport INT NOT NULL)";
            createTable(CLIENTS_TABLE, structure);

            // the credits one
            structure = "(id INT NOT NULL," +
                    "amount REAL NOT NULL," +
                    "percent REAL NOT NULL," +
                    "payed REAL NOT NULL," +
                    "needed REAL NOT NULL," +
                    "date TEXT NOT NULL)";
            createTable(CREDITS_TABLE, structure);

            System.out.println("Tables were created");

            try {
                for (Client client : clients)
                    insertClient(client);
                for (Credit credit : credits)
                    insertCredit(credit);

                statement.close();
                connection.commit();
            } catch (Exception e) {
                e.printStackTrace();
                System.err.println(e.getClass().getName() + ": " + e.getMessage());
                System.exit(0);
            }

            System.out.println("Default data was inserted");
        }
    }

    // destructor
    public void destroy() {
        closeConnection();
    }

    // main logic
    private boolean tableExist(String... args) {
        for (String name : args) {
            try {
                ResultSet res = connection.getMetaData().getTables(null, null, name, null);
                if (!res.next()) return false;
            } catch (Exception e) {
                e.printStackTrace();
                System.err.println(e.getClass().getName() + ": " + e.getMessage());
                System.exit(0);
            }
        }

        return true;
    }

    private void createTable(String name, String structure) {
        try {
            statement = connection.prepareStatement("CREATE TABLE IF NOT EXISTS " + name + structure);
            statement.executeUpdate();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void openConnection() {
        try {
            Class.forName("org.sqlite.JDBC");
            connection = DriverManager.getConnection("jdbc:sqlite:banksys.db");
            System.out.println("Sqlite database is opened...");
            connection.setAutoCommit(false);
        } catch (Exception e) {
            e.printStackTrace();
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
            System.exit(0);
        }
    }

    private void closeConnection() {
        try {
            connection.close();
        } catch (Exception e) {
            e.printStackTrace();
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
            System.exit(0);
        }
    }

    private void initClients() {
        try {
            statement = connection.prepareStatement("SELECT * FROM " + CLIENTS_TABLE);
            ResultSet res = statement.executeQuery();

            String oldPassport;
            clients = new ArrayList<>();
            while (res.next()) {
                oldPassport = Integer.toString(res.getInt("oldPassport"));

                List<String> data = new ArrayList<>();
                data.add(Integer.toString(res.getInt("id")));
                data.add(res.getString("name"));
                data.add(res.getString("surname"));
                data.add(res.getString("middlename"));
                data.add(Long.toString(res.getLong("phone")));
                data.add(Integer.toString(res.getInt("passport")));
                data.add(res.getString("date"));

                if (oldPassport.length() > 1) data.add(oldPassport);
                clients.add(new Client(data.toArray(new String[0])));
            }

            statement.close();
            connection.commit();
        } catch (Exception e) {
            e.printStackTrace();
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
            System.exit(0);
        }
    }

    private void initCredits() {
        try {
            statement = connection.prepareStatement("SELECT * FROM " + CREDITS_TABLE);
            ResultSet res = statement.executeQuery();

            credits = new ArrayList<>();
            while (res.next()) {
                ArrayList<String> data = new ArrayList<>();
                data.add(Integer.toString(res.getInt("id")));
                data.add(Double.toString(res.getDouble("amount")));
                data.add(Double.toString(res.getDouble("percent")));
                data.add(Double.toString(res.getDouble("payed")));
                data.add(Double.toString(res.getDouble("needed")));
                data.add(res.getString("date"));

                credits.add(new Credit(data.toArray(new String[0])));
            }

            statement.close();
            connection.commit();
        } catch (Exception e) {
            e.printStackTrace();
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
            System.exit(0);
        }
    }

    private void insertClient(Client client) throws Exception {
        statement = connection.prepareStatement("INSERT INTO " + CLIENTS_TABLE
                + " (id, name, surname, middlename, phone, passport, date, oldPassport)"
                + "VALUES (?, ?, ?, ?, ?, ?, ?, ?)");

        statement.setInt(1, Integer.parseInt(client.getId()));
        statement.setString(2, client.getName());
        statement.setString(3, client.getSurname());
        statement.setString(4, client.getMiddlename());
        statement.setLong(5, Long.parseLong(client.getPhone()));
        statement.setInt(6, Integer.parseInt(client.getPassport()));
        statement.setString(7, client.getDate().toString());
        statement.setInt(8, client.getOldPassport().isEmpty() ? 0 : Integer.parseInt(client.getOldPassport()));
        statement.executeUpdate();
    }

    private void insertCredit(Credit credit) throws Exception {
        statement = connection.prepareStatement("INSERT INTO " + CREDITS_TABLE + " (id, amount, percent, payed, needed, date) VALUES (?, ?, ?, ?, ?, ?)");

        statement.setInt(1, Integer.parseInt(credit.id));
        statement.setDouble(2, Double.parseDouble(credit.amount));
        statement.setDouble(3, Double.parseDouble(credit.percent));
        statement.setDouble(4, Double.parseDouble(credit.payed));
        statement.setDouble(5, Double.parseDouble(credit.needed));
        statement.setString(6, credit.date.toString());
        statement.executeUpdate();
    }

    public void rewriteData() {
        try {
            if (connection == null || connection.isClosed()) openConnection();

            statement = connection.prepareStatement("DELETE FROM " + CLIENTS_TABLE);
            statement.executeUpdate();
            statement = connection.prepareStatement("DELETE FROM " + CREDITS_TABLE);
            statement.executeUpdate();

            for (Client client : clients)
                insertClient(client);
            for (Credit credit : credits)
                insertCredit(credit);

            statement.close();
            connection.commit();
        } catch (Exception e) {
            e.printStackTrace();
            System.err.println(e.getClass().getName() + ": " + e.getMessage());
            System.exit(0);
        }
    }
}
