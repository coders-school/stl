# `advancedCalculator`

Napisz program advanced_calculator. Program ten powinien posiadać pętle główną, która będzie przyjmować dane od użytkownika, np. dla 5 % 3 zwrócić wynik 2. Wszystkie komendy kalkulatora powinny być przechowywane w mapie. Która jako klucz char w postaci znaku odwołującego się do komendy (np. + -> dodaj , % -> modulo) a jej wartością powinna być funkcja std::function<> będąca wraperem na wyrażenia lambda dokonujące określonej kalkulacji. Program powinien także zwracać odpowiedni error code, jeżeli użytkownik poda złe dane. Np. dzielenie przez 0 lub spróbuje dodać ala + 5. Input: 5 + 5 -> operacja dodawania dwóch liczb 5 i 5 -> output: 10. Input: 5 ^ 2 -> operacje potęgowania -> output 25. Input 125 $ 3 -> operacja pierwiastka (sqrt za długie), pierwiastek sześcienny z 125 -> output: 5.

___

## Funkcje kalkulatora

* Dodawanie, mnożenie, dzielenie, odejmowanie, (+, *, /, -),
* Modulo (%),
* Obliczanie silni (!),
* Podnoszenie liczby do potęgi (^),
* Obliczanie pierwiastka ($).
  
___

## Error code

* Ok,
* BadCharacter -> Jeżeli użytkownik poda znak inny niż liczbę.
* BadFormat -> Jeżeli użytkownik poda zły format komendy np. + 5 4, powinno być 4 + 5.
* DivideBy0 -> dzielenie przez 0.
* SqrtOfNegativeNumber -> pierwiastek z liczby ujemnej.
* ModuleOfNonIntegerValue -> Póba obliczenia % na liczbie niecałkowitej.

___

## Funkcja, która będzie testowana

* ErrorCode process(std::string input, double* out)
* Funkcja ta powinna w pętli przyjmować kolejne dane od użytkownika oraz dokonywać odpowiedniej kalkulacji.
* Jeżeli dane są poprawne, zwróci 'ErrorCode:Ok', a w zmiennej out zapisze dane.
* Jeżeli wystąpi któryś z błędów, funkcja go zwodzi a w out nie zapisze nic.

___

## Add proper files

Please add proper files. In CMakeLists.txt you can see which files will be compiled.

```cmake
add_executable(${PROJECT_NAME} main.cpp advancedCalculator.cpp)
add_executable(${PROJECT_NAME}-ut test.cpp advancedCalculator.cpp)
```

You need to remember about both cpp and hpp file. Don't forget the header guard in hpp!
