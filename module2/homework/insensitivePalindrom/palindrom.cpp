#include "palindrom.h"
#include <algorithm>

bool is_palindrome(std::string sequence){

    std::transform(sequence.begin(), sequence.end(), sequence.begin(), [](auto str){ return std::tolower(str); });
    sequence.erase( (remove_if(sequence.begin(), sequence.end(), [](auto el){ return !isalpha(el); })), sequence.end());
    return std::equal(sequence.begin(), sequence.begin() + sequence.size()/2, sequence.rbegin());
};



