cmake_minimum_required(VERSION 3.10)
project(WIPE_Project)

set(CMAKE_CXX_STANDARD 17)
include_directories(include)

add_executable(WIPE 
    src/main.cpp 
    src/Interface.cpp 
    src/PortScanner.cpp
    src/HashCracker.cpp
    src/NetworkAnalyzer.cpp
    src/IpLookup.cpp
    src/DnsLookup.cpp
    src/PacketSniffer.cpp
    src/WebhookTools.cpp
)

target_link_libraries(WIPE ws2_32)