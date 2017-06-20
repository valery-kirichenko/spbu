package dopusk.exam;

import org.springframework.jdbc.core.RowMapper;

import java.sql.ResultSet;
import java.sql.SQLException;


public class ClientRowMapper implements RowMapper<Clients> {
    @Override
    public Clients mapRow(ResultSet resultSet, int i) throws SQLException {
        Clients client = new Clients();
        client.setId(resultSet.getInt("id"));
        client.setName(resultSet.getString("first_name"));
        client.setSurName(resultSet.getString("last_name"));
        client.setmName(resultSet.getString("mid_name"));
        client.setPh(resultSet.getString("phone"));
        client.setNewPass(resultSet.getString("new_passport"));
        client.setData(resultSet.getString("dat"));
        client.setOldPass(resultSet.getString("old_passport"));

        return client;
    }
}
