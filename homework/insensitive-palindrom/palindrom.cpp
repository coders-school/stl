#include "palindrom.hpp"

bool is_high_letter(char a)
{
    if (a >= 65 && a <= 90)
        return true;
    else
        return false;
}

bool is_low_letter(char a)
{
    if (a >= 97 && a <= 122)
        return true;
    else
        return false;
}

bool isSame(char low, char high)
{
    return high + 32 == low;
}

bool is_letter(char a)
{
    return is_high_letter(a) || is_low_letter(a);
}

bool is_palindrome(std::string str)
{
    auto p = str.size() / 2;
    auto q = str.size() / 2;
    if (str.size() % 2 == 0)
        q++;
    while (p != -1 && q == str.size())
    {
        if (is_letter(str[p]) && is_letter(str[q]))
        {
            if (str[p] != str[q])
            {
                if (is_high_letter(str[p]) && is_low_letter(str[q]))
                {
                    if (!isSame(str[q], str[p]))
                        return false;
                }
                else if (is_high_letter(str[q]) && is_low_letter(str[p]))
                {
                    if (!isSame(str[p], str[q]))
                        return false;
                }
            }
        }
    }

    
    
    return true;
}