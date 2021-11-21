#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

template <typename T>
void printVector(const std::vector<T>& collection) {
	    for (const auto& element : collection) {
		            std::cout << element << '\n';
			        }
	        std::cout << '\n';
}
void removeVowels(std::vector<std::string>& words) {
	char vowels [] = {"aeiouyAEIOUY"};
	for(auto& word : words) {
		for(const auto& mark : vowels) {
		  word.erase(std::remove(word.begin(), word.end(), mark), word.end());		
		}
	}
}

int main() {
   std::vector<std::string> words = {
            "Somebody once told me the world is gonna roll me",
            "I ain't the sharpest tool in the shed",
            "She was looking kind of dumb with her finger and her thumb",
            "In the shape of an L on her forehead"
};
    printVector(words);
    removeVowels(words);
    printVector(words);

    return 0;
}
