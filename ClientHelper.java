package com.example.CreditBase1;

import java.util.List;


public interface ClientHelper {
    void clientsList(List<Credits> credits, List<Clients> clients);

    void creditsList(List<Credits> credits, List<Clients> clients);

    void total(List<Credits> credits, List<Clients> clients);
}
