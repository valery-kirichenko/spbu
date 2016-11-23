#include "stdafx.h"
#include <winsock.h>
#include <sys/types.h>
#include <sys/utime.h>
#include <iostream>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

#define SIZE 128

int main() {
	WSADATA wsa;
	int socket_desc;
	sockaddr_in server;
	char message[SIZE], server_reply[SIZE];

	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		return 1;
	}

	printf("Initialised.\n");

	if ((socket_desc = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		std::cout << "Could not create socket" << std::endl;
		return 0;
	}
	std::cout << "Socket created" << std::endl;

	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(8888);

	if (connect(socket_desc, (sockaddr*) &server, sizeof(server)) < 0) {
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