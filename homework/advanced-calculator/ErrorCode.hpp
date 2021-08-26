#pragma once

enum class ErrorCode {
    OK,
    BadCharacter,             //znak inny niż liczba
    BadFormat,                //zły format komendy np. + 5 4, powinno być 4 + 5
    DivideBy0,                //dzielenie przez 0
    SqrtOfNegativeNumber,     //pierwiastek z liczby ujemnej
    ModuleOfNonIntegerValue,  //próba obliczenia % na liczbie niecałkowitej
    OtherError                //dodatkowy dla innych niż powyższe
};
