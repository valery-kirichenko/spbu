package com.database.Model;

import java.io.Serializable;
import java.time.LocalDateTime;
import java.util.Collection;
import java.util.LinkedList;

public class ClientRecord implements Serializable
{
    private Long id;
    private String name;
    private String family;
    private String patronymic;
    private String phone;
    private String passport;
    private String date;
    private String oldPassport;
    private LinkedList<CreditRecord> clientCredits;
    private int debtStatus;

    public ClientRecord()
    {
        this.name = "";
        this.family = "";
        this.patronymic = "";
        this.phone = "";
        this.passport = "";
        this.date = "";
        this.oldPassport = "";
        clientCredits = new LinkedList<CreditRecord>();
    }

    public ClientRecord(String[] strings)
    {
        this.id = Long.valueOf(strings[0]);
        this.name = strings[1];
        this.family = strings[2];
        this.patronymic = strings[3];

        this.phone = strings[4];
        this.passport = strings[5];
        this.date = strings[6];
        this.oldPassport = strings[7];
        clientCredits = new LinkedList<CreditRecord>();
    }

    public void setId(Long id) {this.id = id;}
    public void setName(String name) {this.name = name;}
    public void setFamily(String family) {this.family = family;}
    public void setPatronymic(String patronymic) {this.patronymic = patronymic;}
    public void setPhone(String phone) {this.phone = phone;}
    public void setPassport(String passport) {this.passport = passport;}
    public void setDate(String date) {this.date = date;}
    public void setOldPassport(String oldPassport) {this.oldPassport = oldPassport;}
    public void setDebtStatus(int debtStatus)
    {
        this.debtStatus = debtStatus;
    }
    public void setDebtStatus(Collection <CreditRecord> creditRecords)
            {
                this.debtStatus = this.debtStatus(creditRecords);
            }

    public Long getId() {return this.id;}
    public String getName() {return this.name;}
    public String getFamily() {return this.family;}
    public String getPatronymic() {return this.patronymic;}
    public String getPhone() {return this.phone;}
    public String getPassport() {return this.passport;}
    public String getDate() {return this.date;}
    public String getOldPassport() {return this.oldPassport;}
    public int getDebtStatus() {return debtStatus;}
    public String getDebtStatusWord()
    {
        switch (this.debtStatus)
        {
            case (0) : return "defaulter";
            case (1) : return "debtor";
            case (2) : return "clean";
            default : return "error";
        }
    }

    public Collection<CreditRecord> getCredits()
    {
        return clientCredits;
    }

    public void addCredit(CreditRecord creditRecord)
    {
        clientCredits.addLast(creditRecord);
    }
    public void addCredits(Collection<CreditRecord> creditRecords)
    {
        clientCredits.addAll(creditRecords);
    }

    public void replaceE()
    {
        this.name.replace('ё', 'е');
        this.family.replace('ё', 'е');
        this.patronymic.replace('ё', 'е');
    }

    private int debtStatus(Collection <CreditRecord> creditRecords)
    {
        //0 - overdue credit
        //1 - has an active credit
        //2 - no active credits

        boolean flug = false;
        LocalDateTime localDateTime = LocalDateTime.now();

        for(CreditRecord creditRecord : creditRecords)
        {
            if (creditRecord.getId().equals(this.getId()))
            if (!creditRecord.getPaidSum().equals(creditRecord.getPaidUpSum()))
            {
                if (creditRecord.getStatus() == 0) {return 0;}
                flug = true;
            }
        }
        if (flug) {return 1;}
        return 2;
    }


    public String getStringWithCredits()
    {
        String line = "";
        line += "Id : "+ id + "\n";
        line += "Name : "+ name + "\n";
        line += "Family : "+ family + "\n";
        line += "Patronomic : "+ patronymic + "\n";
        line += "Phone number : "+ phone + "\n";
        line += "Passport : "+ passport + "\n";
        line += "Date : "+ date + "\n";
        line += "Old Passport : "+ oldPassport + "\n";
        line += "Credits:\n";
        for (int i=0; i<clientCredits.size(); i++)
        {
            line += (i+1) + ") Credit\n" + clientCredits.get(i).getStringWithoutId();
        }
        line += "--------------------------------------------------------------------------------------\n";
        return line;
    }
    public String getString()
    {
        String line = "";
        line += "Id : "+ id + "\n";
        line += "Name : "+ name + "\n";
        line += "Family : "+ family + "\n";
        line += "Patronomic : "+ patronymic + "\n";
        line += "Phone number : "+ phone + "\n";
        line += "Passport : "+ passport + "\n";
        line += "Date : "+ date + "\n";
        line += "Old Passport : "+ oldPassport + "\n";
        line += "--------------------------------------------------------------------------------------\n";
        return line;
    }
}
