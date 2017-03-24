package MyBank;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * Created by Aspire on 10.03.2017.
 */
public class Client {
    private int id;
    private String passport;
    private boolean hasoldpas;
    private String oldpas;
    private Date birthDate;
    private String name;
    private String family;
    private String father;
    private String phone;
    private List<Credit> credits = new ArrayList<Credit>();

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getPassport() {
        return passport;
    }

    public void setPassport(String passport) {
        this.passport = passport;
    }

    public boolean isHasoldpas() {
        return hasoldpas;
    }

    public void setHasoldpas(boolean hasoldpas) {
        this.hasoldpas = hasoldpas;
    }

    public String getOldpas() {
        return oldpas;
    }

    public void setOldpas(String oldpas) {
        this.oldpas = oldpas;
    }

    public Date getBirthDate() {
        return birthDate;
    }

    public void setBirthDate(Date birthDate) {
        this.birthDate = birthDate;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getFamily() {
        return family;
    }

    public void setFamily(String family) {
        this.family = family;
    }

    public String getFather() {
        return father;
    }

    public void setFather(String father) {
        this.father = father;
    }

    public String getPhone() {
        return phone;
    }

    public void setPhone(String phone) {
        this.phone = phone;
    }

    public List<Credit> getCredits() {
        return credits;
    }

    public void setCredits(List<Credit> credits) {
        this.credits = credits;
    }
}
