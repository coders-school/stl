#include <algorithm>
#include <cctype>
#include <iostream>

bool is_palindrome(std::string palindrome)
{
    std::string removeSpecialSigns;
    std::copy_if(palindrome.begin(), palindrome.end(), std::back_inserter(removeSpecialSigns), [](char ch){ return std::isalnum(ch);});
    std::cout << removeSpecialSigns << '\n';
    std::transform(removeSpecialSigns.begin(), removeSpecialSigns.end(), removeSpecialSigns.begin(), [](auto& ch){return std::tolower(ch);});
    std::cout << removeSpecialSigns << '\n';
    return(std::equal(removeSpecialSigns.begin(), removeSpecialSigns.begin() + removeSpecialSigns.size()/2, removeSpecialSigns.rbegin()));

}