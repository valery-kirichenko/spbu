#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include "../MyProto.h"

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

struct Clt {
	SOCKET sock;
	std::string name = NULL;
	sockaddr_in addr;
	Clt() {}
	Clt(SOCKET sock, sockaddr_in sockAddr, std::string name) :sock(sock), name(name), addr(sockAddr) {}
};

class LowServer {
protected:
	const int  DEFAULT_PORT = 4444;
	SOCKET 		listenSocket = INVALID_SOCKET;
	std:: map <int, Clt> cliset;
	std::map <std::string, int> clbyname;
	int clientCount = 0;
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

	void _HandleConnection(int clientID)
	{
		std::cout << "Connected with " << GetHostDescription(cliset[clientID].addr) << ".\n";
		char tempBuffer[MAX_MESSAGE_SIZE];
		try {
			while (true)
			{
				int retval;
				retval = recv(cliset[clientID].sock, tempBuffer, sizeof(tempBuffer), 0);
				if (retval == 0) {
					break;
				}
				else if (shuttedDown)
					break;
				else if (retval == SOCKET_ERROR)
					throw ROTException("socket error while receiving.");
				else
				{
					std::cout << "Sended " << GetHostDescription(cliset[clientID].addr) << ".\n";
					handleRequest(clientID, protos::MyProto(tempBuffer));
				}
			}
		}
		catch (ROTException e) {
			std::cerr << e.what();
		}
		
		closesocket(cliset[clientID].sock);
		std::cout << "Connection closed " << GetHostDescription(cliset[clientID].addr) << "\n";
		clbyname.erase(cliset[clientID].name);
		cliset.erase(clientID);
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
				clientCount++;
				std::string name = "$" + std::to_string(clientCount);
				cliset.insert(std::make_pair(clientCount, Clt(hClientSocket, clientSockAddr, name)));
				clbyname[name] = clientCount;
				vt.push_back(std::thread(&LowServer::_HandleConnection, this, clientCount));
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

	void _send(SOCKET clientSocket, protos::MyProto mp) {
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

	virtual void handleRequest(int clientID, protos::MyProto mp) {};
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
		for (auto c = cliset.begin(); c != cliset.end(); ++c) {
			shutdown(c->second.sock, 1);
			closesocket(c->second.sock);
		}
	}
	void handleRequest(int clientID, protos::MyProto mp)override {
		if (mp.type == "Authorize") {
			if (cliset[clientID].name[0] != '$' || clbyname.count(mp.name)) {
				_send(cliset[clientID].sock, protos::MyProto(false));
				return;
			}
			clbyname.erase(cliset[clientID].name);
			clbyname.insert(make_pair(mp.name, clientID));
			cliset[clientID].name = mp.name;
			_send(cliset[clientID].sock, protos::MyProto(true));
		}
		else if (cliset[clientID].name[0] == '$') {
			_send(cliset[clientID].sock, protos::MyProto("Server", cliset[clientID].name, "You are not authorized"));
		}
		else if (mp.type == "Message")
			if (clbyname.count(mp.gettername))
				_send(cliset[clbyname[mp.gettername]].sock, protos::MyProto(cliset[clientID].name, mp.gettername, mp.message));
			else
				_send(cliset[clientID].sock, protos::MyProto("Server", cliset[clientID].name, "There is no such user: " + mp.gettername));
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