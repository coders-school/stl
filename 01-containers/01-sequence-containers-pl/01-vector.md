<!-- .slide: data-background="#111111" -->

# `std::vector<T>`

## Tablica o dynamicznym rozmiarze

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Cechy `std::vector<T>`

* <!-- .element: class="fragment fade-in" --> Cache-friendly
  * <!-- .element: class="fragment fade-in" --> Elementy są ZAWSZE ułożone obok siebie w pamięci, tak jak w zwykłej tablicy
  * <!-- .element: class="fragment fade-in" --> Iterując po <code>std::vector&lt;T&gt;</code>, kolejne jego elementy będą ładowane do pamięci podręcznej procesora z wyprzedzeniem, co niesamowicie przyspieszy odczytywanie danych (oraz modyfikację, jeśli robimy to jednowątkowo)
* <!-- .element: class="fragment fade-in" --> Typ <code>T</code> może być dowolny. Zarówno typ wbudowany jak <code>int</code>, <code>double</code>, jak i własny zdefiniowany przez nas typ.
* <!-- .element: class="fragment fade-in" --> Dodawanie/usuwanie elementów na końcu jest:
  * szybkie jeśli `size() < capacity()`
  * kosztowne w przeciwnym przypadku, gdyż zachodzi alokacja dodatkowej pamięci na nowe elementy
* <!-- .element: class="fragment fade-in" --> Dodawanie/usuwanie z początku oraz środka jest kosztowne, gdyż należy przesunąć o 1 pozycję wszystkie kolejne elementy, aby zachować ciągłość wektora
* <!-- .element: class="fragment fade-in" --> W praktyce jednak pamięć cache tak bardzo przyspiesza pracę z <code>std::vector</code>, że nawet dodawanie/usuwanie elementów ze środka często będzie szybsze niż w innych kontenerach

___
<!-- .element: style="font-size: 0.6em" -->

## Operacje na `std::vector<T>`

| Operacja                                    | Metody                                                                                                                                                     |
| :------------------------------------------ | :--------------------------------------------------------------------------------------------------------------------------------------------------------- |
| dodawanie elementu                          | <!-- .element: class="fragment fade-in" --> <code>push_back()</code>, <code>emplace_back()</code>, <code>insert()</code>, <code>emplace()</code>           |
| modyfikowanie/dostęp do elementu            | <!-- .element: class="fragment fade-in" --> <code class="fragment highlight-green">at()</code>, <code class="fragment highlight-green">operator[]</code>   |
| pierwszy/ostatni element                    | <!-- .element: class="fragment fade-in" --> <code>back()</code>, <code>front()</code>                                                                      |
| rozmiar                                     | <!-- .element: class="fragment fade-in" --> <code>size()</code>                                                                                            |
| zarezerwowane miejsce                       | <!-- .element: class="fragment fade-in" --> <code class="fragment highlight-green">capacity()</code>                                                       |
| rezerwowanie miejsca w pamięci              | <!-- .element: class="fragment fade-in" --> <code class="fragment highlight-green">reserve()</code>                                                        |
| wyczyszczenie nieużywanej pamięci z wektora | <!-- .element: class="fragment fade-in" --> <code class="fragment highlight-green">shrink_to_fit()</code>                                                  |
| odwrócony (ang. reverse) iterator           | <!-- .element: class="fragment fade-in" --> <code>rbegin()</code>, <code>rend()</code>                                                                     |
| stały iterator                              | <!-- .element: class="fragment fade-in" --> <code>cbegin()</code>, <code>cend()</code>, <code>crbegin()</code>, <code>crend()</code>                       |
| wyczyszczenie kontenera                     | <!-- .element: class="fragment fade-in" --> <code>clear()</code>                                                                                           |
| przygotowanie elementu do usunięcia         | <!-- .element: class="fragment fade-in" --> <code class="fragment highlight-blue">std::remove()</code> (nie jest metodą <code>std::vector&lt;T&gt;</code>) |
| wymazanie elementów z pamięci               | <!-- .element: class="fragment fade-in" --> <code>erase()</code>                                                                                           |

___
<!-- .element: style="font-size: 0.9em" -->

## Wstawianie elementów na koniec

### `std::vector<T>::push_back()`
<!-- .element: class="fragment fade-in" -->

```cpp
void push_back( const T& value );
void push_back( T&& value );
```
<!-- .element: class="fragment fade-in" -->

### `std::vector<T>::emplace_back()`
<!-- .element: class="fragment fade-in" -->

```cpp
template< class... Args >
reference emplace_back( Args&&... args );
```
<!-- .element: class="fragment fade-in" -->

```cpp
struct Point2D {
    int x;
    int y;
};

std::vector<Point> vec{{1, 1}, {2, 0}, {-3, 10}};
vec.push_back({5, 2});
vec.emplace_back(5, 2);
```
<!-- .element: class="fragment fade-in" -->

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
vec.insert(vec.begin() + 2, list.begin(), list.end());
// vec = {1, 2, 10, 20, 30, 40, 3, 4}
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

Ponieważ najszybciej usuwane są elementy z końca wektora, biblioteka STL umożliwia nam przygotowanie `std::vector<T>` do usunięcia elementów poprzez przeniesienie tych nieprzeznaczonych do usunięcia na początek kontenera.
W wyniku tego część wartości do usunięcia jest nadpisywana wartościami z końca wektora, które nie powinny zostać usunięte.
Na końcu wektora pozostają "śmieci", które należy wymazać (ang. erase) z pamięci.
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
iterator erase( const_iterator first, const_iterator last );
```
<!-- .element: class="fragment fade-in" -->

Dzięki metodzie erase, możemy teraz usunąć niepotrzebne dane z kontenera:
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
* Stwórz nowy plik i napisz funkcję `main()`
* Stwórz wektor o wartościach `{1, 2, 4, 5, 6}`
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
* Stwórz nowy plik i napisz funkcję `main()`
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
