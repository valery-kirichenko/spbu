package com.ridiculousdev.bank;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;

public class Client {
    private int id, passport, oldPassport;
    private String firstName, lastName, middleName, phoneNumber;
    private LocalDate birthDate;
    private List<Credit> credits = new ArrayList<>();
    private boolean paid = true, dodger = false;

    public Client() {
    }

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

    public String getPassportString() {
        return Integer.toString(passport);
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

    public boolean isPaid() {
        return paid;
    }

    public boolean isDodger() {
        return dodger;
    }

    public void setId(int id) {
        this.id = id;
    }

    public void setPassport(int passport) {
        this.passport = passport;
    }

    public void setPassport(String passport) {
        this.passport = Integer.parseInt(passport);
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

    public void setBirthDate(String birthDate) {
        this.birthDate = LocalDate.parse(birthDate);
    }

    public void addCredit(Credit credit) {
        if (!credit.isPaid()) this.paid = false;
        if (credit.isDodger()) this.dodger = true;
        credit.setParent(this);
        this.credits.add(credit);
    }

    public void updateStatus() {
        this.paid = true;
        this.dodger = false;
        for (Credit credit : credits) {
            if (!credit.isPaid()) this.paid = false;
            if (credit.isDodger()) this.dodger = true;
        }
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