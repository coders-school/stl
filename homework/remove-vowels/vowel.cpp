#include "vowel.hpp"

void removeVowels(std::vector<std::string>& vector)
{
	std::string vowels{ "aAeEiIoOuUyY" };
	for (auto& str : vector) {
		for (const auto& vow : vowels) {
			str.erase(std::remove(str.begin(), str.end(), vow), str.end());
		}
	}
}