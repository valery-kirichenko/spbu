#include <winsock.h>
#include <iostream>
#include <thread>

#include <ostream>

using namespace std;

const int MAX_SIZE = 2048;

void writing_thread(int new_s){
    string message; char msg[MAX_SIZE];

    while(true){
        cout << "You: ";
        getline(cin, message);

        if(message.size() < 1) continue;

        if(SOCKET_ERROR == (send (new_s, message.c_str(), message.size(), 0) ) ){
            cout << "\nError sending data..." << endl;
            break;
        }
    }
}

int main(){
    SOCKET s;
    WSADATA wsaData;

    if(FAILED(WSAStartup(MAKEWORD(1, 1), &wsaData))){
        cout << "Wsa data startup failed: " << WSAGetLastError() << endl;
        return 1;
    }

    if(INVALID_SOCKET == (s = socket(AF_INET, SOCK_STREAM, 0))){
        cout << "Socket creation failed: " << WSAGetLastError() << endl;
        return 1;
    }

    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.S_un.S_addr = INADDR_ANY;
    addr.sin_port = htons(80);

    if(SOCKET_ERROR == (bind(s, (sockaddr*) &addr, sizeof(addr)))){
        cout << "Bind failed: " << WSAGetLastError() << endl;
        return 1;
    }

    if(FAILED(listen(s, SOMAXCONN))){
        cout << "Listener failed: " << WSAGetLastError() << endl;
        return 1;
    }else cout << "Waiting for connection" << endl;

    sockaddr_in new_addr;
    int new_s, new_len = sizeof(new_addr);

    if(FAILED(new_s = accept(s, (sockaddr*) &new_addr, &new_len))){
        cout << "Connection failed: " << WSAGetLastError() << endl;
        return 1;
    }else cout << "Connection set\n" << endl;

    char answer[MAX_SIZE];

    thread mthread(writing_thread, new_s);
    mthread.detach();

    while(true){
        memset(answer, 0, MAX_SIZE);

        if (SOCKET_ERROR == (recv (new_s, answer, MAX_SIZE, 0 ) ) )  {
            cout << "\nError receiving data: " << WSAGetLastError() << endl;
            break;
        }

        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO buff;

        GetConsoleScreenBufferInfo(h, &buff);
        SetConsoleCursorPosition(h, {0, buff.dwCursorPosition.Y});

        cout << "Comrade: " << answer << endl << "You: ";
    }

    closesocket(s);
    WSACleanup();

    return 0;
}
