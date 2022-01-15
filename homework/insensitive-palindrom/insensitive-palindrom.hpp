#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
bool insensitivePalindrom(std::string s)
{
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] < 'A'  s[i] > 'Z' &&
        s[i] < 'a'  s[i] > 'z')
        {
            s.erase(i, 1);
            i--;
        }
    }

    std::transform(s.begin(), s.end(), s.begin(), ::toupper);

    std::string s1 = s;
    std::reverse(s.begin(), s.end());

    if(s1 == s)
    {
       return true;
    }
    return false;
}