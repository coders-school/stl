#include "advancedCalculator.hpp"

#include <cmath>
#include <functional>
#include <iterator>
#include <regex>
#include <unordered_map>
#include <variant>

ErrorCode checkInput(const std::string& input) {
    std::size_t pos;
    std::string gr("^-?(0|([1-9][0-9]*))(\\.[0-9]+)? ?[-+*/%\\^\\$] ?-?(0|([1-9][0-9]*))(\\.[0-9]+)?$");
    std::string grf("^-?(0|([1-9][0-9]*))(\\.[0-9]+)? ?!$");
    std::regex generalRegex(gr, std::regex_constants::extended);
    std::regex generalRegexFactorial(grf, std::regex_constants::extended);
    std::string onr("^ ?([-+*/%!\\^\\$] ?)?(-?(0|([1-9][0-9]*))([\\.,][0-9]+)* ?([-+*/%!\\^\\$] ?)?)*$");
    std::regex operatorNumberRegex(onr, std::regex_constants::extended);
    if (std::regex_match(input, generalRegex) || std::regex_match(input, generalRegexFactorial)) {
        std::regex zeroRegex("^ ?-?0(\\.0+)? ?$", std::regex_constants::extended);
        std::regex nonIntegerRegex("^ ?-?(0|([1-9][0-9]*))\\.[0-9]+ ?$",
                                         std::regex_constants::extended);
        std::regex negativeRegex("^ ?-[1-9][0-9]*(\\.[0-9]+)? ?$", std::regex_constants::extended);
        if ((pos = input.find("/")) != std::string::npos
            && std::regex_match(input.substr(pos + 1), zeroRegex)) {
            return ErrorCode::DivideBy0;
        }
        if ((pos = input.find("%")) != std::string::npos) {
            if (std::regex_match(input.substr(0, pos), nonIntegerRegex)
                || std::regex_match(input.substr(pos + 1), nonIntegerRegex)) {
                return ErrorCode::ModuleOfNonIntegerValue;
            } else if (std::regex_match(input.substr(pos + 1), zeroRegex)) {
                return ErrorCode::DivideBy0;
            }
        }
        if ((pos = input.find("$")) != std::string::npos) {
            if (std::regex_match(input.substr(0, pos), negativeRegex)) {
                return ErrorCode::SqrtOfNegativeNumber;
            } else if (std::regex_match(input.substr(0, pos), zeroRegex)
                && std::regex_match(input.substr(pos + 1), negativeRegex)) {
                return ErrorCode::DivideBy0;
            }
        }
        if ((pos = input.find("^")) != std::string::npos
            && std::regex_match(input.substr(0, pos), zeroRegex)
            && (std::regex_match(input.substr(pos + 1), zeroRegex)
                || std::regex_match(input.substr(pos + 1), negativeRegex))) {
            return ErrorCode::DivideBy0;
        }
        return ErrorCode::OK;
    } else if ((pos = input.find("!")) != std::string::npos
        && ! std::regex_match(input, generalRegexFactorial)) {
        if (! (std::regex_match(input.substr(0, pos), operatorNumberRegex)
            && std::regex_match(input.substr(pos + 1), operatorNumberRegex))) {
            return ErrorCode::BadCharacter;
        } else {
            return ErrorCode::BadFormat;
        }
    } else if ((pos = input.find("+")) != std::string::npos
        && ! std::regex_match(input, generalRegex)) {
        if (! (std::regex_match(input.substr(0, pos), operatorNumberRegex)
            && std::regex_match(input.substr(pos + 1), operatorNumberRegex))) {
            return ErrorCode::BadCharacter;
        } else {
            return ErrorCode::BadFormat;
        }
    } else if ((pos = input.find("-")) != std::string::npos
        && ! std::regex_match(input, generalRegex)) {
        if (! (std::regex_match(input.substr(0, pos), operatorNumberRegex)
            && std::regex_match(input.substr(pos + 1), operatorNumberRegex))) {
            return ErrorCode::BadCharacter;
        } else {
            return ErrorCode::BadFormat;
        }
    } else if ((pos = input.find("*")) != std::string::npos
        && ! std::regex_match(input, generalRegex)) {
        if (! (std::regex_match(input.substr(0, pos), operatorNumberRegex)
            && std::regex_match(input.substr(pos + 1), operatorNumberRegex))) {
            return ErrorCode::BadCharacter;
        } else {
            return ErrorCode::BadFormat;
        }
    } else if ((pos = input.find("/")) != std::string::npos
        && ! std::regex_match(input, generalRegex)) {
        if (! (std::regex_match(input.substr(0, pos), operatorNumberRegex)
            && std::regex_match(input.substr(pos + 1), operatorNumberRegex))) {
            return ErrorCode::BadCharacter;
        } else {
            return ErrorCode::BadFormat;
        }
    } else if ((pos = input.find("%")) != std::string::npos
        && ! std::regex_match(input, generalRegex)) {
        if (! (std::regex_match(input.substr(0, pos), operatorNumberRegex)
            && std::regex_match(input.substr(pos + 1), operatorNumberRegex))) {
            return ErrorCode::BadCharacter;
        } else {
            return ErrorCode::BadFormat;
        }
    } else if ((pos = input.find("^")) != std::string::npos
        && ! std::regex_match(input, generalRegex)) {
        if (! (std::regex_match(input.substr(0, pos), operatorNumberRegex)
            && std::regex_match(input.substr(pos + 1), operatorNumberRegex))) {
            return ErrorCode::BadCharacter;
        } else {
            return ErrorCode::BadFormat;
        }
    } else if ((pos = input.find("$")) != std::string::npos
        && ! std::regex_match(input, generalRegex)) {
        if (! (std::regex_match(input.substr(0, pos), operatorNumberRegex)
            && std::regex_match(input.substr(pos + 1), operatorNumberRegex))) {
            return ErrorCode::BadCharacter;
        } else {
            return ErrorCode::BadFormat;
        }
    } else {
        return ErrorCode::BadCharacter;
    }
}

ErrorCode process(std::string input, double* out) {
    std::size_t backslash = input.find("\\");
    if (backslash != std::string::npos) {
        do {
            auto it = input.begin();
            std::advance(it, backslash);
            input.insert(it, '\\');
            std::size_t temp = input.substr(backslash + 2).find("\\");
            if (temp != std::string::npos) {
                backslash += (temp + 2);
            } else {
                break;
            }
        } while (true);
    }
    std::unordered_map<char, std::variant<std::function<double(double, double)>,
                                          std::function<int(int, int)>,
                                          std::function<double(double)>>> operations;
    operations.emplace('+', std::function([](double l, double r) {
        return l + r;
    }));
    operations.emplace('-', std::function([](double l, double r) {
        return l - r;
    }));
    operations.emplace('*', std::function([](double l, double r) {
        return l * r;
    }));
    operations.emplace('/', std::function([](double l, double r) {
        return l / r;
    }));
    operations.emplace('%', std::function([](int l, int r) {
        return l % r;
    }));
    operations.emplace('!', std::function([](double n) {
        if (n < 0) {
            return (-1) * std::tgamma(std::fabs(n) + 1);
        }
        return std::tgamma(n + 1);
    }));
    operations.emplace('^', std::function([](double l, double r) {
        return std::pow(l, r);
    }));
    operations.emplace('$', std::function([](double l, double r) {
        return std::pow(l, 1 / r);
    }));
    ErrorCode whatIsWrong = checkInput(input);
    if (whatIsWrong == ErrorCode::OK) {
        std::regex opsRegex("-?(0|([1-9][0-9]*))(\\.[0-9]+)? ?[-+*/%!\\^\\$]", std::regex_constants::extended);
        auto opsBegin = std::sregex_iterator(input.cbegin(), input.cend(), opsRegex);
        auto opsEnd = std::sregex_iterator();
        std::string command("");
        for (std::sregex_iterator it = opsBegin; it != opsEnd; ++it) {
            command += it->str();
        }
        std::size_t pos = command.size() - 1;
        if (command[pos] == '!') {
            auto factorial = std::get<std::function<double(double)>>(operations[command[pos]]);
            *out = factorial(std::stod(input.substr(0, pos)));
        } else if (command[pos] == '%') {
            auto mod = std::get<std::function<int(int, int)>>(operations[command[pos]]);
            *out = mod(std::stoi(input.substr(0, pos)), std::stoi(input.substr(pos + 1)));
        } else {
            auto f = std::get<std::function<double(double, double)>>(operations[command[pos]]);
            *out = f(std::stod(input.substr(0, pos)), std::stod(input.substr(pos + 1)));
        }
    }
    return whatIsWrong;
}

std::ostream& operator<<(std::ostream& out, const ErrorCode& error) {
    if (error == ErrorCode::OK) {
        out << "OK";
    } else if (error == ErrorCode::BadCharacter) {
        out << "BadCharacter";
    } else if (error == ErrorCode::BadFormat) {
        out << "BadFormat";
    } else if (error == ErrorCode::DivideBy0) {
        out << "DivideBy0";
    } else if (error == ErrorCode::SqrtOfNegativeNumber) {
        out << "SqrtOfNegativeNumber";
    } else if (error == ErrorCode::ModuleOfNonIntegerValue) {
        out << "ModuleOfNonIntegerValue";
    }
    return out;
}
