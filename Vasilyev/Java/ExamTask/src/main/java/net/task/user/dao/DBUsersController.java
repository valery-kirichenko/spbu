package net.task.user.dao;

import net.task.user.models.User;

import java.util.List;

public interface DBUsersController {
    void saveNewClient(User toCreate);

    List<User> getAllClients();
}