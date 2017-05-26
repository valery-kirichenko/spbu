package net.task.client.dao;


import net.task.client.models.Credit;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.client.RestTemplate;


@Controller
public class RestCreditsController implements CreditsController {
    private String urlCredits = "http://localhost:8080/credit/";

    @Autowired
    private RestTemplate restTemplate;

    @Override
    public void createCredit(Credit credit) {
        restTemplate.postForEntity(urlCredits, credit, Credit.class);
    }

    @Override
    public void deleteCredit(int id) {
        restTemplate.delete(urlCredits + "/" + id);
    }
}
