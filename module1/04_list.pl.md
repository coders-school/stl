<!-- .slide: data-background="#111111" -->

# `std::list<T>`

## Lista dwukierunkowa

<a href="https://coders.school">
    <img width="500" data-src="../img/coders_school_logo.png" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Cechy `std::list<T>`

* <!-- .element: class="fragment fade-in" --> Elementy porozrzucane po pamięci
* <!-- .element: class="fragment fade-in" --> Każdy element (węzeł, ang. node) posiada wskaźnik na poprzedni i następny element
* <!-- .element: class="fragment fade-in" --> Typ <code>&lt;T&gt;</code> może być dowolny. Zarówno typ wbudowany jak <code>int</code>, <code>double</code>, jak i własny zdefiniowany przez nas typ
* <!-- .element: class="fragment fade-in" --> Nie jest cache-friendly
* <!-- .element: class="fragment fade-in" --> Dodawanie nowego elementu jest proste. Program zaalokuje potrzebną pamięć dla węzła i przekaże sąsiednim węzłom (o ile istnieją) informacje o swoim położeniu
* <!-- .element: class="fragment fade-in" --> Usuwanie elementu jest szybkie, program zwalnia pamięć zaalokowaną dla danego węzła oraz informuje o tym sąsiednie węzły, aby mogły zmienić swoje wskaźniki
* <!-- .element: class="fragment fade-in" --> Wyszukiwanie węzła (np. do usunięcia lub wstawienia za nim nowego elementu) jest już kosztowne, gdyż musimy się przeiterować kolejno przez wszystkie węzły, aż odnajdziemy poszukiwany (nawet, jeżeli dokładnie wiemy, że jest on np. 40-tym elementem listy)

___
<!-- .element: style="font-size: 0.9em" -->

## Operacje na `std::list<T>`

* <!-- .element: class="fragment fade-in" --> dodawanie elementu: <code>push_back()</code>, <code>emplace_back()</code>, <code>push_front()</code>, <code>emplace_front()</code>, <code>insert()</code>
* <!-- .element: class="fragment fade-in" --> modyfikowanie/dostęp do elementu: należy samodzielnie odnaleźć element
* <!-- .element: class="fragment fade-in" --> pierwszy/ostatni element: <code>back()</code>, <code>front()</code>
* <!-- .element: class="fragment fade-in" --> rozmiar/czy kontener jest pusty: <code>size()</code>, <code>empty()</code>
* <!-- .element: class="fragment fade-in" --> iterator początku/końca: <code>begin()</code>, <code>end()</code>
* <!-- .element: class="fragment fade-in" --> odwrócony (ang. reverse) iterator: <code>rbegin()</code>, <code>rend()</code>
* <!-- .element: class="fragment fade-in" --> stały iterator: <code>cbegin()</code>, <code>cend()</code>, <code>crbegin()</code>, <code>crend()</code>
* <!-- .element: class="fragment fade-in" --> wyczyszczenie kontenera: <code>clear()</code>
* <!-- .element: class="fragment fade-in" --> posortowanie listy: <code>sort()</code>
* <!-- .element: class="fragment fade-in" --> odwrócenie listy: <code>reverse()</code>
* <!-- .element: class="fragment fade-in" --> usunięcie duplikatów: <code>unique()</code>
* <!-- .element: class="fragment fade-in" --> usunięcie elementów z listy: <code>remove()</code>
* <!-- .element: class="fragment fade-in" --> wymazanie elementów z pamięci: <code>erase()</code>
* <!-- .element: class="fragment fade-in" --> podmiana całego kontenera: <code>swap()</code>

___

## `std::list<T>::remove()` && `std::list<T>::erase()`

Ponieważ lista zawiera swoją metodę `remove()`, nie musimy już korzystać z `erase()`.
<!-- .element: class="fragment fade-in" -->

```cpp []
std::list<int> list{1, 4, 2, 4, 3, 4, 5};
list.remove(4);
// list {1, 2, 3, 5}
```
<!-- .element: class="fragment fade-in" -->

`erase()` używamy podobnie jak dla `std::vector<T>`
<!-- .element: class="fragment fade-in" -->

```cpp []
std::list<int> list{1, 2, 3, 4, 5, 6, 7, 8};
auto it = list.begin();
std::advance(it, 3); // like on pointer ptr += 3
list.erase(list.begin(), it);
// list {4, 5, 6, 7, 8}
```
<!-- .element: class="fragment fade-in" -->

`std::advance()` służy do inkrementowania iteratorów. W naszym przypadku przesuwamy się o 3 elementy do przodu.
<!-- .element: class="fragment fade-in" -->

___

## Zadanie 4

* Znajdź dokumentację `std::list` na [cppreference.com](https://en.cppreference.com)
* Stwórz nowy plik cpp i napisz funkcję `main()`
* Stwórz listę zawierającą elementy od 0 do 5
* Wyświetl listę
* Usuń trzeci element z listy
* Dodaj na początek i koniec listy wartość 10
* Wyświetl listę
* Dodaj na czwartej pozycji liczbę 20
* Przepisz listę do `std::array`
* Wyświetl `std::array`

___

## Q&A
