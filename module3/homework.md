<!-- .slide: data-background="#111111" -->

# Zadanie domowe

___

## Zadanie 1

Wykorzystując `std::inner_product`, napisz program, który obliczy średnią arytmetyczną dwóch `std::vector<int>`.

Input: `{1, 2, 3, 4}` `{1, 2, 3, 4}`
<!-- .element: class="fragment fade-in" -->

Output: `2.5`
<!-- .element: class="fragment fade-in" -->

___

## Zadanie 1 #2

Następnie wykorzystując `std::inner_product`, napisz funkcję, która obliczy odległość między 2 punktami dla n wymiarów.

Metrykę euklidesową w przestrzeni definiujemy:
<!-- .element: class="fragment fade-in" -->

```tex
{\displaystyle \mathbb {R} ^{n}}{\mathbb  R}^{n}

{\displaystyle d_{e}(\mathbf {x} ,\mathbf {y} )={\sqrt {(y_{1}-x_{1})^{2}+\dots +(y_{n}-x_{n})^{2}}},}d_e(\mathbf x, \mathbf y) = \sqrt{(y_1 - x_1)^2 + \dots + (y_n - x_n)^2},
```
<!-- .element: class="fragment fade-in" -->

Input: `{7, 4, 3}` `{17, 6, 2}`
<!-- .element: class="fragment fade-in" -->

Output: `10.247`
<!-- .element: class="fragment fade-in" -->

___

## Zadanie 2

Napisz program `advanced_calculator`. Program ten powinien posiadać pętle główną, która będzie przyjmować dane od użytkownika. Wszystkie komendy kalkulatora powinny być przechowywane w mapie, która ma klucz `char` w postaci znaku odwołującego się do komendy (np. `+` -> dodaj , `%` -> modulo), a jej wartością powinna być funkcja `std::function<>` będąca wraperem na wyrażenia lambda dokonujące określonej kalkulacji. Program powinien także zwracać odpowiedni error code, jeżeli użytkownik poda złe dane np. dzielenie przez 0 lub spróbuje dodać `ala + 5`.

Input: `5 + 5` -> operacja dodawania dwóch liczb 5 i 5 -> output: `10`.
<!-- .element: class="fragment fade-in" -->
Input: `5 ^ 2` -> operacje potęgowania -> output: `25`.
<!-- .element: class="fragment fade-in" -->
Input `125 $ 3` -> operacja pierwiastka (sqrt za długie), pierwiastek sześcienny z 125 -> output: `5`.
<!-- .element: class="fragment fade-in" -->
___

### Funkcje kalkulatora

* <!-- .element: class="fragment fade-in" --> Dodawanie, mnożenie, dzielenie, odejmowanie, (<code>+</code>, <code>*</code>, <code>/</code>, <code>-</code>),
* <!-- .element: class="fragment fade-in" --> Modulo (<code>%</code>),
* <!-- .element: class="fragment fade-in" --> Obliczanie silni (<code>!</code>),
* <!-- .element: class="fragment fade-in" --> Podnoszenie liczby do potęgi (<code>^</code>),
* <!-- .element: class="fragment fade-in" --> Obliczanie pierwiastka (<code>$</code>).
  
___

### Error code

* <!-- .element: class="fragment fade-in" --> <code>Ok</code>,
* <!-- .element: class="fragment fade-in" --> <code>BadCharacter</code> -> Jeżeli użytkownik poda znak inny niż liczbę.
* <!-- .element: class="fragment fade-in" --> <code>BadFormat</code> -> Jeżeli użytkownik poda zły format komendy np. + 5 4, powinno być 4 + 5.
* <!-- .element: class="fragment fade-in" --> <code>DivideBy0</code> -> dzielenie przez 0.
* <!-- .element: class="fragment fade-in" --> <code>SqrtOfNegativeNumber</code> -> pierwiastek z liczby ujemnej.
* <!-- .element: class="fragment fade-in" --> <code>ModuleOfNonIntegerValue</code> -> Próba obliczenia % na liczbie niecałkowitej.

___

### Funkcja, która będzie testowana

* `ErrorCode process(std::string input, double* out)`
* Funkcja ta powinna w pętli przyjmować kolejne dane od użytkownika oraz dokonywać odpowiedniej kalkulacji.
* Jeżeli dane są poprawne, zwróci `ErrorCode:Ok`, a w zmiennej `out` zapisze dane.
* Jeżeli wystąpi któryś z błędów, funkcja go zwróci, a w `out` nie zapisze nic.
