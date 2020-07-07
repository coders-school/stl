#include "palindroms.hpp"

#include <iostream>
#include <algorithm>

bool isInRanges(const char c);
bool isInRange(const char c, const int upperBound1, const int upperBound2);
bool insensitiveCapital(const int first, const int second);

bool is_palindrome(std::string word)
{
    bool itCouldBePalindrome;
    auto start_it = word.begin();
    auto end_it = word.end();
    auto iterators = std::make_pair(word.begin(), word.rbegin());
    auto middle = start_it + word.size() / 2;

    do
    {
        itCouldBePalindrome = false;
        iterators = std::mismatch(iterators.first, middle, iterators.second);
        if (iterators.first == middle)
            return true;
        if (!isInRanges(*iterators.first))
        {
            iterators.first++;
            itCouldBePalindrome = true;
        }
        if (!isInRanges(*iterators.second))
        {
            itCouldBePalindrome = true;
            iterators.second++;
        }
        if (insensitiveCapital(*iterators.first, *iterators.second) && isInRanges(*iterators.first) && isInRanges(*iterators.second))
        {

            itCouldBePalindrome = true;
            iterators.first++;
            iterators.second++;
        }

        if (iterators.first >= end_it || iterators.second.base() < start_it)
            if (itCouldBePalindrome)
                return true;
            else
                return false;

    } while (itCouldBePalindrome);
    std::cout << std::string(iterators.first, iterators.second.base());
    return false;
}
bool isInRange(const char c, const uint8_t lowerBound, const uint8_t upperBound2)
{
    const int index = (const int)c;
    if (index >= lowerBound && index <= upperBound2)
        return true;
    else
        return false;
}

///Jesli jest poza kazdym z zakresow to jest poza zakresem
bool isInRanges(const char c)
{
    if (isInRange(c, ASCII_digits_range_start, ASCII_digits_range_end))
        return true;
    if (isInRange(c, ASCII_small_letters_range_start, ASCII_small_letters_range_end))
        return true;
    if (isInRange(c, ASCII_Capital_letters_range_start, ASCII_Capital_letters_range_end))
        return true;
    return false;
}
bool insensitiveCapital(const int first, const int second)
{
    int diffrence = first - second;
    if (diffrence == ASCII_Capital_small_distance || diffrence == - ASCII_Capital_small_distance)
        return true;
    else
        return false;
}
