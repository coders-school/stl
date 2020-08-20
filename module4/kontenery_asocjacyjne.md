# Kontenery asocjacyjne

___

## Posortowane

* Set
* Multiset
* Map
* Multimap
  
___

## Nieuporządkowane

* Unordered_set
* Unordered_multiset
* Unordered_map
* Unordered_multimap

___

## Quiz

Do czego możesz użyć:

* Set?
* Multiset?
* Map?
* Multimap?
* Unordered_set?
* Unordered_multiset?
* Unordered_map?
* Unordered_multimap?

___

## Notacja dużego O

<img src="https://miro.medium.com/max/1180/1*QGb8BP4vq0KB4Ee0-p2VuA.png">

___

## Cechy `std::map<K, T>` i `std::multimap<K, T>` #1

* Forma drzewa binarnego (red-black-tree)
* Nie jest cache friendly
* Pozwala przechowywać parę klucz-wartość (key-value)
* Multimapa może mieć wiele takich samych kluczy
* Mapa ma unikatowe klucze
* Alternatywą dla multimapy jest `std::map<key, std::vector<value>>`

___

## Cechy `std::map<K, T>` i `std::multimap<K, T>` #2

Ponieważ jest ona zaimplementowana przeważnie jako red-black-tree (GNU standard C++ library) to czas wstawiania, usuwania i dodawania elementu to `O(log(n)`).

Zalety:

* Szybkie wyszukiwanie elementów (kontenery sekwencyjnie `O(n)`),
* Względnie szybki czas ich dodawania i usuwania np. `std::vector<T>` dodaje elementy w środku w czasie `O(n)` ale `std::list<T>` (jeżeli mamy podany iterator) w czasie `O(1)`. Stąd mapa jest względnie szybka zarówno w dodawaniu jak i usuwaniu.
* Idealna, gdy często poszukujemy danych a rzadziej je dodajemy lub usuwamy.

Jeżeli będziemy jej używać jako zwykłego kontenera, to stracimy na wydajności. Mapę należy sortować wtedy, kiedy faktycznie chcemy posiadać pary klucz-wartość i często je wyszukiwać. W innym przypadku możemy użyć `std::vector<pair<K, V>>` lub innego kontenera.
  
___

## Operacje na `std::map<K, T>` i `std::multimap<K, T>`

* dodawanie elementu: insert(), emplace(), emplace_hint(). Dodatkowo mapa posiada: insert_or_assign(), try_emplace() oraz operator[] (dodająco modyfikujący)
* modyfikowanie/dostęp do elementu: at(), operator[] (Multimapa nie posiada takich opcji)
* pierwszy/ostatni element: Brak
* rozmiar/czy kontener jest pusty: size(), empty()
* wyczyszczenie nieużywanej pamięci: Brak
* iterator początku/końca: begin(), end()
* odwrócony (ang. reverse) iterator: rbegin(), rend()
* stały iterator: cbegin(), cend(), crbegin(), crend()
* wyczyszczenie kontenera: clear()
* przygotowanie elementu do usunięcia: Brak
* wymazanie elementów z pamięci: erase()
* podmiana całego kontenera: swap()
* zliczenie elementów pasujących do danego klucza: count (dla mapy to 0 albo 1, dla multimapy od 0 do n)
* odnalezienie elementu o podanym kluczu: find()

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

Output:
`Ten`

Podpowiadamy mapie miejsce, gdzie powinna wstawić element, dzięki temu taka operacja będzie miała złożoność O(1). Jeżeli jednak źle podpowiemy, to czas wstawienia będzie O(long(n)). Raczej rzadko stosowane 🙂

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

Otput:

```C++
Ten
Dziesiec
Cent
```

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

Output: `4`

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

Output:

```C++
5 | Five
5 | Funf
5 | Piec
5 | Cinq
```

___

## Zadanie 1

* Stwórz multimapę i wypełnij ją podanymi wartościami

```C++
map.insert({5, "Ala"});
map.insert({5, "Ma"});
map.insert({5, "Kota"});
map.insert({5, "A"});
map.insert({5, "Kot"});
map.insert({5, "Ma"});
map.insert({5, "Ale"});
```

* Napisz funkcję, która wyświetli słowa w mapie o liczbie znaków równej 3.

___

## Rozwiązanie

```C++
std::vector<std::pair<int, std::string>> result;
std::copy_if(it, end(map), std::back_inserter(result),
                [](const auto& pair) { return pair.second.size() == 3; });
std::for_each(begin(result), end(result),
            [](const auto& pair) { std::cout << pair.second << '\n'; });
```

___

## Cechy `std::set<T>` i `std::multiset<T>` #1

* Forma drzewa binarnego (red-black-tree)
* Nie jest cache friendly
* Pozwala przechowywać wartości w uporządkowanej kolejności
* Multiset może mieć wiele takich samych wartości
* Set ma unikatowe wartości
* Alternatywą dla multiset jest posortowany `std::vector<T>`

___

## Cechy `std::set<T>` i `std::multiset<T>` #2

Ponieważ jest on zaimplementowany przeważnie jako red-black-tree (GNU standard C++ library) to czas wstawiania, usuwania i dodawania elementu to `O(log(n)`).

Zalety:

* Szybkie wyszukiwanie elementów (kontenery sekwencyjnie `O(n)`),
* Względnie szybki czas ich dodawania i usuwania np. `std::vector<T>` dodaje elementy w środku w czasie `O(n)` ale `std::list<T>` (jeżeli mamy podany iterator) w czasie `O(1)`. Stąd set jest względnie szybki zarówno w dodawaniu jak i usuwaniu.
* Idealny, gdy chcemy zawsze posiadać posortowane wartości.

Jeżeli nie zależy nam, aby kontener był zawsze posortowany, lecz jedynie w specyficznych momentach, to może lepiej nam użyć `std::vector<T>` i sortować go, gdy przyjdzie taka potrzeba. Jeżeli też zależy nam tylko czasami na unikatowych wartościach, to możemy wtedy użyć `std::unique<>`.
  
___

## Operacje na `std::set<T>` i `std::multiset<T>`

* dodawanie elementu: insert(), emplace(), emplace_hint()
* modyfikowanie/dostęp do elementu: Brak
* pierwszy/ostatni element: Brak
* rozmiar/czy kontener jest pusty: size(), empty()
* wyczyszczenie nieużywanej pamięci: Brak
* iterator początku/końca: begin(), end()
* odwrócony (ang. reverse) iterator: rbegin(), rend()
* stały iterator: cbegin(), cend(), crbegin(), crend()
* wyczyszczenie kontenera: clear()
* przygotowanie elementu do usunięcia: Brak
* wymazanie elementów z pamięci: erase()
* podmiana całego kontenera: swap()
* zliczenie elementów pasujących do danego klucza: count (dla set to 0 albo 1, dla multiset od 0 do n)
* odnalezienie elementu o podanym kluczu: find()

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

Output:

```C++
0 1 2 3 4 5 6 7 8
8 7 6 5 4 3 2 1 0
```

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

Output:

```C++
0 1 1 2 2 3 3 4 4 5 5 6 6 7 8
8 7 6 6 5 5 4 4 3 3 2 2 1 1 0
```

___

## Hash Table

<image src="https://ycpcs.github.io/cs201-fall2018/notes/figures/chainedHashing.png">

___

## Funkcja mieszająca

Jest to funkcja, która z dowolnego obiektu wygeneruje nam index w tablicy. Najważniejszą jej cechą jest to, że zawsze dla takich samych danych wejściowych musi wygenerować ten sam index. Kolejną ważną cechą jest takie generowanie indexu, aby tylko dla jednej kombinacji mógł on się powtórzyć np.:

```C++
size_t hash(const std::string& str) { return str.size(); }
```

```C++
size_t hash(const std::string& str) {
    size_t index = 0;
    for (size_t i = 0 ; i < str.size() ; ++i) {
        index += (int)str[i];
    }
    return index;
}
```

```C++
size_t hash(const std::string& str) {
    size_t index = 0;
    for (size_t i = 0 ; i < str.size() - 1 ; ++i) {
        index += ((int)str[i] * int(str[i + 1]) * (i + 5)) & (((int)str[i] + int(str[i + 1]) * i * i));
    }
    return index * str.size();
}
```

Oceń funkcje mieszające.
___

## Cechy `std::unordered_set<T>` i `std::unordered_multiset<T>` #1

* Forma tablicy hash.
* Może, ale nie musi być cache friendly. Hash table, często są tworzone w formie hybrydy `std::vector<T>` i `std::list<T>`.
* Wartości nie są posortowane
* Multiset może mieć wiele takich samych wartości
* Set ma unikatowe wartości

___

## Cechy `std::unordered_set<T>` i `std::unordered_multiset<T>` #2

Ponieważ jest on zaimplementowany jako hash table to średni czas dodawania, usuwania, dostępu oraz modyfikacji to `O(1)`. Najgorszy dla wszystkich operacji czas to `O(n)`.

Zalety:

* Błyskawiczne wyszukiwanie elementów
* Błyskawicznie szybki czas ich dodawania i usuwania
* Oczywiście przy założeniu, że mamy dobrą funkcję mieszającą.

Doskonały dla kontenerów read-only. Czas odczytu `O(1)`.
Doskonały dla kontenerów mających dobrą funkcję mieszającą. Czas dodawania, dostepu i modyfikacji `O(1)`.
  
___

## Operacje na `std::unordered_set<T>` i `std::unordered_multiset<T>`

* dodawanie elementu: insert(), emplace(), emplace_hint()
* modyfikowanie/dostęp do elementu: Brak
* pierwszy/ostatni element: Brak
* rozmiar/czy kontener jest pusty: size(), empty()
* wyczyszczenie nieużywanej pamięci: Brak
* iterator początku/końca: begin(), end()
* odwrócony (ang. reverse) iterator: BRAK
* stały iterator: cbegin(), cend()
* wyczyszczenie kontenera: clear()
* przygotowanie elementu do usunięcia: Brak
* wymazanie elementów z pamięci: erase()
* podmiana całego kontenera: swap()
* zliczenie elementów pasujących do danego klucza: count (dla set to 0 albo 1, dla multiset od 0 do n)
* odnalezienie elementu o podanym kluczu: find()

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

## `unordered_map<K, T>` i `unordered_multimap<K, T>`

* Zgadnij cechy,
* Zgadnij implementację,
* Wyślij przykład wykorzystujący te 2 kontenery

## Zadanie 2

* Stwórz `std::unordered_map<int, std::string>` oraz `std::multiset<int>`
* Wypełnij je dowolnymi wartościami
* Usuń jeden z elementów,
* dodaj dodatkowy element
* Usuń elementy, według wymyślonego przez Ciebie predykatu.
  
___

## Q&A

___
