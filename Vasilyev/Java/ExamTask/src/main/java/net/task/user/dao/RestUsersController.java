package net.task.user.dao;

import net.task.user.models.Result;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.client.RestTemplate;


@Controller
public class RestUsersController implements RUsersController {
    private String urlClients = "https://randomuser.me/api/?page=3&results=100&seed=abc";

    @Autowired
    private RestTemplate restTemplate;

    @Override
    @RequestMapping(value = "users/{count}", method = RequestMethod.GET)
    public ResponseEntity<Result> getResult(@PathVariable(name = "count") Integer count) {
        Result responseEntity = restTemplate.getForObject(
                "https://randomuser.me/api/?page=3&results=" + count.toString() + "&seed=abc", Result.class);
        ResponseEntity<Result> resultResponseEntity = restTemplate.getForEntity(
                "https://randomuser.me/api/?page=3&results=" + count.toString() + "&seed=abc", Result.class);
        return resultResponseEntity;
    }
}
