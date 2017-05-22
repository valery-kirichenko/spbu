package com.banksys.java;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Algo {
    public static String getInt(String data){
        Pattern pattern = Pattern.compile("\\d+");
        Matcher matcher = pattern.matcher(data);

        String result = "";

        while (matcher.find()){
            result += matcher.group(0);
        }

        return result.trim();
    }
}
