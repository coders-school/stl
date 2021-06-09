#include "vowel.hpp"

#include <algorithm>
#include <regex>

void removeVowels(std::vector<std::string>& strings) {
    std::regex vowels("a|e|i|o|u|y|A|E|I|O|U|Y");
    std::for_each(strings.begin(), strings.end(),
                  [&vowels](std::string& str) {
                      str = std::regex_replace(str, vowels, "");
                  });
}
