<!-- .slide: data-background="#111111" -->

# AGENDA

* <!-- .element: class="fragment fade-in" --> Funktory
* <!-- .element: class="fragment fade-in" --> Lambda
* <!-- .element: class="fragment fade-in" --> Typy funktorów
* <!-- .element: class="fragment fade-in" --> Algorytmy niemodyfikujące kontenery
* <!-- .element: class="fragment fade-in" --> Algorytmy modyfikujące kolejność elementów

___

## Funktory

___

### Czym jest Funktor #1?

Funktor jest to obiekt, który może zostać wywołany jak zwykła funkcja. Każda klasa oraz struktura, 
która posiada zdefiniowany operator () może pełnić rolę funktora. 
Alternatywną nazwą dla funktora jest obiekt funkcyjny.

```
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


### Czym jest Funktor #2?

Za funktor możemy potraktować także funkcję. Ponieważ ją również możemy wywołać poprzez `()`.

```
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

### Czym jest Funktor #3?

Funktory możemy wykorzystać w algorytmach. Przykładowo algorytm `for_each` powoduje, że dla każdego elementu
przekazanego do `for_each` zostanie wywołany funktor, który za swój jedyny argument przyjmie ten element. 

```
  struct functor {
    void operator() (int el) {
      std::cout << el << ' ';
    }
  };

  void print(int el) {
    std::cout << el << ' ';
  }

  int main() {
    std::vector<int> vec {1, 2, 3, 4, 5};
    std::for_each(begin(vec), end(vec), functor{});
    std::cout << '\n';
    std::for_each(begin(vec), end(vec), print);

    return 0;
  }
```
output:
```
  1 2 3 4 5 
  1 2 3 4 5
```

___

### std::function

W standardzie C++ znajdziemy bibliotekę o nazwie <functional>, która umożliwia nam korzystanie z std::function<>,
który krótko mówiąc jest `wrapperem` na funktor. 

przykładowo:
`std::function<void(int, double)>` to nic innego jak `wrapper` na funkcję void(int, double). Czyli nie zwracającej
żadnego argumentu a przyjmującego 2 argumenty typu int oraz double.

`std::function<int(const std::string&, int * const)>` to `wrapper` na funkcję przyjmującą jako pierwszy argument
stała referencje na obiekt typu string oraz stały wskaźnik na typ int. Funkcja ta zwraca typ int.

___

### Użycie std::function #1

Z std::function<> korzystamy tak samo jak ze zwykłej funkcji.

```
int foo(const std::string& str, int * const ptr) {
  std::cout << "I'm Groot\n";
  std::cout << "str: " << str << '\n';
  std::cout << "ptr: " << *ptr << '\n';

  return 41;
}

int main() {
  std::function<int(const std::string&, int * const)> fun;
  fun = foo;

  int num = 5;
  int* ptr = &num;
  auto result = fun("Some string", ptr);
  std::cout << "Retunr: " << result << '\n';

  return 0;
}
```
___

### Użycie std::function #2

std::function<> może być także `wrapperem` na funktor.

```
struct Foo {
  int operator() (const std::string& str, int * const ptr) {
    std::cout << "I'm Groot\n";
    std::cout << "str: " << str << '\n';
    std::cout << "ptr: " << *ptr << '\n';

    return 41;
  }
};

int main() {
  std::function<int(const std::string&, int * const)> fun;
  fun = Foo{};

  int num = 5;
  int* ptr = &num;
  auto result = fun("Some string", ptr);
  std::cout << "Retunr: " << result << '\n';

  return 0;
}
```
___

### Użycie std::function #3

std::function<> możemy również swobodnie przekazywać do funkcji jako argumenty.
Nie musimy się martwić o pisanie wskaźników na funkcję, które czasem są zawiłe.
Wystarczy przekazać std::functiom<>.

```
std::string functionWhichWillWorkOnOtherThread() {
  return "Some specail string\n";
}

void doSth(std::function<void(const std::string&)> callback) {
  auto result = functionWhichWillWorkOnOtherThread();
  callback(result);
}

void foo(const std::string& str) {
  std::cout << str << '\n';
}

int main() {
  doSth(foo);

  return 0;
}
```

___

## Q&A
___

## Lambda, czyli nowoczesny funktor, wypierający inne z użycia :)

___

### Czym jest wyrażenie lambda?

* W C++11 wprowadzono tak zwane wyrażenie lambda. Jest to nic innego jak obiekt funkcyjny,
  który może zostać wywołany dla konkretnych parametrów i zwrócić wynik. 
* Dzięki swojej prostocie w budowie `[](){}` można zwięźle napisać obiekt funkcyjny,
  który normalnie zająłby nam kilka razy więcej miejsca.
* Zyskujemy lepszą czytelność, oraz większą swobodę w działaniu.
* Typ lambdy nazywa się domknięciem (ang. clousure). I jest znany tylko kompilatorowi.
* aby zapisać wyrażenie lambda musimy użyć typu auto, ponieważ, tylko kompilator zna typ tego wyrażenia.

___

### Utworzenie prostego wyrażenia lambda:

```
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
  vec.erase(std::remove_if(vec.begin(), vec.end(), 
    [](int num){
        return num % 2;
    }), vec.end());

  auto print = [](int num){ std::cout << num << ' '; };
  std::for_each(vec.begin(), vec.end(), print);

  return 0;
}
```

___

### Możliwości wyrażenia lambda #1:

* [] -> Nawias ten określa, jakie parametry chcemy przechwycić do naszego wyrażenia
  Możemy np. chcieć przechwycić nazwę jakiegoś pliku, może, jaką zmienną, z którą będziemy
  chcieli porównywać każdy element kontenera itp.
* Wartości możemy przechwycić przez referencję `[&value]` 
* Możemy je także przechwycić przez kopie `[value]`
* Możemy też mieszać obie możliwości `[&by_ref, by_copy, by_copy2]`
* Wyrażenia lambda umożliwia także przechwycenie wszystkiego, co potrzebujemy:
   * poprzez kopie [=]
   * poprzez referencje [&]
* Wszystkiego, co potrzebne rozumiemy w kontekście, ze tylko to, co wykorzystane jest
  wewnątrz ciała lambdy, czyli pomiędzy `{}`.
* O ile [=] jest bezpieczne, to [&] nie zawsze jest zalecane.

Pytanie: kiedy [&] może byc niebezpieczne?

___

### Możliwości wyrażenia lambda #2:

* Od C++14 możemy pisać tzw. generyczne lambdy. Czyli lambdy wielokrotnego użytku (dla różnych typów).
  `[](const auto first, const auto& second, auto third){}`
* Pisanie generycznych lambd jest opłacalne, ponieważ łatwo można ją wielokrotnie wykorzystać.
* Przed C++11 bardzo często wykorzystywany był `std::bind`, w celu przekazania jakiś argumentów do funkcji.
* Aktualnie używamy wyrażeń lambda ponieważ, std::bind nie jest już nam potrzebne. Ponadto konstrukcja
  std::bind, jest trudniejsza w zrozumieniu. Wyrażenia lambda są bardziej uniwersalne.

```
int multiply(int first, int second) {
  return first * second;
}

int main() {
  int number = 10;

  // before C++11
  auto multiplyBy10 = std::bind(multiply, number, std::placeholders::_1);
  std::cout << multiplyBy10(20) << '\n';

  auto multiplyByX = [&number](int num){ return multiply(num, number); };
  std::cout << multiplyByX(20) << '\n';

  return 0;
}
```

___

### Możliwości wyrażenia lambda #3:

* W Lambdzie możemy także tworzyć własne zmienne, które maja taki sam czas życia jak to wyrażenie
  `[i{0}](const auto el){ return el + i; };
* Nie podajemy typu, gdyż domyślnie wyrażenie lambda dedukuje ten typ poprzez dane zawarte w `{}`.
* Domyślnie typ zwracany przez wyrażenie lambda również jest dedukowany na podstawie wyrażenia return
  `[i{0}](const int el){ return el + i; }; // typem zwracanym jest int
* Jeżeli chcemy narzucić konkretny typ zwracany robimy to poprzez `->`
  `[i{0}](const auto el) -> double { return el + i; };`
* Parametry przechwycone przez wyrażenie lambda w `[]` są domyślnie stałe. Dlatego nie musimy
  pisać `[const& first, const& second]` lub `[const&]`.
* Jeżeli chcemy mieć możliwość ich modyfikacji, musimy dodać ta informacje do lambdy słowem
  kluczowym `mutable`:
  `[i{0}](const auto el) mutable -> double { return el + i++; };`
  
___

### Możliwości wyrażenia lambda #4:

* C++17 umożliwia nam definiowanie `constexpr` lambd. Czyli wyrażeń lambda znanych już w trakcie kompilacji.

```
  int main() {
    constexpr auto factorial = [](int n){
      long long result = 1;
       for (int i = 1 ; i <= n ; ++i) {
         result *= i;
       }
       return result;
    };
    constexpr int num = 20;
    constexpr auto result = factorial(num);
    std::cout << result << '\n';
    static_assert(factorial(num) == 2432902008176640000);

    return 0;
  }
```
Obliczenie result nastąpi już w trakcie kompilacji. Gdyby tak nie było, `static_assert` nie skompilowałby się.
Dodatkowo, jeżeli wyrażenie lambda spełnia warunki `contexpr` to nie musimy nawet tego pisać, gdyż typ auto sam wydedukuje
taki typ.
___


### Ograniczenia wyrażenia lambda #1:

* Lambda nie może przechwytywać globalnych wartości (nawet jeżeli robimy to przez kopie!):
```
  int global_value = 5;

  int main() {
    auto lambda = [global_value](){ std::cout << global_value; };

    return 0;
}
```
Error:
```
  main.cpp:11:18: error: 'global_value' cannot be captured because it does not
        have automatic storage duration
    auto lambda = [global_value](){ std::cout << global_value; };
                   ^
  main.cpp:8:5: note: 'global_value' declared here
  int global_value = 5;
      ^
  1 error generated.
```
___

### Ograniczenia wyrażenia lambda #2:

* Analogicznie, lambda nie umożliwia nam przechwytywanie zmiennych statycznych. Gdyż tak jak zmienne globalne
  nie znajdują się one na stosie, tylko w specjalnym module `data`.
  
```
int main() {
  static int static_variable = 10;
  auto lambda = [static_variable](){ std::cout << static_variable; };

  return 0;
}
```
Error:
```
  main.cpp:10:18: error: 'static_variable' cannot be captured because it does not
        have automatic storage duration
    auto lambda = [static_variable](){ std::cout << static_variable; };
                   ^
  main.cpp:9:14: note: 'static_variable' declared here
    static int static_variable = 10;
               ^
  1 error generated.
```
___

### Jak ominąć ten problem?

Zastosujmy przechwytywanie przez `[=]` bądź `[&]`.

```
  int global_value = 5;

  int main() {
    auto lambda = [global_value](){ std::cout << global_value << '\n; };
    static int static_variable = 10;
    auto lambda2 = [static_variable](){ std::cout << static_variable << '\n'; };
    
    lambda();
    lambda2();
   }
```
output:
```
  5
  10
```

Pytanie? W jaki sposób kompilator przechwycił zmienna globalna? A jak statyczną?

___

### Odpowiedź

cppreference:

```
The identifier in any capture without an initializer (other than the this-capture) is looked up using usual unqualified name lookup in the reaching scope of the lambda. The result of the lookup must be a variable with automatic storage duration declared in the reaching scope.
```
Lambda tak naprawdę nie przechwytuje zmiennej statycznej czy globalnej poprzez `[&]` lub `[=]`. Ponieważ dostęp do tych danych
jest zapewniany przez specjalny blok w pamięci `data`. Dlatego nie trzeba nawet pisać `[&]` ani `[=]`.

```
 void foo(std::function<void(void)> fun) {
  fun();
 } 

int main() {
  static int static_variable = 10;
  std::cout << "Before call lambda: " << static_variable << '\n';
  auto lambda = []() mutable { std::cout << ++static_variable << '\n'; };
  foo(lambda);
  std::cout << "Outside lambda: " << static_variable << '\n';

  return 0;
 }
```
Output:
```
  Before call lambda: 10
  11
  Utside lambda: 11
```

### Pułapka:

Jeżeli przechwytujemy przez wartość (kopie) `[=]` i zapomnimy, że globalne zmienne, nie są przechwytywane.
Przypadkowo zmodyfikujemy tą zmienną mimo, że ani nie mamy słowa kluczowego `mutable` oraz przechwytujemy
wszystkie wartości przez wartość `[=]`.

```
  int global_val = 10;

  void foo(std::function<void(void)> fun) {
    fun();
  } 

  int main() {
    std::cout << "Before call lambda: " << global_val << '\n';
    auto lambda = [=](){ std::cout << ++global_val << '\n'; };
    foo(lambda);
    std::cout << "Outside lambda: " << global_val << '\n';

    return 0;
  }
```
output:
```
  Before call lambda: 10
  11
  Outside lambda: 11
```
___

### Jak kompilator interpretuje wyrażenie lambda

Kolejną zaletą wyrażeń lambda jest skrócony zapis. Otóż, jeżeli zrobimy sobie następujące wyrażenie:
```
int num = 5;
std::string str = "Hello World";

auto lambda = [num, &str](const int first, const std::vector<int>& second) { doSth(first, second); }`
```

Kompilator rozwinie to przykładowo do takiej postaci
```
struct NoName {
public:
  NoName(int num, const std::string& str): num_(num), str_(str) {}
  void operator()(const int first, const std::vector<int>& second) {
    doSth(first, second);
  }
private:
  int num_;
  std::string str_;
};
```
Oszczędność w pisaniu kodu!

___

## Q&A -> Tym razem przed zadaniami, bo temat trudny :)
___

## Zadanie1:

1. Utwórz predykat sprawdzający czy podana liczba jest podzielna przez 6, 2 oraz 3.
2. Utwórz lambdę, która wygeneruje ciąg znaków '*', kolejno: '*' '**' '***' etc.
   Przy każdym zawołaniu funkcji powinniśmy dostać ciąg `*` dłuższy o jeden.
3. Utwórz lambdę, która do podanego ciągu znaków doda cudzysłów. np krowa -> "krowa"
4. Utwórz lambdę, która przyjmie 2 argumenty typu int oraz zwróci ich iloczyn.

__

## Zadanie2:

1. Utwórz std::vector<int> i wypełnij go dowolnymi wartościami
2. Utwórz lambdę, która przechwyci ten wektor, oraz wyświetli jego wartość
3. Utwórz lambdę, która w swoim argumencie przyjmie int i go wyświetli.
4. Wykorzystaj tą lambdę w funkcji std::for_each() do wyświetlenia całego kontenera.

___

## Typy funktorów
___

### Generator

* Jest to funktor, który nie przyjmuje żadnych argumentów, natomiast zwraca wartość 
  pożądanego typu
  
* `[](){ retunr 1; }` -> najprostszy generator
* `[i{0}]() mutable { return i++; };` -> generator zwracający liczby od 0 do x;
* 
  ```
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(1, 6);

    auto generator = [&](){ return dis(gen); };
  ```
  -> generator zwracający liczby losowe dla danego rozkładu. W naszym przypadku od 1 do 6.

___
  
### Unary function

* Jest to funktor, który przyjmuje jeden argument (i opcjonalnie zwraca jakąś wartość).
* Szczególnym typem `unary function` jest funktor przyjmujący jeden argument 
  i zwracający typ `bool`. Taki funktor nazywa się predykatem.
 
* `[](const auto& el){ return el - 3; }` -> funktor odejmujący od każdej podanej mu liczby.
  wartość `3`.
* `[](const auto& el){ return el % 2; }` -> predykat sprawdzający czy liczba jest nieparzysta.
* `[&pattern](const auto& el){ return el == pattern; }` -> predykat sprawdzający
   czy podany wzór (`pattern`) jest zgodny z elementem podanym, jako argument.
   
___
  
### Binary function   

* Jest to funktor przyjmujący 2 argumenty (i opcjonalnie zwracającym wartość).
* Najczęstszym przykładem takiego funktora jest operator porównania `operator==`

* `[](const auto& lhs, const auto& rhs){ return lhs != rhs; }` -> Funktor sprawdzający
  czy `lhs` jest różny od `rhs`.
* `[](const auto& sum, const auto value){ return sum += value; }` -> Funktor sumujący
  wszystkie wartośći `value` i zapisujący je w zmiennej `sum`.
* `[](const auto& first, const auto& second){ return first / second}` -> Funktor
  wykonujący dzielenie wartości `first` przez wartośc `second`.
  
___

## Q&A
___

## Algorytmy niemodyfikujące kontenery
___

### std::find_if

```
template< class InputIt, class UnaryPredicate >
InputIt find_if( InputIt first, InputIt last,
                 UnaryPredicate p );
```
* Algorytm wykorzystywany do wyszukiwania interesujących nas elementów. O tym co nas interesuje
  będzie decydować przekazany predykat. Jeżeli chcemy liczby podzielnie przez 3 użyjemy predykatu:
  `[](const auto& el){ return (el / 3 == 0); }`
* `std::find_if` rózni się od `std::find` tylko tym, że zamiast poszukiwanej wartości, podajemy
  predykat jaki musi zostać spełniony aby uznać dany element za poszukiwana wartość.
* Typem zwróconym przez `std::find_if` jest iterator, wskazujący na znaleziony element.
* Jeżeli element nie został znaleziony, wartością zwróconą będzie równy `last`.

___

### std::find_if użycie

```
  std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto found = std::find_if(begin(vec), end(vec),
    [](const auto& el){
        return el == 7;
    });
  if (found != vec.end())
    std::cout << *found << '\n';
```
Output: `found 7`
___

### std::search

```
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

### std::search użycie
  
```
  std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> vec2 {4, 5, 6};
  auto found = std::search(begin(vec), end(vec),
                          begin(vec2), end(vec2));
  if (found != vec.end())
    std::cout << "first found element: " << *found << '\n';
```
Output: `first found element: 4`

  ___

### std::count oraz std::count_if

```
template< class InputIt, class T >
typename iterator_traits<InputIt>::difference_type
    count( InputIt first, InputIt last, const T &value );
```
```
template< class InputIt, class UnaryPredicate >
typename iterator_traits<InputIt>::difference_type
    count_if( InputIt first, InputIt last, UnaryPredicate p );
```
* `std::count` zlicza dla danego zakresu wystąpienie konkretnej wartości. 
* `std::count_if` zlicza dla danego zakresu ilość zwróconych `true` przez predykat.

  ___
  

### std::count oraz std::count_if użycie

```
  std::vector<int> vec {1, 2, 3, 4, 5, 1, 1, 1, 6, 7};
  std::cout << std::count(begin(vec), end(vec), 1) << '\n';
  std::cout << std::count_if(begin(vec), end(vec),
    [](const auto& el){
      return el % 3 == 0;
    });
```
Output:
```
4
2
```

  ___
  
### std::equal

```
  template< class InputIt1, class InputIt2 >
  bool equal( InputIt1 first1, InputIt1 last1,
              InputIt2 first2 );
```
```
  template< class InputIt1, class InputIt2 >
  bool equal( InputIt1 first1, InputIt1 last1,
              InputIt2 first2, InputIt2 last2 )
```
* Algorytm przyjmuje zakres pierwszego kontenera oraz początek drugiego kontenera. Funkcja będzie dokonywać
  sprawdzenia, aż nie dojdzie do końca 1 zakresu. Nawet jeżeli 2 zakres jest dłuższy. Jeżeli 2 zakres jest krótszy
  to funkcja zwróci false, gdyż na pewno 1 zakres nie będzie identyczny ponieważ jest dłuższy.
* Wersja druga algorytmu, pozwala przyjąć pełny zakres 1 i 2 kontenera i porównać te zakresy.

___
  
### std::count oraz std::count_if użycie #1
  
```
  std::cout << std::boolalpha << "EQUAL?: "
    << std::equal(begin(vec1), end(vec1), begin(vec2)) << '\n';
  std::cout << std::boolalpha << "EQUAL?: "
    << std::equal(begin(vec2), end(vec2), begin(vec1)) << '\n';
  std::cout << std::boolalpha << "EQUAL?: "
    << std::equal(begin(vec1), end(vec1), 
        begin(vec2), std::next(vec2.begin(), 5)) << '\n';
```
Output:
```
  EQUAL?: true
  EQUAL?: false
  EQUAL?: true
```
___

### std::count oraz std::count_if użycie #2

```
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

```
  "radar" is a palindrome
  "hello" is not a palindrome
```
___

### std::mismatch

```
template< class InputIt1, class InputIt2 >
std::pair<InputIt1,InputIt2>
    mismatch( InputIt1 first1, InputIt1 last1,
              InputIt2 first2 );
```
```
template< class InputIt1, class InputIt2 >
std::pair<InputIt1,InputIt2>
    mismatch( InputIt1 first1, InputIt1 last1,
              InputIt2 first2, InputIt2 last2 );
```

Działa analogicznie do equal. Z tym wyjątkiem, że zwraca parę iteratorów (dla pierwszego i drugiego zakresu)
wskazującą początek niezgodności.

  ___
  
### std::mismatch użycie:
``` 
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
```
  ab
  a
  aba
```
___
  
## Q&A
___

## Algorytmy modyfikujące kolejność elementów

___

### std::copy and std::copy_if

```
template< class InputIt, class OutputIt >
OutputIt copy( InputIt first, InputIt last, OutputIt d_first );
```
```
template< class InputIt, class OutputIt, class UnaryPredicate >
OutputIt copy_if( InputIt first, InputIt last,
                  OutputIt d_first,
                  UnaryPredicate pred );
```
* Podstawowa wersja copy, kopiuje podany zakres do innego zakresu. Przykładowo kopiuje elementy z wektora do listy.
* `std::copy_if` kopiuje tylko te elementy które spełniają podany przez nas predykat. Np. ::is_upper, ::is::digit.

___

### std::copy and std::copy_if użycie:

```
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
```
  1 2 3 4 5 
  1 3 5 
```
___

### std::fill
```
template< class ForwardIt, class T >
void fill( ForwardIt first, ForwardIt last, const T& value );
```

Funkcja wypełnia podany zakres wartościami `value`

```
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

### std::transform -> Potężny algorytm, mogący zrobić dużo więcej niż się wydaje na początku :)
```
template< class InputIt, class OutputIt, class UnaryOperation >
OutputIt transform( InputIt first1, InputIt last1, OutputIt d_first,
                    UnaryOperation unary_op );
```
```
template< class InputIt1, class InputIt2, class OutputIt, class BinaryOperation >
OutputIt transform( InputIt1 first1, InputIt1 last1, InputIt2 first2,
                    OutputIt d_first, BinaryOperation binary_op );
```
* Pierwsza wersja `std::transform` przyjmuje zakres, oraz wykonuje na każdym elemencie operacje `unary_op`
  a następnie zapisuje ten zmodyfikowany element w drugim zakresie.
* Druga wersja, przyjmuje 2 zakresy, wykonuje na nich operacje `binary_op` ,czyli pobieram z każdego zakresu po 1 elemencie
  i wykonuje na nich operacje, następnie zapisuje wynik w 3 zakresie.
___  
  
### std::transform przykład użycia #1

Konwersja jednego typu kontenera na drugi

```
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

### std::transform przykład użycia #2
Konwersja kontenera
```
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

### std::transform przykład użycia #3
Zamiana znaków na małe litery
```
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
Output: `zero one two three four five `

___

### std::transform przykład użycia #4

Sumowanie Wartości wektora i listy:

```
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
Output: `11 22 33 44 55 66 77 88 `
__

### std::generate 

```
  template< class ForwardIt, class Generator >
  void generate( ForwardIt first, ForwardIt last, Generator g );
```

Funkcja służąca do generowania jakiś danych.

```
int main() {
  std::vector<int> vec(10);
  std::generate(begin(vec), end(vec), [i {0}]() mutable { return i++; });
  print(vec);

  return 0;
}
```
Output: `0 1 2 3 4 5 6 7 8 9`
__

### std::swap_ranges

```
template< class ForwardIt1, class ForwardIt2 >
ForwardIt2 swap_ranges( ForwardIt1 first1, ForwardIt1 last1,
                        ForwardIt2 first2 );
```

Podmienia pewien zakres danych

```
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
```
  10 20 30 4 5 6 7 8 
  1 2 3 40 50 60 70 80
```
___

### std::reverse
```
template< class BidirIt >
void reverse( BidirIt first, BidirIt last );
```
Odwraca zakres
```
int main() {
  std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8};
  std::reverse(begin(vec), end(vec));
  print(vec);

  return 0;
}
```
Out: `8 7 6 5 4 3 2 1`

__

## std::unique

```
template< class ForwardIt >
ForwardIt unique( ForwardIt first, ForwardIt last );
```
Usuwa duplikaty. Ważne, kontener musi byc posortowany. Tak naprawdę to funkcja nie usuwa duplikatów,
lecz przenosi unikalne wartości na początek kontenera (nie zmieniając ich kolejności) oraz zwraca
iterator wskazujący pierwszy element, gdzie zaczynają się duplikaty.
```
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
```
  1 2 3 1 1 2 2 2 2 2 3 3 3 
  1 2 3
```
__

### Zadanie 3

1. Stwórz std::vector<int>
2. Wypełnij go elementami nieparzystymi licząc o 1 do 15
3. Odwróć kontener nie używając pętli ani std::reverse.
4. Przepisz std::vector<int> do listy używając copy
5. Stwórz drugi vector<int> i wypełnij go liczbami parzystymi od 0 do 14.
6. Znajdź sposób jak połączy oba std::vector w jeden zawierający wartości od 0 do 15 ułożone po kolei.

__

### Zadanie 4

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

Postaraj się poprawić program z poprzednich zajęć (kompresja, dekompresja) obrazków, 
tak, aby zamiast pętli wykorzystać algorytmy.

### Zadanie 2

Napisz program, który będzie sprawdzał, czy podany ciąg wyrazów jest palindromem. 
Program powinien ignorować znaki specjalne jak `,` wielkość liter oraz białe znaki jak spacja.

### Zadanie 3

1) Napisz funkcję, która przyjmie `std::list<std::string>` oraz `std::deque<int>`.
2) Usunie duplikaty z obu kontenerów.  
3) Na koniec skonwertuje to na `std::map<int, std::string>` i ją zwróci (użyj std::transform).
___
  
### Zadanie 4 #1
Napisz program advanced_calculator. Program ten powinien posiadać pętle główną, która będzie przyjmować dane od użytkownika, np. dla 5 % 3 zwrócić wynik 2. Wszystkie komendy kalkulatora powinny być przechowywane w mapie. Która jako klucz `char` w postaci znaku odwołującego się do komendy (np. + -> dodaj ,  % -> modulo) a jej wartością powinna być funkcja std::function<> będąca wraperem na wyrażenia lambda dokonujące określonej kalkulacji. Program powinien także zwracać odpowiedni error code, jeżeli użytkownik poda złe dane. Np. dzielenie przez 0 lub spróbuje dodać `ala + 5`.
Input: 5 + 5 -> operacja dodawania dwóch liczb 5 i 5 -> output: 10.
Input: 5 ^ 2 -> operacje potęgowania -> output 25.
Input 125 $ 3  -> operacja pierwiastka (sqrt za długie), pierwiastek sześcienny z 125 -> output: 5.
____
  
### Zadanie 4 #2

Funkcje kalkulatora:
- Dodawanie, mnożenie, dzielenie, odejmowanie, (+, *,  /, -),
- Modulo (%),
- Obliczanie silni (!),
- Podnoszenie liczby do potęgi (^),
- Obliczanie pierwiastka ($).

____

### Zadanie 4 #3

Error code:
- Ok,
- BadCharacter -> Jeżeli użytkownik poda znak inny niż liczbę.
- BadFormat -> Jeżeli użytkownik poda zły format komendy np. + 5 4, powinno być 4 + 5.
- DivideBy0 -> dzielenie przez 0.
- SqrtOfNagativeNumber -> pierwiastek z liczby ujemnej. 
- ModuleOfNonIntegerValue -> Póba obliczenia % na liczbie niecałkowitej. 
___

### Zadanie 4 #3

Funkcja, która będzie testowana:
* ErrorCode process(std::string input, double* out)
* Funkcja ta powinna w pętli przyjmować kolejne dane od użytkownika oraz dokonywać odpowiedniej kalkulacji.
* Jeżeli dane są poprawne, zwróci 'ErrorCode:Ok', a w zmiennej out zapisze dane.
* Jeżeli wystąpi któryś z błędów, funkcja go zwodzi a w out nie zapisze nic.

____
