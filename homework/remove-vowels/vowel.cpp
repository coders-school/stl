#include"vowel.hpp"

bool pred(char c)   {
    std::string str = "aAoOeEuUiIyY";
    if(str.find(c)!= std::string::npos) return true;
     return false;
}

void removeVowels(std::vector<std::string>& v)  {
    for(std::string& s:v)  {
        auto it = std::remove_if(s.begin(),s.end(),pred);
        s.erase(it,s.end());
        }
    }