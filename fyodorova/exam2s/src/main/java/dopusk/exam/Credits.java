package dopusk.exam;

public class Credits {
    private Integer clId;
    private String loan;
    private String percent;
    private String paidSum;
    private String wholeLoan;
    private String dataString;
    private String credId;

    public Credits() {
    }

    public void setClId(Integer clId) {
        this.clId = clId;
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


    public Integer getClId() {
        return this.clId;
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

    public String getCredId() {
        return credId;
    }

    public void setCredId(String credId) {
        this.credId = credId;
    }
}
