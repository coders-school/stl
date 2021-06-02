<!-- .slide: data-background="#111111" -->

# `std::deque<T>`

## Kolejka dwustronna

### deque = double ended queue

<a href="https://coders.school">
    <img width="500" data-src="../img/coders_school_logo.png" src="../img/coders_school_logo.png"  alt="Coders School" class="plain">
</a>

___

## Cechy `std::deque<T>`

* <!-- .element: class="fragment fade-in" --> Hybryda listy oraz wektora
* <!-- .element: class="fragment fade-in" --> <code>deque</code> dzieli się na kawałki (ang. chunk), które są tablicami porozrzucanymi po pamięci
* <!-- .element: class="fragment fade-in" --> Rozmiar takiego kawałka zależy od kompilatora i implementacji biblioteki standardowej (nie ma jednej reguły)
* <!-- .element: class="fragment fade-in" --> Dodatkowo deque posiada jeszcze jeden wektor, który przechowuje wskaźniki wskazujące początek każdego <code>chunka</code> w pamięci.
* <!-- .element: class="fragment fade-in" --> W ten sposób zyskujemy 2 rzeczy:
  * Dodawanie nowego elementu jest szybsze, bo alokujemy co najwyżej pamięć dla jednego, całego `chunka` i nie będziemy przenosić elementów jak w `std::vector<T>`, gdy zabraknie nam miejsca na alokacje dodatkowej pamięci
  * Dane załadowane z jednego `chunka` są cache-friendly

___

## Struktura `std::deque<T>`

<img height="600" src="../img/deque-white.png" alt="deque" class="plain">

___

## Cechy `std::deque<T>` cd.

* <!-- .element: class="fragment fade-in" --> Częściowo cache-friendly, czyli poszczególne <code>chunki</code> znajdą się w pamięci podręcznej procesora
* <!-- .element: class="fragment fade-in" --> Typ <code>T</code> może być dowolny. Zarówno typ wbudowany jak <code>int</code>, <code>double</code>, jak i własny zdefiniowany przez nas typ
* <!-- .element: class="fragment fade-in" --> Każdy <code>chunk</code> jest reprezentowany w pamięci jak tablica, natomiast same <code>chunki</code> nie sąsiadują ze sobą i są porozrzucane jak węzły listy
* <!-- .element: class="fragment fade-in" --> Dodanie nowego elementu jest szybkie
  * Jeżeli dany `chunk` ma jeszcze miejsce to dopisujemy go na koniec
  * Jeżeli nie, to alokowany jest nowy chunk i tam wpisywany jest nowy element
* <!-- .element: class="fragment fade-in" --> Usuwanie z początku i końca jest szybkie, bo powoduje jedynie przesunięcie iteratorów <code>begin()</code> lub <code>end()</code>
* <!-- .element: class="fragment fade-in" --> Usuwanie elementów ze środka jest kosztowne
* <!-- .element: class="fragment fade-in" --> Odczyt i modyfikacja jest szybka
  * Znamy rozmiar `chunka`, więc wiemy dokładnie, z którego pola w naszym wektorze pomocniczym powinniśmy odczytać adres `chunka`
  * Wiemy także, z którego pola odczytać daną, gdyż `chunk` jest ułożony jak tablica.

___

## Dostęp do elementu

Matematycznie ujmując: jeżeli `chunk` ma 16 elementów a my chcemy dostać się do 100 elementu to:

* `x = 100 / 16 -> x = 6` (ucinamy część po przecinku)
* `y = 100 % 16 -> y = 4`

Zatem wiemy, że jest to 4-ty element w 6-tym `chunku`.
<!-- .element: class="fragment fade-in" -->

Ta wiedza jest zupełnie niepotrzebna przy użytkowaniu `std::deque`. Kontener zajmuje się tym automatycznie.
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.55em" -->

### Operacje na `std::deque<T>`

| Operacje                            | Metody                                                                                                                                                                                                                                                                      |
| :---------------------------------- | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| dodawanie elementu                  | <!-- .element: class="fragment fade-in" --> <code>push_back()</code>, <code>emplace_back()</code>, <code class="fragment highlight-green">push_front()</code>, <code class="fragment highlight-green">emplace_front()</code>, <code>insert()</code>, <code>emplace()</code> |
| modyfikowanie/dostęp do elementu    | <!-- .element: class="fragment fade-in" --> <code class="fragment highlight-green">at()</code>, <code class="fragment highlight-green">operator[]</code>                                                                                                                    |
| pierwszy/ostatni element            | <!-- .element: class="fragment fade-in" --> <code>back()</code>, <code>front()</code>                                                                                                                                                                                       |
| rozmiar                             | <!-- .element: class="fragment fade-in" --> <code>size()</code>                                                                                                                                                                                                             |
| wyczyszczenie nieużywanej pamięci   | <!-- .element: class="fragment fade-in" --> <code class="fragment highlight-green">**shrink_to_fit**()</code>,                                                                                                                                                                  |
| odwrócony (ang. reverse) iterator   | <!-- .element: class="fragment fade-in" --> <code>rbegin()</code>, <code>rend()</code>                                                                                                                                                                                      |
| stały iterator                      | <!-- .element: class="fragment fade-in" --> <code>cbegin()</code>, <code>cend()</code>, <code>crbegin()</code>, <code>crend()</code>                                                                                                                                        |
| wyczyszczenie kontenera             | <!-- .element: class="fragment fade-in" --> <code>clear()</code>                                                                                                                                                                                                            |
| przygotowanie elementu do usunięcia | <!-- .element: class="fragment fade-in" --> <code>remove()</code> (nie jest metodą <code>std::deque</code>),                                                                                                                                                                |
| wymazanie elementów z pamięci       | <!-- .element: class="fragment fade-in" --> <code>erase()</code>                                                                                                                                                                                                            |

___

### Przykład użycia

```cpp []
#include <iostream>
#include <deque>

int main() {
    std::deque<int> d = {7, 5, 16, 8};

    d.push_front(13);
    d.push_back(25);

    for(const auto& n : d) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}
```

Output:

`13 7 5 16 8 25`

___

## Zadanie

* Znajdź dokumentację `std::deque` na [cppreference.com](https://en.cppreference.com)
* Stwórz nowy plik i napisz funkcję `main()`
* Stwórz pusty `deque`
* Dodaj do niego 5 dowolnych wartości
* Wyświetl `deque`
* Usuń 2-gi i 4-ty element
* Dodaj na początek i koniec wartość 30
* Wyświetl `deque`
* Dodaj na 4 pozycji liczbę 20
* Wyświetl `deque`

___

## Q&A
