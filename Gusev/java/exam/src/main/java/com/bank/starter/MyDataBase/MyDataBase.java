package com.bank.starter.MyDataBase;

import com.bank.starter.models.User;

import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collection;

/**
 * Created by gusef on 18.06.2017.
 */
public interface MyDataBase {
    ArrayList<User> getArrayListOfUsers();
    void addUser(User newUser);
    void addAllUsers(Collection<User> newUsers);
    void getRandomUsers(int number);
    void outDataToExcel(FileOutputStream outFile) throws IOException;
}
