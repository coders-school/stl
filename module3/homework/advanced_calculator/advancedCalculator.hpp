#pragma once
#include <string>
//class advance_calculator?
/*  
    main loop (taking input from user)
    all commands in map ( key[+] and command), value should be std::function<> which is wrapper for lambdas
    application should return errorcode  when user enters bad data
*/



/*
    Error code
    Ok,
    BadCharacter -> Jeżeli użytkownik poda znak inny niż liczbę.
    BadFormat -> Jeżeli użytkownik poda zły format komendy np. + 5 4, powinno być 4 + 5.
    DivideBy0 -> dzielenie przez 0.
    SqrtOfNegativeNumber -> pierwiastek z liczby ujemnej.
    ModuleOfNonIntegerValue -> Próba obliczenia % na liczbie niecałkowitej.
*/
enum class ErrorCode{
    Ok,
    BadCharacter,
    BadFormat,
    DivideBy0,
    SqrtOfNegativeNumber,
    ModuleOfNonIntegerValue,
};

ErrorCode process(std::string input, double* out);
