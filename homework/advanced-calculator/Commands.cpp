#include "Commands.hpp"
#include <algorithm>
#include <cmath>

struct Command{
    Command(std::function<Value(Value lhs, Value rhs)> fun2, ErrorCode optionalError=ErrorCode::OK)
    :optionalError(optionalError){
        lambda2 = fun2;
        requirements = 2;
    }

    Command(std::function<Value(Value lhs)> fun1, ErrorCode optionalError=ErrorCode::OK)
    :optionalError(optionalError){
        lambda1 = fun1;
        requirements = 1;
    }

    CalculationResult operator()(Numbers::const_iterator num, Numbers::const_iterator end){
        if (std::distance(num, end) != requirements){
            return CalculationResult{ErrorCode::BadFormat, {}};
        }

        if(requirements == 2){
            double par1 = *num;
            double par2 = *++num;
            auto result = lambda2(par1, par2);
            if(std::isnan(result)){
                return CalculationResult{optionalError, {}};
            }
            return CalculationResult{ErrorCode::OK, result};
        }else{
            double par1 = *num;
            auto result = lambda1(par1);
            if(std::isnan(result)){
                return CalculationResult{optionalError, {}};
            }
            return CalculationResult{ErrorCode::OK, result};
        }
    }
    std::function<Value(Value lhs)> lambda1;
    std::function<Value(Value lhs, Value rhs)> lambda2;
    ErrorCode optionalError = ErrorCode::OK;
    size_t requirements = 2;
};

CommandsMap commands{
    {'+', //add
        Command{[](auto lhs, auto rhs){ return lhs + rhs; }}
    },
    {'-', //substract
        Command{[](auto lhs, auto rhs){ return lhs - rhs; }}
    },
    {'*', //multiply
        Command{[](auto lhs, auto rhs){ return lhs * rhs; }}
    },
    {'/', //divide
        Command{[](auto lhs, auto rhs){ 
            if ((int)rhs == 0){
                return std::numeric_limits<Value>::signaling_NaN();
            }
            return lhs / rhs; }, 
            ErrorCode::DivideBy0
        }
    },
    {'%', //modulo
        Command{[](auto lhs, auto rhs){ 
            if (rhs - static_cast<int>(rhs) > 0.0001 || static_cast<int>(rhs) == 0){
                return std::numeric_limits<Value>::signaling_NaN();
            }
            return std::fmod(lhs, rhs); }, 
            ErrorCode::ModuleOfNonIntegerValue
        }
    },
    {'!', //factorial
        Command{[](auto lhs){ 
            if (lhs > 0.0){
                return std::tgamma(lhs + 1);
            }
            return -std::tgamma(-lhs + 1);}
        }
    },
    {'^', //power
        Command{[](auto lhs, auto rhs){ return std::pow(lhs, rhs); }}
    },
    {'$', //nth root
        Command{[](auto lhs, auto rhs){ 
            if (lhs < 0){
                return std::numeric_limits<Value>::signaling_NaN();
            }
            return std::pow(lhs, 1.0 / rhs);}, 
            ErrorCode::SqrtOfNegativeNumber
        }
    }
};
