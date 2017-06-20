package com.banksys.java.models;

import org.junit.rules.ExternalResource;

public class User {
    private String image;

    private String name;
    private String address;

    private String email;
    private String username;
    private String password;

    private String registered;
    private String phone;

    private String nat;

    public User(String title, String first, String last,
                String street, String city, String state, String postcode,
                String email, String username, String password, String registered, String phone,
                String image, String nat){

        title = firstUpperCase(title);
        first = firstUpperCase(first);
        last = firstUpperCase(last);

        this.name = title + " " + first + " " + last;
        this.address = street + ", " + city + ", " + state + ", " + postcode;

        this.email = email;
        this.username = username;
        this.password = password;
        this.registered = registered;
        this.phone = phone;

        this.image = image;
        this.nat = nat;
    }

    public String getName() {
        return name;
    }

    public String getAddress() {
        return address;
    }

    public String getEmail() {
        return email;
    }

    public String getUsername() {
        return username;
    }

    public String getPassword() {
        return password;
    }

    public String getRegistered() {
        return registered;
    }

    public String getPhone() {
        return phone;
    }

    public String getImage(){
        return image;
    }

    public String getNat() {
        return nat;
    }

    public String firstUpperCase(String word){
        if(word == null || word.isEmpty()) return "";
        return word.substring(0, 1).toUpperCase() + word.substring(1);
    }
}
