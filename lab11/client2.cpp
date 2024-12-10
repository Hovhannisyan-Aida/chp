#include <iostream>
#include <winsock2.h>

#pragma comment(lib, "Ws2_32.lib")

#define PORT 54000
#define BUFFER_SIZE 1024

using namespace std;

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "WSAStartup failed.\n";
        return 1;
    }

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        cerr << "Socket creation failed.\n";
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cerr << "Bind failed.\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        cerr << "Listen failed.\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }
    cout << "Server is listening on port " << PORT << "...\n";

    sockaddr_in clientAddr;
    int clientSize = sizeof(clientAddr);
    SOCKET clientSocket = accept(serverSocket, (sockaddr*)&clientAddr, &clientSize);
    if (clientSocket == INVALID_SOCKET) {
        cerr << "Accept failed.\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    cout << "Client connected.\n";

    char buffer[BUFFER_SIZE];
    int bytesReceived;
    do {
        ZeroMemory(buffer, BUFFER_SIZE);
        bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
        if (bytesReceived > 0) {
            cout << "Client: " << string(buffer, 0, bytesReceived) << endl;
        }
    } while (bytesReceived > 0);

    closesocket(clientSocket);
    closesocket(serverSocket);
    WSACleanup();
    return 0;
}