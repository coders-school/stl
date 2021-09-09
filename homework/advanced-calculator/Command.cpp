#include "Command.hpp"

Command::Command(TwoArgsCallback callback)
    : callback2_(callback), requirements_(2) {}

Command::Command(OneArgCallback callback)
    : callback1_(callback), requirements_(1) {}

CalculationResult Command::operator()(Numbers::const_iterator num, Numbers::const_iterator end) {
    if (std::distance(num, end) != requirements_) {
        return CalculationResult{ErrorCode::BadFormat, {}};
    }

    CallbackVariants result;
    Value par1 = *num;
    if (requirements_ == 2) {
        Value par2 = *++num;
        result = callback2_(par1, par2);
    } else {
        result = callback1_(par1);
    }

    if (result.index()) {// 0 - Value, 1 - ErrorCode
        return CalculationResult{std::get<ErrorCode>(result), {}};
    }
    return CalculationResult{ErrorCode::OK, std::get<Value>(result)};
}
