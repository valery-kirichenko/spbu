import java.util.Date;
import java.util.List;

class ClientHelperClass implements ClientHelper{

    private Date date;
    private boolean once;
    private double cash;
    private int num;

    ClientHelperClass() {
        date = new Date();
        once = false;
    }

    @Override
    public void getListOfDebtors(List<Client> clients) {
        System.out.println("POTENTIAL BUMS ID'S:");
        for (Client client : clients) {
            if (!client.getCredits().isEmpty()) {
                for (int j = 0; j < client.getCredits().size(); j++) {
                    if (client.getCredits().get(j).getDeadline().before(date)) {
                        if (client.getCredits().get(j).getCastLeft() > client.getCredits().get(j).getCashPaid()) {
                            System.out.println(client.getId());
                            break;
                        }
                    }
                }
            }
        }
    }

    @Override
    public void getListOfCredits(List<Client> clients) {
        System.out.println("ID: CREDIT_SUM ... CREDIT_SUM");
        for (Client client : clients) {
            if (!client.getCredits().isEmpty()) {
                for (int j = 0; j < client.getCredits().size(); j++) {
                    if (client.getCredits().get(j).getDeadline().before(date)) {
                        if (client.getCredits().get(j).getCastLeft() > client.getCredits().get(j).getCashPaid()) {
                            if (!once) {
                                System.out.print(client.getId() + ": ");
                                once = true;
                            }
                            System.out.print(client.getCredits().get(j).getCastLeft() + " ");
                        }
                    }
                }
                if (once) {
                    System.out.println();
                    once = false;
                }

            }
        }
    }

    @Override
    public void getFullDebtOfClt(List<Client> clients, int ID) {
        cash = 0;
        num = -1;
        for (int i = 0; i < clients.size(); i++)
            if (clients.get(i).getId() == ID) {
                num = i;
                break;
            }
        if (num == -1) {
            System.out.println("NO CLIENT WITH ENTERED ID");
            return;
        }

        if (!clients.get(num).getCredits().isEmpty()) {
            for (int j = 0; j < clients.get(num).getCredits().size(); j++) {
                if (clients.get(num).getCredits().get(j).getDeadline().before(date)) {
                    if (clients.get(num).getCredits().get(j).getCastLeft() > clients.get(num).getCredits().get(j).getCashPaid()) {
                        cash = cash + clients.get(num).getCredits().get(j).getCastLeft();
                    }
                }
            }
            if (cash == 0)
                System.out.println("CLIENT DOES NOT HAVE DEBTS");
            else
                System.out.println("DEBT: " + cash);
        }
        else {
            System.out.println("CLIENT DOES NOT HAVE DEBTS");
        }
    }
}
