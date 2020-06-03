<!-- .slide: data-background="#111111" -->

# `std::forward_list<T>`

## Lista jednokierunkowa

<a href="https://coders.school">
    <img width="500" data-src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Cechy `std::forward_list<T>`

* <!-- .element: class="fragment fade-in" --> Elementy porozrzucane po pamięci
* <!-- .element: class="fragment fade-in" --> Każdy element (węzeł -> ang. node) posiada wskaźnik na następny element
* <!-- .element: class="fragment fade-in" --> Typ <code>&lt;T&gt;</code> może być dowolny. Zarówno typ wbudowany jak <code>int</code>, <code>double</code>, jak i własny zdefiniowany przez nas typ.
* <!-- .element: class="fragment fade-in" --> Nie jest cache-friendly
* <!-- .element: class="fragment fade-in" --> Dodawanie nowego elementu jest proste. Program zaalokuje potrzebną pamięć dla węzła i przekaże poprzedniemu węzłowi (o ile istnieje) informacje o swoim położeniu.
* <!-- .element: class="fragment fade-in" --> Usuwanie elementu jest szybkie, program zwalnia pamięć zaalokowaną dla danego węzła oraz informuje o tym poprzedni węzeł, aby mógł zmienić swój wskaźnik.
* <!-- .element: class="fragment fade-in" --> Wyszukiwanie węzła jest już kosztowne, gdyż musimy się przeiterować kolejno przez wszystkie węzły, aż odnajdziemy poszukiwany (nawet, jeżeli dokładnie wiemy, że jest on np. 40-tym elementem listy)

___
<!-- .slide: style="font-size: 0.9em" -->

### Operacje na `std::forward_list<T>`

* <!-- .element: class="fragment fade-in" --> dodawanie elementu: <code>push_front()</code>, <code>emplace_front()</code>, <code>insert_after()</code>, <code>emplace_after()</code>
* <!-- .element: class="fragment fade-in" --> modyfikowanie/dostęp do elementu: należy samodzielnie odnaleźć element
* <!-- .element: class="fragment fade-in" --> pierwszy/ostatni element: <code>front()</code>
* <!-- .element: class="fragment fade-in" --> rozmiar/czy kontener jest pusty: nie mamy <code>size()</code>, dostępny jest tylko <code>empty()</code>
* <!-- .element: class="fragment fade-in" --> iterator początku/końca: <code>begin()</code>, <code>end()</code>
* <!-- .element: class="fragment fade-in" --> iterator wskazujący element przed <code>begin()</code>: <code>before_begin()</code>
* <!-- .element: class="fragment fade-in" --> stały iterator: <code>cbegin()</code>, <code>cend()</code>, <code>cbefore_begin()</code>
* <!-- .element: class="fragment fade-in" --> wyczyszczenie kontenera: <code>clear()</code>
* <!-- .element: class="fragment fade-in" --> posortowanie listy: <code>sort()</code>
* <!-- .element: class="fragment fade-in" --> odwrócenie listy: <code>reverse()</code>
* <!-- .element: class="fragment fade-in" --> usunięcie duplikatów: <code>unique()</code>
* <!-- .element: class="fragment fade-in" --> przygotowanie elementu do usunięcia: <code>remove()</code>
* <!-- .element: class="fragment fade-in" --> wymazanie elementów z pamięci: <code>erase_after()</code>
* <!-- .element: class="fragment fade-in" --> wymazanie elementów z pamięci używając <code>&lt;algorithm&gt;</code>: <code>erase()</code>
* <!-- .element: class="fragment fade-in" --> podmiana całego kontenera: <code>swap()</code>

___

## `std::forward_list<T>::insert_after()` && `std::forward_list<T>::before_begin()`
<!-- .element: style="font-size: 1.2em" -->

Lista jednokierunkowa (ang. singly linked list) umożliwia nam wstawianie elementu za konkretnym węzłem.
Jeżeli chcemy wstawić wartość na początku listy używając metody `insert_after`, musimy podać jej specjalny iterator `before_begin`, który wskazuje element przed pierwszym węzłem listy.
W ten sposób, metoda `insert_after()` wstawi pożądaną przez na wartość dokładnie jako pierwszy element listy.
<!-- .element: class="fragment fade-in" -->

```cpp
std::forward_list<int> list {1, 2, 3, 4, 5, 6};
list.insert_after(list.begin(), 10);
print(list);
list.insert_after(list.before_begin(), 0);
print(list);
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```cpp
1 10 2 3 4 5 6
0 1 10 2 3 4 5 6
```
<!-- .element: class="fragment fade-in" -->

___

## `std::forward_list<T>::remove()`

Ponieważ lista zawiera swoją metodę `remove()`, nie musimy już korzystać z `erase()`.
<!-- .element: class="fragment fade-in" -->

```cpp
std::forward_list<int> list {1, 4, 2, 4, 3, 4, 5};
list.remove(4);
// {1, 2, 3, 5}
```
<!-- .element: class="fragment fade-in" -->

___

## `std::forward_list<T>::erase_after()`
<!-- .element: style="font-size: 1.3em" -->

Erase_after służy do usunięcia węzłów od miejsca za elementem wskazanym przez pierwszy iterator do momentu wskazanego przez drugi iterator (bez elementu wskazywanego przez niego).
<!-- .element: class="fragment fade-in" -->

```cpp
std::forward_list<int> list {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
auto it = list.begin();
std::advance(it, 4);
std::cout << "it: " << *it << std::endl;
auto it2 = list.begin();
std::advance(it2, 7);
std::cout << "it2: " << *it2 << std::endl;
list.erase_after(it, it2);
print(list);
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```cpp
it: 5
it2: 8
1 2 3 4 5 8 9 10
```
<!-- .element: class="fragment fade-in" -->

___

## Zadanie 5

* Znajdź dokumentację `std::forward_list` na [cppreference.com](https://en.cppreference.com)
* Skorzystaj z kodu z zadania z `std::list`
* Stwórz listę jednokierunkową zawierającą elementy od 0 do 5
* Wyświetl listę
* Usuń 3 element z listy
* Dodaj na początek i koniec listy wartość 10
* Wyświetl listę
* Dodaj na czwartej pozycji liczbę 20
* Wyświetl listę

___

## Q&A
