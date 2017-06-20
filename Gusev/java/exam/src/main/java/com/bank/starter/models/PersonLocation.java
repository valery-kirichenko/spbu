package com.bank.starter.models;

/**
 * Created by gusef on 20.06.2017.
 */
public class PersonLocation {
    //{"street":"1959 rue duguesclin",
    //    "city":"montreuil",
    //    "state":"val-d'oise",
    //    "postcode":14129}
    private String street,city,state;
    private String postcode;

    public String getStreet() {
        return street;
    }

    public void setStreet(String street) {
        this.street = street;
    }

    public String getCity() {
        return city;
    }

    public void setCity(String city) {
        this.city = city;
    }

    public String getState() {
        return state;
    }

    public void setState(String state) {
        this.state = state;
    }

    public String getPostcode() {
        return postcode;
    }

    public void setPostcode(String postcode) {
        this.postcode = postcode;
    }
}
