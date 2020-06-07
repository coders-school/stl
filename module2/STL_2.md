<!-- .slide: data-background="#111111" -->

# AGENDA

* <!-- .element: class="fragment fade-in" --> Funktory
* <!-- .element: class="fragment fade-in" --> Wyrażenia lambda
* <!-- .element: class="fragment fade-in" --> Algorytmy niemodyfikujące kontenery
* <!-- .element: class="fragment fade-in" --> Algorytmy modyfikujące kolejność elementów

___

## Funktory

___

## Czym jest Funktor #1?

Funktor jest to obiekt, który może zostać wywołany jak zwykła funkcja. Każda klasa oraz struktura, która posiada zdefiniowany `operator()` może pełnić rolę funktora.
Alternatywną nazwą dla funktora jest obiekt funkcyjny.

```cpp
struct Functor {
    void operator() () {
        std::cout << "I'm functor!\n";
    }
};

int main() {
    Functor funct;
    funct();

    return 0;
}
```

output: `I'm functor!`

___

## Czym jest Funktor #2?

Funkcja także jest traktowana jako funktor, ponieważ również możemy ją wywołać poprzez `()`.

```cpp
void function() {
    std::cout << "I'm functor!\n";
}

int main() {
    function();

    return 0;
}
```

output: `I'm functor!`

___

## Czym jest Funktor #3?

Funktory możemy wykorzystać w algorytmach. Przykładowo algorytm `for_each` powoduje, że dla każdego elementu przekazanego do `for_each` zostanie wywołany funktor, który za swój jedyny argument przyjmie ten element.

```cpp
struct Functor {
    void operator()(int el) {
        std::cout << el << ' ';
    }
};

void print(int el) {
    std::cout << el << ' ';
}

int main() {
    std::vector<int> vec {1, 2, 3, 4, 5};
    std::for_each(begin(vec), end(vec), Functor{});
    std::cout << '\n';
    std::for_each(begin(vec), end(vec), print);

    return 0;
}
```

output:

```text
1 2 3 4 5
1 2 3 4 5
```

___

## Q&A

___

## Lambda

### czyli nowoczesny funktor, wypierający inne z użycia :)

___

## Czym jest wyrażenie lambda?

* W C++11 wprowadzono tak zwane wyrażenie lambda. Jest to nic innego jak obiekt funkcyjny, który może zostać wywołany dla konkretnych parametrów i zwrócić wynik.
* Dzięki swojej prostocie w budowie `[](){}` można zwięźle napisać obiekt funkcyjny, który normalnie zająłby nam kilka razy więcej miejsca.
* Zyskujemy lepszą czytelność, oraz większą swobodę w działaniu.
* Typ lambdy nazywa się domknięciem (ang. closure) i jest znany tylko kompilatorowi.
* Aby zapisać wyrażenie lambda musimy użyć typu auto, ponieważ tylko kompilator zna typ tego wyrażenia.

___

## Utworzenie prostego wyrażenia lambda

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vec.erase(std::remove_if(vec.begin(),
                             vec.end(),
                             [](int num) { return num % 2; }),
              vec.end());

    auto print = [](int num) { std::cout << num << ' '; };
    std::for_each(vec.begin(), vec.end(), print);

    return 0;
}
```

___

## Możliwości wyrażenia lambda #1

* `[]` Kwadratowy nawias określa, jakie parametry chcemy przechwycić do naszego wyrażenia. Możemy np. chcieć przechwycić jakąś zmienną, z którą będziemy chcieli porównywać każdy element kontenera
* Wartości możemy przechwycić przez referencję `[&value]`
* Możemy je także przechwycić przez kopie `[value]`
* Możemy też mieszać obie możliwości `[&by_ref, by_copy, by_copy2]`
* Wyrażenia lambda umożliwia także przechwycenie wszystkiego, co potrzebujemy:
  * poprzez kopię `[=]`
  * poprzez referencję `[&]`
* O ile `[=]` jest bezpieczne, to `[&]` nie zawsze jest zalecane

Pytanie: kiedy [&] może byc niebezpieczne?

___

## Możliwości wyrażenia lambda #2

* Od C++14 możemy pisać tzw. generyczne lambdy
* Są to lambdy wielokrotnego użytku (dla różnych typów) i używamy w nich typu `auto` jako parametru
  * `[](const auto first, const auto& second, auto third){}`
* Pisanie generycznych lambd jest opłacalne, ponieważ łatwo można je wielokrotnie wykorzystać

```cpp
int multiply(int first, int second) {
    return first * second;
}

int main() {
    int number = 10;
    auto multiplyByX = [&number](auto num) { return multiply(num, number); };
    std::cout << multiplyByX(20) << '\n';

    return 0;
}
```

___

## Możliwości wyrażenia lambda #3

* Nie podajemy typu, gdyż domyślnie wyrażenie lambda dedukuje ten typ poprzez dane zawarte w `[]` oraz `()`
* Domyślnie typ zwracany przez wyrażenie lambda również jest dedukowany na podstawie wyrażenia `return`
  `[i{0}](const int el){ return el + i; }; // typem zwracanym jest int`
* Jeżeli chcemy narzucić konkretny typ zwracany robimy to poprzez `->`
  `[i{0}](const auto el) -> double { return el + i; };`

___

## Q&A

### Tym razem przed zadaniami, bo temat trudny :)

___

## Zadanie

1. Utwórz funktor sprawdzający czy podana liczba typu `int` jest podzielna przez `6`
2. Utwórz lambdę, która przyjmie 2 argumenty typu `int` oraz zwróci ich iloczyn
3. Utwórz lambdę, która do podanego ciągu znaków doda cudzysłów. np.
   `krowa` -> `"krowa"`
4. Utwórz lambdę, która wypisze ciąg znaków `*`. Przy każdym zawołaniu funkcji powinniśmy dostać ciąg dłuższy o jedną `*`. Kolejno:
   `*`
   `**`
   `***`
   itd.

___

## Zadanie

1. Utwórz `std::vector<int>` i wypełnij go dowolnymi wartościami
2. Utwórz lambdę, która przechwyci ten wektor, oraz wyświetli jego zawartość
3. Utwórz lambdę, która w swoim argumencie przyjmie `int` i go wyświetli
4. Wykorzystaj tą lambdę w algorytmie `std::for_each()` do wyświetlenia całego kontenera

___

## Algorytmy niemodyfikujące kontenerów

___

### `std::find_if`

```cpp
template< class InputIt, class UnaryPredicate >
InputIt find_if( InputIt first, InputIt last, UnaryPredicate p );
```

* Algorytm wykorzystywany do wyszukiwania interesujących nas elementów. O tym co nas interesuje
  będzie decydować przekazany predykat. Jeżeli chcemy liczby podzielnie przez 3 użyjemy predykatu:
  `[](const auto& el){ return (el % 3 == 0); }`
* `std::find_if` rózni się od `std::find` tylko tym, że zamiast poszukiwanej wartości, podajemy
  predykat jaki musi zostać spełniony aby uznać dany element za poszukiwana wartość.
* Typem zwróconym przez `std::find_if` jest iterator, wskazujący na znaleziony element.
* Jeżeli element nie został znaleziony, wartością zwróconą będzie równy `last`.

___

### `std::find_if` - użycie

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

### `std::search`

```cpp
  template< class ForwardIt1, class ForwardIt2 >
  ForwardIt1 search( ForwardIt1 first, ForwardIt1 last,
                     ForwardIt2 s_first, ForwardIt2 s_last );
```

* Najprostsza wersja std::search, przyjmuje 2 zakresy i sprawdza, czy zakres drugi `{s_first, s_last}`
  jest podzakresem `{first, last}`. Jeżeli tak zwraca iterator wskazujący na początek tego podzakresu.
* Jeżeli podzakres nie zostanie znaleziony, zwrócony iterator będzie równy `last`.
* Istnieją także wersje `std::search`, przyjmujących `binary predicate` oraz typ `searcher`. Zachęcam
  Was do samodzielnej pracy w celu zdobycia wiedzy, jak wykorzystać te funkcję :).
  
___

### `std::search` - użycie
  
```cpp
  std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> vec2 {4, 5, 6};
  auto found = std::search(begin(vec), end(vec),
                          begin(vec2), end(vec2));
  if (found != vec.end())
    std::cout << "first found element: " << *found << '\n';
```

Output: `first found element: 4`

___

### `std::count` oraz `std::count_if`

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

### `std::count` oraz `std::count_if` - użycie

```cpp
  std::vector<int> vec {1, 2, 3, 4, 5, 1, 1, 1, 6, 7};
  std::cout << std::count(begin(vec), end(vec), 1) << '\n';
  std::cout << std::count_if(begin(vec), end(vec),
    [](const auto& el){
      return el % 3 == 0;
    });
```

Output:

```text
4
2
```

___
  
### `std::equal`

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

* Algorytm przyjmuje zakres pierwszego kontenera oraz początek drugiego kontenera. Funkcja będzie dokonywać
  sprawdzenia, aż nie dojdzie do końca 1 zakresu. Nawet jeżeli 2 zakres jest dłuższy. Jeżeli 2 zakres jest krótszy
  to funkcja zwróci false, gdyż na pewno 1 zakres nie będzie identyczny ponieważ jest dłuższy.
* Wersja druga algorytmu, pozwala przyjąć pełny zakres 1 i 2 kontenera i porównać te zakresy.

___
  
### `std::count` oraz `std::count_if` - użycie #1
  
```cpp
  std::cout << std::boolalpha << "EQUAL?: "
    << std::equal(begin(vec1), end(vec1), begin(vec2)) << '\n';
  std::cout << std::boolalpha << "EQUAL?: "
    << std::equal(begin(vec2), end(vec2), begin(vec1)) << '\n';
  std::cout << std::boolalpha << "EQUAL?: "
    << std::equal(begin(vec1), end(vec1), 
        begin(vec2), std::next(vec2.begin(), 5)) << '\n';
```

Output:

```text
  EQUAL?: true
  EQUAL?: false
  EQUAL?: true
```

___

### `std::count` oraz `std::count_if` - użycie #2

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

### `std::mismatch`

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

Działa analogicznie do equal. Z tym wyjątkiem, że zwraca parę iteratorów (dla pierwszego i drugiego zakresu)
wskazującą początek niezgodności.

___

### `std::mismatch` - użycie

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

___

## Algorytmy modyfikujące kolejność elementów

___

### `std::copy`, `std::copy_if`

```cpp
template< class InputIt, class OutputIt >
OutputIt copy( InputIt first, InputIt last, OutputIt d_first );
```

```cpp
template< class InputIt, class OutputIt, class UnaryPredicate >
OutputIt copy_if( InputIt first, InputIt last,
                  OutputIt d_first,
                  UnaryPredicate pred );
```

* Podstawowa wersja copy, kopiuje podany zakres do innego zakresu. Przykładowo kopiuje elementy z wektora do listy.
* `std::copy_if` kopiuje tylko te elementy które spełniają podany przez nas predykat. Np. ::is_upper, ::is::digit.

___

### `std::copy`, `std::copy_if` - użycie

```cpp
  std::vector<int> vec {1, 2, 3, 4, 5};
  std::array<int, 5> arr;
  std::copy(begin(vec), end(vec), begin(arr));
  print(arr);

  std::vector<int> vec2(3);
  std::copy_if(begin(vec), end(vec), begin(vec2),
    [](auto num){
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

### `std::fill`

```cpp
template< class ForwardIt, class T >
void fill( ForwardIt first, ForwardIt last, const T& value );
```

Funkcja wypełnia podany zakres wartościami `value`

```cpp
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

### `std::transform`

Potężny algorytm, mogący zrobić dużo więcej niż się wydaje na początku :)

```cpp
template< class InputIt, class OutputIt, class UnaryOperation >
OutputIt transform( InputIt first1, InputIt last1, OutputIt d_first,
                    UnaryOperation unary_op );
```

```cpp
template< class InputIt1, class InputIt2, class OutputIt, class BinaryOperation >
OutputIt transform( InputIt1 first1, InputIt1 last1, InputIt2 first2,
                    OutputIt d_first, BinaryOperation binary_op );
```

* Pierwsza wersja `std::transform` przyjmuje zakres, oraz wykonuje na każdym elemencie operacje `unary_op`
  a następnie zapisuje ten zmodyfikowany element w drugim zakresie.
* Druga wersja, przyjmuje 2 zakresy, wykonuje na nich operacje `binary_op` ,czyli pobieram z każdego zakresu po 1 elemencie
  i wykonuje na nich operacje, następnie zapisuje wynik w 3 zakresie.

___

### `std::transform` - przykład użycia #1

Konwersja jednego typu kontenera na drugi

```cpp
int main() {
  std::vector<std::pair<int, std::string>> vec {
    {0 , "Zero"},
    {1, "One"},
    {2, "Two"},
    {3, "Three"},
    {4, "Four"},
    {5, "Five"}
  };
  std::vector<int> vec2(5);
  std::transform(begin(vec), end(vec), vec2.begin(),
    [](const auto& pair){
        return pair.first;
    });
  print(vec2);

  return 0;
}
```

Output: `0 1 2 3 4 5`

___  

### `std::transform` - przykład użycia #2

Konwersja kontenera

```cpp
  std::vector<std::pair<int, std::string>> vec {
    {0 , "Zero"},
    {1, "One"},
    {2, "Two"},
    {3, "Three"},
    {4, "Four"},
    {5, "Five"}
  };
  std::vector<std::string> vec2;
  std::transform(begin(vec), end(vec), std::back_inserter(vec2),
    [](const auto& pair){
        return pair.second + " : " + std::to_string(pair.first);
    });
  print(vec2);
```

Output: `Zero : 0 One : 1 Two : 2 Three : 3 Four : 4 Five : 5`

___

### `std::transform` - przykład użycia #3

Zamiana znaków na małe litery

```cpp
int main() {
  std::vector<std::string> vec {
    "ZeRo", "ONe", "TwO", "ThREe", "FoUr", "FiVe"
  };
  std::transform(begin(vec), end(vec), begin(vec),
    [](auto str){
        std::transform(begin(str), end(str), begin(str),
          [](auto c){
              return std::towlower(c);
          });
        return str;
    });
  print(vec);

  return 0;
}
```

Output: `zero one two three four five`

___

### `std::transform` przykład użycia #4

Sumowanie Wartości wektora i listy:

```cpp
int main() {
  std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8};
  std::list<int> list {10, 20, 30 , 40 , 50, 60, 70, 80};
  std::transform(begin(vec), end(vec), begin(list), begin(vec),
    [](auto first, auto second) {
      return first + second;
    });
  print(vec);

  return 0;
}
```

Output: `11 22 33 44 55 66 77 88`

___

### `std::generate`

```cpp
  template< class ForwardIt, class Generator >
  void generate( ForwardIt first, ForwardIt last, Generator g );
```

Funkcja służąca do generowania jakiś danych.

```cpp
int main() {
  std::vector<int> vec(10);
  std::generate(begin(vec), end(vec), [i {0}]() mutable { return i++; });
  print(vec);

  return 0;
}
```

Output: `0 1 2 3 4 5 6 7 8 9`

___

### `std::swap_ranges`

```cpp
template< class ForwardIt1, class ForwardIt2 >
ForwardIt2 swap_ranges( ForwardIt1 first1, ForwardIt1 last1,
                        ForwardIt2 first2 );
```

Podmienia pewien zakres danych

```cpp
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

### `std::reverse`

```cpp
template< class BidirIt >
void reverse( BidirIt first, BidirIt last );
```

Odwraca zakres

```cpp
int main() {
  std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8};
  std::reverse(begin(vec), end(vec));
  print(vec);

  return 0;
}
```

Out: `8 7 6 5 4 3 2 1`

___

## `std::unique`

```cpp
template< class ForwardIt >
ForwardIt unique( ForwardIt first, ForwardIt last );
```

Usuwa duplikaty. Ważne, kontener musi byc posortowany. Tak naprawdę to funkcja nie usuwa duplikatów,
lecz przenosi unikalne wartości na początek kontenera (nie zmieniając ich kolejności) oraz zwraca
iterator wskazujący pierwszy element, gdzie zaczynają się duplikaty.

```cpp
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

1. Stwórz std::vector<int>
2. Wypełnij go elementami nieparzystymi licząc o 1 do 15
3. Odwróć kontener nie używając pętli ani std::reverse.
4. Przepisz std::vector<int> do listy używając copy
5. Stwórz drugi vector<int> i wypełnij go liczbami parzystymi od 0 do 14.
6. Znajdź sposób jak połączy oba std::vector w jeden zawierający wartości od 0 do 15 ułożone po kolei.

___

### Zadanie

1. Stwórz std::list<int> z wartościami od 1 do 10.
2. Utwórz std::vector<int> z wartościami od 5 do 10.
3. Przekaż odpowiednie iteratory do funkcji std::equal, tak by zwróciła, że oba 
   kontenery są sobie równe.
4. Za pomocą mismatch oraz erase, usuń niepasujące elementy z kontenera 1
5. Zawołaj funkcję std::equal dla pełnych zakresów aby upewnić się, ze są teraz identyczne.

___

## Q&A

___

## Zadania domowe

___

### Zadanie 1

Postaraj się poprawić program z poprzednich zajęć (kompresja, dekompresja) obrazków, tak, aby zamiast pętli wykorzystać algorytmy.

### Zadanie 2

Napisz program, który będzie sprawdzał, czy podany ciąg wyrazów jest palindromem.
Program powinien ignorować znaki specjalne jak `,` wielkość liter oraz białe znaki jak spacja.

### Zadanie 3

1) Napisz funkcję, która przyjmie `std::list<std::string>` oraz `std::deque<int>`.
2) Usunie duplikaty z obu kontenerów.  
3) Na koniec skonwertuje to na `std::map<int, std::string>` i ją zwróci (`użyj std::transform`).
