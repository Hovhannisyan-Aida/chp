#include <iostream>
#include <winsock2.h>
#include <thread>
#include <string>

#pragma comment(lib, "Ws2_32.lib")

#define PORT 54000
#define BUFFER_SIZE 1024

void handleClient(SOCKET clientSocket, SOCKET otherClientSocket) {
    char buffer[BUFFER_SIZE];
    while (true) {
        int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
        if (bytesReceived <= 0) {
            std::cerr << "Client disconnected.\n";
            break;
        }
        buffer[bytesReceived] = '\0';
        std::cout << "Received: " << buffer << "\n";

        send(otherClientSocket, buffer, bytesReceived, 0);
    }
    closesocket(clientSocket);
}

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "WSAStartup failed.\n";
        return 1;
    }

    SOCKET serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Socket creation failed.\n";
        WSACleanup();
        return 1;
    }

    sockaddr_in serverAddr{};
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 

    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Bind failed.\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        std::cerr << "Listen failed.\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    std::cout << "Waiting for clients to connect...\n";

    SOCKET client1 = accept(serverSocket, nullptr, nullptr);
    if (client1 == INVALID_SOCKET) {
        std::cerr << "Accept failed.\n";
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }
    std::cout << "Client 1 connected.\n";

    SOCKET client2 = accept(serverSocket, nullptr, nullptr);
    if (client2 == INVALID_SOCKET) {
        std::cerr << "Accept failed.\n";
        closesocket(client1);
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }
    std::cout << "Client 2 connected.\n";

    std::thread client1Thread(handleClient, client1, client2);
    std::thread client2Thread(handleClient, client2, client1);

    client1Thread.join();
    client2Thread.join();

    closesocket(serverSocket);
    WSACleanup();
    return 0;
}
