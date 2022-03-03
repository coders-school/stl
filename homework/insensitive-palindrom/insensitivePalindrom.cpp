#include "insensitivePalindrom.hpp"

bool is_palindrome(std::string s){
    auto op = [](std::string r, unsigned char c){
        c = std::tolower(c);
        std::isalnum(c) ? r += c : r;
        return r;
    };
    s = std::accumulate(s.begin(), s.end(), std::string{}, op);

    return std::equal(s.begin(),s.end(), s.rbegin());
}