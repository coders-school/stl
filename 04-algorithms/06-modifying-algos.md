<!-- .slide: data-background="#111111" -->

# Algorytmy

## Modyfikujące sekwencje

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Algorytmy modyfikujące sekwencje

Modyfikują kontenery na których działają. Mogą:
<!-- .element: class="fragment fade-in" -->

* zmieniać kolejności elementów <!-- .element: class="fragment fade-in" -->
* usuwać elementy <!-- .element: class="fragment fade-in" -->
* dodawać elementy <!-- .element: class="fragment fade-in" -->

___
<!-- .element: style="font-size: 0.9em" -->
### Typy takich algorytmów

1. <!-- .element: class="fragment fade-in" --> Kopiowanie - <code>std::copy</code>, <code>std::copy_backward</code>
2. <!-- .element: class="fragment fade-in" --> Przenoszenie - <code>std::move</code>, <code>std::move_backward</code>
3. <!-- .element: class="fragment fade-in" --> Tworzenie elementów - <code>std::transform</code>, <code>std::generate</code>
4. <!-- .element: class="fragment fade-in" --> Usuwanie - <code>std::remove</code>
5. <!-- .element: class="fragment fade-in" --> Zamiana - <code>std::fill</code>, <code>std::replace</code>, <code>std::swap_ranges</code>, <code>std::iter_swap</code>
6. <!-- .element: class="fragment fade-in" --> Zmiana kolejności - <code>std::reverse</code>, <code>std::rotate</code>, <code>std::shift</code>, <code>std::shuffle</code>
7. <!-- .element: class="fragment fade-in" --> Próbkowanie - <code>std::sample</code>
8. <!-- .element: class="fragment fade-in" --> Usuwanie duplikatów - <code>std::unique</code>

___

### `std::transform`

```cpp
std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8};
std::list<int> list {10, 20, 30 , 40 , 50, 60, 70, 80};
std::transform(begin(vec),
               end(vec),
               begin(list),
               begin(vec),
               [](auto first, auto second) {
                   return first + second;
               });
// vec = {11, 22, 33, 44, 55, 66, 77, 88}
}
```
<!-- .element: class="fragment fade-in" -->

___
<!-- .element: style="font-size: 0.9em" -->

### `std::generate*`

```cpp
std::vector<int> vec(10);
std::generate(begin(vec), end(vec), [i{0}]() mutable { return i++; });
// vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
```
<!-- .element: class="fragment fade-in" -->

```cpp
std::mt19937 rng;
std::generate_n(std::ostream_iterator<std::mt19937::result_type>(std::cout, " "),
                5,
                std::ref(rng));
// Possible output: 3499211612 581869302 3890346734 3586334585 545404204
```
<!-- .element: class="fragment fade-in" -->

___

### `std::generate*` vs `std::transform`

* <!-- .element: class="fragment fade-in" --> <code>std::generate</code> generuje wartości "z niczego"
* <!-- .element: class="fragment fade-in" --> <code>std::transform</code> transformuje wartości z innego kontenera
* <!-- .element: class="fragment fade-in" --> Oba biorą funktor mówiący jak generować/transformować elementy
* <!-- .element: class="fragment fade-in" --> Aby wrzucać nowe elementy, użyj <code>std::back_inserter(v)</code> jako iterator docelowy
* <!-- .element: class="fragment fade-in" --> Możesz użyć <code>std::ostream_iterator<T>(std::cout, " ")</code> jako iterator docelowy, aby wyświetlić wynik na ekranie!

___

### Zadanie 💻

1. Utwórz poniższy wektor:

    ```cpp
    std::vector<std::pair<int, std::string>> v {
        {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}
    };
    ```
    <!-- .element: style="font-size: 0.55em" -->

2. Utwórz wektor intów `v2` i wypełnij go wszystkimi intami (pierwszymi elementami pary) z wektora `v`
3. Utwórz wektor stringów `v3` i wypełnij go konkatenacją string + dwukropek + int ze wszystkich par z wektora `v`
4. Utwórz wektor charów `v4` i wypełnij go co drugą literą alfabetu

___
<!-- .element: style="font-size: 0.9em" -->

### `std::reverse*`, `std::rotate*`, `std::shift*`

```cpp
int a[] = {4, 5, 6, 7};
std::reverse(std::begin(a), std::end(a));
// a = {7, 6, 5, 4};
```
<!-- .element: class="fragment fade-in" -->

```cpp
std::vector<int> v{2, 4, 2, 0, 5, 10, 7, 3, 7, 1};
std::rotate(v.begin(), v.begin() + 3, v.end());
// v = {0, 5, 10, 7, 3, 7, 1, 2, 4, 2}
```
<!-- .element: class="fragment fade-in" -->

```cpp
std::vector<std::string>  c{"a", "b", "c", "d", "e", "f", "g"};
std::shift_left(begin(c), end(c), 3);
// c = {"d", "e", "f", "g", "", "", ""}
std::shift_right(begin(c), end(c), 2);
// c = {"", "", "d", "e", "f", "g", ""}
```
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>std::reverse</code> odwraca kolejność elementów
* <!-- .element: class="fragment fade-in" --> <code>std::rotate</code> bierze 3 iteratory: first, middle, last. Po obrocie middle jest pierwszym elementem, a zakres [first, middle) jest na końcu.
* <!-- .element: class="fragment fade-in" --> <code>std::shift_left/std::shift_right</code> (C++20) przesuwa wszystkie elementy o N pozycji w lewo/prawo

___

### `std::shuffle`

```cpp
std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
std::random_device rd;
std::mt19937 g(rd());
std::shuffle(v.begin(), v.end(), g);
std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
```
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>std::shuffle</code> zmienia kolejność elementów używając dostarczonego generatora liczb losowych

___

### Zadanie 💻

1. Utwórz `std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};`
2. Usuń wszystkie duplikaty z `v`
3. Wypisz wszystkie elementy używając `std::copy` i `std::ostream_iterator`
4. Pomieszaj losowo wszystkie elementy
5. Wypisz je raz jeszcze
