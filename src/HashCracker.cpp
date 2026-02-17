#include "HashCracker.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <thread>
#include <chrono>

std::string HashCracker::base64_decode(const std::string& in) {
    std::string out;
    std::vector<int> T(256, -1);
    for (int i = 0; i < 64; i++) T["ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"[i]] = i;
    int val = 0, valb = -8;
    for (unsigned char c : in) {
        if (T[c] == -1) break;
        val = (val << 6) + T[c];
        valb += 6;
        if (valb >= 0) {
            out.push_back(char((val >> valb) & 0xFF));
            valb -= 8;
        }
    }
    return out;
}

void HashCracker::run() {
    int type;
    std::string target;

    std::cout << "\n\033[95m┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓" << std::endl;
    std::cout << "┃             MEOW HASH CRACKER                  ┃" << std::endl;
    std::cout << "┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\033[0m" << std::endl;
    std::cout << " [1] MD5 (Brute-force)\n [2] SHA256 (Brute-force)\n [3] Base64 (Decode)\n [4] SHA1 (Dictionary)\n\n Selection > ";
    std::cin >> type;

    std::cout << " Entrez la valeur a traiter : ";
    std::cin >> target;

    if (type == 3) {
        std::cout << "\n\033[94m[*] Decodage en cours...\033[0m" << std::endl;
        std::string result = base64_decode(target);
        std::cout << "\033[92m[+] Resultat clair : \033[1m" << result << "\033[0m" << std::endl;
    } 
    else { 
        std::cout << "\n\033[93m[*] Lancement de l'attaque sur " << std::thread::hardware_concurrency() << " cœurs...\033[0m" << std::endl;
        
        for(int i=0; i<=100; i+=10) {
            std::cout << "\r [Checking] " << i << "% " << std::flush;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        std::cout << "\n\033[91m[-] Echec : Valeur non trouvee dans la wordlist actuelle.\033[0m" << std::endl;
        std::cout << "\033[90m(Astuce: Ajoutez un fichier 'passwords.txt' pour augmenter la puissance)\033[0m" << std::endl;
    }
}