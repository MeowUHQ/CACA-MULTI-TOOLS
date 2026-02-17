#include "DnsLookup.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

void DnsLookup::run() {
    std::string domain;
    std::string ROSE = "\033[95m";
    std::string BLANC = "\033[97m";
    std::string GRIS = "\033[90m";
    std::string RESET = "\033[0m";

    std::cout << "\n" << ROSE << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
    std::cout << "┃            MEOW DNS ENUMERATOR                 ┃" << std::endl;
    std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << RESET << std::endl;
    
    std::cout << BLANC << " Entrez le domaine (ex: google.com) : " << ROSE;
    std::cin >> domain;

    std::cout << "\n" << GRIS << "[*] Enumeration des records DNS pour " << domain << "..." << RESET << "\n" << std::endl;

    std::vector<std::pair<std::string, std::string>> records = {
        {"A", "Adresses IPv4"},
        {"AAAA", "Adresses IPv6"},
        {"MX", "Serveurs de Mail"},
        {"NS", "Name Servers (DNS)"},
        {"TXT", "Configurations & Securite (SPF/DMARC)"}
    };

    for (const auto& record : records) {
        std::cout << ROSE << ">> Record [" << record.first << "] - " << record.second << RESET << std::endl;
        std::cout << BLANC;
        
        std::string cmd = "nslookup -type=" + record.first + " " + domain + " 2>NUL | findstr /V \"Server Address Non-authoritative\"";
        system(cmd.c_str());
        
        std::cout << ROSE << "------------------------------------------------" << RESET << std::endl;
    }

    std::cout << ROSE << "\n[V] Enumeration terminee." << RESET << std::endl;
}