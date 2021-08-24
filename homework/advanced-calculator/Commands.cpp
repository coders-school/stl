#include "Commands.hpp"

CommandsMap commands{
    {'+',  //add
     [](auto num, auto end) {
         if (std::distance(num, end) != 2) {
             return CalculationResult{ErrorCode::BadFormat, {}};
         }
         double par1 = *num;
         double par2 = *++num;
         return CalculationResult{ErrorCode::OK, par1 + par2};
     }},
    {'-',  //substract
     [](auto num, auto end) {
         if (std::distance(num, end) != 2) {
             return CalculationResult{ErrorCode::BadFormat, {}};
         }
         double par1 = *num;
         double par2 = *++num;
         return CalculationResult{ErrorCode::OK, par1 - par2};
     }},
    {'*',  //multiply
     [](auto num, auto end) {
         if (std::distance(num, end) != 2) {
             return CalculationResult{ErrorCode::BadFormat, {}};
         }
         double par1 = *num;
         double par2 = *++num;
         return CalculationResult{ErrorCode::OK, par1 * par2};
     }},
    {'/',  //divide
     [](auto num, auto end) {
         if (std::distance(num, end) != 2) {
             return CalculationResult{ErrorCode::BadFormat, {}};
         }
         auto par1 = *num;
         auto par2 = *++num;
         if (par2 == 0) {
             return CalculationResult{ErrorCode::DivideBy0, {}};
         }
         return CalculationResult{ErrorCode::OK, par1 / par2};
     }},
    {'%',  //modulo
     [](auto num, auto end) {
         if (std::distance(num, end) != 2) {
             return CalculationResult{ErrorCode::BadFormat, {}};
         }
         double par1 = *num;
         double par2 = *++num;
         if (par2 - static_cast<int>(par2) > 0.0001 || static_cast<int>(par2) == 0) {
             return CalculationResult{ErrorCode::ModuleOfNonIntegerValue, {}};
         }
         return CalculationResult{ErrorCode::OK, std::fmod(par1, par2)};
     }},
    {'!',  //factorial
     [](auto num, auto end) {
         if (std::distance(num, end) != 1) {
             return CalculationResult{ErrorCode::BadFormat, {}};
         }
         double par1 = *num;
         if (par1 > 0.0) {
             return CalculationResult{ErrorCode::OK, std::tgamma(par1 + 1)};
         }
         return CalculationResult{ErrorCode::OK, -std::tgamma(-par1 + 1)};
     }},
    {'^',  //power
     [](auto num, auto end) {
         if (std::distance(num, end) != 2) {
             return CalculationResult{ErrorCode::BadFormat, {}};
         }
         auto par1 = *num;
         auto par2 = *++num;
         return CalculationResult{ErrorCode::OK, std::pow(par1, par2)};
     }},
    {'$',  //nth root
     [](auto num, auto end) {
         if (std::distance(num, end) != 2) {
             return CalculationResult{ErrorCode::BadFormat, {}};
         }
         auto par1 = *num;
         auto par2 = *++num;
         if (par1 < 0) {
             return CalculationResult{ErrorCode::SqrtOfNegativeNumber, {}};
         }
         return CalculationResult{ErrorCode::OK, std::pow(par1, 1.0 / par2)};
     }}};
