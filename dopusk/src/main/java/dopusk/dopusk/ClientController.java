package dopusk.dopusk;

import java.util.List;

/**
 * Created by USER on 18.06.2017.
 */
public interface ClientController {void saveNewClient(Clients newClient);
    List<Clients> getAllClients();
    void deleteClient(int client_id);
    Clients getByID(int client_id);
    void updateClient(Clients clientUpdate);

}
