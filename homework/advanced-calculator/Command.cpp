#include "Command.hpp"

Command::Command(TwoArgsCallback callback)
    : callback2(callback), requirements(2) {}

Command::Command(OneArgCallback callback)
    : callback1(callback), requirements(1) {}

CalculationResult Command::operator()(Numbers::const_iterator num, Numbers::const_iterator end) {
    if (std::distance(num, end) != requirements) {
        return CalculationResult{ErrorCode::BadFormat, {}};
    }

    CallbackVariants result;
    Value par1 = *num;

    if (requirements == 2) {
        Value par2 = *++num;

        result = callback2(par1, par2);
    } else if (requirements == 1) {
        result = callback1(par1);
    }

    if (result.index()) {
        return CalculationResult{std::get<ErrorCode>(result), {}};
    }
    return CalculationResult{ErrorCode::OK, std::get<Value>(result)};
}
