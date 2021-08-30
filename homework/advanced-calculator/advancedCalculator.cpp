#include "advancedCalculator.hpp"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <cctype>
#include <cmath>
#include <functional>
#include <sstream>

std::map<const char, std::function<double(const double, const double)>> operations {
    { '+', std::plus<double>{} },
    { '-', std::minus<double>{} },
    { '*', std::multiplies<double>{} },
    { '/', std::divides<double>{} },
    { '%', std::modulus<int>{} },
    { '!', [](const auto number, const auto temp = 1) { 
            return number > 0 ? std::tgamma(number + 1) : std::tgamma(-number + 1) * -1; }},
    { '^', [](const auto base, const auto exp) { return std::pow(base, exp); }},
    { '$', [](const auto value, const auto n) { return std::pow(value, 1/n); }}
};

namespace AdvancedCalculator {
static constexpr std::array<char, 8> valid_operators {
    '+', '-', '*', '/', '%', '!', '^', '$'
};

bool is_bad_format(const tuple_type& expression) {
    auto [lhs, op, rhs] = expression;
    return !(lhs.has_value() && op.has_value() && rhs.has_value())
       && !(lhs.has_value() && op.has_value() && op.value() == '!'); 
}

bool is_bad_character(const std::string& expression) {  
    return !std::all_of(expression.cbegin(), expression.cend(), [](const auto ch) {
            return std::isdigit(ch) || std::find(valid_operators.cbegin(),
                    valid_operators.cend(), ch) != valid_operators.cend() 
                    || std::isspace(ch) || ch == '.' || ch == ',';
    });
}

bool is_too_long(const std::string& expression) {
    std::stringstream stream{ expression };
    char temp{};
    stream >> temp;

    if(temp == '+') return true;
    stream.putback(temp);

    double temp_value{};
    stream >> temp_value;
    if(!stream) return true;
    char operation{};
    stream >> operation;
    if(!stream) return true;
    if(operation == '!') {
        stream >> std::ws;
        return !stream.eof();
    }
    stream >> temp_value;
    stream >> std::ws;
    if(!stream.eof()) return true;
    return false; 
}


// MUST BE CALLED AFTER IS_BAD_FORMAT, OTHERWISE
// MIGHT THROW AN EXCEPTION:

bool is_division_by0(const tuple_type& expression) {
    auto [lhs, op, rhs] = expression;
    return op.value() == '/' && rhs.value() == 0;
}

bool is_sqrt_of_negative_number(const tuple_type& expression) {
    auto [lhs, op, rhs] = expression;
    return op.value() == '$' && lhs.value() < 0;
}

bool is_module_of_non_integer_value(const tuple_type& expression) {
    auto [lhs, op, rhs] = expression;
    return op.value() == '%' 
        && (std::floor(lhs.value()) != lhs.value()
        || std::floor(rhs.value()) != rhs.value());
}

bool is_bad_operation(const tuple_type& expression) {
    auto [lhs, op, rhs] = expression;
    return std::find(valid_operators.cbegin(), valid_operators.cend(), op)
        == valid_operators.cend();
}

tuple_type get_values(const std::string& input) {
    std::stringstream input_stream{ input };
    double lhs{};
    input_stream >> lhs;
    if(!input_stream) return tuple_type{};
    char operation{};
    input_stream >> operation;
    if(operation == '!') return tuple_type{ lhs, operation, std::optional<double>{} };
    double rhs{};
    input_stream >> rhs;
    if(!input_stream) return tuple_type{ lhs, operation, std::optional<double>{} };
    return tuple_type{ lhs, operation, rhs };
}

ErrorCode check_errors(const tuple_type& expression) {
    using pair_type = std::pair<std::function<bool(const tuple_type&)>, ErrorCode>; 
    static std::array<pair_type, 5> validation_functions {
        pair_type{ is_bad_format, ErrorCode::BadFormat },
        pair_type{ is_bad_operation, ErrorCode::BadFormat }, 
        pair_type{ is_division_by0, ErrorCode::DivideBy0 }, 
        pair_type{ is_sqrt_of_negative_number, ErrorCode::SqrtOfNegativeNumber },
        pair_type{ is_module_of_non_integer_value, ErrorCode::ModuleOfNonIntegerValue }
    };
    auto error_pair_it = std::find_if(validation_functions.cbegin(), 
            validation_functions.cend(), [&expression](const auto& pair) {
            return pair.first(expression);
    });
    return error_pair_it == validation_functions.cend() ? 
        ErrorCode::OK : error_pair_it->second;
}

double calculate_result(const tuple_type& expression) {
    auto [lhs, op, rhs] = expression;
    if(op == '!') return operations.at(op.value())(lhs.value(), 1);
    return operations.at(op.value())(lhs.value(), rhs.value());
}

ErrorCode process(const std::string& input, double* out) {
    if(is_bad_character(input)) return ErrorCode::BadCharacter;
    if(is_too_long(input)) return ErrorCode::BadFormat;
    tuple_type expression = get_values(input);
    auto error = check_errors(expression); 
    if(error != ErrorCode::OK) return error;

    *out = calculate_result(expression);
    return ErrorCode::OK;       
}





}
