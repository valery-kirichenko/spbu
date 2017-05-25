package com.NewDataBase;

import org.springframework.stereotype.Service;

import java.io.File;
import java.io.FileNotFoundException;
import java.net.URL;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by Я on 17.03.2017.
 */
@Service
public class GetCreditFromFileImpl implements GetGreditFromFile {

    @Override
    public List<Credits> getCredit() throws FileNotFoundException, ParseException {

        String str2;
        URL url = Thread.currentThread().getContextClassLoader().getResource("credits.omg");
        Scanner sc2 = new Scanner(new File(url.getPath())).useDelimiter("&");
        List<Credits> listCredits = new ArrayList<Credits>();
        while (sc2.hasNext()) {
            str2 = sc2.next();
            String arr2[] = str2.split("Credit\\{|\\||,|%,|\\^|___");//длина = 7 arr2[0] - пустой
            Credits cr = new Credits(arr2[1], arr2[2], arr2[3], arr2[4], arr2[5], arr2[6]);
            listCredits.add(cr);
        }


        return listCredits;
    }
}
