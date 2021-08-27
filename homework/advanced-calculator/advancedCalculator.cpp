#include "advancedCalculator.hpp"

bool is_integer(double k) {
    return std::floor(std::abs(k)) == std::abs(k);
}

ErrorCode checkForErrorsPostProcess(double firstOperand, double secondOperand, char operation) {
    switch (operation) {
    case '/':
        if (0 == secondOperand) {
            return DivideBy0;
        }
        break;
    case '%':
        if (not(is_integer(firstOperand) and is_integer(secondOperand))) {
            return ModuleOfNonIntegerValue;
        }
        break;
    case '$':
        if (firstOperand < 0) {
            return SqrtOfNegativeNumber;
        }
        break;

    case '!':
        if (secondOperand != 0) {
            return BadFormat;
        }
        break;

    default:
        break;
    }

    return OK;
}

ErrorCode checForErrorsPreProcess(std::string str) {
    int dots = 0;

    for (auto& it : str) {
        if (it == '.') {
            dots++;
        }
        if (dots > 2) {
            return BadFormat;
        }
    }

    std::smatch n;
    const std::regex re_invalid(R"([\@\#\&\{\}\[\]\;\:\'\"\<\>\?\=a-zA-Z])");

    if (std::regex_search(str, n, re_invalid)) {
        return BadCharacter;
    }

    int repeats = 0;
    std::smatch m;
    const std::regex re(R"([\+\*\/\%\!\^\$\,])");

    while (std::regex_search(str, m, re)) {
        str = m.suffix().str();
        ++repeats;

        if ((repeats > 1) or (m.str().at(0) == ',')) {
            return BadFormat;
        }
    }

    return OK;
}

ErrorCode process(std::string input, double* out) {
    
    ErrorCode er = checForErrorsPreProcess(input);
    if (OK != er) {
        return er;
    }

    std::string::iterator end_pos = std::remove(input.begin(), input.end(), ' ');
    input.erase(end_pos, input.end());

    int sign = 1;
    std::string strToProcess = input;
    if ('-' == input.at(0)) {
        sign = -1;
        strToProcess = input.substr(1, input.size());
    }

    std::smatch m;
    const std::regex re(R"([\+\-\*\/\%\!\^\$])");

    if (std::regex_search(strToProcess, m, re)) {
        double firstOperand = 0;
        double secondOperand = 0;
        char operation = m.str().at(0);
        try {
            firstOperand = sign * std::stod(m.prefix().str());
            secondOperand = std::stod(m.suffix().str());
        } catch (std::invalid_argument const& ex) {
            if ('!' != operation) {
                return BadFormat;
            }
        }

        ErrorCode er = checkForErrorsPostProcess(firstOperand, secondOperand, operation);
        if (OK != er) {
            return er;
        }
        *out = operationLambdaMap.at(operation)(firstOperand, secondOperand);

    } else {
        return BadCharacter;
    }

    return OK;
}
