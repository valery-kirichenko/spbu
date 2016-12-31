#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <ctime>
#pragma comment (lib, "Ws2_32.lib")
using namespace std;

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

void olut(const char* s) {
	for (int i = 0; i < 30; i++)
		cout << s[i];
	cout << endl;
}

struct MyProto {
	string sendername;
	string gettername;
	string message;

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
		cout << "From: " << sendername << "\tTo: " << gettername << "\tMessage: "<< message << endl;
	}
	MyProto(string sendn, string getn, string msg):sendername(sendn), gettername(getn), message(msg){}
private:
	void writeStoC(const string& s, char* c, int& start, bool needDel = true) {
		for (int i = 0; i < s.size(); i++)
			c[start + i] = s[i];
		start += s.size();
		if (needDel)
			c[start++] = ' ';
	}
	void writeCtoS(const char* c, string& s, int& start) {
		while (c[start] != 0 && c[start] != ' ')
			s += c[start++];
		start++;
	}
};

class LowClient {
protected:
	const int  SERVER_PORT = 4444;
	sockaddr_in	sockAddr = { 0 };
	SOCKET 		hSocket = INVALID_SOCKET;
	typedef unsigned long IPNumber;
	
	void _send(MyProto mp) {
		char msgtmp[MAX_MESSAGE_SIZE];
		int sz = mp.getBytes(msgtmp);
		if (send(hSocket, msgtmp, sz + 5, 0) == SOCKET_ERROR)
			throw HRException("failed to send data.");		
	}

	void _FillSockAddr(sockaddr_in *pSockAddr, int portNumber)
	{
		pSockAddr->sin_family = AF_INET;
		pSockAddr->sin_port = htons(portNumber);
		pSockAddr->sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	}
	bool _Authorize()
	{
		char		tempBuffer[MAX_MESSAGE_SIZE];
		bool		bSuccess = true;
		try
		{
			_FillSockAddr(&sockAddr, SERVER_PORT);
			if ((hSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TC)) == INVALID_SOCKET)
				throw HRException("could not create socket.");
			if (connect(hSocket, (sockaddr*)(&sockAddr), sizeof(sockAddr)) != 0)
				throw HRException("could not connect.");

		}
		catch (HRException e)
		{
			cerr << "\nError: " << e.what() << endl;
			bSuccess = false;
		}
		return bSuccess;
	}
	~LowClient() {
		if (hSocket != INVALID_SOCKET)
			closesocket(hSocket);
	}
};

class Client: LowClient {
public:
	Client() {
		_Authorize();
	}
	void send(MyProto mp) {
		_send(mp);
	}
private:
};

int main()
{
	srand(time(NULL));
	Client client;
	string a, b, c;
	while ((cin >> a >> b >> c), a != "exit")
		client.send(MyProto(a, b, c));
}