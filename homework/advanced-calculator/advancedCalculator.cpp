#include "advancedCalculator.hpp"

std::map<const char, std::function<double(double, double)>> calculator{
    {'+', std::plus<double>()},
    {'-', std::minus<double>()},
    {'*', std::multiplies<double>()},
    {'/', std::divides<double>()},
    {'%', std::modulus<int>()},
    {'^', [](const auto a, const auto b) { return std::pow(a, b); }},
    {'$', [](const auto a, const auto b) { return std::pow(a, 1.0 / b); }},
    {'!', [](auto a, [[maybe_unused]] auto b) {
        if (a > 0) {
            return std::tgamma(a + 1);
        }
        else {
            a *= -1;
            return std::tgamma(a + 1) * -1;
        }
    }}
};

void removeSpace(std::string& input) {
    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
}

Data divideInput(std::string& input) {
    std::string str = "+-*/%^$!";
    Data data;
    removeSpace(input);
    auto it = std::find_first_of(input.begin() + 1, input.end(), str.begin(), str.end());
    data.firstValue = input.substr(0, std::distance(input.begin(), it));
    if (it == input.end()) {
        return {};
    }
    data.character = *it;
    if (data.character == '!') {
        data.secondValue = "";
    } else {
        data.secondValue = input.substr(data.firstValue.size() + 1, std::distance(it + 1, input.end()));
    }
    return data;
}

bool isBadNumber(std::string& input) {
    removeSpace(input);
    if (!(input[0] == '-' || isdigit(input[0]))) {
        return true;
    }
    if (std::count(input.begin(), input.end(), '.') > 1) {
        return true;
    }
    if (std::count(input.begin(), input.end(), '-') > 1) {
        return true;
    }
    return false;
}

bool isBadFormat(std::string& input, Data& data) {
    removeSpace(input);
    if (std::count(input.begin(), input.end(), '-') > 3) {
        return true;
    }
    if (std::count(input.begin(), input.end(), '.') > 2) {
        return true;
    }
    if (std::count(input.begin(), input.end(), ',') > 0) {
        return true;
    }
    const std::string str = "+*/%^$!";
    int counter = 0;
    for (const auto & i : str) {
        counter += std::count(input.begin(), input.end(), i);
    }
    if (counter > 1) {
        return true;
    }
    if (isBadNumber(data.firstValue)) {
        return true;
    }
    if (data.character == '!') {
        if (input.size() != data.firstValue.size() + 1) {
            return true;
        }
    } 
    else {
        if (isBadNumber(data.secondValue)) {
            return true;
        }
    }
    return false;
}

bool isGoodCharacter(char operation) {
    std::string str = "+-*/%^$!";
    auto it = std::find_if(str.begin(), str.end(), [&operation](auto el) {
        return el == operation;
    });
    return it != str.end();
}

bool isBadCharacter(std::string& input) {
    return std::any_of(input.begin(), input.end(), [](auto ch) {
        return !isdigit(ch) && !isGoodCharacter(ch) && ch != '.' && ch != ',';
    });
}

double stringToDouble(std::string& input) {
    double number;
    std::stringstream ss(input);
    ss >> number;
    return number;
}

ErrorCode process(std::string input, double* out) {
    Data data = divideInput(input);
    
    if (isBadCharacter(input)) {
        return ErrorCode::BadCharacter;
    }
    if (isBadFormat(input, data)) {
        return ErrorCode::BadFormat;
    }
    
    double firstNumber = stringToDouble(data.firstValue);
    double secondNumber = stringToDouble(data.secondValue);
    
    if (data.character == '/' && secondNumber == 0) {
        return ErrorCode::DivideBy0;
    }
    if (data.character == '%' && (!static_cast<int>(firstNumber) || !static_cast<int>(secondNumber))) {
        return ErrorCode::ModuleOfNonIntegerValue;
    }
    if (data.character == '$' && firstNumber < 0) {
        return ErrorCode::SqrtOfNegativeNumber;
    }
    *out = calculator.at(data.character)(firstNumber, secondNumber);
    return ErrorCode::OK;
}