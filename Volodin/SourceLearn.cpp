#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <thread>
#include <ctime>
#include <winsock.h>
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

struct MyProto {
	std::string sendername;
	std::string gettername;
	std::string message;

	MyProto(const char* s) {
		int start = 0;
		writeCtoS(s, sendername, start);
		writeCtoS(s, gettername, start);
		writeCtoS(s, message, start);
	}
	int getBytes(char* req) {
		int res = 0;
		writeStoC(sendername, req, res);
		writeStoC(gettername, req, res);
		writeStoC(message, req, res, false);
		req[res] = 0;
		return res;
	}
	void out() {
		std::cout << "From: " << sendername << "\tTo: " << gettername << "\tMessage: "<< message << std::endl;
	}
	MyProto(std::string sendn, std::string getn, std::string msg):sendername(sendn), gettername(getn), message(msg){}
private:
	void writeStoC(const std::string& s, char* c, int& start, bool needDel = true) {
		for (int i = 0; i < s.size(); i++)
			c[start + i] = s[i];
		start += s.size();
		if (needDel)
			c[start++] = ' ';
	}
	void writeCtoS(const char* c, std::string& s, int& start) {
		while (c[start] != 0 && c[start] != ' ')
			s += c[start++];
		start++;
	}
};

class LowClient {
public:
	bool connectionWorks() {
		return authorized && servWorks;
	}
protected:
	const int  SERVER_PORT = 4444;
	sockaddr_in	sockAddrServ = { 0 };
	SOCKET 		hSocket = INVALID_SOCKET;
	typedef unsigned long IPNumber;
	bool authorized = false;
	bool servWorks = false;
	void _send(MyProto mp) {
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
		char		tempBuffer[MAX_MESSAGE_SIZE];
		bool		bSuccess = true;
		_FillSockAddr(&sockAddrServ, SERVER_PORT);
		try {
			if ((hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
				throw HRException("could not create socket.");
			if (connect(hSocket, (sockaddr*)(&sockAddrServ), sizeof(sockAddrServ)) != 0)
				throw HRException("could not connect.");
			authorized = true;
			servWorks = true;
		}
		catch (HRException e) {
			std::cerr << e.what();
			return;
		}
	}

	void _receive() {
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
					handleReceived(MyProto(tempBuffer));
			}
		}
		catch (HRException e) {
			std::cerr << e.what();
		}
	}

	virtual void handleReceived(MyProto mp) {};

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
	}
	void receive() {
		_receive();
	}
	void send(MyProto mp) {
		_send(mp);
	}
	void handleReceived(MyProto mp) override {
		mp.out();
	}
	void shutdown() {
		_shutdown();
	}
private:
};

void f() {
	srand(time(NULL));
	Client client;
	client.Authorize();
	std::thread th(&Client::receive, &client);
	std::string a, b, c;
	while (client.connectionWorks()) {
		std::cin >> a >> b >> c;
		if (a == "exit")
			break;
		client.send(MyProto(a, b, c));
	}
	client.shutdown();
	th.join();
}


int main()
{
	f();
}