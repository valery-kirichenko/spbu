package com.example;

import org.springframework.stereotype.Service;

import java.util.ArrayList;

/**
 * Created by Lenovo on 21.03.2017.
 */
@Service
public class ClientHelper implements HelperInterface {
    public void getUnPaid(ArrayList<newBase> BankBase)
    {
        for (int i=0; i<BankBase.size(); i++)
        {
            if (!BankBase.get(i).checkForPaid())
            {

                System.out.println(BankBase.get(i).getAll());
            }
        }
    }
    public void getUnPaidYet(ArrayList<newBase> BankBase)
    {
        for (int i=0; i<BankBase.size(); i++)
        {
            if (!BankBase.get(i).checkForPaidNow())
            {
                System.out.println(BankBase.get(i).getUnPaidByString());
            }
        }
    }

}
