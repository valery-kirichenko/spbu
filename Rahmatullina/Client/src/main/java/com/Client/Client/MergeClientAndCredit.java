package com.Client.Client;

import java.util.List;


public interface MergeClientAndCredit {
     void getMerge(List<Clients> listClient, List<Credits> listCredit);
     String getNameFromID(Integer ID, List<Clients> clients);
     void getReplace(List<Clients> listClient);
}