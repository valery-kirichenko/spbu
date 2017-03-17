package MyBank;

import java.util.ArrayList;
import java.util.Date;

/**
 * Created by Aspire on 10.03.2017.
 */
public class Client {
    int id;
    int passport;
    boolean hasoldpas;
    int oldpas;
    Date birthDate;
    String name, family, father;
    String phone;
    ArrayList<Credit> credits = new ArrayList<Credit>();
}
