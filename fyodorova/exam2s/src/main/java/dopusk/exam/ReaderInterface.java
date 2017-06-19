package dopusk.exam;

import java.io.FileNotFoundException;
import java.util.List;


public interface ReaderInterface {
    List<Credits> getCredit() throws FileNotFoundException;

    List<Clients> getClient() throws FileNotFoundException;

    void getMerge(List<Clients> clients, List<Credits> credits);


    String getNameFromID(Integer ID, List<Clients> clients);

    void mainMerge() throws FileNotFoundException;

    List<Clients> getClientsList();

    List<Credits> getCreditsList();
}
