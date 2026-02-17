#include "WebhookTools.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

void WebhookTools::run() {
    int choice;
    std::string ROSE = "\033[95m";
    std::string BLANC = "\033[97m";

    std::cout << "\n" << ROSE << "┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
    std::cout << "┃             WIPE WEBHOOK TOOLS                 ┃" << std::endl;
    std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛" << std::endl;
    std::cout << BLANC << " [1] Webhook Spammer\n [2] Webhook Deleter (Permanent)\n\n Selection > ";
    std::cin >> choice;

    if (choice == 1) spammer();
    else if (choice == 2) deleter();
}

void WebhookTools::spammer() {
    std::string url, msg;
    int count;
    std::cout << "\n\033[95mURL Webhook : \033[97m"; std::cin >> url;
    std::cout << "\033[95mMessage : \033[97m"; std::cin.ignore(); std::getline(std::cin, msg);
    std::cout << "\033[95mNombre : \033[97m"; std::cin >> count;

    for(int i = 0; i < count; i++) {
        std::string cmd = "curl -X POST -H \"Content-Type: application/json\" -d \"{\\\"content\\\":\\\"" + msg + "\\\"}\" " + url + " -s >NUL";
        system(cmd.c_str());
        std::cout << "\r\033[97m[+] Envois : " << i + 1 << std::flush;
    }
    std::cout << "\n\033[95m[V] Fini." << std::endl;
}

void WebhookTools::deleter() {
    std::string url;
    std::cout << "\n\033[95mURL du Webhook a supprimer : \033[97m";
    std::cin >> url;

    std::cout << "\033[90m[*] Tentative de suppression...\033[0m" << std::endl;

    std::string cmd = "curl -X DELETE " + url + " -s";
    int res = system(cmd.c_str());

    if (res == 0) {
        std::cout << "\033[92m[+] Webhook supprime avec succes.\033[0m" << std::endl;
    } else {
        std::cout << "\033[91m[!] Erreur lors de la suppression.\033[0m" << std::endl;
    }
}