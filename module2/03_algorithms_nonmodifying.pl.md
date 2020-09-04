<!-- .slide: data-background="#111111" -->

# Algorytmy niemodyfikujące

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Algorytmy niemodyfikujące kontenerów

Nie modyfikują one kontenerów na których działają.

Nie mogą:

* zmieniać kolejności elementów w kontenerze
* usuwać elementy
* dodawać elementy

Tutaj znajdziesz tylko popularne lub ciekawe użycia niektórych algorytmów. Pełna lista algorytmów dostępna jest na cppreference.com

[Algorytmy na cppreference.com](https://en.cppreference.com/w/cpp/algorithm)

___

## `std::find_if`

```cpp
template< class InputIt, class UnaryPredicate >
InputIt find_if( InputIt first, InputIt last, UnaryPredicate p );
```

* Predykat = funktor, funkcja, lambda, która zwraca `bool` (`true/false`)
* Algorytm wykorzystywany do wyszukiwania interesujących nas elementów. O tym co nas interesuje będzie decydować przekazany predykat. Jeżeli chcemy liczby podzielnie przez 3 użyjemy predykatu:
  * `[](const auto& el){ return (el % 3 == 0); }`
* `std::find_if` różni się od `std::find` tylko tym, że zamiast poszukiwanej wartości, podajemy predykat jaki musi zostać spełniony, aby uznać dany element za poszukiwaną wartość.
* Typem zwróconym przez `std::find_if` jest iterator, wskazujący na znaleziony element.
* Jeżeli element nie został znaleziony, wartością zwróconą będzie równy `last`.

___

## `std::find_if` - użycie

```cpp
std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
auto found = std::find_if(begin(vec), end(vec), [](const auto& el) {
    return el == 7;
});
if (found != vec.end()) {
    std::cout << *found << '\n';
}
```

Output: `found 7`

___

## `std::search`

```cpp
template< class ForwardIt1, class ForwardIt2 >
ForwardIt1 search( ForwardIt1 first, ForwardIt1 last,
                   ForwardIt2 s_first, ForwardIt2 s_last );
```

* Najprostsza wersja `std::search`, przyjmuje 2 zakresy i sprawdza, czy zakres drugi `{s_first, s_last}` jest podzakresem `{first, last}`.
  * Jeżeli tak zwraca iterator wskazujący na początek tego podzakresu.
  * Jeżeli podzakres nie zostanie znaleziony, zwrócony iterator będzie równy `last`.
* Istnieją także wersje `std::search`, przyjmujące `binary predicate` oraz typ `searcher`. Zachęcam Was do samodzielnej pracy w celu zdobycia wiedzy, jak wykorzystać te funkcję :).

___

## `std::search` - użycie

```cpp
std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
std::vector<int> vec2 {4, 5, 6};
auto found = std::search(begin(vec), end(vec),
                         begin(vec2), end(vec2));
if (found != vec.end()) {
    std::cout << "first found element: " << *found << '\n';
}
```

Output: `first found element: 4`

___

## `std::count` oraz `std::count_if`

```cpp
template< class InputIt, class T >
typename iterator_traits<InputIt>::difference_type
    count( InputIt first, InputIt last, const T &value );
```

```cpp
template< class InputIt, class UnaryPredicate >
typename iterator_traits<InputIt>::difference_type
    count_if( InputIt first, InputIt last, UnaryPredicate p );
```

* `std::count` zlicza dla danego zakresu wystąpienie konkretnej wartości.
* `std::count_if` zlicza dla danego zakresu ilość zwróconych `true` przez predykat.

___

## `std::count` oraz `std::count_if` - użycie

```cpp
std::vector<int> vec {1, 2, 3, 4, 5, 1, 1, 1, 6, 7};

std::cout << std::count(begin(vec), end(vec), 1) << '\n';

auto counter = std::count_if(begin(vec), end(vec), [](const auto& el){
    return el % 3 == 0;
});
std::cout << counter << '\n';
```

Output:

```text
4
2
```

___

## `std::equal`

```cpp
  template< class InputIt1, class InputIt2 >
  bool equal( InputIt1 first1, InputIt1 last1,
              InputIt2 first2 );
```

```cpp
  template< class InputIt1, class InputIt2 >
  bool equal( InputIt1 first1, InputIt1 last1,
              InputIt2 first2, InputIt2 last2 )
```

* Algorytm przyjmuje zakres pierwszego kontenera oraz początek drugiego kontenera. Funkcja będzie dokonywać sprawdzenia, aż nie dojdzie do końca 1 zakresu, nawet jeżeli 2 zakres jest dłuższy. Jeżeli 2 zakres jest krótszy, to funkcja zwróci false, gdyż na pewno 1 zakres nie będzie identyczny, ponieważ jest dłuższy.
* Wersja druga algorytmu, pozwala przyjąć pełny zakres 1 i 2 kontenera i porównać te zakresy.

___

## `std::equal` - użycie #1

```cpp
// Missing vec1 and vec2 :D Can you think of the examples of vec1 and 2 that
// will make the output look like below?
std::cout << std::boolalpha << "EQUAL?: "
          << std::equal(begin(vec1), end(vec1), begin(vec2)) << '\n';
std::cout << std::boolalpha << "EQUAL?: "
          << std::equal(begin(vec2), end(vec2), begin(vec1)) << '\n';
std::cout << std::boolalpha << "EQUAL?: "
          << std::equal(begin(vec1), end(vec1),
                        begin(vec2), std::next(vec2.begin(), 5))
          << '\n';
```

Output:

```text
EQUAL?: true
EQUAL?: false
EQUAL?: true
```

___

## `std::equal` - użycie #2

```cpp
bool is_palindrome(const std::string& s) {
    return std::equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}
void test(const std::string& s) {
    std::cout << "\"" << s << "\" "
              << (is_palindrome(s) ? "is" : "is not")
              << " a palindrome\n";
}
int main() {
    test("radar");
    test("hello");
}
```

Output:

```text
  "radar" is a palindrome
  "hello" is not a palindrome
```

___

## `std::mismatch`

```cpp
template< class InputIt1, class InputIt2 >
std::pair<InputIt1,InputIt2>
    mismatch( InputIt1 first1, InputIt1 last1,
              InputIt2 first2 );
```

```cpp
template< class InputIt1, class InputIt2 >
std::pair<InputIt1,InputIt2>
    mismatch( InputIt1 first1, InputIt1 last1,
              InputIt2 first2, InputIt2 last2 );
```

Działa analogicznie do `std::equal`, z tym wyjątkiem, że zwraca parę iteratorów (dla pierwszego i drugiego zakresu) wskazującą początek niezgodności.

___

## `std::mismatch` - użycie

```cpp
std::string mirror_ends(const std::string& in) {
    return std::string(in.begin(),
                       std::mismatch(in.begin(), in.end(), in.rbegin()).first);
}

int main() {
    std::cout << mirror_ends("abXYZba") << '\n'
              << mirror_ends("abca") << '\n'
              << mirror_ends("aba") << '\n';
}
```

Output:

```text
ab
a
aba
```

___

## Q&A
