package dopusk.dopusk;

/**
 * Created by USER on 18.06.2017.
 */
public class Credits {
    private Integer clientId;
    private String loan;
    private String percent;
    private String paidSum;
    private String wholeLoan;
    private String dataString;
    private String creditId;

    public Credits() {}

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

    public void setClientId(Integer clientId) {
        this.clientId = clientId;
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

    public String getCreditId() {
        return creditId;
    }

    public Integer getClientId() {
        return this.clientId;
    }

    public void setCreditId(String creditId) {
        this.creditId = creditId;
    }
}
