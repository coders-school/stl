#include "Commands.hpp"
#include <algorithm>
#include <cmath>
#include "Command.hpp"

//Note:
//CommandsMap is std::map<char, std::function<CalculationResult(std::vector<double>::const_iterator, std::vector<double>::const_iterator)>>
//where CalculationResult is struct holding ErrorCode and std::optional<double> (its more readable than pair).
//Command is wrapper for lambda. It gives conversion to use lambda with number of parameters rather than iterators range.
//and also hide otherwise duplicated code for lambdas (ie. check range, error result).
//PS. can use lambdas directly too but its less readable.

CommandsMap commands{
    //feature1: Command will check is number of arguments parsed equal to number of lamba argument
    {'+', Command{[](auto lhs, auto rhs) { return lhs + rhs; }}},  //almost same as commented version
    // {'+', [](auto num, auto end) {
    //      if (std::distance(num, end) != 2) {
    //          return CalculationResult{ErrorCode::BadFormat, {}};
    //      }
    //      double par1 = *num;
    //      double par2 = *++num;
    //      return CalculationResult{ErrorCode::OK, par1 + par2};
    //  }},
    {'-', Command{[](auto lhs, auto rhs) { return lhs - rhs; }}},
    {'*', Command{[](auto lhs, auto rhs) { return lhs * rhs; }}},
    {'/', Command{[](auto lhs, auto rhs) -> CallbackVariants {  //feature2: lambda can return errors
         if (rhs == 0.0) {
             return ErrorCode::DivideBy0;
         }
         return lhs / rhs;
     }}},
    {'%', Command{[](auto lhs, auto rhs) -> CallbackVariants {
         Value int_part;
         if (std::modf(rhs, &int_part) != 0.0 or rhs == 0.0) {  //not integer or zero
             return ErrorCode::ModuleOfNonIntegerValue;
         }
         return std::fmod(lhs, rhs);
     }}},
    {'!', Command{[](auto lhs) {  //feature3: can use one argument lambda too
         if (lhs > 0.0) {
             return std::tgamma(lhs + 1);
         }
         return -std::tgamma(-lhs + 1);
     }}},
    {'^', Command{[](auto lhs, auto rhs) { return std::pow(lhs, rhs); }}},
    {'$', Command{[](auto lhs, auto rhs) -> CallbackVariants {
         if (lhs < 0.0) {
             return ErrorCode::SqrtOfNegativeNumber;
         }
         return std::pow(lhs, 1.0 / rhs);
     }}}};