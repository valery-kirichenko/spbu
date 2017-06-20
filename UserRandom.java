package com.MyProj.MyProj;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
/**
 * Created by Lenovo on 20.06.2017.
 */
@Service
public class UserRandom {
    private List<User> result = new ArrayList<>();
    private int count = 10;
    public List<User> getAllUsers(){
        getNewUsers();
        return getUsers();
    }
    public List<User> getUsers(){
        return result;
    }
    @Autowired
    RestTemplate restTemplate;
    private final String URL = "https://randomuser.me/api/?results=" + String.valueOf(count);
    public void getNewUsers(){
        ServAns ans = restTemplate.getForObject(URL, ServAns.class);
        for (Map<String, Object> user : ans.getResults()){
            Map<String, String> login = (Map<String, String>) user.get("login");
            String username = login.get("username");
            String password = login.get("password");
            result.add(new User(username, password));
        }
    }
}
