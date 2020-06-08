#include "vowel.hpp"
#include <array>
#include <algorithm>

void removeVowels(std::vector<std::string> &vec) {
  std::array<char, 12>
      a{ 'a','e','i','o','u','y','A','E','I','O','U','Y' };
  std::sort(a.begin(), a.end());
  const auto predicate = [&a](const char letter) -> bool {
      return std::binary_search(a.cbegin(), a.cend(), letter);
  };

  for (auto& it: vec) {
    it.erase(std::remove_if(it.begin(), it.end(), predicate), it.end());
  }
}
