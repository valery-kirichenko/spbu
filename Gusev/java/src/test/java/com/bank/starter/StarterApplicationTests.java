package com.bank.starter;

import org.junit.Test;
import org.junit.runner.RunWith;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringRunner;

import java.time.LocalDate;

import static junit.framework.TestCase.assertEquals;

@RunWith(SpringRunner.class)
@SpringBootTest
public class StarterApplicationTests {

	@Test
	public void contextLoads() {
		Credit cr = Credit.parse("Credit{727|515584.72710622626,5.0%,269089.711338759^541363.9634615376___2012-12-31&");
        assertEquals(727,cr.getId());
        assertEquals("515584.72710622626",cr.getStartSum());
        assertEquals("5.0",cr.getPercent());
        assertEquals("269089.711338759",cr.getPaidSum());
        assertEquals("541363.9634615376",cr.getAllSum());
        assertEquals(LocalDate.parse("2012-12-31"),cr.getFinishDate());

        Client cl = Client.Parse("934->>>>Елена---Водохлёбова\\\\Федоровна~~~~+79646546254==559253___1945-10-01==613027");
        assertEquals(934,cl.getNowId());
        assertEquals("Елена",cl.getName());
        assertEquals("Водохлёбова",cl.getSurName());
        assertEquals("Федоровна",cl.getLastName());
        assertEquals("+79646546254",cl.getPhone());
        assertEquals("559253",cl.getPass());
        assertEquals(LocalDate.parse("1945-10-01"),cl.getBirthDate());
        assertEquals(1,cl.getOldPass().size());
	}

	@Test
    public void chaeck(){
	    String a;
	    a = "34";
        assertEquals(true,a == "3" + "4");
        assertEquals(true, a.equals("3" + "4"));
    }

}
