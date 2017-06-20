package com.bank.starter.models;

/**
 * Created by gusef on 20.06.2017.
 */
public class AnswerInfo {
        //{
        //     "seed":"e33fa859dc523d48",
        //     "results":1,
        //     "page":1,
        //     "version":"1.1"}
    private String seed;
    private int results,page;
    private double version;

    public String getSeed() {
        return seed;
    }

    public void setSeed(String seed) {
        this.seed = seed;
    }

    public int getResults() {
        return results;
    }

    public void setResults(int results) {
        this.results = results;
    }

    public int getPage() {
        return page;
    }

    public void setPage(int page) {
        this.page = page;
    }

    public double getVersion() {
        return version;
    }

    public void setVersion(double version) {
        this.version = version;
    }
}
