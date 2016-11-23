#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
//#include <netinet/in.h>
#include <iostream>

#define SIZE 2000

int main() {
	int socket_desc;
	struct sockaddr_in server;
	char message[SIZE], server_reply[SIZE];

	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1) {
		std::cout << "Could not create socket" << std::endl;
		return 0;
	}
	std::cout << "Socket created" << std::endl;

	server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);

    //Connect to server
    if (connect(socket_desc, (struct sockaddr*) &server, sizeof(server)) < 0) {
        std::cout << "Connection failed" << std::endl;
        return 1;
    }
    std::cout << "Connected" << std::endl;

    while (true) {
    	std::cout << "Message: ";
    	std::cin >> message;

    	if (send(socket_desc, message, strlen(message), 0) < 0) {
            std::cout << "Send failed" << std::endl;
            return 1;
        }

        if (recv(socket_desc, server_reply, SIZE, 0) < 0) {
            std::cout << "recv failed" << std::endl;
            break;
        }

        std::cout << "Reply: " << server_reply << std::endl;
    }

	return 0;
}