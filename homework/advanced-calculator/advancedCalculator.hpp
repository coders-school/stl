#pragma once
#include <algorithm>
#include <cmath>
#include <functional>
#include <string>
#include <map>

enum class ErrorCode {
    OK,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue
};

enum class Operations {
    Add,
    Substract,
    Multiplicate,
    Divide,
    Modulus,
    Exponentiate,
    Root,
    Factor,
    Error
};

ErrorCode process(std::string input, double* out);
ErrorCode checkFormat(const std::string& str);
ErrorCode checkValues(const double& lhs, const double& rhs, const Operations& operation);
bool checkBeforeLhs(const std::string& str);
bool checkForMultipleOperators(const std::string& str);
bool checkForCommas (const std::string& str);
bool checkForForbiddenCharacters(const std::string& str);
bool checkForAdjacentOperands(const std::string& str);
bool checkForTwoOperandsWithUnaryOp(const std::string& str);
bool checkForMultipleDotSeparators(const std::string& str);
std::pair<size_t, Operations> detectOperator(const std::string& str);
double getLhs(const std::string& str, size_t operatorPos);
double getRhs(const std::string& str, size_t operatorPos);
void calculate(const double& lhs, const double& rhs, const Operations& operation, double* out);
double factorial(const double& value);

/*
Napisz program advanced_calculator. Ma on posiadać pętle główną, która będzie przyjmować dane od użytkownika i wyświetlać wynik, np. dla 5 % 3 ma zwrócić wynik 2. Wszystkie komendy kalkulatora powinny być przechowywane w mapie, która jako klucz przechowuje znak char odwołujący się do konkretnej komendy (np. + -> dodaj , % -> modulo), a jako wartości std::function<> będące wraperem na wyrażenia lambda dokonujące określonej kalkulacji.

Program powinien także zwracać odpowiedni kod błędu, jeżeli użytkownik poda złe dane. Np. dzielenie przez 0 lub spróbuje dodać ala + 5.

    Input: 5 + 5 -> operacja dodawania dwóch liczb 5 i 5 -> output: 10.
    Input: 5 ^ 2 -> operacje potęgowania -> output 25.
    Input: 125 $ 3 -> operacja pierwiastka (sqrt za długie), pierwiastek sześcienny z 125 -> output: 5.

Zadanie dostarcz na gałąź advanced-calculator.
Funkcje kalkulatora

    Dodawanie, mnożenie, dzielenie, odejmowanie (+, * , / , -)
    Modulo (%)
    Obliczanie silni (!)
    Podnoszenie liczby do potęgi (^)
    Obliczanie pierwiastka ($)

Error code

    Ok
    BadCharacter - znak inny niż liczba
    BadFormat - zły format komendy np. + 5 4, powinno być 4 + 5
    DivideBy0 - dzielenie przez 0
    SqrtOfNegativeNumber - pierwiastek z liczby ujemnej
    ModuleOfNonIntegerValue - próba obliczenia % na liczbie niecałkowitej

Funkcja, która będzie testowana

ErrorCode process(std::string input, double* out)

    Funkcja ta powinna przyjmować dane od użytkownika oraz dokonywać odpowiedniej kalkulacji
    Jeżeli dane są poprawne, ma zwrócić ErrorCode:Ok, a w zmiennej out ma zapisać wynik
    Jeżeli wystąpi któryś z błędów, funkcja ma go zwrócić, a w out ma nic nie zapisywać

Dodaj właściwe pliki

W CMakeLists.txt możesz zobaczyć które pliki będą kompilowane.

add_executable(${PROJECT_NAME} main.cpp advancedCalculator.cpp)
add_executable(${PROJECT_NAME}-ut test.cpp advancedCalculator.cpp)
*/