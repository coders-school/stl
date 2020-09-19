#include "advancedCalculator.hpp"
#include <functional>
#include <iostream>
#include <map>
#include <math.h>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <stdlib.h>

CalculationException::CalculationException(std::string p_msg, ErrorCode errorCode_)
    : logic_error(p_msg), errorCode(errorCode_)
{
}

const char* CalculationException::what() const throw()
{
    std::ostringstream o;
    o << logic_error::what();
    return o.str().c_str();
}

ErrorCode parse(const std::string& input, double& a, double& b, std::string& oper)
{

    if (input.find_first_not_of("0123456789-+*$/^%!., ") != std::string::npos)
        return ErrorCode::BadCharacter;

    std::vector<std::string> result;

    std::regex command("\\s*(-?\\s*[0-9]+*\\.[0-9]+|-?\\s*[0-9]+)\\s*" // match int or double with or w/o minus sign
                       "\\s*([^!])\\s*"                                // match one char except ! and zero or more spaces
                       "\\s*(-?\\s*[0-9]+*\\.[0-9]+|-?\\s*[0-9]+)\\s*");

    std::regex command_factorial("\\s*([-]?[0-9]*\\.[0-9]+|[+-]?[0-9]+)\\s*"
                                 "\\s*(\\!)\\s*");

    std::smatch match_result;

    if (std::regex_match(input, match_result, command) or std::regex_match(input, match_result, command_factorial))
    {
        auto match_iter = match_result.begin();

        for (std::advance(match_iter, 1); match_iter != match_result.end(); advance(match_iter, 1))
        {
            result.push_back(*match_iter);
        }
        for (std::string& str : result)
        {
            str.erase(remove(str.begin(), str.end(), ' '), str.end());
        }

        if (result.size() == 2)
        {
            a = atof(result[0].c_str());
            oper = result[1];
        }

        else if (result.size() == 3)
        {
            a = atof(result[0].c_str());
            oper = result[1];
            b = atof(result[2].c_str());
        }
        return ErrorCode::OK;
    }
    return ErrorCode::BadFormat;
}

ErrorCode process(std::string input, double* out)
{
    double a = 0.0;
    double b = 0.0;
    std::string oper{};
    ErrorCode status = parse(input,a,b,oper);
    if(status != ErrorCode::OK) return status;

    std::map<std::string, std::function<double(double, double)>> operations;

    operations["-"] = [a, b](double a, double b) { return a - b; };
    operations["+"] = [a, b](double a, double b) { return a + b; };
    operations["*"] = [a, b](double a, double b) { return a * b; };
    operations["/"] = [a, b](double a, double b) {
        if (b == 0)
        {
            throw CalculationException("Divide By Zero", ErrorCode::DivideBy0);
            return 0.0;
        }
        return a / b;
    };

    operations["^"] = [a, b](double a, double b) { return pow(a, b); };

    operations["%"] = [a, b](double a, double b) {
        if (((int)a - a) != 0 or (int) b - b != 0)
        {
            throw CalculationException("Module of Non Integer", ErrorCode::ModuleOfNonIntegerValue);
        }

        return (int)a % (int)b;
    };

    operations["$"] = [a, b](double a, double b) {
        if (a < 0)
        {
            throw CalculationException("Sqrt of Negative Number", ErrorCode::SqrtOfNegativeNumber);
            return 0.0;
        }

        return pow(a, 1 / b);
    };

    operations["!"] = [a, b](double a, double b) {
        if (a < 0)
            return 1.0;
        return tgamma(a + 1.0);
    };

    try
    {
        *out = operations.at(oper)(a, b);
    }
    catch (const std::out_of_range& ex)
    {
        return ErrorCode::BadCharacter;
    }
    catch (const CalculationException& ex)
    {
        return ex.errorCode;
    }
    return ErrorCode::OK;
}
