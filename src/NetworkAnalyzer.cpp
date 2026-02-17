#include "NetworkAnalyzer.hpp"
#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>

void NetworkAnalyzer::run() {
    int choice;
    while (true) {
        std::cout << "\n\033[95m┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
        std::cout << "┃            MEOW NETWORK ANALYZER               ┃" << std::endl;
        std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\033[0m" << std::endl;
        std::cout << " [1] Lister les interfaces (IP/Mac)\n [2] Connexions actives (Netstat)\n [3] Scanner le reseau local (ARP)\n [0] Retour au menu principal\n\n Selection > ";
        
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 0) break;

        switch(choice) {
            case 1: listInterfaces(); break;
            case 2: showActiveConnections(); break;
            case 3: localNetworkScan(); break;
            default: std::cout << "\033[91m[-] Option invalide.\033[0m" << std::endl;
        }
        
        std::cout << "\n\033[90mAppuyez sur une touche pour continuer...\033[0m";
        std::cin.ignore(1000, '\n');
        std::cin.get();
    }
}

void NetworkAnalyzer::listInterfaces() {
    std::cout << "\n\033[94m[*] Recuperation des interfaces reseau...\033[0m\n" << std::endl;
    system("ipconfig /all | findstr /R \"Description IPv4 Adresse.Physique\"");
}

void NetworkAnalyzer::showActiveConnections() {
    std::cout << "\n\033[94m[*] Analyse des connexions etablies...\033[0m\n" << std::endl;
    std::cout << "Proto  Adresse locale          Adresse distante        Etat" << std::endl;
    system("netstat -n | findstr ESTABLISHED");
}

void NetworkAnalyzer::localNetworkScan() {
    std::cout << "\n\033[93m[*] Scan ARP (Appareils sur le meme Wi-Fi)...\033[0m" << std::endl;
    
    for(int i=0; i<15; i++) {
        std::cout << "\033[95m#\033[0m" << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(40));
    }
    std::cout << "\n" << std::endl;

    system("arp -a");
}