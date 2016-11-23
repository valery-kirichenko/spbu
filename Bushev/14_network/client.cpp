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

	if (SOCKET_ERROR == ( connect (s, (sockaddr *) &SOCKADDR, sizeof (SOCKADDR) ) ) ){
		cout << "Connection error" << endl;
		return 1;
	}else cout << "Connection set\n";

	int actual_len = 0;
	
	char buff[512];
	if (SOCKET_ERROR == (actual_len = recv (s, (char* ) &buff, 512, 0 ) ) )  {
		cout << "Error recieving data" << endl;
	}else cout << "\nWe got data: \n";

	for(int i = 0; i < actual_len; i++){
		cout << buff[i];
	}

	closesocket(s);
	WSACleanup();

	cout << endl;
	return 0;
}
