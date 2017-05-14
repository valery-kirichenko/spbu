import java.util.ArrayList;
import java.util.List;

class Client {
    private int id;
    private String Name;
    private String phoneNumber;
    private String birthday;
    private int passport;
    private int oldPassport;
    private List<Credit> credits;

    Client() {credits = new ArrayList<>();}
    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }
    public String getName() {
        return Name;
    }
    public void setName(String name) {
        Name = name;
    }
    public String getPhoneNumber() {
        return phoneNumber;
    }
    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }
    public String getBirthday() {
        return birthday;
    }
    public void setBirthday(String birthday) {
        this.birthday = birthday;
    }
    public int getPassport() {
        return passport;
    }
    public void setPassport(int passport) {
        this.passport = passport;
    }
    public int getOldPassport() {
        return oldPassport;
    }
    public void setOldPassport(int oldPassport) {
        this.oldPassport = oldPassport;
    }
    public List<Credit> getCredits() {
        return credits;
    }
    public void setCredits(List<Credit> credits) {
        this.credits = credits;
    }
}
