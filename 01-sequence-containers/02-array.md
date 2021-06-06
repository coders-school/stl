<!-- .slide: data-background="#111111" -->

# `std::array<T, N>`

## Tablica o stałym rozmiarze

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Cechy `std::array<T, N>`

* <!-- .element: class="fragment fade-in" --> Cache-friendly
  * <!-- .element: class="fragment fade-in" --> Elementy są ułożone obok siebie w pamięci, tak jak w zwykłej tablicy
  * <!-- .element: class="fragment fade-in" --> Iterując po <code>std::array&lt;T, N&gt;</code>, kolejne jego elementy będą ładowane do pamięci podręcznej procesora z wyprzedzeniem, co niesamowicie przyspieszy odczytywanie danych
* <!-- .element: class="fragment fade-in" --> Typ <code>T</code> może być dowolny. Zarówno typ wbudowany jak <code>int</code>, <code>double</code>, jak i własny zdefiniowany przez nas typ
* <!-- .element: class="fragment fade-in" --> Typ <code>N</code> oznacza rozmiar tablicy, który musi być znany już w czasie kompilacji
* <!-- .element: class="fragment fade-in" --> <code>std::array</code> jest najprymitywniejszym <code>wrapperem</code> na zwykłe tablice, używanie jej jest praktycznie tak samo wydajne
* <!-- .element: class="fragment fade-in" --> Rozmiar się nie zmienia, więc:
  * <!-- .element: class="fragment fade-in" --> nie możemy dodawać nowych elementów
  * <!-- .element: class="fragment fade-in" --> nie możemy usunąć istniejących elementów
  * <!-- .element: class="fragment fade-in" --> możemy dokonać modyfikacji istniejących elementów

___
<!-- .element: style="font-size: 0.65em" -->

## Operacje na `std::array<T, N>`

| Operacja                            | Metody                                                                                                                                                                |
| :---------------------------------- | :-------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| dodawanie elementu                  | <!-- .element: class="fragment fade-in" -->  <span class="fragment highlight-red">nie da się</span>                                                                   |
| modyfikacja/dostęp do elementu      | <!-- .element: class="fragment fade-in" -->  <code class="fragment highlight-green">at()</code>, <code class="fragment highlight-green">operator[]</code>             |
| pierwszy/ostatni element            | <!-- .element: class="fragment fade-in" -->  <code>back()</code>, <code>front()</code>                                                                                |
| rozmiar                             | <!-- .element: class="fragment fade-in" -->  <code>size()</code>                                                                                                      |
| odwrócony (ang. reverse) iterator   | <!-- .element: class="fragment fade-in" -->  <code>rbegin()</code>, <code>rend()</code>                                                                               |
| stały iterator                      | <!-- .element: class="fragment fade-in" -->  <code>cbegin()</code>, <code>cend()</code>, <code>crbegin()</code>, <code>crend()</code>                                 |
| wyczyszczenie kontenera             | <!-- .element: class="fragment fade-in" -->  <span class="fragment highlight-red">nie da się</span>, można użyć <code>fill()</code>, aby wyzerować wszystkie elementy |
| przygotowanie elementu do usunięcia | <!-- .element: class="fragment fade-in" -->  <span class="fragment highlight-red">nie da się</span>                                                                   |
| wymazanie elementów z pamięci       | <!-- .element: class="fragment fade-in" -->  <span class="fragment highlight-red">nie da się</span>                                                                   |

___

### Przekazanie `std::array<T, N>` do funkcji

Ponieważ `std::array<T, N>` ma 2 parametry szablonowe, niektórzy mogą mieć problem przy przekazywaniu jej do funkcji, gdyż pisząc `std::array<T>` zapominają o rozmiarze tablicy.
<!-- .element: class="fragment fade-in" -->

```cpp
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

## Zadanie 1

* Pomyśl, kiedy `empty()` może zwrócić `true` dla `std::array`
* Znajdź dokumentację funkcji `empty()` dla `std::array` na [cppreference.com](https://en.cppreference.com)
* Przejdź do sekcji Example i kliknij Run przy przykładzie z kodem
* Dopisz nową tablicę intów o rozmiarze 3 i nazwie `other` bez przypisywania jej elementów - `std::array<int, 3> other;`
* Dodaj kod odpowiedzialny za wyświetlenie informacji czy ta tablica jest pusta.
* Zweryfikuj to ze swoją intuicją z pierwszego punktu 🙂
* Wypisz zawartość tablicy `other`
* Zmień kompilator np. na clang i zobacz czy zawartość jest ta sama

___

## Zadanie 2

* Znajdź dokumentację `std::array` na [cppreference.com](https://en.cppreference.com)
* Stwórz nowy plik i napisz funkcję `main()`
* Stwórz `std::array` przechowujący wartości całkowitoliczbowe o rozmiarze 10
* Wypełnij ją wartościami 5
* Do czwartego elementu przypisz wartość 3
* Stwórz inną tablicę o tym samym rozmiarze
* Podmień tablice
* Wypisz obie tablice, każdą w osobnej linii

___

## Q&A
