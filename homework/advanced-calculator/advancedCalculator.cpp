#include "advancedCalculator.hpp"
#include "Parsing_iterator.hpp"

ErrorCode process(std::string input, double* out) {
    print_input(input);

    Parsing_Iterator it{};
    it = std::copy(input.cbegin(), input.cend(), it);

    Result command = it.getResult();
    CalculationResult result = command.invoke();

    if (result.second) {
        *out = result.second.value();
    }
    return result.first;
}
