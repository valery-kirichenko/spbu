// server_chat.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h" 
#include <winsock.h> 
#include <iostream> 
#include <thread> 
#include <Windows.h> 
#include <vector>


#pragma comment(lib,"ws2_32.lib")

#define port 6100


std::vector <int> users;
const int s = 1000;
char repl[s];
void func2(int socket)
{
	for (unsigned int i = 0; i < users.size(); i++)
	{
		std::cout << " Send mes - " << repl << std::endl;
		send(users[i], repl, sizeof(repl), 0);
	}
}
void func(int socket)
{
	while (true) {
		memset(repl, 0, s);
		if (recv(socket, repl, sizeof(repl), 0) > 0)
		{
			std::cout << " Polucheno ot " << socket << "\n"; func2(socket);
		}
		else {
			std::cout << "\nConnection error\n" << std::endl;
			for (unsigned int i = 0; i < users.size(); i++)
				if (users[i] == socket)
					users.erase(users.begin() + i);
			break;
		}
		
		
	}
}


int main()
{
	users.resize(0);
	setlocale(0, "");
	WSADATA wsa;
	sockaddr_in stSockAddr, stSockAddr_Client;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		perror("Failed.");system("pause");
		exit(EXIT_FAILURE);
	}
	int i32SocketFD = socket(AF_INET, SOCK_STREAM, 0);

	if (i32SocketFD == -1) {
		perror("Cannot create a socket, sry(");system("pause");
		exit(EXIT_FAILURE);
	}

	memset(&stSockAddr, 0, sizeof(stSockAddr));

	stSockAddr.sin_family = AF_INET;
	stSockAddr.sin_port = htons(port);
	stSockAddr.sin_addr.s_addr = INADDR_ANY;
	if ((bind(i32SocketFD, (struct sockaddr*) &stSockAddr, sizeof(stSockAddr))) < 0)
	{
		perror("Cannot bind, sry((");
		system("pause");
		shutdown(i32SocketFD, 1);
		exit(EXIT_FAILURE);
	}
	listen(i32SocketFD, 3);
	int i32ConnectFD;int c = sizeof(stSockAddr_Client);
	while (i32ConnectFD = accept(i32SocketFD, (struct sockaddr*)&stSockAddr_Client, &c))
	{
		std::cout << "New connection!\n";
		users.push_back(i32ConnectFD); 
		std::thread thr(func, i32ConnectFD);
		thr.detach();
		if (i32ConnectFD < 0) {
			perror("Cannot accept the connection, sry(((");system("pause");
			shutdown(i32SocketFD, 1);
			exit(EXIT_FAILURE);
		}
	}
	shutdown(i32SocketFD, 1);
	WSACleanup();
	return 0;
}

