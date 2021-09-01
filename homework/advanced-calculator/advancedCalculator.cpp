#include "advancedCalculator.hpp"
#include <cctype>
#include <string>

bool is_integer(double i)
{
    return std::floor(i) == i;
}

bool badCharacter(const std::string &string)
{
    return std::any_of(string.begin(), string.end(), [](char chars)
                       { return !isdigit(chars) && !isAllowedChar(chars) && chars != '.' && chars != ' ' && chars != ','; });
}
char checkCommand(const std::string &string)
{   
    auto tmp = 0;
    auto result = std::find_first_of(string.begin() + 1, string.end(), symbols.begin(), symbols.end());
    return tmp = *result;
}

bool isAllowedChar(char operation)
{
    std::string symbolsx = "-+/*%!^$";
    auto it = std::find_if(symbolsx.begin(),
                           symbolsx.end(),
                           [&operation](auto el)
                           {
                               return el == operation;
                           });
    return it != symbolsx.end();
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

double parseFirst (std::string &input, std::string::size_type &str) {
    return std::stod(input, &str);
}

double parseSecond (std::string &input, std::string::size_type &str, char &command) {
    double rhs;
    if (command == '!') {
        return rhs = 0;
    }
    return rhs = std::stod(input.substr(str+1));
}

ErrorCode process(std::string input, double *out)
{
    input.erase(std::remove(begin(input), end(input), ' '), end(input));

    if (badCharacter(input))
    {
        return ErrorCode::BadCharacter;
    }
    if (!badFormat(input))
    {
        return ErrorCode::BadFormat;
    }

    auto command = checkCommand(input);

    std::string::size_type str;
    double lhs = parseFirst(input, str);
    double rhs = parseSecond(input, str, command);

    switch (command) {
        case '+':
            *out = advanced_calculator.find('+')->second(lhs, rhs);
            return ErrorCode::OK;
            break;
        case '-':
            *out = advanced_calculator.find('-')->second(lhs, rhs);
            return ErrorCode::OK;
            break;
        case '*':
            *out = advanced_calculator.find('*')->second(lhs, rhs);
            return ErrorCode::OK;
            break;
        case '/':
            if (lhs == 0 || rhs == 0) {
                return ErrorCode::DivideBy0;
            }
            *out = advanced_calculator.find('/')->second(lhs, rhs);
            return ErrorCode::OK;
            break;
        case '%':
            if (!is_integer(lhs) || !is_integer(rhs)){
                return ErrorCode::ModuleOfNonIntegerValue;
            }
            *out = advanced_calculator.find('%')->second(lhs, rhs);
            return ErrorCode::OK;
            break;
        case '!':
            *out = advanced_calculator.find('!')->second(lhs, rhs);
            return ErrorCode::OK;
            break;
        case '^':
            *out = advanced_calculator.find('^')->second(lhs, rhs);
            return ErrorCode::OK;
            break;
        case '$':
            if (lhs <= 0 || rhs == 0) {
                return ErrorCode::SqrtOfNegativeNumber;
            }
            *out = advanced_calculator.find('$')->second(lhs, rhs);
            std::cout << *out;
            return ErrorCode::OK;
            break;
        default:
            break;
    }
    return ErrorCode::OK;
}
