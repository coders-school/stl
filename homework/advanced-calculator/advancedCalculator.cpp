#include "advancedCalculator.hpp"

#include <algorithm>
#include <cctype>

std::map<char, std::function<double(double, double)>> possibilities = {
    { '+', [](const auto& val1, const auto& val2)->double{ return val1 + val2; } },
    { '*', [](const auto& val1, const auto& val2)->double{ return val1 * val2; } },
    { '/', [](const auto& val1, const auto& val2)->double{ return val1 / val2; } },
    { '-', [](const auto& val1, const auto& val2)->double{ return val1 - val2; } },
    { '%', [](const auto& val1, const auto& val2)->double{ return static_cast<int>(val1) % static_cast<int>(val2); } },
    { '!', [](const auto& val1, const auto& val2)->double{ return val1 < 0 ? -std::tgamma(std::abs(val1) + 1) : std::tgamma(val1 + 1); } },
    { '^', [](const auto& val1, const auto& val2)->double{ return std::pow(val1, val2); } },
    { '$', [](const auto& val1, const auto& val2)->double{ return std::pow(val1, 1./val2); } }
};

ErrorCode process(std::string input, double* out) {
    auto itToRemove = std::copy_if(input.begin(), input.end(), input.begin(), [](const auto& ch){return !(std::isspace(ch)); });
    if (itToRemove != input.end()) {
        input.erase(itToRemove, input.end());
    }
    auto symbolIt =  std::adjacent_find(input.begin(), 
                                        input.end(), 
                                        [](const auto& ch1, const auto& ch2){ 
                                            return ((std::isdigit(ch1) && std::ispunct(ch2)) && ch2 != '.');
                                            }) + 1;
    std::string value;
    std::copy(input.begin(), symbolIt, std::back_inserter(value));
    if ( std::find_if(value.begin(), value.end(), [](const auto& ch){ return !std::isdigit(ch) && ch != '.' && ch != '-'; }) != value.end() ) {
        return ErrorCode::BadFormat;
    }
    double val1 = std::stod(value);
    value.clear();
    if (symbolIt + 1 != input.end()) {
        std::copy(symbolIt + 1, input.end(), std::back_inserter(value));
        if ( std::find_if(value.begin(), value.end(), [](const auto& ch){ return !std::isdigit(ch) && ch != '.' && ch != '-'; }) != value.end() ) {
            return ErrorCode::BadFormat;
        }
        double val2 = std::stod(value);
        if (*symbolIt == '/' && val2 == 0) {
            return ErrorCode::DivideBy0;
        }
        if (*symbolIt == '%' && (static_cast<int>(val1) != val1 || static_cast<int>(val2) != val2)) {
            return ErrorCode::ModuleOfNonIntegerValue;
        }
        if (possibilities.find(*symbolIt) == possibilities.end()) {
            return ErrorCode::BadCharacter;
        }
        *out = possibilities[*symbolIt](val1, val2);
        return ErrorCode::OK;
    }
    if (possibilities.find(*symbolIt) == possibilities.end()) {
        return ErrorCode::BadCharacter;
    }
    if (*symbolIt == '&' && val1 < 0) {
        return ErrorCode::SqrtOfNegativeNumber;
    }
    if (symbolIt == input.end()) {
        return ErrorCode::BadFormat;
    }
    *out = possibilities[*symbolIt](val1, 0);
    return ErrorCode::OK;
}