#include <cmath>
#include <iterator>
#include <sstream>

#include "advancedCalculator.hpp"

const std::map<char, std::function<double(double, double)>> calculations {
    {'+', std::plus<>()},
    {'-', std::minus<>()},
    {'*', std::multiplies<>()},
    {'/', std::divides<>()},
    {'%', std::modulus<int>()},
    {'!', [](auto n, auto x) { return n <= 0 ? 1.0 : std::tgamma(n + 1.0 + x - x); }},
    {'^', [](auto base, auto exponent) { return pow(base, exponent); }},
    {'$', [](auto value, auto root) { return pow(value, 1.0 / root); }}
};

bool isFormatBad(const std::vector<std::string>& terms) {
    return ((terms.size() < MAX_TERMS) ||
            (terms.size() > MAX_TERMS + 1) ||
            (terms.at(OPERATOR).length() != 1) ||
            (!std::regex_search(terms.at(OPERATOR), arithmeticOp) &&
                !std::regex_search(terms.at(OPERATOR), factorialOp)) ||
            (!(terms.size() <= MAX_TERMS) &&
                (std::regex_search(terms.at(OPERATOR), factorialOp))) ||
            (terms.front().length() == OPERATOR &&
                std::regex_search(terms.front(), arithmeticOp)) ||
            (terms.back().length() == OPERATOR &&
                std::regex_search(terms.back(), arithmeticOp))
       ) ? true : false;
}

bool areOperandsBad(const std::vector<std::string>& terms,
                    double* lhsOperand, double* rhsOperand) {
    try {
        size_t lhsPosition{};
        size_t rhsPosition{};
        *lhsOperand = std::stod(terms.front(), &lhsPosition);
        if (!std::regex_search(terms.back(), factorialOp)) {
            *rhsOperand = std::stod(terms.back(), &rhsPosition);
        }
        if (lhsPosition != terms.front().length() ||
            (!std::regex_search(terms.back(), factorialOp) &&
                rhsPosition != terms.back().length())
           ) {
            return true;
        }
    } catch (std::exception& err) {
        return true;
    }

    return false;
}

bool isDividedByZero(const std::vector<std::string>& terms,
                     double* rhsOperand) {
    return (terms.at(OPERATOR).front() == '/' ||
            terms.at(OPERATOR).front() == '$' ||    
            terms.at(OPERATOR).front() == '%')
            ? *rhsOperand == 0 : false;
}

bool isRootOfNegativeNumber(const std::vector<std::string>& terms,
                            double* lhsOperand) {
    return (terms.at(OPERATOR).front() == '$')
            ? *lhsOperand < 0 : false;
}

bool isModulusOfNonIntegerValue(const std::vector<std::string>& terms,
                               double* lhsOperand, double* rhsOperand) {
    return (terms.at(OPERATOR).front() == '%')
            ? (!(static_cast<int>(*lhsOperand) == *lhsOperand) ||
               !(static_cast<int>(*rhsOperand) == *rhsOperand))
            : false;
}

ErrorCode process(std::string input, double* out) {
    std::istringstream iss(input);
    std::vector<std::string> terms(std::istream_iterator<std::string>{iss},
                                   std::istream_iterator<std::string>());
    double lhsOperand{};
    double rhsOperand{};

    if (isFormatBad(terms)) {
        return ErrorCode::BadFormat;
    }
    if (areOperandsBad(terms, &lhsOperand, &rhsOperand)) {
        return ErrorCode::BadCharacter;
    }
    if (isDividedByZero(terms, &rhsOperand)) {
        return ErrorCode::DivideBy0;
    }
    if (isRootOfNegativeNumber(terms, &lhsOperand)) {
        return ErrorCode::SqrtOfNegativeNumber;
    }
    if (isModulusOfNonIntegerValue(terms, &lhsOperand, &rhsOperand)) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }

    *out = calculations.at(terms.at(OPERATOR).front())(lhsOperand, rhsOperand);

    return ErrorCode::OK;
}
