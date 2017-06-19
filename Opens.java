package com.example.CreditBase1;

import org.springframework.stereotype.Service;

import java.io.*;
import java.lang.String;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


@Service
public class Opens {

    public void start(List<Credits> credits, List<Clients> clients) throws IOException {
        int k = -1, i = 0, zn = -1, p = 6, l = 10;
        char h = 'a';

        FileReader fr = new FileReader(new File("c:/windows/clients.omg"));
        int ch;
        String s = "";
        //List<Clients> clients = new ArrayList<Clients>() {
        //};
        Clients on = new Clients();

        Scanner in2 = new Scanner(new File("c:/windows", "clients.omg"));


        // Посимвольное считывание данных о клиентах и заполнение полей

        while ((ch = fr.read()) != -1) {
            if (i > zn && k == -1) {
                if (h != 'a') {
                    s += h;
                    h = 'a';
                }
                if ((char) ch == '-') {
                    on.setId(s);
                    s = "";
                    k++;
                    zn = i;
                } else
                    s += (char) ch;
            }

            if (i > zn && k == 0 && (char) ch != '>') {
                if ((char) ch == '-') {
                    on.setName(s);
                    s = "";
                    k++;
                    zn = i;
                } else
                    s += (char) ch;
            }

            if (i > zn && k == 1 && (char) ch != '-') {
                if ((char) ch == '\\') {
                    on.setFam(s);
                    s = "";
                    k++;
                    zn = i;
                } else
                    s += (char) ch;
            }

            if (i > zn && k == 2 && (char) ch != '\\') {
                if ((char) ch == '~') {
                    on.setOt(s);
                    s = "";
                    k++;
                    zn = i;
                } else
                    s += (char) ch;
            }

            if (i > zn && k == 3 && (char) ch != '~') {
                if ((char) ch == '=') {
                    on.setSot(s);
                    s = "";
                    k++;
                    zn = i;
                } else
                    s += (char) ch;
            }

            if (i > zn && k == 4 && (char) ch != '=') {
                if ((char) ch == '_') {
                    on.setPas1(s);
                    s = "";
                    k++;
                    zn = i;
                } else
                    s += (char) ch;
            }

            if (i > zn && k == 5 && (char) ch != '_') {
                if (l > 0) {
                    s += (char) ch;
                    l--;
                } else {
                    on.setDate(s);
                    s = "";
                    k++;
                    zn = i;
                }
            }


            if (i == zn + 1 && k == 6 && (char) ch != '=' && p != 0) {
                p = 0;
                on.setPas2("");
                k++;
                h = (char) ch;
            } else if (((char) ch == '\n') && i > zn && k == 6 && (char) ch != '=' && p != 0) {
                p = 0;
            } else if (i > zn && k == 6 && (char) ch != '=' && p != 0) {
                s += (char) ch;
                p--;

            } else if (p == 0 && k == 6) {
                on.setPas2(s);
                s = "";
                k++;
            }

            if (k == 7) {
                k = -1;
                i = 0;
                p = 6;
                zn = -1;
                l = 10;
                clients.add(on);
                on = new Clients();
            } else
                i++;
        }

        for (int r = 0; r < clients.size(); r++) {
            if (clients.get(r).getPas2().length() > 5 && clients.get(r).getPas2() != "")
                if (clients.get(r).getPas2().charAt(4) == '\n') {
                    clients.get(r + 1).setId(clients.get(r).getPas2().charAt(5) + clients.get(r + 1).getId());
                    clients.get(r).setPas2((clients.get(r).getPas2().charAt(0) + "") + (clients.get(r).getPas2().charAt(1) + "") + (clients.get(r).getPas2().charAt(2) + "") + (clients.get(r).getPas2().charAt(3) + ""));
                }
        }


        // Перевод даты в нужный формат

        for (Clients bum : clients) {
            bum.setDate((bum.getDate().charAt(8) + "") + (bum.getDate().charAt(9) + "") + '.' + (bum.getDate().charAt(5) + "") + (bum.getDate().charAt(6) + "") + '.' + (bum.getDate().charAt(0) + "") + (bum.getDate().charAt(1) + "") + (bum.getDate().charAt(2) + "") + (bum.getDate().charAt(3) + ""));
        }

        String s4;
        i = 0;
        s4 = in2.nextLine();

        while (in2.hasNextLine()) {
            for (String line : s4.split("->>>>", 0)) {
                if (p % 2 == 0) {
                    clients.get(i).setId(line);
                    i++;
                    s4 = in2.nextLine();
                }
                p++;
            }
        }

        in2.close();

        // Разделение строки с кредитами на строки по каждому кредиту

        String s2;
        Scanner in = new Scanner(new File("c:/windows", "credits.omg"));
        s2 = in.nextLine() + "\r\n";
        in.close();

        try {
            FileWriter writer = new FileWriter("credits2.txt");
            for (String line : s2.split("Credit", 0)) {
                writer.write(line);
                writer.write(System.getProperty("line.separator"));
            }
            writer.close();
        } catch (IOException ex) {
            ex.printStackTrace();
        }

        k = -1;
        i = 0;
        zn = -1;
        int po = -1;

        FileReader fr2 = new FileReader(new File("credits2.txt"));
        int ch2;
        String s3 = "";
        //List<Credits> credits = new ArrayList<Credits>() {
        //};

        Credits on2 = new Credits();

        // Посимвольное считывание кредитов и заполнение полей

        while ((ch2 = fr2.read()) != -1) {
            if (i > 0 && k == -1 && po == 1) {
                if ((char) ch2 == '|') {

                    on2.setId(s3);
                    s3 = "";
                    k++;
                    zn = i;
                } else
                    s3 += (char) ch2;
            }

            if (po < 1) {
                po++;
                i--;
            }

            if (i > zn && k == 0 && (char) ch2 != '|') {
                if ((char) ch2 == ',') {
                    on2.setSum(s3);
                    s3 = "";
                    k++;
                    zn = i;
                } else
                    s3 += (char) ch2;
            }

            if (i > zn && k == 1) {
                if ((char) ch2 == ',') {
                    on2.setPer(s3);
                    s3 = "";
                    k++;
                    zn = i;
                } else
                    s3 += (char) ch2;
            }

            if (i > zn && k == 2) {
                if ((char) ch2 == '^') {
                    on2.setVyp(s3);
                    s3 = "";
                    k++;
                    zn = i;
                } else
                    s3 += (char) ch2;
            }

            if (i > zn && k == 3) {
                if ((char) ch2 == '_') {
                    on2.setOst(s3);
                    s3 = "";
                    k++;
                    zn = i;
                } else
                    s3 += (char) ch2;
            }

            if (i > zn && k == 4 && (char) ch2 != '_') {
                if ((char) ch2 == '&') {
                    on2.setDate(s3);
                    s3 = "";
                    k++;
                    zn = i;
                } else
                    s3 += (char) ch2;
            }

            if (k == 5) {
                k = -1;
                i = 0;
                zn = -1;
                po = -1;
                credits.add(on2);
                on2 = new Credits();
            } else
                i++;
        }


        // Перевод даты в нужный формат

        for (Credits bum : credits) {
            bum.setDate((bum.getDate().charAt(8) + "") + (bum.getDate().charAt(9) + "") + '.' + (bum.getDate().charAt(5) + "") + (bum.getDate().charAt(6) + "") + '.' + (bum.getDate().charAt(0) + "") + (bum.getDate().charAt(1) + "") + (bum.getDate().charAt(2) + "") + (bum.getDate().charAt(3) + ""));
        }


        for (int r = 0; r < clients.size(); r++)
            for (int u = 0; u < credits.size(); u++)
                if (Integer.parseInt(clients.get(r).getId()) == Integer.parseInt(credits.get(u).getId()))
                    clients.get(r).getCreditsList().add(credits.get(u));


        List<Integer> arr = new ArrayList<>();

        // Исправление битых записей, связанных с совпадением старого и нового номеров паспорта

        for (int r = 0; r < clients.size(); r++)
            for (int u = 0; u < clients.size(); u++) {
                if (Integer.parseInt(clients.get(r).getPas1()) == Integer.parseInt(clients.get(u).getPas1()) && r < u) {
                    clients.get(r).getCreditsList().addAll(clients.get(u).getCreditsList());
                    arr.add(u);
                } else if (clients.get(u).getPas1() != "" && clients.get(r).getPas2() != "")
                    if (Integer.parseInt(clients.get(u).getPas1()) == Integer.parseInt(clients.get(r).getPas2())) {
                        clients.get(r).getCreditsList().addAll(clients.get(u).getCreditsList());
                        arr.add(u);
                    }
            }

        for (int u = 0; u < arr.size(); u++) {
            i = arr.get(u);
            clients.remove(i);
        }


        int sd;

        // Запись всех данных в общий файл

        try {
            FileWriter writer = new FileWriter("newBase.txt");
            for (int r = 0; r < clients.size(); r++) {
                writer.write(Integer.parseInt(clients.get(r).getId()) + " ");
                writer.write(clients.get(r).getName() + " ");
                writer.write(clients.get(r).getFam() + " ");
                writer.write(clients.get(r).getOt() + " ");
                writer.write(clients.get(r).getSot() + " ");
                writer.write(clients.get(r).getPas1() + " ");
                writer.write(clients.get(r).getDate() + " ");
                writer.write(clients.get(r).getPas2());
                writer.write(System.getProperty("line.separator"));
                for (int u = 0; u < clients.get(r).getCreditsList().size(); u++) {
                    sd = u + 1;
                    writer.write("   " + sd + ") ");
                    writer.write(Integer.parseInt(clients.get(r).getCreditsList().get(u).getId()) + " ");
                    writer.write(clients.get(r).getCreditsList().get(u).getSum() + " ");
                    writer.write(clients.get(r).getCreditsList().get(u).getPer() + " ");
                    writer.write(clients.get(r).getCreditsList().get(u).getVyp() + " ");
                    writer.write(clients.get(r).getCreditsList().get(u).getOst() + " ");
                    writer.write(clients.get(r).getCreditsList().get(u).getDate());
                    writer.write(System.getProperty("line.separator"));
                }
            }
            writer.close();
        } catch (IOException ex) {
            ex.printStackTrace();
        }


        //ClientHelperRealization helper = new ClientHelperRealization();
        //helper.clientsList(credits, clients);
        //helper.creditsList(credits, clients);
        //helper.total(credits, clients);
    }
}
