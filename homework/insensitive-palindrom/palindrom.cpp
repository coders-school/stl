#include "palindrom.hpp"

bool is_palindrome(std::string text)
{
    std::string specialCharacters = "!@#$%^&*(),./?;': <>|\\\"“”’-_—";
    std::string cpText = text;
    std::transform(text.begin(), text.end(), cpText.begin(), [](char a){return std::tolower(a);});
    std::string cleanText;
    std::copy_if(cpText.begin(),
                 cpText.end(), 
                 std::back_inserter(cleanText), 
                 [specialCharacters](char a){return std::none_of(specialCharacters.begin(),
                                                                 specialCharacters.end(),
                                                                 [a](char b){return a == b;});});
    std::cout<<"\n"<< cleanText<<"\n";
    std::string reversedCleanText;
    std::reverse_copy(cleanText.begin(), cleanText.end(),std::back_inserter(reversedCleanText));
    std::cout<<"\n"<< reversedCleanText<<"\n";
    return reversedCleanText == cleanText;
}
