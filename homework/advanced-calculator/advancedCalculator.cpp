#include "advancedCalculator.hpp"
#include <cctype>

bool is_integer(double i)
{
    return std::floor(i) == i;
}
bool badCharacter(const std::string &string)
{
    return std::any_of(string.begin(), string.end(), [string](char chars)
                       { return !(isdigit(chars)) && !isAllowedChar(chars) && chars != '.' && chars != ' ' && chars != ','; });
}
char checkCommand(const std::string &string)
{
    auto result = std::find_first_of(string.begin(), string.end(), symbols.begin(), symbols.end());
    return *result;
}

bool isAllowedChar(char operation)
{
    auto it = std::find_if(symbols.begin(),
                           symbols.end(),
                           [&operation](auto el)
                           {
                               return el == operation;
                           });
    return it != symbols.end();
}
bool badFormat(std::string string)
{
    if (*begin(string) == '+')
    {
        return false;
    }
    if (std::count_if(string.begin() + 1, string.end(), [](char c) { return isAllowedChar(c);}) > 1)
    {
        return false;
    }
    if (std::count(begin(string), end(string), ',') > 0)
    {
        return false;
    }
    if (std::count(begin(string), end(string), '-') > 3)
    {
        return false;
    }
    if (std::count(begin(string), end(string), '.') > 2)
    {
        return false;
    }
    if (checkCommand(string) == '!')
    {
        auto it = std::find(string.begin(), string.end(), '!');
        if (it + 1 != string.end())
        {
            return false;
        }
    }
    return true;
}

ErrorCode process(const std::string &input, double *out)
{
    // input.erase(std::remove(begin(input), end(input), ' '), end(input));

    if (badCharacter(input))
    {
        std::cout << "Bad Character\n";
        return ErrorCode::BadCharacter;
    }
    if (badFormat(input))
    {
        std::cout << "Bad Format\n";
        return ErrorCode::BadFormat;
    }

    std::cout << "OK" << '\n';
    return ErrorCode::OK;
}
