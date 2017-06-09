package com.NewDataBase;

import java.util.List;

/**
 * Created by Я on 27.05.2017.
 */
public interface MainController {



    void changeClientInfo();

    String getNameFromId(Integer ID);

    Clients getClient(Integer ID);

    void setClientList(List<Clients> clientList);

    void setCreditList(List<Credits> creditList);

    List<Clients> getClientList();

    List<Credits> getCreditList();

}
