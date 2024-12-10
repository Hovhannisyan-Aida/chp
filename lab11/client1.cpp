#include <iostream>
#include <winsock2.h>
#include <string>

#pragma comment(lib, "Ws2_32.lib")

#define PORT 54000
#define SERVER_IP "127.0.0.1"
#define BUFFER_SIZE 1024

using namespace std;

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "WSAStartup failed.\n";
        return 1;
    }

    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        cerr << "Socket creation failed.\n";
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr);

    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cerr << "Connection failed.\n";
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }
    cout << "Connected to the server.\n";

    string message;
    do {
        cout << "Enter message (type 'exit' to quit): ";
        getline(cin, message);
        if (message != "exit") {
            send(clientSocket, message.c_str(), message.size() + 1, 0);
        }
    } while (message != "exit");

    closesocket(clientSocket);
    WSACleanup();
    return 0;
}