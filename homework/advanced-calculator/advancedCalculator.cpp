#include "advancedCalculator.hpp"

std::function<double(double, double)> fPlus = [](double lhs, double rhs) { return lhs + rhs; };

std::function<double(double, double)> fMinus = [](double lhs, double rhs) { return lhs - rhs; };

std::function<double(double, double)> fMulti = [](double lhs, double rhs) { return lhs * rhs; };

std::function<double(double, double)> fDiv = [](double lhs, double rhs) { return lhs / rhs; };

std::function<double(double, double)> fMod =
    [](double lhs, double rhs) { return static_cast<int>(lhs) % static_cast<int>(rhs); };

std::function<double(double, double)> fFactorial =
    [](double lhs, double rhs) {
        if (lhs < 0) {
            return -1 * std::tgamma(std::abs(lhs) + 1);
        } else {
            return std::tgamma(lhs + 1);
        } };

std::function<double(double, double)> fPower =
    [](double lhs, double rhs) { return std::pow(lhs, rhs); };

std::function<double(double, double)> fRoot =
    [](double lhs, double rhs) { 
        if (rhs <0 ) { 
            return 1 / std::pow(lhs , 1 / std::abs(rhs));
        } else {
            return std::pow(lhs , 1 / rhs);
        } };

std::unordered_map<char, std::function<double(double, double)>> cmdFunction = {
    {'+', fPlus},
    {'-', fMinus},
    {'*', fMulti},
    {'/', fDiv},
    {'%', fMod},
    {'!', fFactorial},
    {'^', fPower},
    {'$', fRoot}};

constexpr std::string_view operations = "+-*/%!^$";

ErrorCode parseSingleArgument(const std::string& arg, double& out) {
    int nOfDots = 0;
    int nOfDigits = 0;
    int nOfLetters = 0;
    bool badCharacter = false;

    ErrorCode status = ErrorCode::OK;

    for (const auto& el : arg) {
        if (std::isdigit(el)) {
            nOfDigits++;
        } else if (el == '.') {
            nOfDots++;
        } else if (std::isalpha(el)) {
            nOfLetters++;
            break;
        } else if (el != ',' and std::none_of(operations.cbegin(), operations.cend(), [=](auto c) { return c == el; })) {
            badCharacter = true;
        }
    }

    if (nOfDigits + nOfDots == arg.length() and nOfDots < 2) {
        try {
            out = std::stod(arg);
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    } else if (arg[0] == '-' and (nOfDigits + nOfDots == arg.length() - 1 and nOfDots < 2)) {
        try {
            out = std::stod(arg);
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
        }
    } else if (nOfLetters > 0 or badCharacter) {
        status = ErrorCode::BadCharacter;
    } else {
        status = ErrorCode::BadFormat;
    }

    return status;
}

ErrorCode process(const std::string cmd, double* out) {
    Command c;

    c.status = ErrorCode::OK;
    std::string firstArg = "";
    std::string secondArg = "";

    // remove all whitespaces from cmd
    std::string cmdClean = "";
    std::copy_if(cmd.cbegin(), cmd.cend(), std::back_inserter(cmdClean), [](char c) { return c != ' '; });

    // divide cmd into two arguments and parse operation
    auto pos = std::string::npos;
    if (cmdClean[0] == '-') {
        pos = cmdClean.find_first_of(operations, 1);
    } else {
        pos = cmdClean.find_first_of(operations);
    }

    if (pos == std::string::npos) {
        c.status = ErrorCode::BadCharacter;
    } else if (pos == 0) {
        c.status = ErrorCode::BadFormat;
    } else {
        firstArg = cmdClean.substr(0, pos);
        c.operation = cmdClean[pos];
        if (pos - 1 < cmdClean.length()) {
            secondArg = cmdClean.substr(pos + 1, cmdClean.length() - (pos + 1));
        }
    }

    // parse first argument
    if (c.status == ErrorCode::OK and firstArg != "") {
        c.status = parseSingleArgument(firstArg, c.firstArg);
    }

    // parse second argument
    if (c.status == ErrorCode::OK and secondArg != "") {
        c.status = parseSingleArgument(secondArg, c.secondArg);
    }

    // check for bad format when factorial
    if (c.status == ErrorCode::OK and secondArg != "" and c.operation == '!') {
        c.status = ErrorCode::BadFormat;
    }

    // check forbidden math operation
    if (c.status == ErrorCode::OK) {
        if (c.operation == '/' and c.secondArg == 0) {
            c.status = ErrorCode::DivideBy0;
        } else if (c.operation == '$' and c.firstArg < 0) {
            c.status = ErrorCode::SqrtOfNegativeNumber;
        } else if (c.operation == '%' and (c.firstArg != std::floor(c.firstArg) or c.secondArg != std::floor(c.secondArg))) {
            c.status = ErrorCode::ModuleOfNonIntegerValue;
        } else {
            *out = cmdFunction[c.operation](c.firstArg, c.secondArg);
        }
    }

    return c.status;
}
