<!-- .slide: data-background="#111111" -->

# `map`, `multimap`

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Cechy #1

### `std::map<K, V>`

### `std::multimap<K, V>`

* <!-- .element: class="fragment fade-in" --> Zazwyczaj zaimplementowane jako drzewa binarne (drzewa czerwono-czarne)
* <!-- .element: class="fragment fade-in" --> Nie są cache-friendly
* <!-- .element: class="fragment fade-in" --> Trzymają parę klucz-wartość
* <!-- .element: class="fragment fade-in" --> Są posortowane wg klucza

## Różnice
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>map</code> ma unikalne klucze
* <!-- .element: class="fragment fade-in" --> <code>multimap</code> pozwala duplikować klucze
* <!-- .element: class="fragment fade-in" --> Alternatywą dla <code>multimap</code> jest <code>std::map&lt;key, std::vector&lt;value&gt;&gt;</code>

___
<!-- .slide: data-background="../img/associative_containers.png" data-background-size="contain" -->

<div data-id="box1" style="height: 230px; background: #363232; opacity: 0.9; margin-bottom: 160px; margin-top: 0"></div>
<div data-id="box2" style="height: 400px; background: #363232; opacity: 0.9; margin-top: 0px"></div>

___

## Cechy #2

### `std::map<K, V>`

### `std::multimap<K, V>`

W drzewach czerwono-czarnych czas wstawiania, usuwania lub dodawania elementów jest **logarytmiczny `O(log n)`**.

Zalety:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> Szybkie wyszukiwanie elementów - kontenery sekwencyjne mają złożoność <code>O(n)</code>,
* <!-- .element: class="fragment fade-in" --> Dodawanie i usuwanie elementów jest stosunkowo tanie
  * <!-- .element: class="fragment fade-in" --> <code>std::vector&lt;T&gt;</code> - dodawanie elementów w środku ma złożoność <code>O(n)</code>
  * <!-- .element: class="fragment fade-in" --> <code>std::list&lt;T&gt;</code> jeśli posiadamy iterator, to dodawanie elementów ma złożoność <code>O(1)</code>
  * <!-- .element: class="fragment fade-in" --> Dlatego też mapy są stosunkowo szybkie zarówno przy wstawianiu i usuwaniu elementów
  * <!-- .element: class="fragment fade-in" --> Nie należy jednak pomijać znaczenia pamięci cache, która bardzo służy wektorowi
* <!-- .element: class="fragment fade-in" --> Są idealne gdy musimy CZĘSTO wyszukiwać dane i RZADKO dodawać lub usuwać elementy.

___
<!-- .slide: style="font-size: 0.95em" -->

## Cechy #3

### `std::map<K, V>`

### `std::multimap<K, V>`

Jeśli będziemy używać map gdy musimy często wstawiać lub usuwać elementy, to nie będą one optymalnym wyborem.
Powinniśmy używać map, jeśli chcemy przechowywać pary klucz-wartość i gdy będziemy często szukać danych.
<!-- .element: class="fragment fade-in" -->

Alternatywą dla `std::map<K, V>` jest `std::vector<pair<K, V>>`.
<!-- .element: class="fragment fade-in" -->

Alternatywą dla `std::multimap<K, V>` jest`std::vector<pair<K, std::vector<V>>>`.
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.6em" -->

## Metody `std::map<K, T>` i `std::multimap<K, T>`

[`std::map<K, T>` na cppreference.org](https://en.cppreference.com/w/cpp/container/map)

[`std::multimap<K, T>` na cppreference.org](https://en.cppreference.com/w/cpp/container/multimap)

| Operacja                                                | Metody                                                                                                                                                                                                                              |
| :------------------------------------------------------ | :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| dodawanie elementów                                     | <!-- .element: class="fragment fade-in" -->  <code>insert()</code>, <code>emplace()</code>, <code class="fragment highlight-green">emplace_hint()</code>                                                                            |
| dodawanie elementów (tylko <code>map</code>)            | <!-- .element: class="fragment fade-in" --> <code class="fragment highlight-green">insert_or_assign()</code>, <code class="fragment highlight-green">try_emplace()</code>, <code class="fragment highlight-green">operator[]</code> |
| modyfikacja/dostęp do elementu (tylko <code>map</code>) | <!-- .element: class="fragment fade-in" -->  <code class="fragment highlight-green">at()</code>, <code class="fragment highlight-green">operator[]</code>                                                                           |
| rozmiar/pusty                                           | <!-- .element: class="fragment fade-in" -->  <code>size()</code>, <code>empty()</code>                                                                                                                                              |
| wyczyszczenie nieużywanej pamięci                       | <!-- .element: class="fragment fade-in" -->  <span class="fragment highlight-red"><span class="fragment highlight-red">brak</span></span>                                                                                           |
| pierwszy/ostatni element                                | <!-- .element: class="fragment fade-in" -->  <span class="fragment highlight-red">brak</span>                                                                                                                                       |

___

## Metody `std::map<K, T>` i `std::multimap<K, T>` #2

* <!-- .element: class="fragment fade-in" --> reverse iterator: <code>rbegin()</code>, <code>rend()</code>
* <!-- .element: class="fragment fade-in" --> constant iterator: <code>cbegin()</code>, <code>cend()</code>, <code>crbegin()</code>, <code>crend()</code>
* <!-- .element: class="fragment fade-in" --> czyszczenie kontenera: <code>clear()</code>
* <!-- .element: class="fragment fade-in" --> przygotowanie do usunięcia: <span class="fragment highlight-red">brak</span>
* <!-- .element: class="fragment fade-in" --> usuwanie elementów: <code>erase()</code>
* <!-- .element: class="fragment fade-in" --> podmiana całego kontenera: <code>swap()</code>
* <!-- .element: class="fragment fade-in" --> zliczanie elementów: <code class="fragment highlight-green">count()</code> (zwraca tylko 0 lub 1 dla <code>map</code> lub liczbę od 0 do <code>size()</code> dla <code>multimap</code>)
* <!-- .element: class="fragment fade-in" --> szukanie elementu dla danego klucza: <code class="fragment highlight-green">find()</code>
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

* <!-- .element: class="fragment fade-in" --> <code>n * (sizeof(std::pair<K, T>) + 2 * sizeof(X*))</code>
* <!-- .element: class="fragment fade-in" --> <code>O(n)</code>
* <!-- .element: class="fragment fade-in" --> Dodatkowe wewnętrzne dane: root, compare, allocator

___

## Unieważnienie iteratorów

* <!-- .element: class="fragment fade-in" --> Bidirectional Iterators
* <!-- .element: class="fragment fade-in" --> Dodawanie, usuwanie i przenoszenie elementów nie unieważnia iteratorów lub referencji
* <!-- .element: class="fragment fade-in" --> Iterator jest unieważniany tylko wtedy, gdy dany element jest usuwany

___

## Przykład: `emplace_hint()`

```cpp []
int main() {
    std::map<int, std::string> map;

    auto it = map.begin();
    map.emplace_hint(it, 10, "Ten");

    std::cout << map[10] << '\n';
}
```
<!-- .element: class="fragment fade-in" -->

Output:
`Ten`
<!-- .element: class="fragment fade-in" -->

Podpowiadamy mapie miejsce, gdzie powinna wstawić element, dzięki temu taka operacja będzie miała złożoność `O(1)`. Podpowiedź to iterator, przed którym dany element powinien być wstawiony.
<!-- .element: class="fragment fade-in" -->

Gdy podany iterator jest niepoprawną wskazówką, to złożoność wstawianie jest `O(log n)`.
<!-- .element: class="fragment fade-in" -->

___

### Przykład: `insert_or_assign()`

```cpp
int main() {
    std::map<int, std::string> map;

    auto it = map.begin();
    map.insert_or_assign(it, 10, "Ten");
    std::cout << map[10] << '\n';
    map.insert_or_assign(it, 10, "Dziesiec");
    std::cout << map[10] << '\n';
    map[10] = "Cent";
    std::cout << map[10] << '\n';
}
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```cpp
Ten
Dziesiec
Cent
```
<!-- .element: class="fragment fade-in" -->

___

### Przykład: `count()`

```cpp
int main() {
    std::multimap<int, std::string> map;

    map.insert({5, "Five"});
    map.insert({5, "Funf"});
    map.insert({5, "Piec"});
    map.insert({5, "Cinq"});
    std::cout << map.count(5) << '\n';
}
```
<!-- .element: class="fragment fade-in" -->

Output: `4`
<!-- .element: class="fragment fade-in" -->

___

### Przykład: `find()`

```cpp
int main() {
    std::multimap<int, std::string> map;

    map.insert({5, "Five"});
    map.insert({5, "Funf"});
    map.insert({5, "Piec"});
    map.insert({5, "Cinq"});
    auto it = map.find(5);

    for (; it != map.end() ; ++it) {
        std::cout << it->first << " | " << it->second << '\n';
    }
}
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```cpp
5 | Five
5 | Funf
5 | Piec
5 | Cinq
```
<!-- .element: class="fragment fade-in" -->

___

## Zadanie

* <!-- .element: class="fragment fade-in" --> Stwórz multimapę i wypełnij ją podanymi wartościami

```cpp
map.insert({5, "Ala"});
map.insert({5, "Ma"});
map.insert({5, "Kota"});
map.insert({5, "A"});
map.insert({5, "Kot"});
map.insert({5, "Ma"});
map.insert({5, "Ale"});
```
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> Napisz funkcję, która wyświetli słowa w mapie o liczbie znaków równej 3.
