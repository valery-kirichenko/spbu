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


class Server {
public:
	Server() {
		RunServer(DEFAULT_PORT);
	}

private:
	const int  DEFAULT_PORT = 4444;

	std::string GetHostDescription(const sockaddr_in &sockAddr)
	{
		std::ostringstream stream;
		stream << inet_ntoa(sockAddr.sin_addr) << ":" << ntohs(sockAddr.sin_port);
		return stream.str();
	}

	void SetServerSockAddr(sockaddr_in *pSockAddr, int portNumber)
	{
		pSockAddr->sin_family = AF_INET;
		pSockAddr->sin_port = htons(portNumber);
		pSockAddr->sin_addr.S_un.S_addr = INADDR_ANY;
	}

	void HandleConnection(SOCKET hClientSocket, const sockaddr_in &sockAddr)
	{
		std::cout << "Connected with " << GetHostDescription(sockAddr) << ".\n";

		char tempBuffer[MAX_MESSAGE_SIZE];
		while (true)
		{
			int retval;
			retval = recv(hClientSocket, tempBuffer, sizeof(tempBuffer), 0);
			if (retval == 0)
				break;
			else if (retval == SOCKET_ERROR)
				throw ROTException("socket error while receiving.");
			else
			{
				MyProto mp(tempBuffer);
				mp.out();
				if (send(hClientSocket, tempBuffer, retval, 0) == SOCKET_ERROR)
					throw ROTException("socket error while sending.");
			}
		}
		closesocket(hClientSocket);
		std::cout << "Connection closed.\n";
	}

	bool RunServer(int portNumber)
	{
		SOCKET 		hSocket = INVALID_SOCKET;
		bool		bSuccess = true;
		sockaddr_in	sockAddr = { 0 };

		try
		{
			if ((hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == INVALID_SOCKET)
				throw ROTException("could not create socket.");
			SetServerSockAddr(&sockAddr, portNumber);
			if (bind(hSocket, reinterpret_cast<sockaddr*>(&sockAddr), sizeof(sockAddr)) != 0)
				throw ROTException("could not bind socket.");
			std::cout << "Adress: " << GetHostDescription(sockAddr) << std::endl;
			if (listen(hSocket, SOMAXCONN) != 0)
				throw ROTException("could not put socket in listening mode.");

			sockaddr_in clientSockAddr;
			int			clientSockSize = sizeof(clientSockAddr);
			std::vector <std::thread> vt;
			while (true) {
				SOCKET hClientSocket = INVALID_SOCKET;
				hClientSocket = accept(hSocket, (sockaddr*)(&clientSockAddr), &clientSockSize);

				if (hClientSocket == INVALID_SOCKET)
					throw ROTException("accept function failed.");

				vt.push_back(std::thread(&Server::HandleConnection, this, hClientSocket, std::cref(clientSockAddr)));
			}
			for (int i = 0; i < vt.size(); i++)
				vt[i].join();
		}
		catch (ROTException e)
		{
			std::cerr << "\nError: " << e.what() << std::endl;
			bSuccess = false;
		}

		if (hSocket != INVALID_SOCKET)
			closesocket(hSocket);

		return bSuccess;
	}
};

class A {
public:
	void f() {
		std::thread t(&A::g, this, 5);
		t.join();
	}
	void g(int x) {
		std::cout << x;
	}
};

int main()
{
	//A a;
	//a.f();
	Server s;
}
