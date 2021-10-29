#include "vowel.hpp"

std::vector<std::string> removeVowels(std::vector<std::string> &text)
{
    for(auto &t: text)
    {
    for(int i=0;i<t.size();i++)
    {
        if(t[i]=='a' || t[i]=='e' || t[i]== 'i' || t[i]=='u' || t[i]=='y' || t[i]=='o' || t[i]=='A' || t[i]=='E' || t[i]== 'I' || t[i]=='U' || t[i]=='Y' || t[i]=='O'){
            t.erase(i,1);
            i--;
        }
    }
    }
    return text;
}