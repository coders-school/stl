#include "checkPalindrome.hpp"
#include <cctype>

bool is_palindrom(std::string sentence) {
    sentence.erase(std::remove_if(sentence.begin(),
                                  sentence.end(),
                                  [](auto c) {
                                      return !std::isalpha(c);
                                  }),
                   sentence.end());

    std::transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);
    std::cout << sentence << std::endl;

    return (std::equal(sentence.begin(), sentence.begin() + sentence.size() / 2, sentence.rbegin()));
};