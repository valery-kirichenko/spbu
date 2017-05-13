#include <string>
#include <iostream>
#include <vector>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <thread>

void write_messages(int sock);

int main(int argc , char *argv[]) {
    int sock;
    struct sockaddr_in server;

    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1) {
        std::cerr << "Could not create socket" << std::endl;
    }
    std::cout << "Socket created" << std::endl;

    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    //Connect to remote server
    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) < 0) {
        std::cerr << "Connect failed" << std::endl;
        return 1;
    }

    std::cout << "Connected" << std::endl;

    std::thread write(write_messages, sock);
    write.detach();

    int n;
    char buf[256];

    while (true) {
        memset(buf, 0, 256);
        if ((n = recv(sock, buf, sizeof(buf), 0)) > 0) {
            std::cout << buf << '\n';
        } else if (n == 0) {
            std::cout << "Server stopped" << std::endl;
            break;
        } else {
            std::cout << "Kinda error " << n << std::endl;
            break;
        }
    }

    return 0;
}

void write_messages(int sock) {
	char buf[256];
    while (true) {
        std::cin.getline(buf, 256);

        if (send(sock, buf, 256, 0) < 0) {
            std::cerr << "Send failed" << std::endl;
        }
    }
}
