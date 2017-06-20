package net.task.user.dao;

import net.task.user.models.*;
import org.springframework.jdbc.core.RowMapper;

import java.sql.ResultSet;
import java.sql.SQLException;


public class UsersRowMapper implements RowMapper<User> {
    @Override
    public User mapRow(ResultSet resultSet, int i) throws SQLException {
        User user = new User();
        Name name = new Name();
        Location location = new Location();
        Id id = new Id();
        Picture picture = new Picture();
        Login login = new Login();

        user.setGender(resultSet.getString("gender"));

        name.setTitle(resultSet.getString("title"));
        name.setFirst(resultSet.getString("first"));
        name.setLast(resultSet.getString("last"));
        user.setName(name);

        location.setStreet(resultSet.getString("street"));
        location.setCity(resultSet.getString("city"));
        location.setState(resultSet.getString("state"));
        location.setPostcode(resultSet.getString("postcode"));
        user.setLocation(location);

        user.setEmail(resultSet.getString("email"));

        user.setDob(resultSet.getString("dob"));

        user.setPhone(resultSet.getString("phone"));

        login.setUsername(resultSet.getString("username"));
        login.setPassword(resultSet.getString("password"));
        login.setSalt(resultSet.getString("salt"));
        login.setMd5(resultSet.getString("md5"));
        login.setSha1(resultSet.getString("sha1"));
        login.setSha256(resultSet.getString("sha256"));
        user.setLogin(login);

        user.setRegistered(resultSet.getString("registered"));

        user.setCell(resultSet.getString("cell"));

        id.setName(resultSet.getString("name"));
        id.setValue(resultSet.getString("value"));
        user.setId(id);

        picture.setLarge(resultSet.getString("large"));
        picture.setMedium(resultSet.getString("medium"));
        picture.setThumbnail(resultSet.getString("thumbnail"));
        user.setPicture(picture);

        user.setNat(resultSet.getString("nat"));

        return user;
    }
}
