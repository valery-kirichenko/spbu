package com.NewDataBase;


public class Credits {
    private Integer id;
    private String loan;
    private String percent;
    private String paidSum;
    private String wholeLoan;
    private String dataString;
    private Integer creditId;

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
        return this.id;
    }

    public String getLoan() {
        return this.loan;
    }

    public String getPercent() {
        return this.percent;
    }

    public String getPaidSum() {
        return this.paidSum;
    }

    public String getWholeLoan() {
        return this.wholeLoan;
    }

    public String getDataString() {
        return this.dataString;
    }

    public Integer getCreditId() { return creditId; }

    public void setCreditId(Integer creditId) { this.creditId = creditId; }

    @Override
    public String toString() {
        return this.getId() + " " + this.getCreditId() + " " + this.getLoan() + " " + this.getWholeLoan() + " " +
                this.getPaidSum() + " " + this.getPercent() + " " + this.getDataString();
    }


}