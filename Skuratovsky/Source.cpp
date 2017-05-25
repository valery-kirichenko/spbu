#define _CRT_SECURE_NO_WARNINGS
//server
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <winsock2.h>
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
	cout << "Connection established\n";
	std::string str;

	int n;
	char buf[256];

	while ((n = recv(s, buf, sizeof(buf), 0)) > 0)
		str.append(buf, buf + n);

	if (n < 0)
	{
		return 1; // error
	}
	message = "Hey, thx for the info, bye";
	std::cout << "received: " << s << '\n';
	send(s, message, strlen(message), 0);

	closesocket(s);
	WSACleanup();
	system("pause");
	return 0;
	
		








	return 0;
}