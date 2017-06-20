package com.exam.Exam.Model;

public class Name {
    private String title;
    private String first;
    private String last;

    public String getTitle() {
        return title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    public String getFirst() {
        return first;
    }

    public void setFirst(String first) {
        this.first = first;
    }

    public String getLast() {
        return last;
    }

    public void setLast(String last) {
        this.last = last;
    }
}


/*
{
"results":
[
{"gender":"male",
"name":
{"title":"mr",
"first":"samuel",
"last":"maki"},
"location":
{"street":"5208 hermiankatu",
"city":"hervanta",
"state":"central finland",
"postcode":35049},"email":"samuel.maki@example.com","login":{"username":"crazygorilla698","password":"sheeba","salt":"M001bxbW","md5":"5cc365d591c077c8fd8f732d03fa57a5","sha1":"2348d29068021cf65e5e7051d9840cdceb59cb4e","sha256":"3e79d1000f8c0c8252447b9793485e0a48f5da1a459abb9ddcd6ba4050814fa9"},"dob":"1987-09-01 06:27:13","registered":"2011-01-12 17:45:55","phone":"03-441-187","cell":"041-448-45-80","id":{"name":"HETU","value":"1087-401E"},"picture":{"large":"https://randomuser.me/api/portraits/men/21.jpg","medium":"https://randomuser.me/api/portraits/med/men/21.jpg","thumbnail":"https://randomuser.me/api/portraits/thumb/men/21.jpg"},"nat":"FI"}],"info":{"seed":"614725eca1db4284","results":1,"page":1,"version":"1.1"}}
 */