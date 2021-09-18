#include "palindrome.hpp"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>

std::string clean_string(const std::string& string) {
    std::string cleaned;
    std::copy_if(begin(string),
                 end(string),
                 std::back_inserter(cleaned),
                 [](auto sign) {
                     return ('A' <= sign && sign <= 'Z') || ('a' <= sign && sign <= 'z');
                 });
    std::transform(begin(cleaned),
                   end(cleaned),
                   begin(cleaned),
                   [](auto sign) {
                       return std::tolower(sign);
                   });
    return cleaned;
}

bool is_palindrome(const std::string& string) {
    int length = string.size();
    int middle = length / 2;
    std::string first = string.substr(0, middle);
    std::string second = string.substr(length - middle, length);
    std::reverse(begin(second), end(second));
    return first == second;
}
