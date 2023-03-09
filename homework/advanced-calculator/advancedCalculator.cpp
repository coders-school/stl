#include "advancedCalculator.hpp"

std::map<char, std::function<double(const double&, const double&)>>
    mapOfType = {
        {'+', [](const double& a, const double& b) -> double { return a + b; }},
        {'*', [](const double& a, const double& b) -> double { return a * b; }},
        {'/', [](const double& a, const double& b) -> double { return a / b; }},
        {'-', [](const double& a, const double& b) -> double { return a - b; }},
        {'%', [](const double& a, const double& b) -> double { return std::fmod(a, b); }},
        {'!', [](const double& a, const double& b) -> double { if (a < 0.f) { double o = a; o*=(-1); return -(std::tgamma(o + 1.f));} return std::tgamma(a + 1.f); }},
        {'^', [](const double& a, const double& b) -> double { return std::pow(a, b); }},
        {'$', [](const double& a, const double& b) -> double { return std::pow(a, 1.f / b); }},
};

ErrorCode process(std::string input, double* out) {
    char type;
    double a;
    double b;

    auto find_string_it = input.find_first_of("+-/*%$!^", 1);

    if (find_string_it != std::string::npos) {
        type = input[find_string_it];
        std::string a_string = input.substr(0, find_string_it);
        std::string b_string = input.substr(find_string_it + 1, input.size());
        try {
            a = std::stod(a_string);
            if (type != '!') {
                b = std::stod(b_string);
            }
        } catch (std::invalid_argument) {
            std::cout << "error \n";
            return ErrorCode::BadFormat;
        }
        std::cout << "a: " << a << ", b: " << b << ", type: " << type << "." << std::endl;
    } else {
        return ErrorCode::BadCharacter;
    }

    std::cout << "\n1\n";

    switch (type) {
    case '/':
        if (b == 0.f) {
            return ErrorCode::DivideBy0;
        }
        break;
    case '%':
        if (a == 0.f || b == 0.f || b != static_cast<int>(b)) {
            return ErrorCode::ModuleOfNonIntegerValue;
        }
        break;
    case '$':
        if (a < 0.f) {
            return ErrorCode::SqrtOfNegativeNumber;
        }
        break;
    }
    std::cout << "\n2\n";

    auto it = mapOfType.find(type);
    if (it != mapOfType.end()) {
        *out = it->second(a, b);
        std::cout << "Wynik 1: " << it->second(a, b) << std::endl;
    }
    return ErrorCode::OK;
}

// D:\Projekty\Coders_School\STL\stl\homework\advanced-calculator\test.cpp:139: Failure
// Expected equality of these values:
//   process("5,1!", &result)
//     Which is: 4-byte object <00-00 00-00>
//   ErrorCode::BadFormat
//     Which is: 4-byte object <02-00 00-00>
// [  FAILED  ] advancedCalculatorTest.ShouldReturnBadFormat (22 ms)
// [ RUN      ] advancedCalculatorTest.ShouldReturnBadCharacter
// a: 123, b: 123, type: -.

// 1

// 2
// Wynik 1: 0
// D:\Projekty\Coders_School\STL\stl\homework\advanced-calculator\test.cpp:155: Failure
// Expected equality of these values:
//   process("123 #- 123", &result)
//     Which is: 4-byte object <00-00 00-00>
//   ErrorCode::BadCharacter
//     Which is: 4-byte object <01-00 00-00>
// [  FAILED  ] advancedCalculatorTest.ShouldReturnBadCharacter (21 ms)