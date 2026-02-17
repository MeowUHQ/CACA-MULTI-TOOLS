#ifndef HASHCRACKER_HPP
#define HASHCRACKER_HPP

#include <string>
#include <vector>

namespace HashCracker {
    void run();
    std::string base64_decode(const std::string& in);
    bool dummy_check(std::string target, std::string candidate, int type);
}

#endif