package MyBank;

import java.io.File;
import java.io.FileNotFoundException;
import java.net.URL;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Scanner;

public class FileBaseInterpreter {
    ArrayList<Client> acl;
    ArrayList<Credit> acr;
    Singleton sn;
    String clientsFile, creditsFile;
    FileBaseInterpreter(String clientsFile, String creditsFile, Singleton sn){
        this.clientsFile = clientsFile;
        this.creditsFile = creditsFile;
        this.sn = sn;
    }

    public void interpret(){
        clientRead();
        creditReadAndAssign();
        checkMergeClient();
        sn.aclient = acl;
    }

    private void creditReadAndAssign() {
        URL url = Thread.currentThread().getContextClassLoader().getResource(creditsFile);
        File file = new File(url.getPath());
        try (Scanner sc = new Scanner(file);){
            String s = sc.nextLine();
            String[] al = s.split("&");
            for (String t : al)
                try {
                    addCredit(t);
                }
                catch (StringIndexOutOfBoundsException siobe){
                }
        }
        catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void addCredit(String s) {
        Credit cr = new Credit();
        s = s.substring(7);
        cr.clientId = Integer.parseInt(s.substring(0, s.indexOf('|')));
        s = s.substring(s.indexOf('|') + 1);
        cr.sum = Double.parseDouble(s.substring(0, s.indexOf(',')));
        s = s.substring(s.indexOf(',') + 1);
        cr.percent = Double.parseDouble(s.substring(0, s.indexOf('%')));
        s = s.substring(s.indexOf('%') + 2);
        cr.sumPaid = Double.parseDouble(s.substring(0, s.indexOf('^')));
        s = s.substring(s.indexOf('^') + 1);
        cr.sumToPay = Double.parseDouble(s.substring(0, s.indexOf('_')));
        s = s.substring(s.indexOf('_') + 3);
        try {
            cr.dateToClose = (new SimpleDateFormat("yyyy-MM-dd")).parse(s);
        } catch (ParseException e) {
            e.printStackTrace();
        }

        for (Client cl : acl)
            if (cr.clientId == cl.id)
                cl.credits.add(cr);

    }

    private void checkMergeClient() {
        ArrayList<Client> nacl = new ArrayList<Client>();
        for (Client c1: acl) {
            boolean was = false;
            for (Client c2 : nacl) {
                boolean eq = false;
                if (c1.passport == c2.passport)
                    eq = true;
                if (c2.hasoldpas && c1.passport == c2.oldpas)
                    eq = true;
                if (c1.hasoldpas && c2.passport == c1.oldpas) {
                    eq = true;
                    c2.passport = c1.passport;
                    c2.oldpas = c1.oldpas;
                }
                if (eq) {
                    for (Credit cr : c1.credits)
                        cr.clientId = c2.id;
                    c2.credits.addAll(c1.credits);
                    was = true;
                }
            }
            if (!was)
                nacl.add(c1);
        }
        acl = nacl;
    }

    private void clientRead() {
        acl = new ArrayList<Client>();
        URL url = Thread.currentThread().getContextClassLoader().getResource(clientsFile);
        File file = new File(url.getPath());
        try (Scanner sc = new Scanner(file);){
            while (sc.hasNext())
                addClient(sc.nextLine());
        }
        catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    private void addClient(String s) {
        Client cl = new Client();
        s.indexOf("");
        cl.id = Integer.parseInt(s.substring(0, s.indexOf('-')));
        s = s.substring(s.lastIndexOf('>') + 1);
        cl.name = s.substring(0, s.indexOf('-'));
        s = s.substring(s.indexOf('-') + 3);
        cl.family = s.substring(0, s.indexOf('\\'));
        s = s.substring(s.indexOf('\\') + 2);
        cl.father = s.substring(0, s.indexOf('~'));
        s = s.substring(s.indexOf('~') + 4);
        cl.phone = s.substring(0, s.indexOf('='));
        s = s.substring(s.indexOf('=') + 2);
        cl.passport = Integer.parseInt(s.substring(0, s.indexOf('_')));
        s = s.substring(s.indexOf('_') + 3);
        try {
            cl.birthDate = (new SimpleDateFormat("yyyy-MM-dd")).parse(s.indexOf('=') == -1 ? s : s.substring(0, s.indexOf('=')));
        } catch (ParseException e) {
            e.printStackTrace();
        }
        if (s.indexOf('=') != -1){
            cl.hasoldpas = true;
            s = s.substring(s.indexOf('=') + 2);
            cl.oldpas = Integer.parseInt(s);
        }
        else cl.hasoldpas = false;
        acl.add(cl);
    }
}
