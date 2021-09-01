#include "advancedCalculator.hpp"

bool isInt(double num) {
    return std::floor(num) == num;
}
std::vector<double> getNumsFromInput(std::string input, int numOfMinuses) {
    std::vector<double> numsToCalculate;
    std::string numS;

    for (int i = 0; i < input.length(); i++) {
        while (isnumber(input[i])) {
            if (i != 0) {
                if (input[i - 1] == '-') {
                    numS += '-';
                }
            }

            numS += input[i];
            if (input[i + 1] == '.') {
                numS += '.';
                i++;
            }
            i++;
        }
        if (!(numS.empty())) {
            double res = std::stod(numS);
            numsToCalculate.push_back(res);
            numS.erase();
        }
    }
    return numsToCalculate;
}
ErrorCode process(std::string input, double* out) {
    for (auto& charac : input) {
        if (!(isnumber(charac) || charac == '-' || charac == '/' || charac == '!' || charac == '+' || charac == '*' || charac == '%' || charac == '^' || charac == '$' || charac == ' ' || charac == '.' || charac == ',')) {
            return ErrorCode::BadCharacter;
        }
    }
    int numOfCharacters = 0;
    int numOfMinuses = 0;
    int numOfAllChar = 0;
    int numOfDots = 0;
    if (input[0] == '+') {
        return ErrorCode::BadFormat;
    }
    for (auto& charac : input) {
        if (charac == ',') {
            return ErrorCode::BadFormat;
        }
        if (charac == '/' || charac == '!' || charac == '+' || charac == '*' || charac == '%' || charac == '^' || charac == '$') {
            numOfCharacters++;
            numOfAllChar++;
        }
        if (charac == '-') {
            numOfCharacters++;
            numOfMinuses++;
        }
        if (charac == '.') {
            numOfDots++;
        }
    }
    if (numOfDots > 2) {
        return ErrorCode::BadFormat;
    }
    if (numOfCharacters - numOfMinuses > 1 || numOfMinuses > 3) {
            return ErrorCode::BadFormat;
    }

    std::vector<double> vecOfNums{getNumsFromInput(input, numOfMinuses)};

    if (vecOfNums.empty()) {
        return ErrorCode::BadFormat;
    }

    if (vecOfNums.size() < 1 && vecOfNums.size() > 2) {
        return ErrorCode::BadFormat;
    }

    auto add = [vecOfNums, &out]() mutable {
        *out = vecOfNums[0] + vecOfNums[1];

        std::cout << *out << std::endl;
    };
    auto subtract = [vecOfNums, &out, numOfMinuses]() mutable {
        if (numOfMinuses == 2 && vecOfNums[0] < 0) {
            *out = vecOfNums[0] - (vecOfNums[1] * -1);
        } else if (numOfMinuses == 1 && vecOfNums[0] > 0 && vecOfNums[1] < 0) {
            *out = vecOfNums[0] - (vecOfNums[1] * -1);
        } else {
            *out = vecOfNums[0] - vecOfNums[1];
        }

        std::cout << *out << std::endl;
    };
    auto divide = [vecOfNums, &out]() mutable {
        *out = vecOfNums[0] / vecOfNums[1];
        std::cout << *out << std::endl;
    };
    auto modulo = [vecOfNums, &out]() mutable {
        *out = int(vecOfNums[0]) % int(vecOfNums[1]);
        std::cout << *out << std::endl;
    };
    auto multiply = [vecOfNums, &out]() mutable {
        *out = vecOfNums[0] * vecOfNums[1];
        std::cout << *out << std::endl;
    };
    auto factorial = [vecOfNums, &out]() mutable {
        if (vecOfNums[0] < 0) {
            double res = -(std::tgamma(-vecOfNums[0] + 1.0));
            *out = res;
        } else {
            double res = std::tgamma(vecOfNums[0] + 1.0);
            *out = res;
        }

        std::cout << *out << std::endl;
    };
    auto power = [vecOfNums, &out]() mutable {
        double res;
        bool first = true;
        for (int i = 0; i < vecOfNums[1]; i++) {
            if (first) {
                res = vecOfNums[0];
                first = !first;
            } else {
                res *= vecOfNums[0];
            }
        }
        *out = res;
        std::cout << *out << std::endl;
    };
    auto squareRoot = [vecOfNums, &out]() mutable {
        *out = std::pow(vecOfNums[0], 1.0 / vecOfNums[1]);
        std::cout << *out << std::endl;
    };
    std::map<char, std::function<void(void)>>
        calcMap{{'+', add}, {'-', subtract}, {'/', divide}, {'*', multiply}, {'%', modulo}, {'!', factorial}, {'^', power}, {'$', squareRoot}};

    for (auto& charac : input) {
        for (auto& [operation, func] : calcMap) {
            if (charac == operation && charac != '-') {
                if (charac == '/') {
                    if (vecOfNums[1] == 0) {
                        return ErrorCode::DivideBy0;
                    }
                }
                if (charac == '$') {
                    if (vecOfNums[0] < 0) {
                        return ErrorCode::SqrtOfNegativeNumber;
                    }
                }
                if (charac == '!') {
                    if (vecOfNums.size() == 2) {
                        return ErrorCode::BadFormat;
                    }
                }

                if (charac == '%' and (!isInt(vecOfNums[0]) or !isInt(vecOfNums[1]))) {
                    return ErrorCode::ModuleOfNonIntegerValue;
                }

                func();
                return ErrorCode::OK;
            } else if (charac == operation && numOfAllChar == 0 && numOfMinuses > 0) {
                func();
                return ErrorCode::OK;
            }
        }
    }

    for (auto& charac : input) {
        for (auto& [operation, func] : calcMap) {
        }
    }
    return ErrorCode::BadCharacter;
};