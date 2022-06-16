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

std::string::iterator setLastIterator(std::string::iterator it, std::string str)
{
    if(is_letter(*it))
    {
        return it;
    }
    else
    {
        if(it == str.begin())
        {
            return it;
        }
        else
        {
            it--;
            return setLastIterator(it, str);
        }
    }
}

std::string::iterator setBeginIterator(std::string::iterator it, std::string str)
{
    if(is_letter(*it))
    {
        return it;
    }
    else
    {
        if(it == str.end())
        {
            return it;
        }
        else
        {
            it++;
            return setBeginIterator(it, str);
        }
    }
}

bool is_palindrome(std::string str)
{
    auto it_begin = setBeginIterator(str.begin(), str);
    auto it_end = setLastIterator(str.end(), str);

    return true;
}