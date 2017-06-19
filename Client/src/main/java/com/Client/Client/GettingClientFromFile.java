package com.Client.Client;


import java.io.FileNotFoundException;
import java.util.List;


public interface GettingClientFromFile {

     List<Clients> getClient() throws FileNotFoundException;
}
