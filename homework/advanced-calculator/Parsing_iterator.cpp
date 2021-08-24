#include "Parsing_iterator.hpp"

Result::Result(const std::vector<std::string>& args, const std::vector<char>& op, ErrorCode err)
    : op(op), errorCode(err) {
    ErrorCode numFormat = ErrorCode::OK;
    std::transform(
        args.begin(),
        args.end(),
        std::back_inserter(numbers),
        [&numFormat](const auto& text) {
            if (std::count_if(text.begin(), text.end(),
                              [](auto letter) {
                                  return letter == SeparatorFormat::legal;
                              }) > 1) {
                numFormat = ErrorCode::BadFormat;
            }
            return std::stod(text);
        });
    if (numFormat != ErrorCode::OK) {
        errorCode = numFormat;
    }
}

CalculationResult Result::invoke() {
    print_op();
    print_args();

    if (errorCode != ErrorCode::OK) {
        print_error();
        return {errorCode, {}};
    }

    auto it = commands.begin();
    for (auto o : op) {
        it = commands.find(o);
        if (it == commands.end() && o != SeparatorFormat::illegal) {
            errorCode = ErrorCode::BadCharacter;
            print_error();
            return {errorCode, {}};
        }
    }

    if (op.size() != 1) {
        errorCode = ErrorCode::BadFormat;
        print_error();
        return {errorCode, {}};
    }

    auto [error, value] = it->second(numbers.begin(), numbers.end());
    errorCode = error;

    if (error == ErrorCode::OK) {
        if (value) {
            std::cout << value.value() << "\n\n";
        }
    } else {
        print_error();
    }
    return {error, value};
}

std::map<ErrorCode, std::string> errorText{
    {ErrorCode::OK, "OK"},
    {ErrorCode::BadCharacter, "BadCharacter"},
    {ErrorCode::BadFormat, "BadFormat"},
    {ErrorCode::DivideBy0, "DivideBy0"},
    {ErrorCode::ModuleOfNonIntegerValue, "ModuleOfNonIntegerValue"},
    {ErrorCode::SqrtOfNegativeNumber, "SqrtOfNegativeNumber"}};

void print_input(std::string input) {
    std::cout << input << '\n';
}

void Result::print_op() {
    std::cout << "operations: ";
    for (const auto& op : op) {
        std::cout << op << " ";
    }
    std::cout << '\n';
}

void Result::print_args() {
    std::cout << "arguments: ";
    for (const auto& num : numbers) {
        std::cout << num << ", ";
    }
    std::cout << '\n';
}

void Result::print_error() {
    std::cout << errorText[errorCode] << "\n\n";
}

Parsing_Iterator& Parsing_Iterator::operator=(const char& letter) {
    if (std::iswspace(letter)) {//ignore white spaces
        return (*this);
    }

    if (letter == SeparatorFormat::negative) {
        if (state == operation) {//minus as new number
            num.push_back({});
            num.back() += letter;
            state = number;
        } else {//minus as new operator
            op.push_back(letter);
            state = operation;
        }
        return (*this);
    }

    if (!std::isdigit(letter) && letter != SeparatorFormat::legal) {//new operator
        op.push_back(letter);
        state = operation;
        return (*this);
    }

    if (state == operation) {//new number
        num.push_back({});
        state = number;
    }
    num.back() += letter;//add letter to current number
    return (*this);
}
