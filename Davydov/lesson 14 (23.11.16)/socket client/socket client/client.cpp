#include <winsock.h>
#include <sys/types.h>
#include <sys/utime.h>
#include <iostream>
#include <string>

#pragma comment(lib,"ws2_32.lib") //Winsock Library

#define SIZE 128
#define port 8888
#define ip "198.168.1.81"
//#define ip "37.145.134.82"
//#define ip "127.0.0.1"

using namespace std;
void readline(char arr[], int size);
int main() {
	WSADATA wsa;
	int socket_desc;
	sockaddr_in server;
	char message[SIZE];
	char server_reply[SIZE];

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

	server.sin_addr.s_addr = inet_addr(ip);
	//server.sin_addr.s_addr = INADDR_ANY;
	server.sin_family = AF_INET;
	server.sin_port = htons(port);

	if (connect(socket_desc, (sockaddr*) &server, sizeof(server)) < 0) {
		std::cout << "Connection failed" << std::endl;
		return 1;
	}
	std::cout << "Connected" << std::endl;

	while (true) {
		std::cout << "Message: ";
		cin.getline(message, SIZE, '\n');

		if (send(socket_desc, message, sizeof(message), 0) < 0) {
			std::cout << "Send failed" << std::endl;
			return 1;
		}
		else std::cout<<"Send successfully\n";

		if (recv(socket_desc, server_reply, SIZE, 0) < 0) {
			std::cout << "recv failed" << std::endl;
			break;
		}
		else std::cout<<"Recv successfully\n";

		std::cout << "Reply: " << server_reply << std::endl;
	}

	return 0;
}