package DateBase;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.Locale;

public class Client {
    public int id,oldPass,newPass;
    public double deptSum;
    public String fName,sName,ftName,phoneNum,date;
    public ArrayList<Credit> credits;
    public ArrayList<Credit> nonpayedCredits;

    public int getID(){
        return id;
    }

    public String getfName(){
        return fName;
    }

    public String getsName(){
        return sName;
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
        sName = "";
        ftName = "";
        phoneNum = "";
        date = "";
        credits = new ArrayList<>();
        deptSum = 0;
        nonpayedCredits = new ArrayList<>();
    };

    public Client(int nid,int noldPass,int nnewPass,String nfName,String nsName,String nftName,String nphoneNum,String ndate){
        id = nid;
        oldPass = noldPass;
        newPass = nnewPass;
        fName = nfName;
        sName = nsName;
        ftName = nftName;
        phoneNum = nphoneNum;
        date = ndate;
        credits = new ArrayList<>();
        deptSum = 0;
        nonpayedCredits = new ArrayList<>();
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
                        deptSum+=crList.get(i).nSum-crList.get(i).paySum;
                        nonpayedCredits.add(crList.get(i));
                    }
                } catch (ParseException e) {
                    e.printStackTrace();
                }

            }

        }
    }

    public void printInf(){
        System.out.println(String.valueOf(id)+' '+fName+' '+sName+' '+ftName+' '+phoneNum+' '+date+' '+String.valueOf(oldPass)+' '+String.valueOf(newPass));
    }
}
