#include "sort.hpp"
#include <algorithm>
#include <deque>
#include <forward_list>
#include <string>

#include <cctype>

std::deque<std::string> lengthSort(std::forward_list<std::string>& words) {
    std::deque<std::string> sortedWords(words.begin(), words.end());

    std::sort(sortedWords.begin(), sortedWords.end(),
              [](const std::string& a, const std::string& b) {
                  if (a.length() != b.length()) {
                      return a.length() < b.length();
                  }

                  for (size_t i = 0; i < a.length(); ++i) {
                      char charA = std::tolower(static_cast<unsigned char>(a[i]));
                      char charB = std::tolower(static_cast<unsigned char>(b[i]));

                      if (charA != charB) {
                          return charA < charB;
                      }
                  }
                  return a < b;  // If all characters are equal, maintain original order (stable sort)
              });

    return sortedWords;
}