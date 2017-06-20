package dopusk.exam;

import java.util.List;

public interface ClientControl {void saveNewClient(Clients newClient);
    List<Clients> getAllClients();
    void deleteClient(int client_id);
    Clients getByID(int client_id);
    void updateClient(Clients clientUpdate);

}
