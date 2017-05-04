package com.banksys.java;

public class Main {
    public static Storage storage;
    public static void main(String[] args) {
        storage = new Storage();
        //ClientHelper.showUnpaid(storage.getClients(), true);
       // ClientHelper.showUnpaid(storage.getClients(), false);
        storage.destroy();
    }
}
