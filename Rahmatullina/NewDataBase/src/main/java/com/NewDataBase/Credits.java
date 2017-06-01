package com.NewDataBase;


public class Credits {
    private Integer id;
    private String loan;
    private String percent;
    private String paidSum;
    private String wholeLoan;
    private String dataString;

    public Credits() {
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public void setLoan(String loan) {
        this.loan = loan;
    }

    public void setPercent(String percent) {
        this.percent = percent;
    }

    public void setPaidSum(String paidSum) {
        this.paidSum = paidSum;
    }

    public void setWholeLoan(String wholeLoan) {
        this.wholeLoan = wholeLoan;
    }

    public void setDataString(String dataString) {
        this.dataString = dataString;
    }


    public Integer getId() {
        return id;
    }

    public String getLoan() {
        return loan;
    }

    public String getPercent() {
        return percent;
    }

    public String getPaidSum() {
        return paidSum;
    }

    public String getWholeLoan() {
        return wholeLoan;
    }

    public String getCreditData() {
        return dataString;
    }

    @Override
    public String toString() {
        return this.getId() + " " + this.getLoan() + " " + this.getWholeLoan() + " " +
                this.getPaidSum() + " " + this.getPercent() + " " + this.getCreditData();
    }
}