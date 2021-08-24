#include "Result.hpp"
#include <iostream>

Result::Result(const std::vector<std::string>& args, const std::vector<char>& op)
    : op(op) {
    std::transform(  //convert string numbers to double numbers and check correctness
        args.begin(),
        args.end(),
        std::back_inserter(numbers),
        [this](const auto& text) {
            if (std::count_if(
                    text.begin(), text.end(),
                    [](auto letter) {
                        return letter == SeparatorFormat::legalOnce;
                    }) > 1) {
                this->errorCode = ErrorCode::BadFormat;
            }
            return std::stod(text);
        });
}

CalculationResult Result::invoke(const CommandsMap& commands) const {
    print_op();
    print_args();

    if (errorCode != ErrorCode::OK) {
        print_error();
        return {errorCode, {}};
    }

    auto it = commands.begin();
    for (auto operation : op) {  // op have no existing operation in commands
        it = commands.find(operation);
        if (it == commands.end() && operation != SeparatorFormat::illegalFormat) {
            errorCode = ErrorCode::BadCharacter;
            print_error();
            return {errorCode, {}};
        }
    }

    if (op.size() != 1 || op.front() == SeparatorFormat::illegalFormat) {  //more than one operation or illegalFormat separator
        errorCode = ErrorCode::BadFormat;
        print_error();
        return {errorCode, {}};
    }

    auto [error, value] = it->second(numbers.begin(), numbers.end());
    errorCode = error;

    if (error != ErrorCode::OK) {
        print_error();
        return {errorCode, {}};
    }

    if (!value) {
        errorCode = ErrorCode::OtherError;
        print_error();
        return {errorCode, {}};
    }
    std::cout << value.value() << "\n\n";

    return {errorCode, value};
}

std::map<ErrorCode, std::string> errorText{
    {ErrorCode::OK, "OK"},
    {ErrorCode::BadCharacter, "BadCharacter"},
    {ErrorCode::BadFormat, "BadFormat"},
    {ErrorCode::DivideBy0, "DivideBy0"},
    {ErrorCode::ModuleOfNonIntegerValue, "ModuleOfNonIntegerValue"},
    {ErrorCode::SqrtOfNegativeNumber, "SqrtOfNegativeNumber"},
    {ErrorCode::OtherError, "OtherError"}};

void Result::print_op() const {
    std::cout << "operations: ";
    for (const auto& op : op) {
        std::cout << op << " ";
    }
    std::cout << '\n';
}

void Result::print_args() const {
    std::cout << "arguments: ";
    for (const auto& num : numbers) {
        std::cout << num << ", ";
    }
    std::cout << '\n';
}

void Result::print_error() const {
    if (errorText.find(errorCode) == errorText.cend()) {
        std::cout << "UnknownError"
                  << "\n\n";
        return;
    }
    std::cout << errorText[errorCode] << "\n\n";
}
