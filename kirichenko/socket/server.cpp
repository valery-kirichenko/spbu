#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

#define SIZE 2000

int main() {
	int socket_desc, client_sock, c, *new_sock;
	struct sockaddr_in server, client;

	//Create socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);
	if (socket_desc == -1) {
		std::cout << "Could not create socket" << std::endl;
		return 1;
	}
	std::cout << "Socket created" << std::endl;

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8888);

	if (bind(socket_desc, (struct sockaddr*) &server, sizeof(server)) < 0) {
		std::cout << "Bind failed" << std::endl;
		return 1;
	}
	std::cout << "Bind done" << std::endl;

	listen(socket_desc, 3);

	std::cout << "Waiting for connection" << std::endl;

	c = sizeof(struct sockaddr_in);
	client_sock = accept(socket_desc, (struct sockaddr*) &client, (socklen_t*) &c);
	std::cout << "Connection established" << std::endl;

	int read_size;
	char *message, client_message[SIZE];

	while ((read_size = recv(client_sock, client_message, SIZE, 0)) > 0) {
		write(client_sock, client_message, strlen(client_message));
	}

	if(read_size == 0) {
		std::cout << "Client disconnected" << std::endl;
	} else if (read_size == -1) {
		std::cout << "recv failed" << std::endl;
	}

	return 0;
}