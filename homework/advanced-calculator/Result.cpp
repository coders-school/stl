#include "Result.hpp"
#include <iostream>

Result::Result(const std::vector<std::string>& args, const std::vector<char>& op)
    : op(op) {
    std::transform(  //convert string numbers to double numbers and check correctness
        args.cbegin(),
        args.cend(),
        std::back_inserter(numbers),
        [this](const auto& text) {
            if (std::count_if(
                    text.cbegin(), text.cend(),
                    [](auto letter) {
                        return letter == SeparatorFormat::legalOnce;
                    }) > 1) {
                this->errorCode = ErrorCode::BadFormat;
            }
            if (std::count_if(
                text.cbegin(), 
                text.cend(), 
                [](auto letter) { 
                    return std::isdigit(letter); 
                    }) == 0) {
                this->errorCode = ErrorCode::BadFormat;
                return 0.0;
            }
            return std::stod(text);
        });
}

CalculationResult Result::invoke(const CommandsMap& commands) const {
    print_op();
    print_args();

    if (errorCode != ErrorCode::OK) {  //conversion strings to numbers fail
        return print_error_and_get_result(errorCode);
    }

    auto it = commands.cbegin();
    for (const auto& operation : op) {  // operations container have character that don't exist as commands key
        it = commands.find(operation);
        if (it == commands.cend() && operation != SeparatorFormat::illegalFormat) {
            return print_error_and_get_result(ErrorCode::BadCharacter);
        }
    }

    if (op.size() != 1 || op.front() == SeparatorFormat::illegalFormat) {  //more than one operation or illegalFormat separator
        return print_error_and_get_result(ErrorCode::BadFormat);
    }

    auto [error, value] = it->second(numbers.cbegin(), numbers.cend());  //call operation

    if (error != ErrorCode::OK) {
        return print_error_and_get_result(error);
    }

    if (!value) {
        return print_error_and_get_result(ErrorCode::OtherError);
    }
    std::cout << "result: " << value.value() << "\n\n";

    return {ErrorCode::OK, value};
}

const std::map<const ErrorCode, const std::string> errorText{
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

CalculationResult Result::print_error_and_get_result(ErrorCode error) const {
    if (errorText.find(error) == errorText.cend()) {
        std::cout << "UnknownError"
                  << "\n\n";
        return {error, {}};
    }
    std::cout << errorText.at(error) << "\n\n";
    return {error, {}};
}
