<!-- .slide: data-background="#111111" -->

# Kontenery nieuporządkowane

## (hashujące)

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Cechy `std::unordered_set<K>` i `std::unordered_multiset<K>` #1

* <!-- .element: class="fragment fade-in" --> Zaimplementowane jako tablice hashujące.
* <!-- .element: class="fragment fade-in" --> Może, ale nie musi być cache friendly.
  * Hash table, często są tworzone w formie hybrydy <code>std::vector&lt;T&gt;</code> i <code>std::list&lt;T&gt;</code>.
* <!-- .element: class="fragment fade-in" --> Wartości nie są posortowane
* <!-- .element: class="fragment fade-in" --> <code>std::multiset</code> może mieć wiele takich samych wartości
* <!-- .element: class="fragment fade-in" --> <code>std::set</code> ma unikatowe wartości


___

## Cechy `std::unordered_set<K>` and `std::unordered_multiset<K>` #2

Implementacja jako hash table daje średni czas dodawania, usuwania, dostępu oraz modyfikacji `O(1)`. Najgorszy przypadek dla wszystkich operacji czas to `O(n)`.

Zalety:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> Bardzo szybkie przeszukiwanie
* <!-- .element: class="fragment fade-in" --> Stały czas dodawania i usuwania elementów...
* <!-- .element: class="fragment fade-in" --> Przy założeniu, że mamy dobrą funkcję skrótu
* <!-- .element: class="fragment fade-in" --> Doskonały dla kontenerów read-only. Czas odczytu <code>O(1)</code>.
* <!-- .element: class="fragment fade-in" --> Doskonały dla kontenerów mających dobrą funkcję mieszającą. Czas dodawania, dostępu i modyfikacji <code>O(1)</code>.

___

## Metody `std::unordered_set<K>` i `std::unordered_multiset<K>` #1

[`std::unordered_set<K>` on cppreference.org](https://en.cppreference.com/w/cpp/container/unordered_set)

[`std::unordered_multiset<K>` on cppreference.org](https://en.cppreference.com/w/cpp/container/unordered_multiset)

* <!-- .element: class="fragment fade-in" --> dodawanie elementu: <code>insert()</code>, <code>emplace()</code>, <code class="fragment highlight-green">emplace_hint()</code>
* <!-- .element: class="fragment fade-in" --> modyfikowanie/dostęp do elementu: <span class="fragment highlight-red">brak</span>
* <!-- .element: class="fragment fade-in" --> pierwszy/ostatni element: <span class="fragment highlight-red">brak</span>
* <!-- .element: class="fragment fade-in" --> rozmiar/pusty: <code>size()</code>, <code>empty()</code>
* <!-- .element: class="fragment fade-in" --> wyczyszczenie nieużywanej pamięci: <span class="fragment highlight-red">brak</span>
* <!-- .element: class="fragment fade-in" --> iterator początku/końca: <code>begin()</code>, <code>end()</code>
* <!-- .element: class="fragment fade-in" --> odwrócony iterator: <span class="fragment highlight-red">brak</span>

___

## Metody `std::unordered_set<K>` i `std::unordered_multiset<K>` #2

* <!-- .element: class="fragment fade-in" --> stały iterator: <code>cbegin()</code>, <code>cend()</code>
* <!-- .element: class="fragment fade-in" --> wyczyszczenie kontenera: <code>clear()</code>
* <!-- .element: class="fragment fade-in" --> przygotowanie elementu do usunięcia: <span class="fragment highlight-red">brak</span>
* <!-- .element: class="fragment fade-in" --> wymazanie elementów z pamięci: <code>erase()</code>
* <!-- .element: class="fragment fade-in" --> podmiana całego kontenera: <code>swap()</code>
* <!-- .element: class="fragment fade-in" --> zliczenie elementów: <code class="fragment highlight-green">count()</code> (zwraca 0 or 1 dla <code>unordered_set</code> lub od 0 do <code>size()</code> dla <code>std::unordered_multiset</code>)
* <!-- .element: class="fragment fade-in" --> szukanie elementu: <code class="fragment highlight-green">find()</code>

___

## Złożoność operacji

* <!-- .element: class="fragment fade-in" --> Wstawianie/usuwanie
  * <!-- .element: class="fragment fade-in" --> <code>O(1)</code> - średni przypadek
  * <!-- .element: class="fragment fade-in" --> <code>O(n)</code> - pesymistyczny przypadek
* <!-- .element: class="fragment fade-in" --> Dostęp
  * <!-- .element: class="fragment fade-in" --> <code>O(1)</code> - średni przypadek
  * <!-- .element: class="fragment fade-in" --> <code>O(n)</code> - pesymistyczny przypadek
* <!-- .element: class="fragment fade-in" --> Wyszukiwanie
  * <!-- .element: class="fragment fade-in" --> <code>O(1)</code> - średni przypadek
  * <!-- .element: class="fragment fade-in" --> <code>O(n)</code> - pesymistyczny przypadek

___

## Zużycie pamięci

* <!-- .element: class="fragment fade-in" --> <code>n * (sizeof(K) + sizeof(X*)) + n / bucket_size</code>
* <!-- .element: class="fragment fade-in" --> <code>O(n)</code>
* <!-- .element: class="fragment fade-in" --> Dodatkowa pamięć na wektor wskaźników (bucket list)
* <!-- .element: class="fragment fade-in" --> Dodatkowa pamięć na wewnętrzne dane (begin, end, size, hash, key_eq, allocator)

___

## Unieważnienie iteratorów

* Operacje odczytu, `swap`, `std::swap`: nigdy
* `clear()`, `rehash()`, `reserve()`, `operator=()`: zawsze
* `insert()`, `emplace()`, `emplace_hint()`, `operator[]()`: tylko gdy rehash
* `erase()`: tylko usunięty element

___

## Przykład `std::unordered_set<K>`

```cpp
std::unordered_set<std::string> set{"Ala", "Ma", "Kota",
                                    "A", "Kot", "Ma", "ALE"};
for (const auto el : set) {
    std::cout << el << ' ';
}
std::cout << '\n';
set.insert("Ala");
set.insert("Ala");
set.insert("Ala");
for (const auto el : set) {
    std::cout << el << ' ';
}
std::cout << '\n';
```
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: data-background="../img/associative_containers.png" data-background-size="contain" -->

<div data-id="box1" style="height: 390px; background: #363232; opacity: 0.9; margin-bottom: 160px; margin-top: 0"></div>
<div data-id="box2" style="height: 220px; background: #363232; opacity: 0.9; margin-top: 0px"></div>

___

## `unordered_map<K, T>` i `unordered_multimap<K, T>`

* <!-- .element: class="fragment fade-in" --> Odgadnij cechy
* <!-- .element: class="fragment fade-in" --> Odgadnij implementację 🙂

___
<!-- .slide: style="font-size: 0.85em" -->

## Zadanie

```cpp
struct Point {
  int x;
  int y;
}
```

Struktura `Point` ma reprezentować punkt o współrzędnych x i y na mapie.
Mamy też dane 4 miast:

* Wrocław (x = 17, y = 51)
* Moskwa (x = 37, y = 55)
* Nowy Jork (x = -74, y = 40)
* Sydney (x = 151, y = -33)

### Część A - łatwiejsza

* Stwórz `std::unordered_map<std::string, Point>`, która będzie przechowywać powyższe miejsca
* Sprawdź czy w mapie jest element, który znajduje się w promieniu 70 od środka układu współrzędnych (0, 0)
* Pobierz i wypisz współrzędne Sydney

___
<!-- .slide: style="font-size: 0.85em" -->

## Zadanie

```cpp
struct Point {
  int x;
  int y;
}
```

Struktura `Point` ma reprezentować punkt o współrzędnych x i y na mapie.
Mamy też dane 4 miast:

* Wrocław (x = 17, y = 51)
* Moskwa (x = 37, y = 55)
* Nowy Jork (x = -74, y = 40)
* Sydney (x = 151, y = -33)

### Część B - trudniejsza

* Stwórz `std::unordered_map<Point, std::string>`
* Sprawdź czy w odwróconej mapie jest element, który znajduje się w promieniu 70 od środka układu współrzędnych (0, 0)
* Pobierz i wypisz współrzędne Sydney
