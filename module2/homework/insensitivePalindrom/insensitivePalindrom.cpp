#include "insensitivePalindrom.hpp"

#include <algorithm>

std::string preparedString(std::string& string) {
    std::transform(string.begin(), string.end(), string.begin(),
                   [](auto& characker) {
                       return tolower(characker);
                   });

    string.erase(std::remove_if(string.begin(), string.end(),
                                [](auto& charackter) {
                                    return (isalpha(charackter) ? false : true);
                                }),
                 string.end());

    return string;
}

bool is_palindrome(std::string string) {
    std::string preparedstring = preparedString(string);

    return std::equal(preparedstring.begin(), preparedstring.begin() + preparedstring.size() / 2, preparedstring.rbegin());
}