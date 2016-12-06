// server.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h" 
#include <winsock.h> 
#include <iostream> 
#include <thread> 
#include <Windows.h> 

#pragma comment(lib,"ws2_32.lib")

#define port	1100

int main()
{
	setlocale(0, "");
	WSADATA wsa;
	sockaddr_in stSockAddr; 
	char repl[11]="Hello,pidr";
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());system("pause");
		return 1;
	}
	int i32SocketFD = socket(AF_INET, SOCK_STREAM,0);

	if (i32SocketFD == -1) {
		perror("ошибка при создании сокета");system("pause");
		exit(EXIT_FAILURE);
	}

	memset(&stSockAddr, 0, sizeof(stSockAddr));

	stSockAddr.sin_family = AF_INET;
	stSockAddr.sin_port = htons(port);
	stSockAddr.sin_addr.s_addr =INADDR_ANY;

	if (bind(i32SocketFD, (struct sockaddr*) &stSockAddr, sizeof(stSockAddr)) == -1) {
		perror("Ошибка: связывания");system("pause");

		shutdown(i32SocketFD,1); 
		exit(EXIT_FAILURE);
	}
	listen(i32SocketFD, 3);
	/*if (connect(i32SocketFD, (sockaddr*)&stSockAddr, sizeof(stSockAddr)) < 0) {
		std::cout << "Connection failed" << std::endl;	system("pause");
		return 1;
		
	}*/
	int read_size;
	for (;;)
	{
		int i32ConnectFD = accept(i32SocketFD, 0, 0);

		if (i32ConnectFD < 0) {
			perror("Ошибка: принятия");system("pause");
			shutdown(i32SocketFD, 1);
			exit(EXIT_FAILURE);
		}
		
		
	
			send(i32ConnectFD, repl, 11, 0);
		/*read_size = recv(i32ConnectFD, "Hello,pidr", 10, 0);
		
		if (read_size == 0) {
			std::cout << "Client disconnected" << std::endl;

		}
		else if (read_size == -1) {
			std::cout << "recv failed" << std::endl;

		}*/
	}
	system("pause");
	return 0;
}