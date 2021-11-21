#include "vowels.hpp"

void removeVowels(std::vector<std::string>& words) {
	char vowels [] = {"aeiouyAEIOUY"};
	for(auto& word : words) {
		for(const auto& mark : vowels) {
		  word.erase(std::remove(word.begin(), word.end(), mark), word.end());		
		}
	}
}



