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
	SOCKET s, new_socket;
	struct sockaddr_in client;
	int c;
	char *message;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	client.sin_family = AF_INET;
	client.sin_port = htons(8888);
	s = socket(AF_INET, SOCK_STREAM, 0);
	if (connect(s, (struct sockaddr *)&client, sizeof(client)) < 0)
	{
		cout << WSAGetLastError();
		
	}
	string input;
	cout << "Please input what you want to send...\n";
	cout << "> ";
     cin >> input;
	int n;
	n = send(s, input.data(), input.size(), 0);
	std::string str;


	char buf[256];

	while ((n = recv(s, buf, sizeof(buf), 0)) > 0)
		str.append(buf, buf + n);

	if (n < 0)
	{
		return 1; // error
	}


	std::cout << "received: " << s << '\n';
	closesocket(s);
	WSACleanup();
	system("pause");
	return 0;










	return 0;
}