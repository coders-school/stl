#include "isPalindrome.hpp"

#include <algorithm>
#include <cctype>

bool is_palindrome(std::string testedString) {
    testedString.erase(std::remove_if(testedString.begin(),
                                      testedString.end(),
                                      [](unsigned char c) {
                                          return !std::isalpha(c);
                                      }));

    std::transform(testedString.begin(),
                   testedString.end(),
                   testedString.begin(),
                   [](unsigned char c) {
                       return std::tolower(c);
                   });

    return equal(testedString.begin(),
                 testedString.begin() + testedString.size() / 2,
                 testedString.rbegin());
}

int main() {
    return 0;
}
