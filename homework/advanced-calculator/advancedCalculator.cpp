#include "advancedCalculator.hpp"
#include <iostream>
#include "Commands.hpp"
#include "Parsing_iterator.hpp"

ErrorCode process(const std::string& input, double* const out) {
    if (!out) {
        return ErrorCode::OtherError;
    }
    std::cout << "input: " << input << '\n';

    Parsing_Iterator it{};
    it = std::copy(input.cbegin(), input.cend(), it);

    auto result = it.getResult().invoke(commands);

    if (result.value) {
        *out = result.value.value();
    }
    return result.errorCode;
}
