package com.example.CreditBase1;
import java.util.List;

/**
 * Created by Егор on 09.05.2017.
 */
public interface ClientHelper {

    void clientsList(List<Credits> credits, List<Clients> clients);

    void creditsList(List<Credits> credits, List<Clients> clients);

    void total(List<Credits> credits, List<Clients> clients);
}
