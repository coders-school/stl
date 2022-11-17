#include "vowel.hpp"


void printVector(const std::vector<std::string>& vec) {
    for(auto& n : vec) {
        std::cout << n << '\n';
    }
}

void removeVowels(std::vector<std::string>& vec) {
    std::vector<std::string> n;
    for (auto& n : vec) {
        auto it = std::remove(n.begin(), n.end(),'a');
        n.erase(it, n.end());
    }
    for (auto& n : vec) {
        auto it = std::remove(n.begin(), n.end(),'A');
        n.erase(it, n.end());
    }
    for (auto& n : vec) {
        auto it = std::remove(n.begin(), n.end(),'e');
        n.erase(it, n.end());
    }
    for (auto& n : vec) {
        auto it = std::remove(n.begin(), n.end(),'E');
        n.erase(it, n.end());
    }
    for (auto& n : vec) {
        auto it = std::remove(n.begin(), n.end(),'i');
        n.erase(it, n.end());
    }
    for (auto& n : vec) {
        auto it = std::remove(n.begin(), n.end(),'I');
        n.erase(it, n.end());
    }
    for (auto& n : vec) {
        auto it = std::remove(n.begin(), n.end(),'y');
        n.erase(it, n.end());
    }
    for (auto& n : vec) {
        auto it = std::remove(n.begin(), n.end(),'Y');
        n.erase(it, n.end());
    }
    for (auto& n : vec) {
        auto it = std::remove(n.begin(), n.end(),'o');
        n.erase(it, n.end());
    }
    for (auto& n : vec) {
        auto it = std::remove(n.begin(), n.end(),'O');
        n.erase(it, n.end());
    }
    for (auto& n : vec) {
        auto it = std::remove(n.begin(), n.end(),'u');
        n.erase(it, n.end());
    }
    for (auto& n : vec) {
        auto it = std::remove(n.begin(), n.end(),'U');
        n.erase(it, n.end());
    }
}