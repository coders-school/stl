<!-- .slide: data-background="#111111" -->

# `std::array<T, N>`

## Tablica o stałym rozmiarze

<a href="https://coders.school">
    <img width="500" data-src="../img/coders_school_logo.png" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Cechy `std::array<T, N>`

* <!-- .element: class="fragment fade-in" --> Cache-friendly, tzn. iterując po <code>std::array&lt;T, N&gt;</code>, zostanie on cały załadowany do pamięci podręcznej procesora, co przyspieszy odczytywanie danych
* <!-- .element: class="fragment fade-in" --> Typ <code>&lt;T&gt;</code> może być dowolny. Zarówno typ wbudowany jak <code>int</code>, <code>double</code>, jak i własny zdefiniowany przez nas typ
* <!-- .element: class="fragment fade-in" --> Typ <code>&lt;N&gt;</code> oznacza rozmiar tablicy, który musi być znany już w czasie kompilacji
* <!-- .element: class="fragment fade-in" --> Elementy są ułożone obok siebie w pamięci, tak jak w zwykłej tablicy
* <!-- .element: class="fragment fade-in" --> <code>std::array</code> jest najprymitywniejszym <code>wrapperem</code> na zwykłe tablice, używanie jej jest praktycznie tak samo wydajne
* <!-- .element: class="fragment fade-in" --> Nie możemy dodać nowego elementu, możemy jedynie dokonać modyfikacji już istniejących pól
* <!-- .element: class="fragment fade-in" --> Odczyt oraz modyfikacja elementów jest bardzo szybka
* <!-- .element: class="fragment fade-in" --> Tak jak nie możemy dodać elementów, tak też nie możemy ich usunąć (rozmiar się nie zmienia)

___

## Operacje na `std::array<T, N>`

* <!-- .element: class="fragment fade-in" --> dodawanie elementu: nie da się
* <!-- .element: class="fragment fade-in" --> modyfikowanie/dostęp do elementu: <code>at()</code>, <code>operator[]</code>
* <!-- .element: class="fragment fade-in" --> pierwszy/ostatni element: <code>back()</code>, <code>front()</code>
* <!-- .element: class="fragment fade-in" --> rozmiar/czy kontener jest pusty: <code>size()</code>, <code>empty()</code>
* <!-- .element: class="fragment fade-in" --> iterator początku/końca: <code>begin()</code>, <code>end()</code>
* <!-- .element: class="fragment fade-in" --> odwrócony (ang. reverse) iterator: <code>rbegin()</code>, <code>rend()</code>
* <!-- .element: class="fragment fade-in" --> stały iterator: <code>cbegin()</code>, <code>cend()</code>, <code>crbegin()</code>, <code>crend()</code>
* <!-- .element: class="fragment fade-in" --> wyczyszczenie kontenera: nie da się, jednak mamy metodę <code>fill</code>, którą możemy np. wyzerować wszystkie elementy
* <!-- .element: class="fragment fade-in" --> przygotowanie elementu do usunięcia: nie da się
* <!-- .element: class="fragment fade-in" --> wymazanie elementów z pamięci: nie da się
* <!-- .element: class="fragment fade-in" --> podmiana całego kontenera: <code>swap()</code>

___

### Przekazanie `std::array<T, N>` do funkcji

Ponieważ `std::array<T, N>` ma 2 parametry szablonu, niektórzy mogą mieć problem przy przekazywaniu jej do funkcji, gdyż pisząc `std::array<T>` zapominając o rozmiarze tablicy.
<!-- .element: class="fragment fade-in" -->

```cpp []
void print(const std::array<int, 10>& arr) {
    for (const auto& el : arr) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::array<int, 10> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print(arr);

    return 0;
}
```
<!-- .element: class="fragment fade-in" -->

___

## Zadanie

* Znajdź dokumentację `std::array` na [cppreference.com](https://en.cppreference.com)
* Stwórz nowy plik cpp i napisz funkcję `main()`
* Stwórz `std::array` o rozmiarze 10
* Wypełnij ją wartościami 5
* Do czwartego elementu przypisz wartość 3
* Stwórz inną tablicę o tym samym rozmiarze
* Podmień tablice
* Wypisz obie tablice, każdą w osobnej linii

___

## Q&A
