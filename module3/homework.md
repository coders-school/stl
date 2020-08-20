<!-- .slide: data-background="#111111" -->

# Zadanie domowe

___

## Zadanie 1

Wykorzystując `std::inner_product`, napisz program, kóry obliczy średnią arytmetyczną dwóch `std::vector<int>`

Input: `{1, 2, 3, 4}` `{1, 2, 3, 4}`
Output: `2.5`

Następnie wykorzystując `std::inner_product`, napisz funkcję, która obliczy odległość między 2 punktami dla n wymiarów.

Metrykę euklidesową w przestrzeni definujemy:

```math
{\displaystyle \mathbb {R} ^{n}}{\mathbb  R}^{n}

{\displaystyle d_{e}(\mathbf {x} ,\mathbf {y} )={\sqrt {(y_{1}-x_{1})^{2}+\dots +(y_{n}-x_{n})^{2}}},}d_e(\mathbf x, \mathbf y) = \sqrt{(y_1 - x_1)^2 + \dots + (y_n - x_n)^2},
```

Input: `{7, 4, 3}` `{17, 6, 2}`
Output: `10.247`

___

## Zadannie 2

Napisz program `advanced_calculator`. Program ten powinien posiadać pętle główną, która będzie przyjmować dane od użytkownika, np. dla `5 % 3` zwrócić wynik `2`. Wszystkie komendy kalkulatora powinny być przechowywane w mapie, która jako klucz `char` w postaci znaku odwołującego się do komendy (np. `+` -> dodaj , `%` -> modulo), a jej wartością powinna być funkcja `std::function<>` będąca wraperem na wyrażenia lambda dokonujące określonej kalkulacji. Program powinien także zwracać odpowiedni error code, jeżeli użytkownik poda złe dane np. dzielenie przez 0 lub spróbuje dodać `ala + 5`. Input: `5 + 5` -> operacja dodawania dwóch liczb 5 i 5 -> output: `10`. Input: `5 ^ 2` -> operacje potęgowania -> output: `25`. Input `125 $ 3` -> operacja pierwiastka (sqrt za długie), pierwiastek sześcienny z 125 -> output: `5`.

___

### Funkcje kalkulatora

* Dodawanie, mnożenie, dzielenie, odejmowanie, (`+`, `*`, `/`, `-`),
* Modulo (`%`),
* Obliczanie silni (`!`),
* Podnoszenie liczby do potęgi (`^`),
* Obliczanie pierwiastka (`$`).
  
___

### Error code

* Ok,
* BadCharacter -> Jeżeli użytkownik poda znak inny niż liczbę.
* BadFormat -> Jeżeli użytkownik poda zły format komendy np. + 5 4, powinno być 4 + 5.
* DivideBy0 -> dzielenie przez 0.
* SqrtOfNegativeNumber -> pierwiastek z liczby ujemnej.
* ModuleOfNonIntegerValue -> Próba obliczenia % na liczbie niecałkowitej.

___

### Funkcja, która będzie testowana

* `ErrorCode process(std::string input, double* out)`
* Funkcja ta powinna w pętli przyjmować kolejne dane od użytkownika oraz dokonywać odpowiedniej kalkulacji.
* Jeżeli dane są poprawne, zwróci `ErrorCode:Ok`, a w zmiennej `out` zapisze dane.
* Jeżeli wystąpi któryś z błędów, funkcja go zwróci a w `out` nie zapisze nic.
