// server.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
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
	char repl[11]="Hello,dear";
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		perror("Failed.");system("pause");
		exit(EXIT_FAILURE);
	}
	int i32SocketFD = socket(AF_INET, SOCK_STREAM,0);

	if (i32SocketFD == -1) {
		perror("îøèáêà ïðè ñîçäàíèè ñîêåòà");system("pause");
		exit(EXIT_FAILURE);
	}

	memset(&stSockAddr, 0, sizeof(stSockAddr));

	stSockAddr.sin_family = AF_INET;
	stSockAddr.sin_port = htons(port);
	stSockAddr.sin_addr.s_addr =INADDR_ANY;

	if (bind(i32SocketFD, (struct sockaddr*) &stSockAddr, sizeof(stSockAddr)) == -1) {
		perror("Îøèáêà: ñâÿçûâàíèÿ");system("pause");

		shutdown(i32SocketFD,1); 
		exit(EXIT_FAILURE);
	}
	listen(i32SocketFD, 3);
	
	int read_size;
	for (;;)
	{
		int i32ConnectFD = accept(i32SocketFD, 0, 0);

		if (i32ConnectFD < 0) {
			perror("Îøèáêà: ïðèíÿòèÿ");system("pause");
			shutdown(i32SocketFD, 1);
			exit(EXIT_FAILURE);
		}
		send(i32ConnectFD, repl, 11, 0);
	}
	shutdown(i32SocketFD,1);
	return 0;
}
