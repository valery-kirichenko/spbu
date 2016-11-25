#include "stdafx.h"
#include <winsock.h>
#include <iostream>
#include <thread>
#include <Windows.h>

#pragma comment(lib,"ws2_32.lib")

#define SIZE 2048

void threadFunction(int socket_desc)
{
	char message[SIZE];

	memset(message, 0, SIZE);

	while (true) {
		std::cout << "Message: ";
		std::cin.getline(message, SIZE);

		if (strlen(message) < 1)
			continue;

		if (send(socket_desc, message, strlen(message), 0) < 0) {
			std::cout << "Send failed\n";
			break;
		}

		/*if ((read_size = recv(socket_desc, server_reply, SIZE, 0)) < 0) {
			std::cout << "recv failed\n";
			std::cout << "Server disconected.\n";
			Sleep(1000);
			closesocket(socket_desc);
			WSACleanup();
			exit(0);
		}

		std::cout << "Reply: " << server_reply;*/
	}
}

int main() {
	WSADATA wsa;
	int socket_desc, read_size;
	sockaddr_in server;
	char server_reply[SIZE];

	memset(server_reply, 0, SIZE);

	std::cout << "\nInitialising Winsock...\n";
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0) {
		std::cout << "Failed. Error Code : " << WSAGetLastError() << "\n";
		system("pause");
		return 1;
	}

	std::cout << "Initialised.\n";

	if ((socket_desc = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
		std::cout << "Could not create socket\n";
		system("pause");
		return 2;
	}
	std::cout << "Socket created\n";

	server.sin_addr.s_addr = inet_addr("172.20.157.87"); //192.168.43.204
	server.sin_family = AF_INET;
	server.sin_port = htons(8888); //80

	if (connect(socket_desc, (sockaddr*)&server, sizeof(server)) < 0) {
		std::cout << "Connection failed\n";
		system("pause");
		return 3;
	}
	std::cout << "Connected\n";

	std::thread thr(threadFunction, socket_desc);
	thr.detach();

	while (true) {

		/*std::cout << "Message: ";
		std::cin.getline(message, SIZE);

		if (send(socket_desc, message, strlen(message), 0) < 0) {
			std::cout << "Send failed\n";
			system("pause");
			return 4;
		}*/
		
		memset(server_reply, 0, SIZE);

		if ((read_size = recv(socket_desc, server_reply, SIZE, 0)) <= 0) {
			std::cout << "recv failed\n";
			break;
		}

		if (strlen(server_reply) < 1)
			continue;

		std::cout << "\nReply: " << server_reply << "\nMessage: ";
	}

	std::cout << "Server disconected.\n";
	system("pause");

	closesocket(socket_desc);
	WSACleanup();
	return 0;
}