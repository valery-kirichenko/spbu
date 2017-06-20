package com.bank.starter.models;

/**
 * Created by gusef on 20.06.2017.
 */
public class PersonLogin {
    //{
    //    "username":"silvertiger297",
    //    "password":"carlos",
    //    "salt":"dAddrFEx",
    //    "md5":"59f872e2273497841836e49a9425f2d7",
    //    "sha1":"32105f21eaa0b4ea7f3796909f617d0bdf6ff2fb",
    //    "sha256":"37d0f1f210ddd2272d4d4cd2e47d43f0e7619e8acf369c95e3f9bc281e4b2bba"}
    private String username,password,salt,md5,sha1,sha256;

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getSalt() {
        return salt;
    }

    public void setSalt(String salt) {
        this.salt = salt;
    }

    public String getMd5() {
        return md5;
    }

    public void setMd5(String md5) {
        this.md5 = md5;
    }

    public String getSha1() {
        return sha1;
    }

    public void setSha1(String sha1) {
        this.sha1 = sha1;
    }

    public String getSha256() {
        return sha256;
    }

    public void setSha256(String sha256) {
        this.sha256 = sha256;
    }
}
