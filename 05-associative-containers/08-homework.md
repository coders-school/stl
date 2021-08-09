<!-- .slide: data-background="#111111" -->

# Praca domowa 💻

<a href="https://coders.school">
    <img width="500px" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___
<!-- .slide: style="font-size: 0.85em" -->

## Praca domowa

### Post-work

Działaj dużo z dokumentacją cppreference i najlepiej z kimś w parze lub nawet grupie 3-osobowej 🙂

* Zadanie 1 - `inner-product` (8 punktów)
* Zadanie 2 - `advanced-calculator` (25 punktów)

#### Bonusy

* **01.09.2021 (środa)** to ostatni dzień na zebranie bonusowych punktów za punktualność
* **3 XP** wpadną Ci za każde zadanie dostarczone w terminie (razem 6 punktów)
* **1 XP** za pracę w grupie dla każdej osoby z grupy za każde zadanie (razem 2 punkty dla każdej osoby). Zalecamy grupy 3 osobowe.

#### [Zadania w repo](https://github.com/coders-school/stl/blob/master/05-associative-containers/08-homework.md)

___

### Pre-work

* Przejrzyj raz jeszcze [złożoność operacji na wszystkich kontenerach STL](https://github.com/gibsjose/cpp-cheat-sheet/blob/master/Data%20Structures%20and%20Algorithms.md) i poczytaj tam też o drzewach binarnych i różnych algorytmach sortowania.

___

## Zadanie 1 - `inner-product`

Zaimplementuj funkcję `ArithmeticAverage()`, która bierze 2 wektory intów i oblicza średnią arytmetyczną wszystkich wartości

Input: `{1, 2, 3, 4} {1, 2, 3, 4}`
Output: `2.5`

Zaimplementuj funkcję `Distance()`, która bierze 2 wektory intów (jako współrzędne punktów w przestrzeni n-wymiarowej) i oblicza odległość między nimi.

Input: `{7, 4, 3} {17, 6, 2}`
Output: `10.247`

Zadanie dostarcz na gałąź [inner-product](https://github.com/coders-school/stl/tree/inner-product/homework/inner-product).

___

## Zadanie 2 - `advanced-calculator`

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
ErrorCode process(std::string input, double* out)
```

* Funkcja ta powinna przyjmować dane od użytkownika oraz dokonywać odpowiedniej kalkulacji
* Jeżeli dane są poprawne, ma zwrócić `ErrorCode:Ok`, a w zmiennej `out` ma zapisać wynik
* Jeżeli wystąpi któryś z błędów, funkcja ma go zwrócić, a w `out` ma nic nie zapisywać
