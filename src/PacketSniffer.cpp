#include "PacketSniffer.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

void PacketSniffer::run() {
    std::string ROSE = "\033[95m";
    std::string BLANC = "\033[97m";
    std::string GRIS = "\033[90m";
    std::string RESET = "\033[0m";

    std::cout << GRIS << "Packet Sniffer n'est pas encore au point, Veuillez attendre la prochaine version." << RESET << std::endl;

    std::cout << "\n" << ROSE << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
    std::cout << "┃            MEOW REAL-TIME SNIFFER              ┃" << std::endl;
    std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << RESET << std::endl;

    std::cout << GRIS << "[*] Reset des ressources systeme..." << RESET << std::endl;
    system("pktmon stop >NUL 2>&1");
    system("pktmon unload >NUL 2>&1");
    system("pktmon filter remove >NUL 2>&1");

    std::cout << ROSE << "[*] Sniffing en cours... (Ctrl+C pour arreter)" << RESET << std::endl;
    std::cout << BLANC << "----------------------------------------------------------------" << RESET << std::endl;

    std::string cmd = "pktmon start -m real-time";
    
    std::cout << BLANC;
    int res = system(cmd.c_str());
    std::cout << RESET;

    if (res != 0) {
        std::cout << ROSE << "\n[!]" << BLANC << " Erreur fatale : Relancez votre terminal en ADMIN." << std::endl;
        std::cout << GRIS << "Si l'erreur persiste, tapez 'pktmon unload' manuellement dans un CMD admin." << RESET << std::endl;
    }

    system("pktmon stop >NUL 2>&1");

}
