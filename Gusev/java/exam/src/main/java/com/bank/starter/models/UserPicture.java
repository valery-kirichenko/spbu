package com.bank.starter.models;

/**
 * Created by gusef on 20.06.2017.
 */
public class UserPicture {
    //"large":"https://randomuser.me/api/portraits/women/91.jpg",
    //     "medium":"https://randomuser.me/api/portraits/med/women/91.jpg",
    //     "thumbnail":"https://randomuser.me/api/portraits/thumb/women/91.jpg"
    private String large,medium,thumbnail;

    public String getLarge() {
        return large;
    }

    public void setLarge(String large) {
        this.large = large;
    }

    public String getMedium() {
        return medium;
    }

    public void setMedium(String medium) {
        this.medium = medium;
    }

    public String getThumbnail() {
        return thumbnail;
    }

    public void setThumbnail(String thumbnail) {
        this.thumbnail = thumbnail;
    }
}
