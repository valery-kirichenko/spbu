//client records
package DataBase;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;

public class Client {
    public int id,oldPass,newPass;
    public double debtSum;
    public String fName, lName,ftName,phoneNum,date;
    public ArrayList<Credit> credits;
    public ArrayList<Credit> UnpaidLoans;

    public int getID(){
        return id;
    }

    public String getfName(){
        return fName;
    }

    public String getlName(){
        return lName;
    }

    public String getftName(){
        return ftName;
    }

    public String getPhoneNum(){
        return phoneNum;
    }

    public int getNewPass(){
        return newPass;
    }

    public int getOldPass(){
        return oldPass;
    }

    public String getdate(){
        return date;
    }


    public Client(){
        id = 0;
        oldPass = 0;
        newPass = 0;
        fName = "";
        lName = "";
        ftName = "";
        phoneNum = "";
        date = "";
        credits = new ArrayList<>();
        debtSum = 0;
        UnpaidLoans = new ArrayList<>();
    };

    public Client(int nid,int noldPass,int nnewPass,String nfName,String nsName,String nftName,String nphoneNum,String ndate){
        id = nid;
        oldPass = noldPass;
        newPass = nnewPass;
        fName = nfName;
        lName = nsName;
        ftName = nftName;
        phoneNum = nphoneNum;
        date = ndate;
        credits = new ArrayList<>();
        debtSum = 0;
        UnpaidLoans = new ArrayList<>();
    };

    public void giveCredits(ArrayList<Credit> crList){
        for (int i = 0; i<crList.size(); i++) {
            if (crList.get(i).id == this.id) {
                credits.add(crList.get(i));
                Date now = new Date();
                SimpleDateFormat format = new SimpleDateFormat();
                format.applyPattern("yyyy-MM-dd");
                Date docDate;
                try {
                    docDate = format.parse(crList.get(i).date);
                    if (crList.get(i).paySum != crList.get(i).nSum && docDate.before(now)) {
                        debtSum +=crList.get(i).nSum-crList.get(i).paySum;
                        UnpaidLoans.add(crList.get(i));
                    }
                } catch (ParseException e) {
                    e.printStackTrace();
                }

            }

        }
    }

    public void printInf(){
        System.out.println(String.valueOf(id)+' '+fName+' '+ lName +' '+ftName+' '+phoneNum+' '+date+' '+String.valueOf(oldPass)+' '+String.valueOf(newPass));
    }
}
