package com.NewDataBase;

import java.util.List;

/**
 * Created by Я on 16.04.2017.
 */
public interface MergeClientAndCredit {
     void getMerge(List<Clients> listClient, List<Credits> listCredit);

     void getReplace(List<Clients> listClient);
}