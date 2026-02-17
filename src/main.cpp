#include <iostream>
#include <windows.h>
#include <string>

#include "Interface.hpp"
#include "PortScanner.hpp"
#include "HashCracker.hpp"
#include "NetworkAnalyzer.hpp"
#include "IpLookup.hpp"
#include "DnsLookup.hpp"
#include "PacketSniffer.hpp"
#include "WebhookTools.hpp"

void setupTerminal() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
    
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
}

int main() {
    setupTerminal();
    int choice = -1;

    while (true) {
        system("cls");
        printMenu();

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                PortScanner::run();
                break;
            case 2:
                HashCracker::run();
                break;
            case 3:
                NetworkAnalyzer::run();
                break;
            case 4:
                IpLookup::run();
                break;
            case 5:
                DnsLookup::run();
                break;
            case 6:
                PacketSniffer::run();
                break;
            case 7:
                WebhookTools::run();
                break;
            case 0:
                std::cout << "\n\033[95m[MEOW]\033[0m Fermeture en cours..." << std::endl;
                Sleep(1000);
                return 0;
            default:
                std::cout << "\n\033[91m[X]\033[0m Option invalide." << std::endl;
                break;
        }

        std::cout << "\n\033[90mAppuyez sur Entree pour continuer...\033[0m";
        std::cin.ignore(1000, '\n');
        std::cin.get();
    }

    return 0;
}