#include "vowel.hpp"
#include "algorithm"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

std::string vowels = "aeiouy";

bool ifVowel(char str)
{
    bool success = false;
    size_t found = vowels.find(tolower(str));
    if (found != std::string::npos)
        success = true;
    return success;
}

void printVector(const std::vector<std::string>& collection)
{
    for (const auto& el : collection) {
        std::cout << el << "\n";
    }
}

void removeVowels(std::vector<std::string>& collection)
{
    for (auto& el : collection) {
        el.erase(std::remove_if(el.begin(), el.end(), [&](char a) { return ifVowel(a); }));
    }
}
