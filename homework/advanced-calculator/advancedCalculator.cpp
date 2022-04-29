#include "advancedCalculator.hpp"

ErrorCode process(std::string input, double* out) {
    ErrorCode checkResult = checkFormat(input);
    if(checkResult != ErrorCode::OK) {return checkResult;}

    input.erase(std::remove_if(input.begin(), input.end(), isspace), input.end());

    auto mathOperator = detectOperator(input);
    auto lhs = getLhs(input, mathOperator.first);
    double rhs; 
    if(mathOperator.second != Operations::Factor) {
        rhs = getRhs(input, mathOperator.first);
    }

    checkResult = checkValues(lhs, rhs, mathOperator.second);
    if(checkResult != ErrorCode::OK) {return checkResult;}

    calculate(lhs, rhs, mathOperator.second, out);
    return ErrorCode::OK;
}
ErrorCode checkFormat(const std::string& str) {
    if(checkForForbiddenCharacters(str)) {return ErrorCode::BadCharacter;}
    if(checkBeforeLhs(str)) {return ErrorCode::BadFormat;}
    if(checkForCommas(str)) {return ErrorCode::BadFormat;}
    if(checkForMultipleOperators(str)) {return ErrorCode::BadFormat;}
    if(checkForAdjacentOperands(str)) {return ErrorCode::BadFormat;}
    if(checkForTwoOperandsWithUnaryOp(str)) {return ErrorCode::BadFormat;}
    if(checkForMultipleDotSeparators(str)) {return ErrorCode::BadFormat;}
    return ErrorCode::OK;
}
ErrorCode checkValues(const double& lhs, const double& rhs, const Operations& operation) {
    if(operation == Operations::Modulus) {
        if((std::round(lhs) != lhs) || (std::round(rhs) != rhs)) {
            return ErrorCode::ModuleOfNonIntegerValue;
        }
    }
    if(operation == Operations::Divide) {
        if(rhs == 0) {
            return ErrorCode::DivideBy0;
        }
    }
    if(operation == Operations::Root) {
        if(lhs < 0) {
            return ErrorCode::SqrtOfNegativeNumber;
        }
    }
    return ErrorCode::OK;
}
bool checkForMultipleOperators(const std::string& str) {
    auto pos = str.find_first_of("+*/%!^$");
    if(pos == std::string::npos) {return false;}
    pos = str.find_first_of("+*/%!^$", pos+1);
    if(pos != std::string::npos) {return true;}
    auto count = std::count(str.begin(), str.end(), '-');
    if(count > 3) {return true;}
    return false;
}
bool checkBeforeLhs(const std::string& str) {
    auto lhsIt = std::find_if(str.begin(), str.end(), [](const char& c){return std::isdigit(c);});
    size_t lhsIndex = std::distance(str.begin(), lhsIt);
    auto specialIndex = str.find_first_of("+*/%!^$");
    if(specialIndex < lhsIndex) {return true;} else {return false;}
}
bool checkForCommas(const std::string& str) {
    return std::any_of(begin(str),
                       end(str), 
                       [](const char& c){
                           return (c == ',');
                        }
    );
}
bool checkForForbiddenCharacters(const std::string& str) {
    if(str.find_first_of("[]{}<>~`&@?\\|#;=") != std::string::npos) {
        return true;
    }
    return std::any_of(str.begin(), str.end(), [](const char& c){return std::isalpha(c);});
}
bool checkForAdjacentOperands(const std::string& str) {
    size_t pos = 0;
    size_t prevPos = 0;
     
    while(pos != std::string::npos) {
        pos = str.find(' ', pos+1);
        if(pos == std::string::npos) {return false;}
        prevPos = pos-1;
        if(pos >= str.length()-1) {return false;}
        while(str.at(pos+1) == ' ') {
            if(pos+1 == str.length()-1) {
                return false;
            }
            ++pos;
        }
        if((isdigit(str.at(prevPos))) && (isdigit(str.at(pos+1)))) {
            return true;
        }  
    }
    return false;
}
bool checkForTwoOperandsWithUnaryOp(const std::string& str) {
    auto pos = str.find('!');
    if(pos != std::string::npos && pos != str.length()) {
        auto it = str.begin();
        std::advance(it, pos);
        if(std::any_of(it, str.end(), isspace)) {return true;}
    }
    return false;
}
bool checkForMultipleDotSeparators(const std::string& str) { 
    if(str.at(0) == '.') {return true;}
    auto prevPos = 0;
    auto nextPos = 0;
    auto itBegin = str.begin();
    auto itEnd = str.end();
    while(prevPos != std::string::npos && nextPos != std::string::npos) {
        prevPos = str.find('.', nextPos+1);
        if(prevPos == std::string::npos) {return false;}
        nextPos = str.find('.', prevPos+1);
        if(nextPos == std::string::npos) {return false;}
        itBegin = str.begin();
        itEnd = str.begin();
        std::advance(itBegin, prevPos+1);
        std::advance(itEnd, nextPos);
        if(std::all_of(itBegin, itEnd, isdigit)) {return true;}
    }
    return false;
}
std::pair<size_t, Operations> detectOperator(const std::string& str) {
    std::map<char, Operations> operators {
        {'+', Operations::Add},
        {'-', Operations::Substract},
        {'*', Operations::Multiplicate},
        {'/', Operations::Divide},
        {'%', Operations::Modulus},
        {'^', Operations::Exponentiate},
        {'$', Operations::Root},
        {'!', Operations::Factor}
    };

    auto pos = str.find_first_of("+*/%!^$");
    if(pos != std::string::npos) {
        return std::make_pair(pos, operators[str.at(pos)]);
    } else {
        auto pos = str.find('-');
        if(pos != std::string::npos) {
            if(pos == 0) {
                return std::make_pair(str.find('-', pos+1), Operations::Substract);
            } else {
                return std::make_pair(pos, Operations::Substract);
            }
        }
    }
    return std::make_pair(0, Operations::Error);
}
double getLhs(const std::string& str, size_t operatorPos) {
    std::string substring = str.substr(0, operatorPos);
    return std::stod(substring, nullptr);
}
double getRhs(const std::string& str, size_t operatorPos) {
    std::string substring = str.substr(operatorPos+1, str.size()-operatorPos);
    return std::stod(substring, nullptr);
}
void calculate(const double& lhs, const double& rhs, const Operations& operation, double* out) {
    std::map<Operations, std::function<double(double, double)>> arithmeticFunctions {
        {Operations::Add, [](auto lhs, auto rhs){return lhs + rhs;}},
        {Operations::Substract, [](auto lhs, auto rhs){return lhs - rhs;}},
        {Operations::Multiplicate, [](auto lhs, auto rhs){return lhs * rhs;}},
        {Operations::Divide, [](auto lhs, auto rhs){return lhs / rhs;}},
        {Operations::Modulus, [](auto lhs, auto rhs){return static_cast<int>(lhs) % static_cast<int>(rhs);}},
        {Operations::Exponentiate, [](auto lhs, auto rhs){return std::pow(lhs, rhs);}},
        {Operations::Factor, [](auto lhs, auto rhs){return factorial(lhs);}},
        {Operations::Root, [](auto lhs, auto rhs){return std::pow(lhs, 1.0/rhs);}}
    };
    *out = arithmeticFunctions[operation](lhs, rhs);
}
double factorial(const double& value) {
    return (value < 0 ? std::tgamma(-value+ 1) * (-1) : std::tgamma(value + 1));
}