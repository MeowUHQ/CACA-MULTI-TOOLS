#include "Interface.hpp"
#include <iostream>
#include <string>

const std::string RESET   = "\033[0m";
const std::string MAGENTA = "\033[95m";
const std::string GRAY    = "\033[90m";
const std::string WHITE   = "\033[97m";

void printMenu() {

    std::cout << MAGENTA << "\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
    std::cout << "┃ " << GRAY << "        MEOW TOOL        " << MAGENTA << "┃" << GRAY << "      Version 1.0        " << MAGENTA << "┃" << GRAY << "        By Meow          " << MAGENTA << "┃" << std::endl;
    std::cout << "┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╋━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫" << std::endl;
    

    std::cout << "┃ " << MAGENTA << "[" << WHITE << "1" << MAGENTA << "] " << GRAY << "Port Scanner    " << MAGENTA << "┃ " 
              << MAGENTA << "[" << WHITE << "4" << MAGENTA << "] " << GRAY << "IP Lookup               " << MAGENTA << "┃ " 
              << MAGENTA << "[" << WHITE << "7" << MAGENTA << "] " << GRAY << "Webhook Tools           " << MAGENTA << "┃" << std::endl;
    

    std::cout << "┃ " << MAGENTA << "[" << WHITE << "2" << MAGENTA << "] " << GRAY << "Hash Cracker    " << MAGENTA << "┃ " 
              << MAGENTA << "[" << WHITE << "5" << MAGENTA << "] " << GRAY << "DNS Enumerator          " << MAGENTA << "┃ " 
              << MAGENTA << "[" << WHITE << "8" << MAGENTA << "] " << GRAY << "Soon..          " << MAGENTA << "┃" << std::endl;
    

    std::cout << "┃ " << MAGENTA << "[" << WHITE << "3" << MAGENTA << "] " << GRAY << "Network Analyzer" << MAGENTA << "┃ " 
              << MAGENTA << "[" << WHITE << "6" << MAGENTA << "] " << GRAY << "Packet Sniffer          " << MAGENTA << "┃ " 
              << MAGENTA << "[" << WHITE << "0" << MAGENTA << "] " << GRAY << "Exit Tool               " << MAGENTA << "┃" << std::endl;
    
    std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << std::endl;
    std::cout << WHITE << " Selection > " << RESET;
}