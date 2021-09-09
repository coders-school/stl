#include "advancedCalculator.hpp"
#include <iostream>
#include "Commands.hpp"
#include "Parsing_iterator.hpp"

ErrorCode process(const std::string& input, double* const out) {
    std::cout << "input: " << input << '\n';
    if (!out) {
        std::cout << "No output.\n";
        return ErrorCode::OtherError;
    }
    
    Parsing_Iterator it{};
    it = std::copy(input.cbegin(), input.cend(), it);

    auto result = it.getResult().invoke(commands);

    if (result.value) {
        *out = result.value.value();
    }
    return result.errorCode;
}
