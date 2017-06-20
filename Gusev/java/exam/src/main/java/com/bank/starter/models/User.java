package com.bank.starter.models;

/**
 * Created by gusef on 20.06.2017.
 */
public class User {
    //{"gender":"female",
    //    "name":{"title":"ms","first":"eléna","last":"fleury"},
    //   "location":{"street":"1959 rue duguesclin","city":"montreuil","state":"val-d'oise","postcode":14129},
    //   "email":"eléna.fleury@example.com",
    //   "login":{"username":"silvertiger297","password":"carlos","salt":"dAddrFEx","md5":"59f872e2273497841836e49a9425f2d7","sha1":"32105f21eaa0b4ea7f3796909f617d0bdf6ff2fb","sha256":"37d0f1f210ddd2272d4d4cd2e47d43f0e7619e8acf369c95e3f9bc281e4b2bba"},
    //    "dob":"1947-12-18 20:26:23",
    //    "registered":"2016-06-02 08:34:37",
    //    "phone":"01-26-51-76-52",
    //    "cell":"06-41-15-29-97",
    //    "id":{"name":"INSEE","value":"2471174709929 87"},
    //    "picture":{"large":"https://randomuser.me/api/portraits/women/91.jpg","medium":"https://randomuser.me/api/portraits/med/women/91.jpg","thumbnail":"https://randomuser.me/api/portraits/thumb/women/91.jpg"},
    //     "nat":"FR"}
    private String email,gender,dob,registered,phone,cell,nat;
    private BigName name;
    private PersonLocation location;
    private PersonLogin login;
    private UserId id;
    private UserPicture picture;

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public String getDob() {
        return dob;
    }

    public void setDob(String dob) {
        this.dob = dob;
    }

    public String getRegistered() {
        return registered;
    }

    public void setRegistered(String registered) {
        this.registered = registered;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public String getCell() {
        return cell;
    }

    public void setCell(String cell) {
        this.cell = cell;
    }

    public String getNat() {
        return nat;
    }

    public void setNat(String nat) {
        this.nat = nat;
    }

    public BigName getName() {
        return name;
    }

    public void setName(BigName name) {
        this.name = name;
    }

    public PersonLocation getLocation() {
        return location;
    }

    public void setLocation(PersonLocation location) {
        this.location = location;
    }

    public PersonLogin getLogin() {
        return login;
    }

    public void setLogin(PersonLogin login) {
        this.login = login;
    }

    public UserId getId() {
        return id;
    }

    public void setId(UserId id) {
        this.id = id;
    }

    public UserPicture getPicture() {
        return picture;
    }

    public void setPicture(UserPicture picture) {
        this.picture = picture;
    }
}
