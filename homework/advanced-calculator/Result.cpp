#include "Result.hpp"
#include <iostream>

namespace{
const std::map<const ErrorCode, const std::string> errorText{
    {ErrorCode::OK, "OK"},
    {ErrorCode::BadCharacter, "BadCharacter"},
    {ErrorCode::BadFormat, "BadFormat"},
    {ErrorCode::DivideBy0, "DivideBy0"},
    {ErrorCode::ModuleOfNonIntegerValue, "ModuleOfNonIntegerValue"},
    {ErrorCode::SqrtOfNegativeNumber, "SqrtOfNegativeNumber"},
    {ErrorCode::OtherError, "OtherError"}};

void print_op(const std::vector<char>& operations) {
    std::cout << "operations: ";
    for (const auto& op : operations) {
        std::cout << op << " ";
    }
    std::cout << '\n';
}

void print_args(const Numbers& numbers) {
    std::cout << "arguments: ";
    for (const auto& num : numbers) {
        std::cout << num << ", ";
    }
    std::cout << '\n';
}

CalculationResult print_and_return_error_result(ErrorCode error) {
    if (errorText.find(error) == errorText.cend()) {
        std::cout << "UnknownError"
                  << "\n\n";
        return {error, {}};
    }
    std::cout << errorText.at(error) << "\n\n";
    return {error, {}};
}

void print_result(Value value){
    std::cout << "result: " << value << "\n\n";
}
}

Result::Result(const std::vector<std::string>& args, const std::vector<char>& op)
    : op_(op) {
    std::transform(  //convert string numbers to double numbers and check correctness
        args.cbegin(),
        args.cend(),
        std::back_inserter(numbers_),
        [this](const auto& text) {
            if (std::count_if(
                    text.cbegin(), text.cend(),
                    [](auto letter) {
                        return letter == SeparatorFormat::legalOnce;
                    }) > 1) {
                this->errorCode_ = ErrorCode::BadFormat;
            }
            if (std::count_if(
                text.cbegin(), 
                text.cend(), 
                [](auto letter) { 
                    return std::isdigit(letter); 
                    }) == 0) {
                this->errorCode_ = ErrorCode::BadFormat;
                return 0.0;
            }
            return std::stod(text);
        });
}

CalculationResult Result::invoke(const CommandsMap& commands) const {
    print_op(op_);
    print_args(numbers_);

    if (errorCode_ != ErrorCode::OK) {  //conversion strings to numbers fail
        return print_and_return_error_result(errorCode_);
    }

    auto it = commands.cbegin();
    for (const auto& operation : op_) {  // operations container have character that don't exist as commands key
        it = commands.find(operation);
        if (it == commands.cend() && operation != SeparatorFormat::illegalFormat) {
            return print_and_return_error_result(ErrorCode::BadCharacter);
        }
    }

    if (op_.size() != 1 || op_.front() == SeparatorFormat::illegalFormat) {  //more than one operation or illegalFormat separator
        return print_and_return_error_result(ErrorCode::BadFormat);
    }

    auto [error, value] = it->second(numbers_.cbegin(), numbers_.cend());  //call operation

    if (error != ErrorCode::OK) {
        return print_and_return_error_result(error);
    }

    if (!value) {
        return print_and_return_error_result(ErrorCode::OtherError);
    }

    print_result(value.value());
    return {ErrorCode::OK, value};
}
