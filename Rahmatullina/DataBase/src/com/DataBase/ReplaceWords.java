package com.DataBase;

import java.util.List;

import com.DataBase.DataBase.*;

/**
 * Created by Я on 17.03.2017.
 */
class ReplaceWords {
    void getReplace(List<Clients> listClient) {

        for (Clients client : listClient) {
            if (client.getName().contains("ё"))
                client.setName(client.getName().replace("ё", "е"));
            if (client.getSurName().contains("ё"))
                client.setSurName(client.getSurName().replace("ё", "е"));
        }


    }
}
