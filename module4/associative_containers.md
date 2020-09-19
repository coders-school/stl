<!-- .slide: data-background="#111111" -->

# Kontenery asocjacyjne

___

## Posortowane

* <!-- .element: class="fragment fade-in" --> <code>set</code>
* <!-- .element: class="fragment fade-in" --> <code>multiset</code>
* <!-- .element: class="fragment fade-in" --> <code>map</code>
* <!-- .element: class="fragment fade-in" --> <code>multimap</code>

___

## Nieuporządkowane

* <!-- .element: class="fragment fade-in" --> <code>unordered_set</code>
* <!-- .element: class="fragment fade-in" --> <code>unordered_multiset</code>
* <!-- .element: class="fragment fade-in" --> <code>unordered_map</code>
* <!-- .element: class="fragment fade-in" --> <code>unordered_multimap</code>

___

## Quiz

Do czego możesz użyć:

* <!-- .element: class="fragment fade-in" --> <code>set</code>?
* <!-- .element: class="fragment fade-in" --> <code>multiset</code>?
* <!-- .element: class="fragment fade-in" --> <code>map</code>?
* <!-- .element: class="fragment fade-in" --> <code>multimap</code>?
* <!-- .element: class="fragment fade-in" --> <code>unordered_set</code>?
* <!-- .element: class="fragment fade-in" --> <code>unordered_multiset</code>?
* <!-- .element: class="fragment fade-in" --> <code>unordered_map</code>?
* <!-- .element: class="fragment fade-in" --> <code>unordered_multimap</code>?

___

## Notacja dużego `O`

<img src="img/bigO.png">

___

## Cechy `std::map<K, T>` i `std::multimap<K, T>` #1

* <!-- .element: class="fragment fade-in" --> Forma drzewa binarnego (red-black tree)
* <!-- .element: class="fragment fade-in" --> Nie jest cache friendly
* <!-- .element: class="fragment fade-in" --> Pozwala przechowywać parę klucz-wartość (key-value)
* <!-- .element: class="fragment fade-in" --> Multimapa może mieć wiele takich samych kluczy
* <!-- .element: class="fragment fade-in" --> Mapa ma unikatowe klucze
* <!-- .element: class="fragment fade-in" --> Alternatywą dla multimapy jest <code>std::map&lt;key, std::vector&lt;value&gt;&gt;</code>

___
<!-- .slide: style="font-size: 0.95em" -->

## Cechy `std::map<K, T>` i `std::multimap<K, T>` #2

Ponieważ jest ona zaimplementowana przeważnie jako red-black tree (GNU standard C++ library) to czas wstawiania, usuwania i dodawania elementu to `O(log(n)`).

Zalety:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> Szybkie wyszukiwanie elementów (kontenery sekwencyjnie <code>O(n)</code>),
* <!-- .element: class="fragment fade-in" --> Względnie szybki czas ich dodawania i usuwania np. <code>std::vector&lt;T&gt;</code> dodaje elementy w środku w czasie <code>O(n)</code>, ale <code>std::list&lt;T&gt;</code> (jeżeli mamy podany iterator) w czasie <code>O(1)</code>. Stąd mapa jest względnie szybka zarówno w dodawaniu jak i usuwaniu.
* <!-- .element: class="fragment fade-in" --> Idealna, gdy często poszukujemy danych, a rzadziej je dodajemy lub usuwamy.

Jeżeli będziemy jej używać jako zwykłego kontenera, to stracimy na wydajności. Mapę należy stosować wtedy, kiedy faktycznie chcemy posiadać pary klucz-wartość i często je wyszukiwać. W innym przypadku możemy użyć `std::vector<pair<K, V>>` lub innego kontenera.
<!-- .element: class="fragment fade-in" -->

___

## Operacje na `std::map<K, T>` i `std::multimap<K, T>`

* <!-- .element: class="fragment fade-in" --> dodawanie elementu: <code>insert()</code>, <code>emplace()</code>, <code>emplace_hint()</code>. Dodatkowo mapa posiada: <code>insert_or_assign()</code>, <code>try_emplace()</code> oraz <code>operator[]</code> (dodająco modyfikujący)
* <!-- .element: class="fragment fade-in" --> modyfikowanie/dostęp do elementu: <code>at()</code>, <code>operator[]</code> (Multimapa nie posiada takich opcji)
* <!-- .element: class="fragment fade-in" --> pierwszy/ostatni element: Brak
* <!-- .element: class="fragment fade-in" --> rozmiar/czy kontener jest pusty: <code>size()</code>, <code>empty()</code>
* <!-- .element: class="fragment fade-in" --> wyczyszczenie nieużywanej pamięci: Brak
* <!-- .element: class="fragment fade-in" --> iterator początku/końca: <code>begin()</code>, <code>end()</code>

<!-- znowu dużo contentu, ciacham na pół :) -->
___

## Operacje na `std::map<K, T>` i `std::multimap<K, T>` #2

* <!-- .element: class="fragment fade-in" --> odwrócony (ang. reverse) iterator: <code>rbegin()</code>, <code>rend()</code>
* <!-- .element: class="fragment fade-in" --> stały iterator: <code>cbegin()</code>, <code>cend()</code>, <code>crbegin()</code>, <code>crend()</code>
* <!-- .element: class="fragment fade-in" --> wyczyszczenie kontenera: <code>clear()</code>
* <!-- .element: class="fragment fade-in" --> przygotowanie elementu do usunięcia: Brak
* <!-- .element: class="fragment fade-in" --> wymazanie elementów z pamięci: <code>erase()</code>
* <!-- .element: class="fragment fade-in" --> podmiana całego kontenera: <code>swap()</code>
* <!-- .element: class="fragment fade-in" --> zliczenie elementów pasujących do danego klucza: <code>count()</code> (dla mapy to 0 albo 1, dla multimapy od 0 do n)
* <!-- .element: class="fragment fade-in" --> odnalezienie elementu o podanym kluczu: <code>find()</code>

___

## Przykład użycia `emplace_hint`

```cpp
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

Podpowiadamy mapie miejsce, gdzie powinna wstawić element, dzięki temu taka operacja będzie miała złożoność `O(1)`. Jeżeli jednak źle podpowiemy, to czas wstawienia będzie `O(log(n))`. Raczej rzadko stosowane 🙂
<!-- .element: class="fragment fade-in" -->

___

### Przykład użycia `insert_or_assign`

```C++
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

```C++
Ten
Dziesiec
Cent
```
<!-- .element: class="fragment fade-in" -->

___

### Przykład użycia `count`

```C++
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

### Przykład użycia `find`

```C++
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

```C++
5 | Five
5 | Funf
5 | Piec
5 | Cinq
```
<!-- .element: class="fragment fade-in" -->

___

## Zadanie 1

* <!-- .element: class="fragment fade-in" --> Stwórz multimapę i wypełnij ją podanymi wartościami

```C++
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

___

## Rozwiązanie

```C++
std::vector<std::pair<int, std::string>> result;
std::copy_if(it,
             end(map),
             std::back_inserter(result),
             [](const auto& pair) { return pair.second.size() == 3; });
std::for_each(begin(result),
              end(result),
              [](const auto& pair) { std::cout << pair.second << '\n'; });
```
<!-- .element: class="fragment fade-in" -->

___

## Cechy `std::set<T>` i `std::multiset<T>` #1

* <!-- .element: class="fragment fade-in" --> Forma drzewa binarnego (red-black tree)
* <!-- .element: class="fragment fade-in" --> Nie jest cache friendly
* <!-- .element: class="fragment fade-in" --> Pozwala przechowywać wartości w uporządkowanej kolejności
* <!-- .element: class="fragment fade-in" --> Multiset może mieć wiele takich samych wartości
* <!-- .element: class="fragment fade-in" --> Set ma unikatowe wartości
* <!-- .element: class="fragment fade-in" --> Alternatywą dla multiset jest posortowany <code>std::vector&lt;T&gt;</code>

___
<!-- .slide: style="font-size: 0.95em" -->

## Cechy `std::set<T>` i `std::multiset<T>` #2

Ponieważ jest on zaimplementowany przeważnie jako red-black tree (GNU standard C++ library) to czas wstawiania, usuwania i dodawania elementu to `O(log(n)`).

Zalety:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> Szybkie wyszukiwanie elementów (kontenery sekwencyjnie <code>O(n)</code>),
* <!-- .element: class="fragment fade-in" --> Względnie szybki czas ich dodawania i usuwania np. <code>std::vector&lt;T&gt;</code> dodaje elementy w środku w czasie <code>O(n)</code>, ale <code>std::list&lt;T&gt;</code> (jeżeli mamy podany iterator) w czasie <code>O(1)</code>. Stąd <code>set</code> jest względnie szybki zarówno w dodawaniu jak i usuwaniu.
* <!-- .element: class="fragment fade-in" --> Idealny, gdy chcemy zawsze posiadać posortowane wartości.

Jeżeli nie zależy nam, aby kontener był zawsze posortowany, lecz jedynie w specyficznych momentach, to może lepiej nam użyć `std::vector<T>` i sortować go, gdy przyjdzie taka potrzeba. Jeżeli też zależy nam tylko czasami na unikatowych wartościach, to możemy wtedy użyć `std::unique()`.
<!-- .element: class="fragment fade-in" -->

___

## Operacje na `std::set<T>` i `std::multiset<T>`

* <!-- .element: class="fragment fade-in" --> dodawanie elementu: <code>insert()</code>, <code>emplace()</code>, <code>emplace_hint()</code>
* <!-- .element: class="fragment fade-in" --> modyfikowanie/dostęp do elementu: Brak
* <!-- .element: class="fragment fade-in" --> pierwszy/ostatni element: Brak
* <!-- .element: class="fragment fade-in" --> rozmiar/czy kontener jest pusty: <code>size()</code>, <code>empty()</code>
* <!-- .element: class="fragment fade-in" --> wyczyszczenie nieużywanej pamięci: Brak
* <!-- .element: class="fragment fade-in" --> iterator początku/końca: <code>begin()</code>, <code>end()</code>
* <!-- .element: class="fragment fade-in" --> odwrócony (ang. reverse) iterator: <code>rbegin()</code>, <code>rend()</code>

<!-- ciacham -->
___

## Operacje na `std::set<T>` i `std::multiset<T>` #2

* <!-- .element: class="fragment fade-in" --> stały iterator: <code>cbegin()</code>, <code>cend()</code>, <code>crbegin()</code>, <code>crend()</code>
* <!-- .element: class="fragment fade-in" --> wyczyszczenie kontenera: <code>clear()</code>
* <!-- .element: class="fragment fade-in" --> przygotowanie elementu do usunięcia: Brak
* <!-- .element: class="fragment fade-in" --> wymazanie elementów z pamięci: <code>erase()</code>
* <!-- .element: class="fragment fade-in" --> podmiana całego kontenera: <code>swap()</code>
* <!-- .element: class="fragment fade-in" --> zliczenie elementów pasujących do danego klucza: <code>count()</code> (dla <code>set</code> to 0 albo 1, dla <code>multiset</code> od 0 do n)
* <!-- .element: class="fragment fade-in" --> odnalezienie elementu o podanym kluczu: <code>find()</code>

___

## Przykład użycia `std::set<T>`

```C++
std::set<int> set {5, 4, 3, 2, 1, 0, 6, 8, 7};
for (const auto el : set) {
    std::cout << el << ' ';
}
std::cout << '\n';

std::set<int, std::greater<int>> set2 {5, 4, 3, 2, 1, 0, 6, 8, 7};
for (const auto el : set2) {
    std::cout << el << ' ';
}
std::cout << '\n';
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```C++
0 1 2 3 4 5 6 7 8
8 7 6 5 4 3 2 1 0
```
<!-- .element: class="fragment fade-in" -->

___

## Przykład użycia `std::multiset<T>`

```C++
std::multiset<int> set {5, 4, 3, 2, 1, 0, 6, 8, 7, 1, 2, 3, 4, 5, 6};
for (const auto el : set) {
    std::cout << el << ' ';
}
std::cout << '\n';

std::multiset<int, std::greater<int>> set2 {5, 4, 3, 2, 1, 0, 6, 8, 7, 1, 2, 3, 4, 5, 6};
for (const auto el : set2) {
    std::cout << el << ' ';
}
std::cout << '\n';
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```C++
0 1 1 2 2 3 3 4 4 5 5 6 6 7 8
8 7 6 6 5 5 4 4 3 3 2 2 1 1 0
```
<!-- .element: class="fragment fade-in" -->

___

## Hash Table

<<<<<<< HEAD
<image src="https://ycpcs.github.io/cs201-fall2018/notes/figures/chainedHashing.png">
=======
<image src="img/chainedHashing.png">
>>>>>>> 1d66207fc7ef740be07bd53cc49682d57a83c218

___
<!-- .slide: style="font-size: 0.8em" -->

## Funkcja mieszająca

Jest to funkcja, która z dowolnego obiektu wygeneruje nam index w tablicy. Najważniejszą jej cechą jest to, że zawsze dla takich samych danych wejściowych musi wygenerować ten sam index. Kolejną ważną cechą jest takie generowanie indexu, aby tylko dla jednej kombinacji mógł on się powtórzyć np.:

```C++
size_t hash(const std::string& str) { return str.size(); }
```
<!-- .element: class="fragment fade-in" -->

```C++
size_t hash(const std::string& str) {
    size_t index = 0;
    for (size_t i = 0 ; i < str.size() ; ++i) {
        index += (int)str[i];
    }
    return index;
}
```
<!-- .element: class="fragment fade-in" -->

```C++
size_t hash(const std::string& str) {
    size_t index = 0;
    for (size_t i = 0 ; i < str.size() - 1 ; ++i) {
        index += ((int)str[i] * int(str[i + 1]) * (i + 5)) & (((int)str[i] + int(str[i + 1]) * i * i));
    }
    return index * str.size();
}
```
<!-- .element: class="fragment fade-in" -->

Oceń funkcje mieszające.
<!-- .element: class="fragment fade-in" -->
___

## Cechy `std::unordered_set<T>` i `std::unordered_multiset<T>` #1

* <!-- .element: class="fragment fade-in" --> Forma tablicy hash.
* <!-- .element: class="fragment fade-in" --> Może, ale nie musi być cache friendly. Hash table, często są tworzone w formie hybrydy <code>std::vector&lt;T&gt;</code> i <code>std::list&lt;T&gt;</code>.
* <!-- .element: class="fragment fade-in" --> Wartości nie są posortowane
* <!-- .element: class="fragment fade-in" --> Multiset może mieć wiele takich samych wartości
* <!-- .element: class="fragment fade-in" --> Set ma unikatowe wartości

___

## Cechy `std::unordered_set<T>` i `std::unordered_multiset<T>` #2

Ponieważ jest on zaimplementowany jako hash table to średni czas dodawania, usuwania, dostępu oraz modyfikacji to `O(1)`. Najgorszy dla wszystkich operacji czas to `O(n)`.

Zalety:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> Błyskawiczne wyszukiwanie elementów
* <!-- .element: class="fragment fade-in" --> Błyskawicznie szybki czas ich dodawania i usuwania
* <!-- .element: class="fragment fade-in" --> Oczywiście przy założeniu, że mamy dobrą funkcję mieszającą.

Doskonały dla kontenerów read-only. Czas odczytu `O(1)`.
Doskonały dla kontenerów mających dobrą funkcję mieszającą. Czas dodawania, dostępu i modyfikacji `O(1)`.
<!-- .element: class="fragment fade-in" -->

___

## Operacje na `std::unordered_set<T>` i `std::unordered_multiset<T>`

* <!-- .element: class="fragment fade-in" --> dodawanie elementu: <code>insert()</code>, <code>emplace()</code>, <code>emplace_hint()</code>
* <!-- .element: class="fragment fade-in" --> modyfikowanie/dostęp do elementu: Brak
* <!-- .element: class="fragment fade-in" --> pierwszy/ostatni element: Brak
* <!-- .element: class="fragment fade-in" --> rozmiar/czy kontener jest pusty: <code>size()</code>, <code>empty()</code>
* <!-- .element: class="fragment fade-in" --> wyczyszczenie nieużywanej pamięci: Brak
* <!-- .element: class="fragment fade-in" --> iterator początku/końca: <code>begin()</code>, <code>end()</code>
* <!-- .element: class="fragment fade-in" --> odwrócony (ang. reverse) iterator: Brak

<!-- ciacham -->
___

## Operacje na `std::unordered_set<T>` i `std::unordered_multiset<T>` #2

* <!-- .element: class="fragment fade-in" --> stały iterator: <code>cbegin()</code>, <code>cend()</code>
* <!-- .element: class="fragment fade-in" --> wyczyszczenie kontenera: <code>clear()</code>
* <!-- .element: class="fragment fade-in" --> przygotowanie elementu do usunięcia: Brak
* <!-- .element: class="fragment fade-in" --> wymazanie elementów z pamięci: <code>erase()</code>
* <!-- .element: class="fragment fade-in" --> podmiana całego kontenera: <code>swap()</code>
* <!-- .element: class="fragment fade-in" --> zliczenie elementów pasujących do danego klucza: <code>count()</code> (dla <code>set</code> to 0 albo 1, dla <code>multiset</code> od 0 do n)
* <!-- .element: class="fragment fade-in" --> odnalezienie elementu o podanym kluczu: <code>find()</code>

___

## Przykład `std::unordered_set<T>` i `std::unordered_multiset<T>`

```C++
std::unordered_set<std::string> set{"Ala", "Ma", "Kota", "A", "Kot", "Ma", "ALE"};
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

## `unordered_map<K, T>` i `unordered_multimap<K, T>`

* <!-- .element: class="fragment fade-in" --> Zgadnij cechy,
* <!-- .element: class="fragment fade-in" --> Zgadnij implementację,
* <!-- .element: class="fragment fade-in" --> Wyślij przykład wykorzystujący te 2 kontenery

___

## Zadanie 2

* <!-- .element: class="fragment fade-in" --> Stwórz <code>std::unordered_map&lt;int, std::string&gt;</code> oraz <code>std::multiset&lt;int&gt;</code>
* <!-- .element: class="fragment fade-in" --> Wypełnij je dowolnymi wartościami
* <!-- .element: class="fragment fade-in" --> Usuń jeden z elementów,
* <!-- .element: class="fragment fade-in" --> dodaj dodatkowy element
* <!-- .element: class="fragment fade-in" --> Usuń elementy, według wymyślonego przez Ciebie predykatu.

___

## Q&A
