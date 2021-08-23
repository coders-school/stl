


enum class errorCode {
    Ok,
    BadCharacter,                             // Jeżeli użytkownik poda znak inny niż liczbę.
    BadFormat,                                // Jeżeli użytkownik poda zły format komendy np. + 5 4, powinno być 4 + 5.
    DivideBy0,                                // dzielenie przez 0.
    SqrtOfNagativeNumber,                     // pierwiastek z liczby ujemnej.
    ModuleOfNonIntegerValue                   // Póba obliczenia % na liczbie niecałkowitej.
};
