#include "advancedCalculator.hpp"

std::map<char, std::function<double(double a, double b)>> Wrapper{
    {'+', [](auto lhs, auto rhs){return lhs + rhs;}},
    {'-', [](auto lhs, auto rhs){return lhs - rhs;}},
    {'*', [](auto lhs, auto rhs){return lhs * rhs;}},
    {'/', [](auto lhs, auto rhs){return lhs / rhs;}},
    {'%', [](auto lhs, auto rhs){return static_cast<int>(lhs) % static_cast<int>(rhs);}},
    {'!', [](auto lhs, auto rhs){return std::tgamma(lhs);}},
    {'^', [](auto lhs, auto rhs){return pow(lhs,rhs);}},
    {'$', [](auto lhs, auto rhs){return std::pow(lhs, 1.0 / rhs);}}
};

ErrorCode process(std::string input, double* out)
{
   
    char operation{};
    double a{},b{};

    auto c = input.find_first_of("+-*/%!^$", 1);
    size_t str_size = input.size();

    operation = input[c];

    auto noSpace = std::remove(input.begin(), input.end(), ' ');
    input.erase(noSpace, input.end());


    a = stod(input.substr(0, c));
        c = input[c];
        if (c < str_size - 1) {
            b = stod(input.substr(++c, str_size));
        }
    //
    if (c == '/' && b == 0.0) {
        return ErrorCode::DivideBy0;
    }

    if (c == '$' && a < 0.0) {
        return ErrorCode::SqrtOfNegativeNumber;
    }

    if (operation == '!' && c != str_size - 1) {
        return ErrorCode::BadFormat;
    }

     double iptr{};
    // find module operation on non-integral value
    if (c == '%' && (std::modf(a, &iptr) != 0 || std::modf(b, &iptr) != 0)) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }

    

    a = 3.1;
    b = 0.9;
[]
    *out = Wrapper[operation](static_cast<double>(a), b);
    std::cout<<"\n"<<*out;

    return ErrorCode::OK;
}