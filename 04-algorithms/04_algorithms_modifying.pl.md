<!-- .slide: data-background="#111111" -->

# Algorytmy modyfikujące

<a href="https://coders.school">
    <img width="500" data-src="../img/coders_school_logo.png" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Algorytmy  modyfikujące kolejność elementów

Modyfikują one kontenery na których działają.

Mogą:

* zmieniać kolejności elementów w kontenerze
* usuwać elementy
* dodawać elementy

Tutaj znajdziesz tylko popularne lub ciekawe użycia niektórych algorytmów. Pełna lista algorytmów dostępna jest na cppreference.com

[Algorytmy na cppreference.com](https://en.cppreference.com/w/cpp/algorithm)

___

## `std::copy`, `std::copy_if`

```cpp []
template< class InputIt, class OutputIt >
OutputIt copy( InputIt first, InputIt last, OutputIt d_first );
```

```cpp []
template< class InputIt, class OutputIt, class UnaryPredicate >
OutputIt copy_if( InputIt first, InputIt last,
                  OutputIt d_first,
                  UnaryPredicate pred );
```

* Podstawowa wersja `std::copy`, kopiuje podany zakres do innego zakresu. Przykładowo kopiuje elementy z wektora do listy.
* `std::copy_if` kopiuje tylko te elementy, które spełniają podany przez nas predykat. Np. `::is_upper`, `::is::digit`.

___

## `std::copy`, `std::copy_if` - użycie

```cpp []
std::vector<int> vec {1, 2, 3, 4, 5};
std::array<int, 5> arr;
std::copy(begin(vec), end(vec), begin(arr));
print(arr);

std::vector<int> vec2(3);
std::copy_if(begin(vec), end(vec), begin(vec2), [](auto num) {
    return num % 2 == 1;
});
print(vec2);
```

Output:

```text
1 2 3 4 5
1 3 5
```

___

## `std::fill`

```cpp []
template< class ForwardIt, class T >
void fill( ForwardIt first, ForwardIt last, const T& value );
```

Funkcja wypełnia podany zakres wartościami `value`

```cpp []
int main() {
    std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::fill(v.begin(), v.end(), -1);
    for (auto elem : v) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}
```

Output: `-1 -1 -1 -1 -1 -1 -1 -1 -1 -1`

___
<!-- .slide: style="font-size: 0.9em" -->

## `std::transform`

Potężny algorytm, mogący zrobić dużo więcej niż się wydaje na początku :)

```cpp []
template< class InputIt, class OutputIt, class UnaryOperation >
OutputIt transform( InputIt first1, InputIt last1,
                    OutputIt d_first,
                    UnaryOperation unary_op );
```

```cpp []
template< class InputIt1, class InputIt2, class OutputIt, class BinaryOperation >
OutputIt transform( InputIt1 first1, InputIt1 last1,
                    InputIt2 first2,
                    OutputIt d_first,
                    BinaryOperation binary_op );
```

* Pierwsza wersja `std::transform` przyjmuje zakres `[first1, last1)`, oraz wykonuje na każdym elemencie operację `unary_op`, a następnie zapisuje zmodyfikowane elementy w drugim zakresie (`d_first`).
* Druga wersja, przyjmuje 2 zakresy, pobiera z obu tych zakresów po 1 elemencie i wykonuje na nich operacje `binary_op`, następnie zapisuje wynik w 3 zakresie (`d_first`).

___

## `std::transform` - przykład użycia #1

Konwersja jednego typu kontenera na drugi

```cpp []
int main() {
    std::vector<std::pair<int, std::string>> vec {
        {0, "Zero"},
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"}
    };
    std::vector<int> vec2(5);
    std::transform(begin(vec), end(vec), vec2.begin(), [](const auto& pair) {
        return pair.first;
    });
    print(vec2);
    return 0;
}
```

Output: `0 1 2 3 4 5`

___

## `std::transform` - przykład użycia #2

Konwersja kontenera

```cpp []
std::vector<std::pair<int, std::string>> vec {
    {0, "Zero"},
    {1, "One"},
    {2, "Two"},
    {3, "Three"},
    {4, "Four"},
    {5, "Five"}
};
std::vector<std::string> vec2;
std::transform(begin(vec),
               end(vec),
               std::back_inserter(vec2),
               [](const auto& pair){
                   return pair.second + " : " + std::to_string(pair.first);
               });
print(vec2);
```

Output: `Zero : 0, One : 1, Two : 2, Three : 3, Four : 4, Five : 5`

___

## `std::transform` - przykład użycia #3

Zamiana znaków na małe litery

```cpp []
int main() {
    std::vector<std::string> vec {
        "ZeRo", "ONe", "TwO", "ThREe", "FoUr", "FiVe"
    };
    std::transform(begin(vec), end(vec), begin(vec), [](auto str) {
        std::transform(begin(str), end(str), begin(str), [](auto c) {
            return std::tolower(c);
        });
        return str;
    });
    print(vec);

    return 0;
}
```

Output: `zero one two three four five`

___

## `std::transform` przykład użycia #4

Sumowanie wartości wektora i listy:

```cpp []
int main() {
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8};
    std::list<int> list {10, 20, 30 , 40 , 50, 60, 70, 80};
    std::transform(begin(vec),
                   end(vec),
                   begin(list),
                   begin(vec),
                   [](auto first, auto second) {
                       return first + second;
                   });
    print(vec);

    return 0;
}
```

Output: `11 22 33 44 55 66 77 88`

___

## `std::generate`

```cpp []
template< class ForwardIt, class Generator >
void generate( ForwardIt first, ForwardIt last, Generator g );
```

Funkcja służąca do generowania danych.

```cpp []
int main() {
    std::vector<int> vec(10);
    std::generate(begin(vec), end(vec), [i{0}]() mutable { return i++; });
    print(vec);

    return 0;
}
```

Output: `0 1 2 3 4 5 6 7 8 9`

___
<!-- .slide: style="font-size: 0.9em" -->

## `std::swap_ranges`

```cpp []
template< class ForwardIt1, class ForwardIt2 >
ForwardIt2 swap_ranges( ForwardIt1 first1, ForwardIt1 last1,
                        ForwardIt2 first2 );
```

Podmienia pewien zakres danych

```cpp []
int main() {
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8};
    std::list<int> list {10, 20, 30, 40, 50, 60, 70, 80};
    std::swap_ranges(begin(vec), std::next(begin(vec), 3), std::begin(list));
    print(vec);
    print(list);

    return 0;
}
```

Output:

```text
10 20 30 4 5 6 7 8
1 2 3 40 50 60 70 80
```

___

## `std::reverse`

```cpp []
template< class BidirIt >
void reverse( BidirIt first, BidirIt last );
```

Odwraca zakres

```cpp []
int main() {
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8};
    std::reverse(begin(vec), end(vec));
    print(vec);

    return 0;
}
```

Output: `8 7 6 5 4 3 2 1`

___

## `std::unique`

```cpp []
template< class ForwardIt >
ForwardIt unique( ForwardIt first, ForwardIt last );
```

Usuwa duplikaty. Ważne! Kontener musi być posortowany. Tak naprawdę ta funkcja nie usuwa duplikatów, lecz przenosi unikalne wartości na początek kontenera (nie zmieniając ich wzajemnej kolejności) oraz zwraca iterator wskazujący pierwszy element, gdzie zaczynają się duplikaty.

___

## `std::unique` - przykład

```cpp []
int main() {
    std::vector<int> vec {1, 2, 1, 2, 1, 2, 3, 2, 3, 1, 3, 2, 1};
    std::sort(begin(vec), end(vec));
    auto it = std::unique(begin(vec), end(vec));
    print(vec);
    vec.erase(it, end(vec));
    print(vec);

    return 0;
}
```

Output:

```text
1 2 3 1 1 2 2 2 2 2 3 3 3
1 2 3
```

___

## Zadanie

1. Stwórz `std::vector<int>`
2. Wypełnij go elementami nieparzystymi licząc od 1 do 15
3. Odwróć kontener nie używając pętli ani `std::reverse`
4. Przepisz `std::vector<int>` do listy używając `std::copy`
5. Stwórz drugi `std::vector<int>` i wypełnij go liczbami parzystymi od 0 do 14.
6. Znajdź sposób jak połączyć oba wektory w jeden, zawierający wartości od 0 do 15 ułożone po kolei.

___

## Zadanie

1. Stwórz `std::list<int>` z wartościami od 1 do 10.
2. Utwórz `std::vector<int>` z wartościami od 5 do 10.
3. Przekaż odpowiednie iteratory do funkcji `std::equal`, tak by zwróciła, że oba kontenery są sobie równe.
4. Za pomocą `std::mismatch` oraz `erase`, usuń niepasujące elementy z listy
5. Zawołaj funkcję `std::equal` dla pełnych zakresów aby upewnić się, że są teraz identyczne.

___

## Q&A
