package com.Client.Client;

import java.io.FileNotFoundException;
import java.util.List;


public interface GetGreditFromFile {
     List<Credits> getCredit() throws FileNotFoundException;
}
