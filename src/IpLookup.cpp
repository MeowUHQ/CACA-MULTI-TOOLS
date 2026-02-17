#include "IpLookup.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

void IpLookup::run() {
    std::string ip;
    std::string ROSE = "\033[95m";
    std::string BLANC = "\033[97m";
    std::string GRIS = "\033[90m";
    std::string RESET = "\033[0m";

    std::cout << "\n" << ROSE << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
    std::cout << "┃            MEOW ADVANCED IP LOOKUP             ┃" << std::endl;
    std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << RESET << std::endl;
    
    std::cout << BLANC << " Entrez l'adresse IP cible : " << ROSE;
    std::cin >> ip;

    std::cout << "\n" << GRIS << "[*] Extraction des donnees profondes..." << RESET << "\n" << std::endl;

    std::string fields = "status,country,regionName,city,zip,lat,lon,timezone,isp,org,as,proxy,query";
    std::string cmd = "curl -s \"http://ip-api.com/line/" + ip + "?fields=" + fields + "\"";

    std::cout << ROSE << "━━━━━━━━━━━━━━━━━━━━ RESULTATS ━━━━━━━━━━━━━━━━━━━━" << BLANC << std::endl;

    int result = system(cmd.c_str());
    
    std::cout << ROSE << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << RESET << std::endl;

    if (result != 0) {
        std::cout << ROSE << "[!]" << BLANC << " Erreur : Connexion impossible ou 'curl' absent." << std::endl;
    }

    std::cout << GRIS << "\n[i] Ordre des donnees : Statut, Pays, Region, Ville, CP, Lat, Lon, TZ, ISP, Org, AS, VPN?, IP" << RESET << std::endl;
    std::cout << ROSE << "\n[V] Recherche terminee." << RESET << std::endl;
}