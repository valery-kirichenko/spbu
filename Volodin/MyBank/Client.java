package MyBank;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

/**
 * Created by Aspire on 10.03.2017.
 */
public class Client {
    private int id;
    private int pasport;
    private boolean hasoldpas;
    private int oldpas;
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

    public int getPasport() {
        return pasport;
    }

    public void setPasport(int pasport) {
        this.pasport = pasport;
    }

    public boolean isHasoldpas() {
        return hasoldpas;
    }

    public void setHasoldpas(boolean hasoldpas) {
        this.hasoldpas = hasoldpas;
    }

    public int getOldpas() {
        return oldpas;
    }

    public void setOldpas(int oldpas) {
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
