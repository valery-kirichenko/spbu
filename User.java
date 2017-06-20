package com.MyProj.MyProj;
import org.springframework.stereotype.Component;
/**
 * Created by Lenovo on 20.06.2017.
 */
public class User {
    private String username;
    private String password;
    public User(String username, String password) {
        this.username = username;
        this.password = password;
    }
    public String getUsername() {
        return username;
    }
    public String getPassword() {
        return password;
    }
}
