#pragma once
#include <algorithm>
#include <string>

void str_tolower(std::string& s) {
    std::transform(begin(s), end(s), begin(s),
                   [](unsigned char ch) { return std::tolower(ch); });
}
bool valid_char(unsigned char ch) {
    return !((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}

std::string prepare_string(const std::string& str) {
    std::string retrunStrng = str;
    retrunStrng.erase(std::remove_if(begin(retrunStrng), end(retrunStrng), valid_char), end(retrunStrng));
    str_tolower(retrunStrng);
    return retrunStrng;
}

bool is_palindrome(const std::string& str) {
    std::string tempString = prepare_string(str);
    auto pair = std::mismatch(begin(tempString), end(tempString), rbegin(tempString), rend(tempString));
    return pair.first == end(tempString);
}