import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class Client {
    private int id, passport, oldPassport;
    private String firstName, lastName, middleName, phoneNumber;
    private LocalDate birthDate;
    private List<Credit> credits = new ArrayList<>();

    public Client() { }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public String getMiddleName() {
        return middleName;
    }

    public int getId() {
        return id;
    }

    public int getOldPassport() {
        return oldPassport;
    }

    public int getPassport() {
        return passport;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public LocalDate getBirthDate() {
        return birthDate;
    }

    public List<Credit> getCredits() {
        return credits;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setPassport(int passport) {
        this.passport = passport;
    }

    public void setOldPassport(int oldPassport) {
        this.oldPassport = oldPassport;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public void setMiddleName(String middleName) {
        this.middleName = middleName;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    public void setBirthDate(LocalDate birthDate) {
        this.birthDate = birthDate;
    }

    public void setBirthdate(String birthdate) {
        this.birthDate = LocalDate.parse(birthdate);
    }

    public void addCredit(Credit credit) {
        this.credits.add(credit);
    }

    @Override
    public String toString() {
        String result = id + " | " + lastName + " " + firstName + " " + middleName + " | "
                + birthDate.getDayOfMonth() + "." + birthDate.getMonthValue() + "." + birthDate.getYear() + " | "
                + phoneNumber + " | " + passport + " | " + oldPassport + "\nCredits:\n";
        for (Credit credit : credits) {
            result += credit.getTotal() + " | " + credit.getRate() + " | " + credit.getPaid() + " | "
                    + credit.getPayable() + " | "
                    + credit.getClosingDate().getDayOfMonth() + "."
                    + credit.getClosingDate().getMonthValue() + "."
                    + credit.getClosingDate().getYear() + "\n";
        }
        return result;
    }
}