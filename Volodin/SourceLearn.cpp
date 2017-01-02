#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <thread>
#include <ctime>
#include <map>
#include <sstream>
#include <winsock.h>
#include "../MyProto.h"
#pragma comment (lib, "Ws2_32.lib")

const int  MAX_MESSAGE_SIZE = 1024;

class HRException
{
public:
	HRException() :
		m_pMessage("") {}
	virtual ~HRException() {}
	HRException(const char *pMessage) :
		m_pMessage(pMessage) {}
	const char * what() { return m_pMessage; }
private:
	const char *m_pMessage;
};

struct {
	struct WSAinit {
		bool ok = false;
		WSADATA wsaData;
		const int  REQ_WINSOCK_VER = 2;
		WSAinit() {
			if (WSAStartup(MAKEWORD(REQ_WINSOCK_VER, 0), &wsaData) == 0)
				if (LOBYTE(wsaData.wVersion) >= REQ_WINSOCK_VER)
					ok = true;
		}
		~WSAinit() { if (ok) WSACleanup(); }
	}t;
}TempWSA;

class LowClient {
public:
	bool connectionWorks() {
		return connected && servWorks;
	}
protected:
	const int  SERVER_PORT = 4444;
	sockaddr_in	sockAddrServ = { 0 };
	SOCKET 		hSocket = INVALID_SOCKET;
	typedef unsigned long IPNumber;
	bool authorized = false;
	bool connected = false;
	bool servWorks = false;
	void _send(protos::MyProto mp) {
		if (!connectionWorks() )
			return;
		char msgtmp[MAX_MESSAGE_SIZE];
		int sz = mp.getBytes(msgtmp);
		try {
			if (send(hSocket, msgtmp, sz + 5, 0) == SOCKET_ERROR)
				throw HRException("failed to send data.");
		}
		catch (HRException e) {
			std::cerr << e.what();
		}

	}
	void _FillSockAddr(sockaddr_in *pSockAddr, int portNumber, const char* cp = "127.0.0.1")
	{
		pSockAddr->sin_family = AF_INET;
		pSockAddr->sin_port = htons(portNumber);
		pSockAddr->sin_addr.S_un.S_addr = inet_addr(cp);
	}
	void _Connect() {
		char		tempBuffer[MAX_MESSAGE_SIZE] = {};
		bool		bSuccess = true;
		_FillSockAddr(&sockAddrServ, SERVER_PORT);
		try {
			if ((hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
				throw HRException("could not create socket.");
			if (connect(hSocket, (sockaddr*)(&sockAddrServ), sizeof(sockAddrServ)) != 0)
				throw HRException("could not connect.");
			connected = true;
			servWorks = true;
		}
		catch (HRException e) {
			std::cerr << e.what();
			return;
		}
	}

	protos::MyProto _request(protos::MyProto mp) {
		if (!connectionWorks())
			return protos::MyProto(false);
		_send(mp);
		char tempBuffer[MAX_MESSAGE_SIZE];
		int retval = recv(hSocket, tempBuffer, sizeof(tempBuffer), 0);
		if (retval == SOCKET_ERROR)
			throw HRException("socket error while receiving.");
		return protos::MyProto(tempBuffer);
	}

	void _startListeningServer() {
		if (!connectionWorks())
			return;
		char tempBuffer[MAX_MESSAGE_SIZE];
		try {
			while (true)
			{
				int retval;
				retval = recv(hSocket, tempBuffer, sizeof(tempBuffer), 0);
				if (retval == 0) {
					std::cout << "Disconnected from server\n";
					servWorks = false;
					break;
				}
				else if (retval == SOCKET_ERROR)
					throw HRException("socket error while receiving.");
				else
					handleReceived(protos::MyProto(tempBuffer));
			}
		}
		catch (HRException e) {
			std::cerr << e.what();
		}
	}

	virtual void handleReceived(protos::MyProto mp) {};

	void _shutdown() {
		if (!connectionWorks())
			return;
		shutdown(hSocket, 1);
	}
	
	~LowClient() {
		if (hSocket != INVALID_SOCKET)
			closesocket(hSocket);
	}
};


class Client: public LowClient {
public:
	Client() {
	}
	void Authorize() {
		_Connect();
		getName();
	}
	void getName() {
		if (!connectionWorks()) {
			std::cout << "Connection is not working\n";
			return;
		}
		if (authorized) {
			std::cout << "You have already authorized\n";
			return;
		}
		std::string name;
		while (true) {
			std::cout << "Choose Login: ";
			std::cin >> name;
			if (name == "Guest")
				break;
			protos::MyProto mp = _request(protos::MyProto(name));
			if (mp.authAnswer) {
				authorized = true;
				break;
			}
		}
		std::cout << "Successful autorization\n";
	}
	void startListeningServer() {
		_startListeningServer();
	}
	void send(protos::MyProto mp) {
		_send(mp);
	}
	void handleReceived(protos::MyProto mp) override {
		mp.out();
	}
	void shutdown() {
		_shutdown();
	}
private:
};

void f() {
	srand((unsigned int)time(NULL));
	Client client;
	client.Authorize();
	std::thread th(&Client::startListeningServer, &client);
	std::string b, c;
	while (client.connectionWorks()) {
		std::cin >> b;
		if (b == "exit")
			break;
		getline(std::cin, c);
		c.clear();
		while (!c.size())
			getline(std::cin, c);
		if (!client.connectionWorks())
			break;
		client.send(protos::MyProto("a", b, c));
	}
	client.shutdown();
	th.join();
}

void gg() {
	std::string b, c;
	while (true) {
		std::cin >> b;
		if (b == "exit")
			break;
		getline(std::cin, c);
		c.clear();
		while (!c.size())
			getline(std::cin, c);
		protos::MyProto mp = protos::MyProto("asdf", b, c);
		char req[1024] = {};
		mp.getBytes(req);
		protos::MyProto pt(req);
		std::cout << pt.message;
	}
}

int main()
{
	//Sleep(10000);
	f();
}