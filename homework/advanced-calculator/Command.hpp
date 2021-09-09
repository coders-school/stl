#pragma once
#include <variant>
#include "Types.hpp"

using CallbackVariants = std::variant<Value, ErrorCode>;
using OneArgCallback = std::function<CallbackVariants(Value)>;
using TwoArgsCallback = std::function<CallbackVariants(Value, Value)>;

class Command {
public:
    Command(TwoArgsCallback callback);
    Command(OneArgCallback callback);

    CalculationResult operator()(Numbers::const_iterator num, Numbers::const_iterator end);

private:
    OneArgCallback callback1_;
    TwoArgsCallback callback2_;
    const size_t requirements_;
};
