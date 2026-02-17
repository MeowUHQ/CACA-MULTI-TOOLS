#include "PortScanner.hpp"
#include <iostream>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

void PortScanner::run() {
    std::string ip;
    int startPort, endPort;

    std::cout << "\n\033[95m--- [ PORT SCANNER ] ---\033[0m" << std::endl;
    std::cout << "IP Cible (ex: 127.0.0.1): "; std::cin >> ip;
    std::cout << "Port Debut: "; std::cin >> startPort;
    std::cout << "Port Fin: "; std::cin >> endPort;

    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "[!] Erreur d'initialisation Winsock." << std::endl;
        return;
    }

    std::cout << "\n[i] Scan en cours sur " << ip << "...\n" << std::endl;

    for (int port = startPort; port <= endPort; port++) {
        SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (sock == INVALID_SOCKET) continue;

        DWORD timeout = 200;
        setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

        sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(port);
        inet_pton(AF_INET, ip.c_str(), &addr.sin_addr);

        int result = connect(sock, (struct sockaddr*)&addr, sizeof(addr));
        
        if (result == 0) {
            std::cout << "\033[92m[+] Port " << port << " : OUVERT\033[0m" << std::endl;
        } else {
            std::cout << "\033[91m[-] Port " << port << " : FERME\033[0m" << std::endl;
        }

        closesocket(sock);
    }

    WSACleanup();
    std::cout << "\n\033[95m[V] Scan termine.\033[0m" << std::endl;
}