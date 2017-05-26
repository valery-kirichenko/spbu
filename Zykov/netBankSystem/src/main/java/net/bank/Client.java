package net.bank;

import java.util.ArrayList;
import java.util.Date;

/**
 * Created by st056673 on 10.03.2017.
 */
public class Client {
    private int ID, idNumber, oldIdNumber;
    private String firstName, lastName, middleName, phoneNumber;
    private Date birthDate;
    public boolean isDeleted = false;
    private ArrayList<Credit> credits = new ArrayList<>();
    public boolean isDebtor(){
        for(Credit credit : this.credits)
            if(credit.isOverdue())
                return true;
        return false;
    }

    public boolean mayBeDebtor() {
        for(Credit credit : this.credits)
            if(credit.isMayBeOverdue())
                return true;
        return false;
    }

    Client(){}

    void setID          (int inputInteger)   { this.ID          = inputInteger; }
    void setFirstName   (String inputString) { this.firstName   = inputString;  }
    void setLastName    (String inputString) { this.lastName    = inputString;  }
    void setMiddleName  (String inputString) { this.middleName  = inputString;  }
    void setPhoneNumber (String inputString) { this.phoneNumber = inputString;  }
    void setIdNumber    (int inputInteger)   { this.idNumber    = inputInteger; }
    void setOldIdNumber (int inputInteger)   { this.oldIdNumber = inputInteger; }
    void setBirthDate   (Date inputDate)     { this.birthDate   = inputDate;    }
    void addCredit      (Credit inputCredit) { this.credits.add(inputCredit);   }

    public int               getID()         { return ID; }
    public String            getFirstName()  { return firstName; }
    public String            getLastName()   { return lastName; }
    public String            getMiddleName() { return middleName; }
    public String            getPhoneNumber(){ return phoneNumber; }
    public int               getIdNumber()   { return idNumber; }
    public int               getOldIdNumber(){ return oldIdNumber; }
    public Date              getBirthDate()  { return birthDate; }
    public ArrayList<Credit> getCredits()    { return credits; }

    @Override
    public String toString(){
        if (this.getOldIdNumber() == 0){
            return (this.getID() + " " + this.getFirstName() + " " + this.getMiddleName() + " " + this.getLastName() + " "
                    + this.getPhoneNumber() + " " + this.getIdNumber() + " " + this.getBirthDate());
        }else{
            return (this.getID() + " " + this.getFirstName() + " " + this.getMiddleName() + " " + this.getLastName() + " "
                    + this.getPhoneNumber() + " " + this.getIdNumber() + " " + this.getBirthDate() + " " + this.getOldIdNumber());
        }
    }


}
