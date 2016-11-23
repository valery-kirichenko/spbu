#include <winsock.h>
#include <iostream>

#define endl endl; system("pause")
#pragma comment (lib, "Ws2_32.lib")

using namespace std;

int main(){
	WSADATA wsaData;

	if(FAILED(WSAStartup(MAKEWORD(1, 1), &wsaData))){
		cout << "Wsa failed setup" << endl;
		return 1;
	}else cout << "Wsa has set up\n";

	SOCKET s;
	if(INVALID_SOCKET == (s = socket(AF_INET, SOCK_STREAM, 0))){
		cout << "Error socket creation" << endl;
		return 1;
	}else cout << "Socked created\n";

	sockaddr_in SOCKADDR;

	SOCKADDR.sin_family = AF_INET;
	SOCKADDR.sin_addr.S_un.S_addr = inet_addr ("127.0.0.1"); 
	SOCKADDR.sin_port = htons(7878);

	if(bind(s, (sockaddr *) &SOCKADDR, sizeof (SOCKADDR))){
		cout << "Bind error" << endl;
		return 1;
	}

	if (FAILED (listen (s, SOMAXCONN) ) ){ 
		cout << "Listener error" << endl;
		 return 1;
	}

	SOCKET new_sock;
	sockaddr_in new_ca;
	int new_len = sizeof (new_ca);
	if (FAILED (new_sock = accept (s, (sockaddr* ) &new_ca, &new_len) ) ) {
		cout << "Error accepting..." << endl;
		return 1;
	}else cout << "Accepted connection!\n";

	char* buff = "Get out of here\0";
	if(SOCKET_ERROR == (send (new_sock, (char*) buff, strlen(buff), 0) ) ){
		cout << "Error sending data..." << endl;
		return 1;
	}
	
	closesocket(s);
	closesocket(new_sock);
	WSACleanup();

	cout << "Data sent" << endl;
	return 0;
}