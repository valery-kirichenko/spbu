package com.bank.starter.models;

import java.util.List;

/**
 * Created by gusef on 20.06.2017.
 */
public class ServerAnswer {

    //{"results":
    // [{"gender":"female",
    //    "name":
    //     {"title":"ms",
    //     "first":"eléna",
    //     "last":"fleury"},
    //   "location":
    //    {"street":"1959 rue duguesclin",
    //    "city":"montreuil",
    //    "state":"val-d'oise",
    //    "postcode":14129},
    //   "email":"eléna.fleury@example.com",
    //   "login":{
    //    "username":"silvertiger297",
    //    "password":"carlos",
    //    "salt":"dAddrFEx",
    //    "md5":"59f872e2273497841836e49a9425f2d7",
    //    "sha1":"32105f21eaa0b4ea7f3796909f617d0bdf6ff2fb",
    //    "sha256":"37d0f1f210ddd2272d4d4cd2e47d43f0e7619e8acf369c95e3f9bc281e4b2bba"},
    //    "dob":"1947-12-18 20:26:23",
    //    "registered":"2016-06-02 08:34:37",
    //    "phone":"01-26-51-76-52",
    //    "cell":"06-41-15-29-97",
    //    "id":{
    //     "name":"INSEE",
    //     "value":"2471174709929 87"},
    //    "picture":{
    //     "large":"https://randomuser.me/api/portraits/women/91.jpg",
    //     "medium":"https://randomuser.me/api/portraits/med/women/91.jpg",
    //     "thumbnail":"https://randomuser.me/api/portraits/thumb/women/91.jpg"},
    //     "nat":"FR"}],
    // "info":{
    //     "seed":"e33fa859dc523d48",
    //     "results":1,
    //     "page":1,
    //     "version":"1.1"}
    //    }
    private AnswerInfo info;
    private List<User> results;

    public AnswerInfo getInfo() {
        return info;
    }

    public void setInfo(AnswerInfo info) {
        this.info = info;
    }

    public List<User> getResults() {
        return results;
    }

    public void setResults(List<User> results) {
        this.results = results;
    }
}
