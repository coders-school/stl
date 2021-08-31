#include "advancedCalculator.hpp"
#include <cctype>

bool is_integer (double i)
{
  return std::floor(i) == i;
}
bool badCharacter (const std::string & string)
{
    return std::any_of (string.begin(), string.end(), [string](char chars)
    {
        return !(isdigit(chars));
    });
}
bool badFormat (std::string string)
{
    return true;
}

ErrorCode process (const std::string & input, double* out)
{
    if(badCharacter(input))
    {
        std::cout << "BadCharacter" << '\n';
        return ErrorCode::BadCharacter;
    }
    std::cout << "OK" << '\n';
    return ErrorCode::Ok;
}