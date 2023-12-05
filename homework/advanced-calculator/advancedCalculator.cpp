#include <algorithm>
#include <cmath>
#include <functional>
#include <limits>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

#include "advancedCalculator.hpp"

double add(double x, double y) {
    return x + y;
}

double sub(double x, double y) {
    return x - y;
}

double mul(double x, double y) {
    return x * y;
}

double my_div(double x, double y) {
    return x / y;
}

double my_mod(double x, double y) {
    return std::fmod(x, y);
}

double fac(double x, double y) {
    auto res = std::tgamma(std::fabs(x) + 1);
    if (x < 0)
        res = -res;
    return res;
}

double my_pow(double x, double y) {
    return std::pow(x, y);
}

double nth_root(double x, double y) {
    return std::pow(x, (1 / y));
}

bool checkOperator(const char& op) {
    std::unordered_set<char> ops{'+', '*', '/', '-', '%', '!', '^', '$'};
    auto it = ops.find(op);

    if (it == ops.end())
        return false;
    return true;
}

ErrorCode isValidCharacter(const std::string& input) {
    auto valid = std::any_of(input.begin(), input.end(), [](const auto& c) {
        return ((c > '9' || c < '0') && c != '.' && c != ',' && c != ' ' && !checkOperator(c));
    });

    if (valid)
        return ErrorCode::BadCharacter;
    return ErrorCode::OK;
}

ErrorCode isMathDomain(const std::string& input) {
    std::istringstream iss(input);
    char op;
    double value1{std::numeric_limits<double>::min()};
    double value2{std::numeric_limits<double>::min()};
    iss >> value1 >> op >> value2;

    if (op == '/' && value2 == 0.0)
        return ErrorCode::DivideBy0;
    if (op == '%' && (value2 > -1 && value2 < 1))
        return ErrorCode::ModuleOfNonIntegerValue;

    if (op == '$' && value1 < 0)
        return ErrorCode::SqrtOfNegativeNumber;

    return ErrorCode::OK;
}

ErrorCode isValidExpression(const std::string& input) {
    if (input.at(0) == '+')
        return ErrorCode::BadFormat;

    std::istringstream iss(input);
    char op;
    double value1{std::numeric_limits<double>::min()};
    double value2{std::numeric_limits<double>::min()};

    bool isRead{iss >> value1 >> op >> value2};

    if (op == '!' && value2 != std::numeric_limits<double>::min())
        return ErrorCode::BadFormat;

    if (op == '!' && value2 == std::numeric_limits<double>::min())
        return ErrorCode::OK;

    if (isRead) {
        if ((iss.eof() || std::isspace(iss.peek())) && (checkOperator(op)) && iss.rdbuf()->in_avail() == 0) {
            return ErrorCode::OK;
        } else
            return ErrorCode::BadFormat;
    }

    return ErrorCode::BadFormat;
}

double returnValue(double x, char op, double y) {
    std::unordered_map<char, std::function<double(double, double)>> operations{
        {'+', add},
        {'-', sub},
        {'*', mul},
        {'/', my_div},
        {'%', my_mod},
        {'!', fac},
        {'^', my_pow},
        {'$', nth_root},
    };
    return operations.at(op)(x, y);
}

ErrorCode process(std::string input, double* out) {
    if (input.empty())
        return ErrorCode::BadFormat;

    auto valid = isValidCharacter(input);
    if (valid != ErrorCode::OK)
        return valid;

    valid = isValidExpression(input);
    if (valid != ErrorCode::OK)
        return valid;

    valid = isMathDomain(input);
    if (valid != ErrorCode::OK)
        return valid;

    std::istringstream iss{input};
    double x{std::numeric_limits<double>::min()};
    double y{std::numeric_limits<double>::min()};
    char op;
    iss >> x >> op >> y;

    *out = returnValue(x, op, y);

    return ErrorCode::OK;
}
