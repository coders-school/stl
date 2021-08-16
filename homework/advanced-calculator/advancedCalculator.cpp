#include "advancedCalculator.hpp"

std::map<char, std::function<double(double a, double b)>> MapCommands_{
    {'+', [](auto a, auto b) { return a + b; }},
    {'-', [](auto a, auto b) { return a - b; }},
    {'*', [](auto a, auto b) { return a * b; }},
    {'/', [](auto a, auto b) { return a / b; }},
    {'%', [](auto a, auto b) { return (static_cast<int>(a) % static_cast<int>(b)); }},
    {'^', [](auto a, auto b) { return std::pow(a, b); }},
    {'!', [](auto a, auto b) { return std::tgamma(a + 1); }},
    {'$', [](auto a, auto b) { return pow(a, 1.0 / b); }}};

ErrorCode process(std::string input, double* out) {
    ExpressionParser Expression(input);
    double d;
if (MapCommands_.find(Expression.getOperation()) == MapCommands_.end()) std::cout << Expression.getOperation() << "\n";

    if (MapCommands_.find(Expression.getOperation()) != MapCommands_.end()) {
        try {
            std::stod(Expression.getOperand1());
        } catch (const std::invalid_argument&) {
            *out = 0;
            return ErrorCode::BadFormat;
            throw;
        };

        if (!Expression.getOperand2().empty()){
          try {
            std::stod(Expression.getOperand2());
        } catch (const std::invalid_argument&) {
            *out = 0;
            return ErrorCode::BadFormat;
            throw;
        };
        };

        switch (Expression.getOperation()) {
        case '!': 
        {
             if (!Expression.getOperand2().empty()) {return ErrorCode::BadFormat;};
            if (std::stod(Expression.getOperand1()) < 0) {
                d = -1 * (std::invoke(MapCommands_.find(Expression.getOperation())->second, -(std::stod(Expression.getOperand1())), 0));
            } else
                d = std::invoke(MapCommands_.find(Expression.getOperation())->second, std::stod(Expression.getOperand1()), 0);
            break;
        }
        default: 
        {
            d = std::invoke(MapCommands_.find(Expression.getOperation())->second, std::stod(Expression.getOperand1()), std::stod(Expression.getOperand2()));
            break;
        }
        };

        std::string recheck = Expression.getOperand1();
        if (std::any_of(recheck.begin(), recheck.end(), [](char z) { return !(z == '-' || z == '.') && !isdigit(z); }) || std::count(recheck.begin(), recheck.end(), '.') > 1) {
            *out = 0;
            return ErrorCode::BadFormat;
        };
        recheck = Expression.getOperand2();
        if (std::any_of(recheck.begin(), recheck.end(), [](char z) { return !(z == '-' || z == '.') && !isdigit(z); })) {
            *out = 0;
            return ErrorCode::BadFormat;
        };

        *out = d;
        return ErrorCode::OK;

    } else {
        *out = 0;
        return ErrorCode::BadCharacter;
    };

    return ErrorCode::OK;
}
