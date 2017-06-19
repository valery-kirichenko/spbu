package dopusk.dopusk;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by USER on 18.06.2017.
 */
public class Clients {
    private Integer id;
    private String name;
    private String surName;
    private String midName;
    private String phone;
    private String newPassport;
    private String oldPassport;
    private List<Credits> credits = new ArrayList<>();
    private String data;
    public Boolean isDeleted = Boolean.FALSE;

    public Clients() {}

    public String getName() {return this.name;}

    public String getSurName() {return this.surName;}

    public String getMidName() {return this.midName;}

    public String getPhone() {
        return this.phone;
    }

    public Integer getId() {return this.id;}

    public String getNewPassport() {
        return this.newPassport;
    }

    public String getData() {
        return this.data;
    }

    public String getOldPassport() {
        return this.oldPassport;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSurName(String surName) {
        this.surName = surName;
    }

    public void setMidName(String midName) {
        this.midName = midName;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public void setId(Integer id) {this.id = id;}

    public void setNewPassport(String newPassport) {
        this.newPassport = newPassport;
    }

    public void setData(String data) {
        this.data = data;
    }

    public void setOldPassport(String oldPassport) {
        this.oldPassport = oldPassport;
    }

    public List<Credits> getCredits() {
        return this.credits;
    }

    public void setCredits(List<Credits> credits) {
        this.credits = credits;
    }

    public void addCredit(Credits credit) {this.credits.add(credit);}
}
