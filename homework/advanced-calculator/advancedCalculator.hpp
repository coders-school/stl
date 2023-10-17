#pragma once
#include <any>
#include <cmath>
#include <functional>
#include <map>
#include <string>
#include <regex>
enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

inline std::function<double(double, double)> add;
inline std::function<double(double, double)> substract;
inline std::function<double(double, double)> multipl;
inline std::function<double(double, double)> divide;
inline std::function<int(int, int)> modulo;
inline std::function<double(double)> factorial;
inline std::function<double(double,double)> power;
inline std::function<double(double,double)> root;

template <typename T>
using FunctionType = std::function<T(T)>;

extern ErrorCode errors;

extern std::map<char, std::any> operations;

ErrorCode process(std::string input, double* out);