package net.task.user.dao;

import net.task.user.models.User;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.jdbc.core.PreparedStatementCallback;
import org.springframework.stereotype.Controller;
import org.springframework.stereotype.Repository;

import java.util.List;

@Repository
public class UsersController implements DBUsersController {
    @Autowired
    private JdbcTemplate template;

    private final String USERS_TABLE_NAME = "users";
    private final String INSERT_QUERY = "INSERT INTO " + USERS_TABLE_NAME +
            " (gender, " +
            "title, first, last, " +
            "street, city, state, postcode," +
            "email, " +
            "dob, " +
            "phone, " +
            "username, password, salt, md5, sha1, sha256," +
            "registered, " +
            "cell, " +
            "name, value, " +
            "large, medium, thumbnail, " +
            "nat)" +

            "VALUES (?," +
            "?,?,?," +
            "?,?,?,?," +
            "?," +
            "?," +
            "?," +
            "?,?,?,?,?,?," +
            "?," +
            "?," +
            "?,?," +
            "?,?,?," +
            "?,);";

    @Override
    public void saveNewClient(User toCreate) {
        template.execute(INSERT_QUERY, (PreparedStatementCallback<Object>) preparedStatement -> {
            preparedStatement.setString(1, toCreate.getGender());

            preparedStatement.setString(2, toCreate.getName().getTitle());
            preparedStatement.setString(3, toCreate.getName().getFirst());
            preparedStatement.setString(4, toCreate.getName().getLast());

            preparedStatement.setString(5, toCreate.getLocation().getStreet());
            preparedStatement.setString(6, toCreate.getLocation().getCity());
            preparedStatement.setString(7, toCreate.getLocation().getState());
            preparedStatement.setString(8, toCreate.getLocation().getPostcode());

            preparedStatement.setString(9, toCreate.getEmail());

            preparedStatement.setString(10, toCreate.getDob());

            preparedStatement.setString(11, toCreate.getPhone());

            preparedStatement.setString(12, toCreate.getLogin().getUsername());
            preparedStatement.setString(13, toCreate.getLogin().getPassword());
            preparedStatement.setString(14, toCreate.getLogin().getSalt());
            preparedStatement.setString(15, toCreate.getLogin().getMd5());
            preparedStatement.setString(16, toCreate.getLogin().getSha1());
            preparedStatement.setString(17, toCreate.getLogin().getSha256());

            preparedStatement.setString(18, toCreate.getRegistered());

            preparedStatement.setString(19, toCreate.getCell());

            preparedStatement.setString(20, toCreate.getId().getName());
            preparedStatement.setString(21, toCreate.getId().getValue());

            preparedStatement.setString(22, toCreate.getPicture().getLarge());
            preparedStatement.setString(23, toCreate.getPicture().getMedium());
            preparedStatement.setString(24, toCreate.getPicture().getThumbnail());

            preparedStatement.setString(25, toCreate.getNat());

            return preparedStatement.execute();
        });
    }

    @Override
    public List<User> getAllClients() {
        return template.query("SELECT * FROM " + USERS_TABLE_NAME, new UsersRowMapper());
    }
}
