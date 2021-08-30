#pragma once

#include <functional>
#include <map>
#include <string>
#include <tuple>
#include <optional>
#include <vector>

namespace AdvancedCalculator {
    enum class ErrorCode {
        OK,
        BadCharacter,
        BadFormat,
        DivideBy0,                                
        SqrtOfNegativeNumber,                     
        ModuleOfNonIntegerValue,
    };
    
    ErrorCode process(const std::string& input, double* out);

    using tuple_type = std::tuple<std::optional<double>, 
          std::optional<char>, std::optional<double>>;  
    tuple_type get_values(const std::string& input);

    std::vector<ErrorCode> get_errors(const tuple_type& expression);
}
