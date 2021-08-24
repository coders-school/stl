#include "advancedCalculator.hpp"
#include "Parsing_iterator.hpp"
#include <iostream>

ErrorCode process(const std::string& input, double* const out) {
    if(!out){
        return ErrorCode::OtherError;
    }

    std::cout << "input: " << input << '\n';

    Parsing_Iterator it{};
    it = std::copy(input.cbegin(), input.cend(), it);

    CalculationResult result = it.getResult().invoke();

    if (result.value) {
        *out = result.value.value();
    }
    return result.errorCode;
}
