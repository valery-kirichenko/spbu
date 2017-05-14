package com.NewDataBase;

import java.io.FileNotFoundException;
import java.text.ParseException;
import java.util.List;

/**
 * Created by Я on 16.04.2017.
 */
public interface GetGreditFromFile {
     List<Credits> getCredit() throws FileNotFoundException, ParseException;
}
