# `advancedCalculator`

Napisz program advanced_calculator. Ma on posiadać pętle główną, która będzie przyjmować dane od użytkownika i wyświetlać wynik, np. dla `5 % 3` ma zwrócić wynik `2`. Wszystkie komendy kalkulatora powinny być przechowywane w mapie, która jako klucz przechowuje znak `char` odwołujący się do konkretnej komendy (np. `+` -> dodaj , `%` -> modulo), a jako wartości `std::function<>` będące wraperem na wyrażenia lambda dokonujące określonej kalkulacji.

Program powinien także zwracać odpowiedni kod błędu, jeżeli użytkownik poda złe dane. Np. dzielenie przez `0` lub spróbuje dodać `ala + 5`.

* Input: `5 + 5` -> operacja dodawania dwóch liczb `5` i `5` -> output: `10`.
* Input: `5 ^ 2` -> operacje potęgowania -> output `25`.
* Input: `125 $ 3` -> operacja pierwiastka (sqrt za długie), pierwiastek sześcienny z `125` -> output: `5`.

Zadanie dostarcz na gałąź [advanced-calculator](https://github.com/coders-school/stl/tree/advanced-calculator/homework/advanced-calculator).

___

### Funkcje kalkulatora

* Dodawanie, mnożenie, dzielenie, odejmowanie (`+`,  `*` , `/` , `-`)
* Modulo (`%`)
* Obliczanie silni (`!`)
* Podnoszenie liczby do potęgi (`^`)
* Obliczanie pierwiastka (`$`)

___

### Error code

* `Ok`
* `BadCharacter` - znak inny niż liczba
* `BadFormat` - zły format komendy np. + 5 4, powinno być 4 + 5
* `DivideBy0` - dzielenie przez 0
* `SqrtOfNegativeNumber` - pierwiastek z liczby ujemnej
* `ModuleOfNonIntegerValue` - próba obliczenia % na liczbie niecałkowitej

___

### Funkcja, która będzie testowana

```cpp

```

* Funkcja ta powinna przyjmować dane od użytkownika oraz dokonywać odpowiedniej kalkulacji
* Jeżeli dane są poprawne, ma zwrócić `ErrorCode:Ok`, a w zmiennej `out` ma zapisać wynik
* Jeżeli wystąpi któryś z błędów, funkcja ma go zwrócić, a w `out` ma nic nie zapisywać

___

## Dodaj właściwe pliki

W CMakeLists.txt możesz zobaczyć które pliki będą kompilowane.

```cmake
add_executable(${PROJECT_NAME} main.cpp advancedCalculator.cpp)
add_executable(${PROJECT_NAME}-ut test.cpp advancedCalculator.cpp)
```
