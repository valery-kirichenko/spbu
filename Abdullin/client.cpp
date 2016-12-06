// client.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
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
	char repl[11];
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		perror("Failed.");system("pause");
		return EXIT_FAILURE;
	}
	int i32SocketFD = socket(AF_INET, SOCK_STREAM, 0);

	if (i32SocketFD == -1) {
		perror("Îøèáêà: íåâîçìîæíî ñîçäàòü ñîêåò");system("pause");
		return EXIT_FAILURE;
	}

	memset(&stSockAddr, 0, sizeof(stSockAddr));

	stSockAddr.sin_family = AF_INET; 
	stSockAddr.sin_port = htons(1100);
	stSockAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if (connect(i32SocketFD, (struct sockaddr*) &stSockAddr, sizeof(stSockAddr)) == -1) {
		perror("Îøèáêà: ñîåäèíåíèÿ");system("pause");
		closesocket(i32SocketFD);
		return EXIT_FAILURE;
	}
	memset(repl, 0, 10);
	while (true) {
		
		if (recv(i32SocketFD, repl, 11, 0) < 0) {
			std::cout << "recv failed" << std::endl;
			break;
		}
		std::cout << "Reply: " << repl << std::endl;
	}
	system("pause");
	closesocket(i32SocketFD);
	return 0;
}	
