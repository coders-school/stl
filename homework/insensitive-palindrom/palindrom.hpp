#pragma once

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>


const std::string charsToRemove = { " “ ” ’ —" };

std::string removeSpecificChars(std::string& str, const std::string& charsToRemove);
bool is_palindrome(const std::string& neo);
