#include <algorithm>
#include <cctype>
#include <iostream>

int main()
{
    std::string removeSpecialSigns {"kwwAAaaaAAakkkk"};
    std::string palindrome {"kw%^#$!&#%&*@^%k!" "kak@" "kek" "kwik!!!@"};
    std::copy_if(palindrome.begin(), palindrome.end(), std::back_inserter(removeSpecialSigns), [](char ch){ return std::isalnum(ch);});
    std::cout << removeSpecialSigns << '\n';
    std::transform(removeSpecialSigns.begin(), removeSpecialSigns.end(), removeSpecialSigns.begin(), [](auto& ch){return std::tolower(ch);});
    std::cout << removeSpecialSigns << '\n';
    
}