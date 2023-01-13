#include "advancedCalculator.hpp"

std::function<void()> fPlus = []() {};
std::function<void()> fMinus = []() {};
std::function<void()> fMulti = []() {};
std::function<void()> fDiv = []() {};
std::function<void()> fMod = []() {};
std::function<void()> fFactorial = []() {};
std::function<void()> fPower = []() {};
std::function<void()> fSqr = []() {};

std::unordered_map<char, std::function<void()>> cmdFunction = {
    {'+', fPlus},
    {'-', fMinus},
    {'*', fMulti},
    {'/', fDiv},
    {'%', fMod},
    {'!', fFactorial},
    {'^', fPower},
    {'$', fSqr}};

ErrorCode process(std::string cmd, double* out) {
    return ErrorCode::OK;
}
