#include "insensitive.hpp"

#include <algorithm>
#include <cctype>

bool is_palindrome(const std::string& s) {
    if (s.empty()) {
        return true;
    }

    std::string str{ s };

    str.erase(remove_if(std::begin(str),
                        std::end(str),
                        [](char ch) {
                            return !std::isalpha(ch) &&
                                   !std::isdigit(ch);
                        }),
              str.end());
    std::transform(std::begin(str),
                   std::end(str),
                   std::begin(str),
                   ::tolower);

    return (std::mismatch(str.begin(),
                          str.end(),
                          str.rbegin()))
               .first == str.end();
}
