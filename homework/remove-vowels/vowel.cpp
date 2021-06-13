#include "vowel.hpp"
#include <algorithm>

void removeVowels(std::vector<std::string>& vec){
	for (std::string& str : vec) {
       removeVowelsFromString(str);
    }
}

void removeVowelsFromString(std::string& str){
	std::vector<char> vowels {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
	
	for(const char& vowel : vowels){
		str.erase(remove(str.begin(), str.end(), vowel), str.end());
	}
}