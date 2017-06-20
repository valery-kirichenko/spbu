package com.PolyProgrammist;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.web.client.RestTemplate;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;

@Service
public class RandomUserInfos {
    private List<UserInfo> resultList = new ArrayList<>();

    private int usersCount = 100;

    public List<UserInfo> updateAndGetUsers(){
        updateUsers();
        return getUsers();
    }

    @Autowired
    RestTemplate restTemplate;

    public void updateUsers(){
        System.out.println("updating");
        String url = "https://randomuser.me/api/?results=" + String.valueOf(usersCount);
        ServiceAnswerDTO sadto = restTemplate.getForObject(url, ServiceAnswerDTO.class);
        for (Map<String, Object> user : sadto.getResults()){
            Map<String, String> login = (Map<String, String>) user.get("login");
            String username = login.get("username");
            String password = login.get("password");
            resultList.add(new UserInfo(username, password));
        }

    }

    public List<UserInfo> getUsers(){
        return resultList;
    }

    public int getUsersCount() {
        return usersCount;
    }

    public void setUsersCount(int usersCount) {
        this.usersCount = usersCount;
    }
}
