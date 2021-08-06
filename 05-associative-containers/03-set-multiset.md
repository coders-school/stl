<!-- .slide: data-background="#111111" -->

# `set`, `multiset`

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Cechy `std::set<K>`, `std::multiset<K>`

* <!-- .element: class="fragment fade-in" --> Te same co w <code>std::map&lt;K, V&gt;</code> i <code>std::multimap&lt;K, V&gt;</code>
* <!-- .element: class="fragment fade-in" --> Jedyna różnica jest taka, że <code>set</code> i <code>multiset</code> przechowują tylko klucze (a nie pary klucz-wartość)
* <!-- .element: class="fragment fade-in" --> Idealne, gdy chcesz mieć zawsze posortowane elementy

Jeśli nie ma potrzeby, aby elementy były zawsze posortowane, to lepszym wyborem może być `std::vector<T>`. Można go posortować tylko wtedy gdy jest to potrzebne za pomocą algorytmu `std::sort()`
<!-- .element: class="fragment fade-in" -->

Jeśli zależy nam na braku duplikatów możemy też wtedy użyć algorytmu `std::unique()`.
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: data-background="../img/associative_containers.png" data-background-size="contain" -->

<div data-id="box2" style="height: 600px; background: #363232; opacity: 0.9; margin-top: 230px"></div>

___

## Metody `std::set<K>` i `std::multiset<K>` #1

[`std::set<K, T>` on cppreference.org](https://en.cppreference.com/w/cpp/container/set)

[`std::multiset<K, T>` on cppreference.org](https://en.cppreference.com/w/cpp/container/multiset)

* <!-- .element: class="fragment fade-in" --> dodawanie elementu: <code>insert()</code>, <code>emplace()</code>, <code class="fragment highlight-green">emplace_hint()</code>
* <!-- .element: class="fragment fade-in" --> modyfikowanie/dostęp do elementu: <span class="fragment highlight-red">przez iteratory</span>
* <!-- .element: class="fragment fade-in" --> rozmiar/pusty: <code>size()</code>, <code>empty()</code>
* <!-- .element: class="fragment fade-in" --> wyczyszczenie nieużywanej pamięci: <span class="fragment highlight-red">brak</span>
* <!-- .element: class="fragment fade-in" --> pierwszy/ostatni element: <span class="fragment highlight-red">brak</span>

___

## Metody `std::set<K>` i `std::multiset<K>` #2

* <!-- .element: class="fragment fade-in" --> odwrócony (ang. reverse) iterator: <code>rbegin()</code>, <code>rend()</code>
* <!-- .element: class="fragment fade-in" --> stały iterator: <code>cbegin()</code>, <code>cend()</code>, <code>crbegin()</code>, <code>crend()</code>
* <!-- .element: class="fragment fade-in" --> wyczyszczenie kontenera: <code>clear()</code>
* <!-- .element: class="fragment fade-in" --> przygotowanie do usunięcia: <span class="fragment highlight-red">brak</span>
* <!-- .element: class="fragment fade-in" --> wymazanie elementów z pamięci: <code>erase()</code>
* <!-- .element: class="fragment fade-in" --> podmiana całego kontenera: <code>swap()</code>
* <!-- .element: class="fragment fade-in" --> zliczenie elementów: <code>count()</code> (dla <code>set</code> zwraca tylko 0 albo 1, dla <code>multiset</code> liczbę od 0 do <code>size()</code>)
* <!-- .element: class="fragment fade-in" --> odnalezienie elementu o podanym kluczu: <code>find()</code>
* <!-- .element: class="fragment fade-in" --> czy klucz istnieje (C++20): <code class="fragment highlight-green">contains()</code>

___

## Złożoność operacji

* <!-- .element: class="fragment fade-in" --> Wstawianie/usuwanie
  * <!-- .element: class="fragment fade-in" --> <code>O(log n)</code>
* <!-- .element: class="fragment fade-in" --> Dostęp
  * <!-- .element: class="fragment fade-in" --> <code>O(log n)</code>
* <!-- .element: class="fragment fade-in" --> Wyszukiwanie
  * <!-- .element: class="fragment fade-in" --> <code>O(log n)</code>

___

## Zużycie pamięci

* <!-- .element: class="fragment fade-in" --> <code>n * (sizeof(K) + 2 * sizeof(X*))</code>
* <!-- .element: class="fragment fade-in" --> <code>O(n)</code>
* <!-- .element: class="fragment fade-in" --> Dodatkowe wewnętrzne dane: root, compare, allocator

___

## Unieważnienie iteratorów

* <!-- .element: class="fragment fade-in" --> Bidirectional Iterators
* <!-- .element: class="fragment fade-in" --> Dodawanie, usuwanie i przenoszenie elementów nie unieważnia iteratorów lub referencji
* <!-- .element: class="fragment fade-in" --> Iterator jest unieważniany tylko wtedy, gdy dany element jest usuwany

___

## Przykład użycia `std::set<K>`

```cpp []
std::vector<int> v = {5, 4, 3, 5, 2, 1, 1, 0, 6, 8, 7, 2};
std::set<int> set {v.begin(), v.end()};
for (const auto el : set) {
    std::cout << el << ' ';
}
std::cout << '\n';

std::set<int, std::greater<int>> set2 {v.begin(), v.end()};
for (const auto el : set2) {
    std::cout << el << ' ';
}
std::cout << '\n';
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```cpp
0 1 2 3 4 5 6 7 8
8 7 6 5 4 3 2 1 0
```
<!-- .element: class="fragment fade-in" -->

___

## Przykład użycia `std::multiset<K>`

```cpp
std::vector<int> v = {5, 4, 3, 2, 1, 0, 6, 8, 7, 1, 2, 3, 4, 5, 6};
std::multiset<int> set {v.begin(), v.end()};
for (const auto el : set) {
    std::cout << el << ' ';
}
std::cout << '\n';

std::multiset<int, std::greater<int>> set2 {v.begin(), v.end()};
for (const auto el : set2) {
    std::cout << el << ' ';
}
std::cout << '\n';
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```cpp
0 1 1 2 2 3 3 4 4 5 5 6 6 7 8
8 7 6 6 5 5 4 4 3 3 2 2 1 1 0
```
<!-- .element: class="fragment fade-in" -->

___

## Zadanie

1. Wygeneruj zbiór liczb od -20 do 20 i zapisz go w `std::set` w kolejności malejącej
2. Wstaw nowe elementy: `-10, 0, 10, 100, -100`
3. Wygeneruj drugi zbiór z liczb od 0 do 40 i zapisz go w `std::multiset`
4. Wstaw nowe elementy: `-10, 0, 10, 100, -100`
5. Połącz oba zbiory w jeden (ma to być `std::multiset`)
6. Znajdź wszystkie elementy równe `0` i `50`

Co każdy krok wypisuj zawartości kontenerów.
