package dopuskToExam;

/**
 * Created by Alena on 17.06.2017.
 */
public class Credits {
    private Integer cliId;
    private String loan;
    private String percent;
    private String paidSum;
    private String wholeLoan;
    private String dataString;
    private String creId;

    public Credits() {
    }

    public void setCliId(Integer cliId) {
        this.cliId = cliId;
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


    public Integer getCliId() {
        return this.cliId;
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

    public String getCreId() {
        return creId;
    }

    public void setCreId(String creId) {
        this.creId = creId;
    }
}
