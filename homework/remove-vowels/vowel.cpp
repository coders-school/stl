#include "vowel.hpp"

void removeVowelsString(std::string& input) {
    auto to_erase = std::remove_if(input.begin(), input.end(), &isVowel);
    input.erase(to_erase, input.end());
  }
  
  bool isVowel(const char p_char) {
      constexpr char vowels[] = {'a', 'e', 'i', 'o', 'u', 'y', 'A', 'E', 'I', 'O', 'U', 'Y'};
      return std::find(std::begin(vowels), std::end(vowels), p_char) != std::end(vowels);
  }
  
  void removeVowels(std::vector<std::string>& inputVect) {
    std::for_each(inputVect.begin(), inputVect.end(), &removeVowelsString);
  }