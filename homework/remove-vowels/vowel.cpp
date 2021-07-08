#include "vowel.hpp"
#include <algorithm>
#include <string>
#include <vector>
void removeVowels(std::vector<std::string> &words) {
  const std::string vowels = {"aeiouyAEIOUY"};
  for (auto &w : words) {
    for (auto v : vowels) {
      w.erase(std::remove(w.begin(), w.end(), v), w.end());
    }
  }
};