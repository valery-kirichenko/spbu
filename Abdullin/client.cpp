// client.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h" 
#include <winsock.h> 
#include <iostream> 
#include <thread> 
#include <Windows.h> 

#pragma comment(lib,"ws2_32.lib")


int main(void) 
{
	setlocale(1, "");
	struct sockaddr_in stSockAddr;
	int i32Res;
	WSADATA wsa;
	char repl[10];
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());system("pause");
		return 1;
	}
	int i32SocketFD = socket(AF_INET, SOCK_STREAM, 0);

	if (i32SocketFD == -1) {
		perror("Ошибка: невозможно создать сокет");
		return EXIT_FAILURE;
	}

	memset(&stSockAddr, 0, sizeof(stSockAddr));

	stSockAddr.sin_family = AF_INET; 
	stSockAddr.sin_port = htons(1100);
	stSockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	

	/*if (i32Res < 0) {
		perror("Ошибка: первый параметр не относится к категории корректных адресов");
		system("pause");

		shutdown(i32SocketFD, 1);
		return EXIT_FAILURE;
	}
	else if (!i32Res) {
		perror("Ошибка: второй параметр не содержит корректного IP-адреса");
		system("pause");

		shutdown(i32SocketFD, 1);
		return EXIT_FAILURE;
	}*/

	if (connect(i32SocketFD, (struct sockaddr*) &stSockAddr, sizeof(stSockAddr)) == -1) {
		perror("Ошибка: соединения");system("pause");
		closesocket(i32SocketFD);
		return EXIT_FAILURE;
	}memset(repl, 0, 10);
	while (true) {
		/*int i32ConnectFD = accept(i32SocketFD, 0, 0);

		if (i32ConnectFD < 0) {
		perror("Ошибка: принятия");system("pause");
		shutdown(i32SocketFD, 1);
		exit(EXIT_FAILURE);
		}

		send(i32ConnectFD,"Hello!",10,10);
		
		std::cout << "Soobshenie - "; std::cin >> mes;
		if (send(i32SocketFD, mes, strlen(mes), 0) < 0) {
			std::cout << "Send failed" << std::endl;
			return 1;
		}	
		*/
		
		if (recv(i32SocketFD, repl, 11, 0) < 0) {
			std::cout << "recv failed" << std::endl;
			break;
		}
		std::cout << "Reply: " << repl << std::endl;
	}
	shutdown(i32SocketFD, 1);
	system("pause");
	closesocket(i32SocketFD);
	return 0;
}	