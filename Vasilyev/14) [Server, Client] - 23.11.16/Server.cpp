#include "stdafx.h"
#include <winsock2.h>
#include <iostream>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

#define SIZE 128

int main() {
	WSADATA wsa;
	sockaddr_in server, client;
	int read_size, socket_desc, client_sock, c, *new_sock;;
	char *message, client_message[SIZE];

	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		return 1;
	}

	printf("Initialised.\n");

	if ((socket_desc = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		std::cout << "Could not create socket" << std::endl;
		return 1;
	}
	std::cout << "Socket created" << std::endl;

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8888);

	if (bind(socket_desc, (sockaddr*)&server, sizeof(server)) < 0) {
		std::cout << "Bind failed" << std::endl;
		return 1;
	}
	std::cout << "Bind done" << std::endl;

	listen(socket_desc, 3);

	std::cout << "Waiting for connection" << std::endl;

	c = sizeof(sockaddr_in);
	client_sock = accept(socket_desc, (sockaddr*)&client, &c);
	std::cout << "Connection established" << std::endl;

	while ((read_size = recv(client_sock, client_message, SIZE, 0)) > 0) {
		send(client_sock, client_message, strlen(client_message), 0);
	}

	if (read_size == 0) {
		std::cout << "Client disconnected" << std::endl;
	}
	else if (read_size == -1) {
		std::cout << "recv failed" << std::endl;
	}

	return 0;
}