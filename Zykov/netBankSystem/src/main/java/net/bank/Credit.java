package net.bank;

import java.util.Date;
import java.time.Instant;

/**
 * Created by st056673 on 10.03.2017.
 */
public class Credit {
    private int clientID;
    private float creditAmount, clientPaid, clientHasToPay, percent;
    private Date closureDate;
    public boolean isOverdue() {
        Instant now = Instant.now();
        return now.isAfter(this.getClosureDate().toInstant()) &&
                (this.getClientPaid() < this.getClientHasToPay());
    }

    public boolean isMayBeOverdue() {
        Instant now = Instant.now();
        return now.isBefore(this.getClosureDate().toInstant()) &&
                (this.getClientPaid() < this.getClientHasToPay());
    }

    Credit(){}

    void setClientID       (int inputInt)    { this.clientID       = inputInt;}
    void setPercent        (float inputFloat){ this.percent        = inputFloat;}
    void setCreditAmount   (float inputFloat){ this.creditAmount   = inputFloat;}
    void setClientPaid     (float inputFloat){ this.clientPaid     = inputFloat;}
    void setClientHasToPay (float inputFloat){ this.clientHasToPay = inputFloat;}
    void setClosureDate    (Date inputDate)  { this.closureDate    = inputDate;}

    int   getClientID()      { return clientID; }
    float getPercent()       { return percent; }
    float getCreditAmount()  { return creditAmount; }
    float getClientPaid()    { return clientPaid; }
    float getClientHasToPay(){ return clientHasToPay; }
    Date  getClosureDate()   { return closureDate; }

    @Override
    public String toString() {
        return (this.getClientID() + " " + this.getCreditAmount() + " " + this.getPercent() + " " + this.getClientPaid() +
                " " + this.getClientHasToPay() + " " + this.getClosureDate());
    }
}
