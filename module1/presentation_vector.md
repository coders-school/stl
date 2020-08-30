<!-- .slide: data-background="#111111" -->

# `std::vector<T>`

## Tablica o dynamicznym rozmiarze

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Cechy `std::vector<T>`

* <!-- .element: class="fragment fade-in" --> Cache-friendly, tzn. iterując po wektorze, zostanie on cały załadowany do pamięci podręcznej procesora, co przyspieszy odczytywanie danych.
* <!-- .element: class="fragment fade-in" --> Typ <code>&lt;T&gt;</code> może być dowolny. Zarówno typ wbudowany jak <code>int</code>, <code>double</code>, jak i własny zdefiniowany przez nas typ.
* <!-- .element: class="fragment fade-in" --> Elementy są ułożone obok siebie w pamięci, tak jak w zwykłej tablicy.
* <!-- .element: class="fragment fade-in" --> Dodawanie nowego elementu, gdy zajdzie zależność <code>vec.size() > vec.capacity()</code> spowoduje alokację dodatkowego miejsca w pamięci. W krytycznej sytuacji, gdy przy obecnym obszarze nie ma już miejsca na dodatkowe dane, cały wektor zostanie przeniesiony w inne miejsce w pamięci.
* <!-- .element: class="fragment fade-in" --> Usuwanie elementu z wektora jest szybkie, gdy usuwamy ostatni element, ale kosztowne, gdy usuwamy ze środka lub z początku.

___
<!-- .element: style="font-size: 0.9em" -->

## Operacje na `std::vector<T>`

* <!-- .element: class="fragment fade-in" --> dodawanie elementu: <code>push_back()</code>, <code>emplace_back()</code>, <code>insert()</code>
* <!-- .element: class="fragment fade-in" --> modyfikowanie/dostęp do elementu: <code>at()</code>, <code>operator []</code>
* <!-- .element: class="fragment fade-in" --> pierwszy/ostatni element: <code>back()</code>, <code>front()</code>
* <!-- .element: class="fragment fade-in" --> rozmiar/czy kontener jest pusty: <code>size()</code>, <code>empty()</code>
* <!-- .element: class="fragment fade-in" --> zarezerwowane miejsce: <code>capacity()</code>
* <!-- .element: class="fragment fade-in" --> rezerwowanie miejsca w pamięci: <code>reserve()</code>
* <!-- .element: class="fragment fade-in" --> wyczyszczenie nieużywanej pamięci z wektora: <code>shrink_to_fit()</code>
* <!-- .element: class="fragment fade-in" --> iterator początku/końca: <code>begin()</code>, <code>end()</code>
* <!-- .element: class="fragment fade-in" --> odwrócony (ang. reverse) iterator: <code>rbegin()</code>, <code>rend()</code>
* <!-- .element: class="fragment fade-in" --> stały iterator: <code>cbegin()</code>, <code>cend()</code>, <code>crbegin()</code>, <code>crend()</code>
* <!-- .element: class="fragment fade-in" --> wyczyszczenie kontenera: <code>clear()</code>
* <!-- .element: class="fragment fade-in" --> przygotowanie elementu do usunięcia: <code>remove()</code> (nie jest metodą <code>std::vector&lt;T&gt;</code>)
* <!-- .element: class="fragment fade-in" --> wymazanie elementów z pamięci: <code>erase()</code>
* <!-- .element: class="fragment fade-in" --> podmiana całego kontenera: <code>swap()</code>

___

## Wstawianie elementów #1

### `std::vector<T>::insert()`

```cpp
iterator insert( const_iterator pos, const T& value );
```
<!-- .element: class="fragment fade-in" -->

W celu dodania elementu do wektora, możemy wykorzystać iterator:
<!-- .element: class="fragment fade-in" -->

```cpp
std::vector<int> vec{1, 2, 3, 4};
auto it = vec.begin();
vec.insert(it, 20); // {20, 1, 2, 3, 4};
```
<!-- .element: class="fragment fade-in" -->

___

## Wstawianie elementów #2

### `std::vector<T>::insert()`

```cpp
iterator insert( const_iterator pos, size_type count, const T& value );
```
<!-- .element: class="fragment fade-in" -->

Możemy także określić ile elementów chcemy dodać:
<!-- .element: class="fragment fade-in" -->

```cpp
std::vector<int> vec{1, 2, 3, 4};
auto it = vec.begin();
vec.insert(it, 5, 20); // {20, 20, 20, 20, 20, 1, 2, 3, 4};
```
<!-- .element: class="fragment fade-in" -->

___

## Wstawianie elementów #3

### `std::vector<T>::insert()`

```cpp
template< class InputIt >
iterator insert( const_iterator pos, InputIt first, InputIt last );
```
<!-- .element: class="fragment fade-in" -->

Istnieje też możliwość wstawienia elementów z jednego kontenera do drugiego:
<!-- .element: class="fragment fade-in" -->

```cpp
std::vector<int> vec{1, 2, 3, 4};
std::list<int> list{10, 20, 30, 40};
vec.insert(vec.begin(), list.begin(), list.end());
// vec = {10, 20, 30, 40, 1, 2, 3, 4}
```
<!-- .element: class="fragment fade-in" -->

___

## Iterowanie od końca

### `std::vector<T>::rbegin()`, `std::vector<T>::rend()`
<!-- .element: style="font-size: 0.9em" -->

```cpp
std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
for (auto it = vec.crbegin() ; it != vec.crend() ; ++it) {
    // cr = (r)everse iterator to (c)onst value
    std::cout << *it << ' ';
}
```
<!-- .element: class="fragment fade-in" -->

Output: `9 8 7 6 5 4 3 2 1`
<!-- .element: class="fragment fade-in" -->

```cpp
std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
for (auto it = vec.rbegin() ; it != vec.rend() ; ++it) {
    *it *= 2;
}
for (auto it = vec.crbegin() ; it != vec.crend() ; ++it) {
    std::cout << *it << ' ';
}
```
<!-- .element: class="fragment fade-in" -->

Output: `18 16 14 12 10 8 6 4 2`
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.95em" -->

## (Prawie) usuwanie 😉

### `std::remove()` z nagłówka `<algorithm>`

```cpp
template< class ForwardIt, class T >
ForwardIt remove( ForwardIt first, ForwardIt last, const T& value );
```
<!-- .element: class="fragment fade-in" -->

Ponieważ najszybciej usuwane są elementy z końca wektora, biblioteka STL umożliwia nam przygotowanie `std::vector<T>` do usunięcia elementów poprzez przeniesienie tych poprawnych na początek kontenera.
W wyniku tego część wartości do usunięcia jest nadpisywana wartościami z końca wektora, które nie powinny zostać usunięte.
Dlatego na końcu wektora pozostają "śmieci", które należy wymazać (ang. erase) z pamięci.
<!-- .element: class="fragment fade-in" -->

```cpp
std::vector<int> vec{1, 4, 2, 4, 3, 4, 5};
std::remove(vec.begin(), vec.end(), 4);
// for example: vec {1, 2, 3, 5, 3, 4, 5}
```
<!-- .element: class="fragment fade-in" -->

`std::remove()` zwróci nam iterator, który wskaże początek danych przeznaczonych do usunięcia.
<!-- .element: class="fragment fade-in" -->

___

## Usuwanie

### `std::vector<T>::erase()`

```cpp
template< class T, class Alloc, class U >
constexpr typename std::vector<T,Alloc>::size_type
    erase(std::vector<T, Alloc>& c, const U& value);
```
<!-- .element: class="fragment fade-in" -->

Dzięki funkcji erase, możemy teraz usunąć niepotrzebne dane z kontenera:
<!-- .element: class="fragment fade-in" -->

```cpp
std::vector<int> vec{1, 4, 2, 4, 3, 4, 5};
auto it = std::remove(vec.begin(), vec.end(), 4);
vec.erase(it, vec.end());
// vec {1, 2, 3, 5}
```
<!-- .element: class="fragment fade-in" -->

Możemy też zapisać to wszystko w jednej linii (Erase-Remove Idiom)
<!-- .element: class="fragment fade-in" -->

```cpp
vec.erase(std::remove(vec.begin(), vec.end(), 4), vec.end());
```
<!-- .element: class="fragment fade-in" -->

___

## Zadanie 1

* [Otwórz dokumentację wektora na cppreference.com](https://en.cppreference.com/w/cpp/container/vector)
* Stwórz nowy plik cpp i napisz funkcję `main()`
* Stwórz wektor o wartościach { 1, 2, 4, 5, 6 }
* Usuń pierwszą wartość
* Dodaj wartość 5 na końcu wektora
* Dodaj wartość 12 na początku wektora metodą `emplace`
* Wypisz rozmiar wektora i maksymalny możliwy rozmiar
* Wypisz zawartość wektora
* Wyczyść wektor
* Wypisz rozmiar wektora

___

## Zadanie 2

* [Otwórz dokumentację wektora na cppreference.com](https://en.cppreference.com/w/cpp/container/vector)
* Stwórz nowy plik cpp i napisz funkcję `main()`
* Stwórz pusty wektor
* Wypisz rozmiar i pojemność wektora
* Zmień rozmiar wektora na 10 i wypełnij go wartościami 5
* Wypisz rozmiar i pojemność wektora
* Zarezerwuj pamięć na 20 elementów
* Wypisz rozmiar i pojemność wektora
* Zredukuj pojemność wektora metodą `shrink_to_fit()`
* Wypisz rozmiar i pojemność wektora

___

## Q&A
