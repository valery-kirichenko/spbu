// chat_client.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h" 
#include <winsock.h> 
#include <iostream> 
#include <thread> 
#include <Windows.h> 
const int s = 1000;
#pragma comment(lib,"ws2_32.lib")
using namespace std;

void func(int i32SocketFD)
{
	char repl[s];
	while (true)
	{
		long c = 0;
		for (long i = 0; i < 1000000; i++)
		{
			c++;
		}
		cout << "Write --- "; cin.getline(repl, s);
		if (send(i32SocketFD, repl, strlen(repl),0) < 0)
		{
			cout << "Fail."; break;
		}
		
	}

}

int main(void)
{
	setlocale(1, "");
	struct sockaddr_in stSockAddr;
	WSADATA wsa;
	char repl[s];
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		perror("Failed.");
		system("pause");
		return EXIT_FAILURE;
	}
	int i32SocketFD = socket(AF_INET, SOCK_STREAM, 0);

	if (i32SocketFD == -1) {
		perror("Cannot create a socket, sry(");system("pause");
		return EXIT_FAILURE;
	}
	thread thr(func, i32SocketFD);
	memset(&stSockAddr, 0, sizeof(stSockAddr));

	stSockAddr.sin_family = AF_INET;
	stSockAddr.sin_port = htons(6100);
	stSockAddr.sin_addr.s_addr = inet_addr("192.168.1.4");

	if (connect(i32SocketFD, (struct sockaddr*) &stSockAddr, sizeof(stSockAddr)) == -1) {
		perror("Cannor create a connection, sry((");system("pause");
		closesocket(i32SocketFD);
		return EXIT_FAILURE;
	}
	cout << "Chat::\n";
	thr.detach();
	while (true) {
		memset(repl, 0, s);
		if (recv(i32SocketFD, repl, 11, 0) < 0) {
			std::cout << "recv failed, sry(((" << endl;
			break;
		}
		if (strlen(repl) < 1)
			continue;
		cout << "Reply: " << repl << endl;
	}
	system("pause");
	closesocket(i32SocketFD);WSACleanup();
	return 0;
}
