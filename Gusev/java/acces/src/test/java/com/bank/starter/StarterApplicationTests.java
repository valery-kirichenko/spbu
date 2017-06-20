package com.bank.starter;

import com.bank.starter.models.Client;
import com.bank.starter.models.Credit;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.ContextConfiguration;
import org.springframework.test.context.junit4.SpringRunner;
import com.bank.starter.app.*;

import java.time.LocalDate;

import static junit.framework.TestCase.assertEquals;

@RunWith(SpringRunner.class)
@SpringBootTest
public class StarterApplicationTests {

	/*@Test
	public void contextLoads() {
		Credit cr = Credit.parse("Credit{727|515584.72710622626,5.0%,269089.711338759^541363.9634615376___2012-12-31&");
        assertEquals(727,cr.getId());
        assertEquals("515584.72710622626",cr.getStartSum());
        assertEquals("5.0",cr.getPercent());
        assertEquals("269089.711338759",cr.getPaidSum());
        assertEquals("541363.9634615376",cr.getAllSum());
        assertEquals(LocalDate.parse("2012-12-31"),cr.getFinishDate());

        Client cl = Client.Parse("\n" + "3751->>>>Ольга---Евгеньева\\\\Прохоровна~~~~+79648590338==898340100___1949-03-23==89");
        assertEquals(3751,cl.getNowId());
        assertEquals("Ольга",cl.getName());
        assertEquals("Евгеньева",cl.getSurName());
        assertEquals("Прохоровна",cl.getLastName());
        assertEquals("+79648590338",cl.getPhone());
        assertEquals("898340100",cl.getPass());
        assertEquals(LocalDate.parse("1949-03-23"),cl.getBirthDate());
        assertEquals("89",cl.getOldPass());
	}//*/

	@Test
    public void chaeck(){
	    String a;
	    a = "34";
        assertEquals(true,a == "3" + "4");
        assertEquals(true, a.equals("3" + "4"));
    }

}
