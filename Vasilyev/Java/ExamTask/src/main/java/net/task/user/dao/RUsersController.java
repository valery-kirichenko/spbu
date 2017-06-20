package net.task.user.dao;

import net.task.user.models.Result;
import net.task.user.models.User;
import org.springframework.http.ResponseEntity;

import java.util.List;

public interface RUsersController {
    ResponseEntity<Result> getResult(Integer count);
}
