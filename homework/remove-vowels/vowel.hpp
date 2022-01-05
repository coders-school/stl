#ifndef Vowel_HPP
#define Vowel_HPP

#include <string>
#include <vector>

// removes all vowels from a vector of strings
void removeVowels(std::vector<std::string>& texts);

// removes vowels from a single string
void removeVowels(std::string& text);

// checks if a given char is a vowel
bool isVowel(char letter);

#endif   // !Vowel_HPP