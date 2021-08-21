#include <string>
#include <algorithm>
#include "insensitivePalindrom.hpp"

bool is_palindrome(std::string testString) {
    
    //std::string testString;
    testString.erase(std::remove_if(testString.begin(), testString.end(), isspace), testString.end());
    testString.erase(std::remove_if(testString.begin(),
                                    testString.end(),
                                    [](auto const & c) -> bool {
                                        return !std::isalnum(c);
                                    }),
                                    testString.end()
                                    );
    std::transform(testString.begin(), testString.end(), testString.begin(), [](auto & c){return std::tolower(c);});
    return  std::equal(testString.begin(), testString.end(), testString.rbegin());
}