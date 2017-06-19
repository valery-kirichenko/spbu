package com.PolyProgrammist.FromFile;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.Scanner;

public class FileBaseInterpreter {
    private String clientsFile, creditsFile;

    public FileBaseInterpreter(String clientsFile, String creditsFile){
        this.clientsFile = clientsFile;
        this.creditsFile = creditsFile;
    }

    public void interpret(){
        for (String s : readFile(clientsFile, "\n"))
            try { addClient(parseClient(s)); }
            catch (Exception ignored){}
        for (String s : readFile(creditsFile, "&"))
            try { addCredit(parseCredit(s)); }
            catch (Exception ignored) {}

        checkMergeClient();
    }

    private void addCredit(CreditInf cr) {
        for (ClientInf cl : ClientStorage.getClientList())
            if (cr.getClientId() == cl.getId())
                cl.getCredits().add(cr);
    }

    private CreditInf parseCredit(String s){
        CreditInf cr = new CreditInf();
        s = s.substring(7);
        cr.setClientId(Integer.parseInt(s.substring(0, s.indexOf('|'))));
        s = s.substring(s.indexOf('|') + 1);
        cr.setSum(Double.parseDouble(s.substring(0, s.indexOf(','))));
        s = s.substring(s.indexOf(',') + 1);
        cr.setPercent(Double.parseDouble(s.substring(0, s.indexOf('%'))));
        s = s.substring(s.indexOf('%') + 2);
        cr.setSumPaid(Double.parseDouble(s.substring(0, s.indexOf('^'))));
        s = s.substring(s.indexOf('^') + 1);
        cr.setSumToPay(Double.parseDouble(s.substring(0, s.indexOf('_'))));
        s = s.substring(s.indexOf('_') + 3);
        try {
            cr.setDateToClose((new SimpleDateFormat("yyyy-MM-dd")).parse(s));
        } catch (ParseException e) {
            e.printStackTrace();
        }
        return cr;
    }

    private ClientInf parseClient(String s){
        ClientInf cl = new ClientInf();

        s.indexOf("");
        cl.setId(Integer.parseInt(s.substring(0, s.indexOf('-'))));
        s = s.substring(s.lastIndexOf('>') + 1);
        cl.setName(s.substring(0, s.indexOf('-')));
        s = s.substring(s.indexOf('-') + 3);
        cl.setFamily(s.substring(0, s.indexOf('\\')));
        s = s.substring(s.indexOf('\\') + 2);
        cl.setFather(s.substring(0, s.indexOf('~')));
        s = s.substring(s.indexOf('~') + 4);
        cl.setPhone(s.substring(0, s.indexOf('=')));
        s = s.substring(s.indexOf('=') + 2);
        cl.setPassport(s.substring(0, s.indexOf('_')));
        s = s.substring(s.indexOf('_') + 3);
        try {
            cl.setBirthDate((new SimpleDateFormat("yyyy-MM-dd")).parse(s.indexOf('=') == -1 ? s : s.substring(0, s.indexOf('='))));
        } catch (ParseException e) {
            e.printStackTrace();
        }
        if (s.indexOf('=') != -1){
            cl.setHasoldpas(true);
            s = s.substring(s.indexOf('=') + 2);
            cl.setOldpas(s);
        }
        else cl.setHasoldpas(false);

        return cl;
    }

    private void addClient(ClientInf cl) {
        ClientStorage.getClientList().add(cl);
    }

    private void checkMergeClient() {
        List<ClientInf> nacl = new ArrayList<ClientInf>();
        for (ClientInf c1: ClientStorage.getClientList()) {
            boolean was = false;
            for (ClientInf c2 : nacl) {
                boolean eq = false;
                if (Objects.equals(c1.getPassport(), c2.getPassport()))
                    eq = true;
                if (c2.isHasoldpas() && Objects.equals(c1.getPassport(), c2.getOldpas()))
                    eq = true;
                if (c1.isHasoldpas() && Objects.equals(c2.getPassport(), c1.getOldpas())) {
                    eq = true;
                    c2.setPassport(c1.getPassport());
                    c2.setOldpas(c1.getOldpas());
                }
                if (eq) {
                    for (CreditInf cr : c1.getCredits())
                        cr.setClientId(c2.getId());
                    c2.getCredits().addAll(c1.getCredits());
                    was = true;
                }
            }
            if (!was)
                nacl.add(c1);
        }
        ClientStorage.setClientList(nacl);
    }

    private String[] readFile(String fileName, String del){
        String[] res = new String[0];
        URL url = Thread.currentThread().getContextClassLoader().getResource(fileName);
        try {
            String now = "";
            Scanner sc = new Scanner(new File(url.getPath()));
            while (sc.hasNext())
                now += sc.nextLine() + '\n';
            res = now.split(del);
        } catch (IOException e) {
            e.printStackTrace();
        }
        return res;
    }
}
