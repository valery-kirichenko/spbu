import java.time.LocalDate;

public class Credit {
    // ID клиента, сумма, процент, уже выплаченная сумма, сумма к выплате, дата закрытия.
    private int id;
    private double total, rate, paid, payable;
    private LocalDate closingDate;

    public Credit() { }

    public int getId() {
        return id;
    }

    public double getTotal() {
        return total;
    }

    public double getRate() {
        return rate;
    }

    public double getPaid() {
        return paid;
    }

    public double getPayable() {
        return payable;
    }

    public LocalDate getClosingDate() {
        return closingDate;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setTotal(double total) {
        this.total = total;
    }

    public void setRate(double rate) {
        this.rate = rate;
    }

    public void setPaid(double paid) {
        this.paid = paid;
    }

    public void setPayable(double payable) {
        this.payable = payable;
    }

    public void setClosingDate(LocalDate closingDate) {
        this.closingDate = closingDate;
    }

    public void setClosingDate(String closingDate) {
        this.setClosingDate(LocalDate.parse(closingDate));
    }

    @Override
    public String toString() {
        return id + " | " + total + " | " + rate + " | " + paid + " | " + payable + " | " +
                closingDate.getDayOfMonth() + "." + closingDate.getMonthValue() + "." + closingDate.getYear();
    }

}
