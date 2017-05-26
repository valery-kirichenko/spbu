package com.database;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ConfigurableApplicationContext;

/**
 * Created by Дмитрий on 04.05.2017.
 */

@SpringBootApplication
public class DB
{
    public static void main(String[] args)
    {
        ConfigurableApplicationContext ctx = SpringApplication.run
                (DB.class, args);
    }
}
