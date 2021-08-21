#include <algorithm>
#include <cctype>
#include <iterator>
#include <iostream>

#include "palindrome.hpp"

bool is_palindrome(const std::string& str) {

	std::string cleaned_str{};
	std::copy_if(str.begin(), str.end(), 
		     std::back_inserter(cleaned_str),
		     [](auto c) { return isalnum(c); });
	std::transform(cleaned_str.begin(), cleaned_str.end(), 
		       cleaned_str.begin(),
                       [](unsigned char c){ return std::tolower(c); });


	return std::equal(cleaned_str.begin(), cleaned_str.begin() + cleaned_str.size()/2, cleaned_str.rbegin()); 
}
