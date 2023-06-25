#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "algorithm"
#include "palindrone.h"
bool is_palindrome(std::string s) {
    s.erase(std::remove_if(s.begin(), s.end(), [](char c) {
                return !std::isalnum(c);
            }),
            s.end());

    std::transform(s.begin(), s.end(), s.begin(), [](char c) {
        return std::tolower(c);
    });
    return std::equal(s.begin(), s.end(), s.rbegin(), s.rend());
}
std::string test(std::string s) {
    s.erase(std::remove_if(s.begin(), s.end(), [](char c) {
                return !std::isalnum(c);
            }),
            s.end());
    std::transform(s.begin(), s.end(), s.begin(), [](char c) {
        return std::tolower(c);
    });

    return s;
}
int main() {
    bool temp = is_palindrome("Eva, can I see bees in a cave?");
    std::cout << std::boolalpha << temp;
    std::cout << test("Eva, can I see bees in a cave?");

    return 0;
}
