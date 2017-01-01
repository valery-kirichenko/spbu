#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <windows.h>
#include <thread>
#pragma comment (lib, "Ws2_32.lib")

class ROTException
{
public:
	ROTException() :
		m_pMessage("") {}
	virtual ~ROTException() {}
	ROTException(const char *pMessage) :
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

const int  MAX_MESSAGE_SIZE = 1024;

struct MyProto {
	std::string sendername;
	std::string gettername;
	std::string message;

	MyProto(char* s) {
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
		std::cout << "From: " << sendername << "\tTo: " << gettername << "\tMessage: " << message << std::endl;
	}
	MyProto(std::string sendn, std::string getn, std::string msg) :sendername(sendn), gettername(getn), message(msg) {}
private:
	void writeStoC(const std::string& s, char* c, int& start, bool needDel = true) {
		for (int i = 0; i < s.size(); i++)
			c[start + i] = s[i];
		start += s.size();
		if (needDel)
			c[start++] = ' ';
	}
	void writeCtoS(char* c, std::string& s, int& start) {
		while (c[start] != 0 && c[start] != ' ')
			s += c[start++];
		start++;
	}
};

struct Clt {
	SOCKET sock;
	std::string name;
	Clt(SOCKET sock, std::string name) :sock(sock), name(name) {}
};

class LowServer {
protected:
	const int  DEFAULT_PORT = 4444;
	SOCKET 		listenSocket = INVALID_SOCKET;
	std:: vector <Clt> vc;
	bool shuttedDown = false;

	std::string GetHostDescription(const sockaddr_in &sockAddr)
	{
		std::ostringstream stream;
		stream << inet_ntoa(sockAddr.sin_addr) << ":" << ntohs(sockAddr.sin_port);
		return stream.str();
	}

	void _SetServerSockAddr(sockaddr_in *pSockAddr, int portNumber)
	{
		pSockAddr->sin_family = AF_INET;
		pSockAddr->sin_port = htons(portNumber);
		pSockAddr->sin_addr.S_un.S_addr = INADDR_ANY;
	}

	void _HandleConnection(SOCKET hClientSocket, sockaddr_in sockAddr, Clt c)
	{
		std::cout << "Connected with " << GetHostDescription(sockAddr) << ".\n";
		char tempBuffer[MAX_MESSAGE_SIZE];
		try {
			while (true)
			{
				int retval;
				retval = recv(hClientSocket, tempBuffer, sizeof(tempBuffer), 0);
				if (retval == 0) {
					break;
				}
				else if (shuttedDown)
					break;
				else if (retval == SOCKET_ERROR)
					throw ROTException("socket error while receiving.");
				else
				{
					std::cout << "Sended " << GetHostDescription(sockAddr) << ".\n";
					handleRequest(c, MyProto(tempBuffer));
				}
			}
		}
		catch (ROTException e) {
			std::cerr << e.what();
		}
		closesocket(hClientSocket);
		std::cout << "Connection closed " << GetHostDescription(sockAddr) << "\n";
	}

	bool _RunServer(int portNumber)
	{
		bool		bSuccess = true;
		sockaddr_in	sockAddr = { 0 };

		try
		{
			if ((listenSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
				throw ROTException("could not create socket.");
			_SetServerSockAddr(&sockAddr, portNumber);
			if (bind(listenSocket, reinterpret_cast<sockaddr*>(&sockAddr), sizeof(sockAddr)) != 0)
				throw ROTException("could not bind socket.");
			std::cout << "Adress: " << GetHostDescription(sockAddr) << std::endl;
			if (listen(listenSocket, SOMAXCONN) != 0)
				throw ROTException("could not put socket in listening mode.");


			
			std::vector <std::thread> vt;
			while (true) {
				sockaddr_in clientSockAddr;
				int			clientSockSize = sizeof(clientSockAddr);
				SOCKET hClientSocket = INVALID_SOCKET;
				hClientSocket = accept(listenSocket, (sockaddr*)(&clientSockAddr), &clientSockSize);
				if (shuttedDown)
					break;
				if (hClientSocket == INVALID_SOCKET)
					throw ROTException("accept function failed.");
				Clt cl(hClientSocket, "Vasya" + std::to_string(rand() % 1000));
				vc.push_back(cl);
				vt.push_back(std::thread(&LowServer::_HandleConnection, this, hClientSocket, clientSockAddr, cl));
			}
			for (int i = 0; i < vt.size(); i++)
				vt[i].join();
		}
		catch (ROTException e)
		{
			std::cerr << "\nError: " << e.what() << std::endl;
			bSuccess = false;
		}

		if (listenSocket != INVALID_SOCKET)
			closesocket(listenSocket);

		return bSuccess;
	}

	void _send(SOCKET clientSocket, MyProto mp) {
		char msgtmp[MAX_MESSAGE_SIZE];
		int sz = mp.getBytes(msgtmp);
		try {
			if (send(clientSocket, msgtmp, sz + 5, 0) == SOCKET_ERROR)
				throw ROTException("failed to send data.\n");
		}
		catch (ROTException e) {
			std::cerr << e.what();
		}
	}

	virtual void handleRequest(Clt cl, MyProto mp) {};
};

class Server:LowServer {
public:
	Server() {
	}
	void start() {
		_RunServer(DEFAULT_PORT);
	}
	void stop() {
		shuttedDown = true;
		closesocket(listenSocket);
		for (int i = 0; i < vc.size(); i++) {
			shutdown(vc[i].sock, 1);
			closesocket(vc[i].sock);
		}
	}
	void handleRequest(Clt cl, MyProto mp)override {
		for (int i = 0; i < vc.size(); i++)
			_send(vc[i].sock, mp);
	}
};

int main()
{
	Server s;
	std::thread th(&Server::start, &s);
	std::string cmd;
	while ((std::cin >> cmd), cmd != "exit");
	s.stop();
	th.join();
}