package dopusk.exam;

import java.util.ArrayList;
import java.util.List;

public class Clients {
    private Integer id;
    private String name;
    private String surName;
    private String mName;
    private String ph;
    private String newPass;
    private String oldPass;
    private List<Credits> credits = new ArrayList<>();
    private String data;
    public Boolean isDeleted = Boolean.FALSE;

    public Clients() {
    }

    public Integer getId() {return this.id;}

    public String getName() {return this.name;}

    public String getSurName() {return this.surName;}

    public String getmName() {return this.mName;}

    public String getPh() {
        return this.ph;
    }

    public String getNewPass() {
        return this.newPass;
    }

    public String getData() {
        return this.data;
    }

    public String getOldPass() {
        return this.oldPass;
    }


    public void setId(Integer id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setSurName(String surName) {
        this.surName = surName;
    }

    public void setmName(String mName) {
        this.mName = mName;
    }

    public void setPh(String ph) {
        this.ph = ph;
    }

    public void setNewPass(String newPass) {
        this.newPass = newPass;
    }

    public void setData(String data) {
        this.data = data;
    }

    public void setOldPass(String oldPass) {
        this.oldPass = oldPass;
    }

    public List<Credits> getCredits() {
        return this.credits;
    }

    public void setCredits(List<Credits> credits) {
        this.credits = credits;
    }

    public void addCredit(Credits credit) {
        this.credits.add(credit);
    }
}
