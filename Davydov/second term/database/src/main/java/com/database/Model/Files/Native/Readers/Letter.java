package com.database.Model.Files.Native.Readers;

/**
 * Created by Дмитрий on 11.03.2017.
 */
public class Letter
{
    public static boolean isRussianLetter(char ch)
    {
        switch (ch)
        {
            case ('а') : return true;
            case ('б') : return true;
            case ('в') : return true;
            case ('г') : return true;
            case ('д') : return true;
            case ('е') : return true;
            case ('ё') : return true;
            case ('ж') : return true;
            case ('з') : return true;
            case ('и') : return true;
            case ('й') : return true;
            case ('к') : return true;
            case ('л') : return true;
            case ('м') : return true;
            case ('н') : return true;
            case ('о') : return true;
            case ('п') : return true;
            case ('р') : return true;
            case ('с') : return true;
            case ('т') : return true;
            case ('у') : return true;
            case ('ф') : return true;
            case ('х') : return true;
            case ('ц') : return true;
            case ('ч') : return true;
            case ('ш') : return true;
            case ('щ') : return true;
            case ('ъ') : return true;
            case ('ы') : return true;
            case ('ь') : return true;
            case ('э') : return true;
            case ('ю') : return true;
            case ('я') : return true;

            case ('А') : return true;
            case ('Б') : return true;
            case ('В') : return true;
            case ('Г') : return true;
            case ('Д') : return true;
            case ('Е') : return true;
            case ('Ё') : return true;
            case ('Ж') : return true;
            case ('З') : return true;
            case ('И') : return true;
            case ('Й') : return true;
            case ('К') : return true;
            case ('Л') : return true;
            case ('М') : return true;
            case ('Н') : return true;
            case ('О') : return true;
            case ('П') : return true;
            case ('Р') : return true;
            case ('С') : return true;
            case ('Т') : return true;
            case ('У') : return true;
            case ('Ф') : return true;
            case ('Х') : return true;
            case ('Ц') : return true;
            case ('Ч') : return true;
            case ('Ш') : return true;
            case ('Щ') : return true;
            case ('Ъ') : return true;
            case ('Ы') : return true;
            case ('Ь') : return true;
            case ('Э') : return true;
            case ('Ю') : return true;
            case ('Я') : return true;

            default: return false;
        }
    }

    public static boolean isRussianLetter(String ch)
    {
        switch (ch)
        {
            case "а" : return true;
            case "б" : return true;
            case "в" : return true;
            case "г" : return true;
            case "д" : return true;
            case "е" : return true;
            case "ё" : return true;
            case "ж" : return true;
            case "з" : return true;
            case "и" : return true;
            case "й" : return true;
            case "к" : return true;
            case "л" : return true;
            case "м" : return true;
            case "н" : return true;
            case "о" : return true;
            case "п" : return true;
            case "р" : return true;
            case "с" : return true;
            case "т" : return true;
            case "у" : return true;
            case "ф" : return true;
            case "х" : return true;
            case "ц" : return true;
            case "ч" : return true;
            case "ш" : return true;
            case "щ" : return true;
            case "ъ" : return true;
            case "ы" : return true;
            case "ь" : return true;
            case "э" : return true;
            case "ю" : return true;
            case "я" : return true;

            default : return false;
        }
    }

    public static boolean isEnglishLetter(String ch)
    {
        switch (ch)
        {
            case "a" : return true;
            case "b" : return true;
            case "c" : return true;
            case "d" : return true;
            case "e" : return true;
            case "f" : return true;
            case "g" : return true;
            case "h" : return true;
            case "i" : return true;
            case "j" : return true;
            case "k" : return true;
            case "l" : return true;
            case "m" : return true;
            case "n" : return true;
            case "o" : return true;
            case "p" : return true;
            case "q" : return true;
            case "r" : return true;
            case "s" : return true;
            case "t" : return true;
            case "u" : return true;
            case "v" : return true;
            case "w" : return true;
            case "x" : return true;
            case "y" : return true;
            case "z" : return true;
            default : return false;
        }
    }

    public static boolean isRussian(String word)
    {
        String[] stringArray = word.toLowerCase().split("");

        for (String ptr : stringArray)
        {
            if (!isRussianLetter(ptr)) return false;
        }
        return true;
    }

    public static boolean isRussianOrEnglish(String word)
    {
        String[] stringArray = word.toLowerCase().split("");

        for (String ptr : stringArray)
        {
            if (!(isRussianLetter(ptr)||isEnglishLetter(ptr)))
                return false;
        }
        return true;
    }
}
