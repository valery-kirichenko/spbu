import java.util.Date;

class Credit {
    private int id;
    private double cashTotal;
    private double cashPaid;
    private double castLeft;
    private double percent;
    private Date deadline;

    public int getId() {return id;}
    public void setId(int id) {
        this.id = id;
    }
    public double getCashTotal() {
        return cashTotal;
    }
    public void setCashTotal(double cashTotal) {
        this.cashTotal = cashTotal;
    }
    public double getCashPaid() {
        return cashPaid;
    }
    public void setCashPaid(double cashPaid) {
        this.cashPaid = cashPaid;
    }
    public double getCastLeft() {
        return castLeft;
    }
    public void setCastLeft(double castLeft) {
        this.castLeft = castLeft;
    }
    public double getPercent() {
        return percent;
    }
    public void setPercent(double percent) {
        this.percent = percent;
    }
    public Date getDeadline() {
        return deadline;
    }
    public void setDeadline(Date deadline) {
        this.deadline = deadline;
    }
}
