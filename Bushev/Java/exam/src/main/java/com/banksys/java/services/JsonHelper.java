package com.banksys.java.services;

import com.banksys.java.models.User;
import org.json.simple.JSONArray;
import org.json.simple.JSONObject;
import org.json.simple.JSONValue;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;

import java.util.ArrayList;
import java.util.List;

@Service
public class JsonHelper {
    @Autowired
    RestTemplate template;

    public List<User> readUsers(String from){
        String res = template.getForObject(from, String.class);

        return readResults((JSONArray) ((JSONObject) JSONValue.parse(res)).get("results"));
    }

    private List<User> readResults(JSONArray results){
        List<User> users = new ArrayList<User>();

        for(int i = 0; i < results.size(); i++){
            JSONObject current = (JSONObject) results.get(i);

            JSONObject name = (JSONObject) current.get("name");
            JSONObject location = (JSONObject) current.get("location");
            JSONObject login = (JSONObject) current.get("login");
            JSONObject picture = (JSONObject) current.get("picture");

            User user = new User(name.get("title").toString(), name.get("first").toString(), name.get("last").toString(),
                    location.get("street").toString(), location.get("city").toString(), location.get("state").toString(), location.get("postcode").toString(),
                    current.get("email").toString(),
                    login.get("username").toString(), login.get("password").toString(),
                    current.get("registered").toString(), current.get("phone").toString(),
                    picture.get("thumbnail").toString(),  current.get("nat").toString());

            users.add(user);
        }

        return users;
    }
}
