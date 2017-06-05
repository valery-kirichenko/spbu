package com.database.Model.Files.Native.Readers;

/**
 * Created by Дмитрий on 11.03.2017.
 */
public class Count
{
    public static boolean isCount(char ch)
    {
        switch (ch)
        {
            case ('0') : return true;
            case ('1') : return true;
            case ('2') : return true;
            case ('3') : return true;
            case ('4') : return true;
            case ('5') : return true;
            case ('6') : return true;
            case ('7') : return true;
            case ('8') : return true;
            case ('9') : return true;

            default: return false;
        }
    }

    public static boolean isCount(String ch)
    {
        switch (ch)
        {
            case ("0") : return true;
            case ("1") : return true;
            case ("2") : return true;
            case ("3") : return true;
            case ("4") : return true;
            case ("5") : return true;
            case ("6") : return true;
            case ("7") : return true;
            case ("8") : return true;
            case ("9") : return true;

            default: return false;
        }
    }
}
