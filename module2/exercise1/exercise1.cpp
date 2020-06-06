#include <iostream>
#include <string>
#include <vector>

void remove_vovwel(std::vector<std::string>& vec) {
  static const char vowels[] {"AEIOUYaeiouy"};
  for (auto& str : vec) {
    size_t pos = str.find_first_of(vowels, 0);
    while (pos != std::string::npos) {
      str.erase(pos, 1);
      pos = str.find_first_of(vowels, pos);
    }
  }
}
