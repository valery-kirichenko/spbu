package app;

import java.time.LocalDate;
import java.util.ArrayList;

import static app.Algo.getInt;

public class Client {
    ArrayList<Credit> credits = new ArrayList<>();

    public String id, phone, passport, oldPassport; // as int
    public String name, surname, middlename;
    public LocalDate date;

    // 934->>>>Елена---Водохлёбова\\Федоровна~~~~+79646546254==559253___1945-10-01==613027
    //ID в старой системе, Имя, Фам, Отчество, телефон, номер паспорта, дата рождения в формате ISO, old pass

    Client(String[] data){
        id = getInt(data[0]);

        name = data[1].replaceAll("ё", "е");
        surname = data[2].replaceAll("ё", "е");
        middlename = data[3].replaceAll("ё", "е");

        phone = getInt(data[4]);
        passport = getInt(data[5]);

        date = LocalDate.from(LocalDate.parse(data[6]));

        if(data.length > 7) {
            oldPassport = getInt(data[7]);
        }else oldPassport = "";
    }

    @Override
    public String toString() {
        return id + "-" + name + "-" + surname + "-" + middlename + "-"
                + phone + "-" + passport + "-" + date.toString() + "-" + oldPassport;
    }
}
