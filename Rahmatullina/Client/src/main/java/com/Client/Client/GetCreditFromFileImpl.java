package com.Client.Client;

import org.springframework.stereotype.Service;

import java.io.File;
import java.io.FileNotFoundException;
import java.net.URL;
import java.net.URLDecoder;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


@Service
public class GetCreditFromFileImpl implements GetGreditFromFile {
    @Override
    public List<Credits> getCredit() throws FileNotFoundException {
        String str2;
        URL url = Thread.currentThread().getContextClassLoader().getResource("credits.omg");
        try {
            url = new URL(URLDecoder.decode(url.toString(), "utf-8"));
        } catch (Exception ex) {
            ex.printStackTrace();
        }
        Scanner sc2 = new Scanner(new File(url.getPath())).useDelimiter("&");
        List<Credits> listCredits = new ArrayList<>();
        while (sc2.hasNext()) {
            str2 = sc2.next();
            String arr2[] = str2.split("Credit\\{|\\||,|%,|\\^|___");//длина = 7 arr2[0] - пустой
            Credits credit = new Credits();
            credit.setId(Integer.parseInt(arr2[1]));
            credit.setLoan(arr2[2]);
            credit.setPercent(arr2[3]);
            credit.setPaidSum(arr2[4]);
            credit.setWholeLoan(arr2[5]);
            credit.setDataString(arr2[6]);
            listCredits.add(credit);
        }

        return listCredits;
    }
}
