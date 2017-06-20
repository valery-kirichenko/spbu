package com.exam.Exam;

import com.exam.Exam.Controllers.JController;
import com.exam.Exam.Model.Person;
import org.junit.runner.RunWith;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.test.context.junit4.SpringJUnit4ClassRunner;


import java.util.List;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertNotNull;

@RunWith(SpringJUnit4ClassRunner.class)
@SpringBootTest
public class RandomPersonTest {

    @Autowired
    JController jController;

    @org.junit.Test
    public void test() throws Exception {
        List<Person> personList = jController.getRandomPersonList(50);
        for (Person person : personList) {
            assertNotNull(person.getResults().get(0).getGender());
            assertNotNull(person.getResults().get(0).getName().getFirst());
            assertNotNull(person.getResults().get(0).getName().getLast());
            assertNotNull(person.getResults().get(0).getName().getTitle());
        }
    }
    @org.junit.Test
    public void newTest() throws Exception {
        assertEquals(3,3);
    }
    @org.junit.Test(expected = ArithmeticException.class)
    public void moreTests() throws Exception {
        assertEquals(5, 5/0);
    }
}
