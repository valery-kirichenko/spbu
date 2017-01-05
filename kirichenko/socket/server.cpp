#include <string>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <thread>
#include <vector>

struct Client {
    int ref;
    std::string name;
    Client(int r) {
        ref = r;
    }
};

std::vector<Client> clients;
char buf[256];

//the thread function
void connection_handler(int sock);
void send_message(int sock, bool to_client, int from);

int main() {
    int socket_desc, client_sock, c, *new_sock;
    struct sockaddr_in server, client;

    //Create socket
    socket_desc = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_desc == -1) {
        std::cerr << "Could not create socket" << std::endl;
        return 1;
    }
    std::cout << "Socket created" << std::endl;

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    if (bind(socket_desc, (struct sockaddr *) &server, sizeof(server)) < 0) {
        std::cerr << "Bind failed" << std::endl;
        return 1;
    }
    std::cout << "Bind done" << std::endl;

    listen(socket_desc, 3);

    std::cout << "Waiting for incoming connections..." << std::endl;
    c = sizeof(struct sockaddr_in);

    while ((client_sock = accept(socket_desc, (struct sockaddr *) &client, (socklen_t*) &c))) {
        std::cout << "Connection accepted" << std::endl;
        clients.push_back(Client(client_sock));

        std::thread incoming(connection_handler, client_sock);
        incoming.detach();
    }

    if (client_sock < 0) {
        std::cerr << "Accept failed" << std::endl;
        return 1;
    }

    close(socket_desc);

    return 0;
}

void connection_handler(int sock) {
    int n, from;
    bool named = false;

    while (true) {

        memset(buf, 0, 256);
        if (!named) {
            strcpy(buf, "Enter your name:");
            send_message(sock, true, -1);
        }

        if ((n = recv(sock, buf, sizeof(buf), 0)) > 0) {
            if (!named) {
                std::cout << "received name from " << sock << ": " << buf << std::endl;
                for (int i = 0; i < clients.size(); i++) {
                    if (clients[i].ref == sock) {
                        clients[i].name = buf;
                        from = i;
                        break;
                    }
                }
                named = true;
            } else {
                std::cout << "received from " << sock << ": " << buf << '\n';
                std::thread send(send_message, sock, false, from);
                send.join();
            }
        } else {
            std::cout << "Connection handler STOPPED" << std::endl;
            for (int i = 0; i < clients.size(); i++) {
                if (clients[i].ref == sock) {
                    clients.erase(clients.begin() + i);
                }
            }
            break;
        }
    }
}

void send_message(int sock, bool to_client, int from) {
    std::string s;
    for (int i = 0; i < clients.size(); i++) {
        if (!to_client) {
            s = clients[from].name + ": " + buf;
            std::cout << "Send to " << clients[i].ref << " msg: " << s << std::endl;
            send(clients[i].ref, s.data(), s.size(), 0);
        } else if (to_client && clients[i].ref == sock) {
            send(clients[i].ref, buf, 256, 0);
        }
    }
}
