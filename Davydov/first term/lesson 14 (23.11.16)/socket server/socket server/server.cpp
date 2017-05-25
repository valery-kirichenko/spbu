#include <winsock2.h>
#include <iostream>

#pragma comment(lib,"ws2_32.lib")

#define SIZE 128
#define ip "37.145.134.82"
#define ip //"192.168.1.81"
#define port 8888

int main() {
	WSADATA wsa;
	sockaddr_in server, client;
	int read_size, socket_desc, client_sock, c, *new_sock;;
	char *message, client_message[SIZE];

	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		system("pause");
		return 1;
	}

	printf("Initialised.\n");

	if ((socket_desc = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		std::cout << "Could not create socket" << std::endl;
		system("pause");
		return 1;
	}
	std::cout << "Socket created" << std::endl;

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(port);

	if (bind(socket_desc, (sockaddr*)&server, sizeof(server)) < 0) {
		std::cout << "Bind failed" << std::endl;
		system("pause");
		return 1;
	}
	std::cout << "Bind done" << std::endl;

	listen(socket_desc, 3);

	std::cout << "Waiting for connection" << std::endl;

	c = sizeof(sockaddr_in);
	client_sock = accept(socket_desc, (sockaddr*)&client, &c);
	std::cout << "Connection established" << std::endl;

	while ((read_size = recv(client_sock, client_message, SIZE, 0)) > 0) {
		std::cout<<"Reply:"<<client_message<<std::endl;
		std::cout << "Message: ";
		std::cin.getline(client_message, SIZE, '\n');
		send(client_sock, client_message, sizeof(client_message), 0);
	}

	if (read_size == 0) {
		std::cout << "Client disconnected" << std::endl;
	}
	else if (read_size == -1) {
		std::cout << "recv failed" << std::endl;
	}

	system("pause");
	return 0;
}