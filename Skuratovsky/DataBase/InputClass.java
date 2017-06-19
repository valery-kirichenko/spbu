package DataBase;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.*;

public class InputClass {

    private static Client dropClientLine(String s){
        Client c = new Client();
        String[] inf;
        s = s.replace("ё","е");
        inf = s.split("->>>>");
        c.id = Integer.parseInt(inf[0]);
        inf = inf[1].split("---");
        c.fName = inf[0];
        inf = inf[1].split("\\\\");
        c.lName = inf[0];
        inf = inf[2].split("~~~~");
        c.ftName = inf[0];
        inf = inf[1].split("==");
        c.phoneNum = inf[0];
        if (inf.length == 3) c.oldPass = Integer.parseInt(inf[2]);
        inf = inf[1].split("___");
        c.newPass = Integer.parseInt(inf[0]);
        c.date = inf[1];
        return c;
    }

    public static ArrayList<Client> clientRead(String path) {
        ArrayList <Client> newList = new ArrayList<Client>();
        ArrayList <Credit> cr = creditRead("credits.omg");
        File client = new File("C:\\Users\\Денис\\Downloads\\"+path);
        try {
            Scanner sc = new Scanner(client);
            String s;
            String[] inf;
            while(sc.hasNextLine()) {
                s = sc.nextLine();
                Client c = dropClientLine(s);
                c.giveCredits(cr);
                boolean flag = false;
                for (int i = 0; i<newList.size(); i++)
                    if (newList.get(i).newPass == c.newPass || newList.get(i).newPass == c.oldPass || newList.get(i).oldPass == c.newPass) flag = true;
                if (!flag) newList.add(c);
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        return newList;
    }

    private static Credit dropCreditLine(String s)
    {
        String [] inf;
        Credit c = new Credit();
        s = s.replace("^","B");
        inf = s.split("\\||,|B|___|&");
        c.id = Integer.parseInt(inf[0]);
        c.sum = Double.parseDouble(inf[1]);
        c.percent = Double.parseDouble(inf[2].substring(0,inf[2].length()-2));
        c.paySum = Double.parseDouble(inf[3]);
        c.nSum = Double.parseDouble(inf[4]);
        c.date = inf[5];
        return c;
    }

    public static ArrayList<Credit> creditRead(String path){
        ArrayList<Credit> cr = new ArrayList<Credit>();
        File credit = new File("C:\\Users\\Денис\\Downloads\\"+path);
        try{
            Scanner sc = new Scanner(credit);
            String s;
            s = sc.nextLine();
            String[] inf = s.split("Credit\\{");
            for (int i = 1; i<inf.length-1; i++) {
                Credit c = dropCreditLine(inf[i]);
                cr.add(c);
            }
        } catch(FileNotFoundException e) {
            e.printStackTrace();
        }
        return cr;
    }
}
