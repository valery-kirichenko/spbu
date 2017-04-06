
#define _CRT_SECURE_NO_WARNINGS
//server
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <winsock2.h>
#include <string>
#pragma comment(lib,"ws2_32.lib") 
using namespace std;
int main()
{
	WSADATA wsa;
	SOCKET s, new_socket;
	struct sockaddr_in server;
	int c;
	char *message;
	WSAStartup(MAKEWORD(2, 2), &wsa);
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(8888);
	s = socket(AF_INET, SOCK_STREAM, 0);
	bind(s, (struct sockaddr *)&server, sizeof(server));
	cout<<"Bind done\n";
	listen(s, 3);
    cout<<"Waiting for incoming connections...\n";
	c = sizeof(server);
	accept(s, (struct sockaddr *)&server, &c);
	std::string str;

	int n;
	char buf[256];
	cout << "Connection established\n";
	

	recv(s, buf, sizeof(buf), 0);
	std::cout << "received: " << strchr(buf, 256) << '\n';

	closesocket(s);
	WSACleanup();
	system("pause");
	return 0;
	
		
//client
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <winsock2.h>
#include <string>
#pragma comment(lib,"ws2_32.lib") 
using namespace std;
int main()
{
	WSADATA wsa;
	SOCKET s;
	struct sockaddr_in server;
	int c;
	char *message;
	WSAStartup(MAKEWORD(2, 2), &wsa);
	printf("Initialised.\n");

	//Create a socket
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
	}

	printf("Socket created.\n");


	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(8888);
	string input;
	cout << "Please input what you want to send...\n";
	cout << "> ";
	cin >> input;
	//Connect to remote server
	if (connect(s, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}

	puts("Connected");
	
	send(s, input.data(), input.size(), 0);
	closesocket(s);
	WSACleanup();
	system("pause");
	return 0;
















	return 0;
}
