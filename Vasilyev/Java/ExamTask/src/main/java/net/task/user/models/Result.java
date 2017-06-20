package net.task.user.models;


import java.util.ArrayList;
import java.util.List;

public class Result {
    private List<User> results = new ArrayList<>();
    private Info info;

    public Result() {
    }

    public List<User> getResults() {
        return results;
    }

    public void setResults(List<User> results) {
        this.results = results;
    }

    public Info getInfo() {
        return info;
    }

    public void setInfo(Info info) {
        this.info = info;
    }
}
