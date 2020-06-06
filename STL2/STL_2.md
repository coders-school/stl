<!-- .slide: data-background="#111111" -->

# AGENDA

* <!-- .element: class="fragment fade-in" --> Funktory
* <!-- .element: class="fragment fade-in" --> Lambda
* <!-- .element: class="fragment fade-in" --> Typy funktorów
* <!-- .element: class="fragment fade-in" --> Algorytmy niemodyfikujące kontenery
* <!-- .element: class="fragment fade-in" --> Algorytmy modifukujące kolejność elementów
* <!-- .element: class="fragment fade-in" --> Algorytmy sortujące
* <!-- .element: class="fragment fade-in" --> Algorytmy binarne
* <!-- .element: class="fragment fade-in" --> Algorytmy min max

___

## Funktory

___

### Czym jest Funktor?

Funktor jest to obiekt, który może zostać wywołany jak zwykła funkcja. Każda klasa oraz struktóra, 
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

### std::function

W standardzie C++ znajdziemy biblioteke o nazwie <functional>, która umożliwia nam korzystanie z std::function<>
krótko mówiąc jest to `wrapper` na funckje. 

przykładowo:
`std::function<void(int, double)>` to nic innego jak `wrapper` na funkjcę void(int, double). Czyli nie zwracającej
żadnego argumentu a przyjmującego 2 argumenty typu int oraz double.

`std::function<int(const std::string&, int * const)>` to `wrapper` na funkjcę przyjmującą jako pierwszy argument
stała referencje na obiekt typu string oraz stały wskaźnik na typ int. Funckja ta zwraca typ int.

___

### Użycie std::function

Z std::function<> korzystamy tak samo jak ze zwykej funckji.

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

### Użycie std::function

std::function możemy wykorzystać jako wrapper do funckji, która zostanie
zawołana (taka funkcja z angielskiego nosi nazwę callback),
gdy zakończy się działanie innej funkcji (np. działającej na innym wątku).

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

## Lambda

___

### Czym jest wyrażenie lambda?

* W C++11 wprowadzono takzwane wyrażenie lambda. Jest to nic innego jak obiekt funkcyjny,
  który może zostać wywołany dla kokretnych parametrów i zwrócić wynik. 
* Dzięki swojej prostocie w budowie `[](){}` możan zwięzle napisać obiekt funkcyjny,
  który normalnie zanjąłby nam kilka razy więcej miejsca.
* Zyskujemy lepszą czytelnośc, oraz większą swobode w działaniu.
* Typ lambdy nazywa się dokmnięciem (ang. clousure).
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

### Możliwości wyrażenia lambda 1/3:

* [] -> Nawias ten określa jakie parametry chcemy przechwycić do naszego wyrażenia
  Możemy np. chiec przechwycić nazwę jakiegoś pliku, może jaką zmienną, z którą będziemy
  chcieli porównywać każdy element kontenera itp.
* Wartości możemy przechwycić przez referencję `[&value]` 
* Możemy je także przechwycić przez kopie `[value]`
* Wyrażenia lambda umożliwia także przechwycenie wszystkiego co potrzebujemy:
   * poprzez kopie [=]
   * poprzez referencje [&]
* Wszystkiego co potrzebne rozumiemy w kontekscie, ze tylko to co wykorzystane jest
  wewnątrz ciała lambdy czyli pomiędzy `{}`.
* O ile [=] jest bezpiecne, to [&] nie zwsze jest zalecane.

Pytanie: kiedy [&] może byc niebezpieczne?

___

### Możliwości wyrażenia lambda 2/3:

* Od C++14 możemy pisać tzw. generyczne lambdy. Czyli lambdy wielokrotnego użytku (dla róznych typów).
  `[](const auto first, const auto& second, auto third){}`
* Pisanie generycznych lambd jest opłacalne, ponieważ łatwo można ją wielokrotnie wykorzystać.
* Przed C++11 bardzo często wykorzystywany był `std::bind`, w celu przekazania jakis argumentów do funckji.
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

### Możliwości wyrażenia lambda 3/3:

* W Lambdzie możemy także tworzyć własne zmienne, które maja taki sam czas życia jak to wyrażenie
  `[i{0}](const auto el){ return el + i; };
* Nie podajemy typu, gdyż domyślnie wyrażenie lambda dedukuje ten typ poprzez dane zawarte w `{}`.
* Domyślnie typ zwracany przez wyrażenie lambda również jest dedukowany na podstawie wyrażenia return
  `[i{0}](const int el){ return el + i; }; // typem zwracanym jest int
* Jeżeli chcemy narzucić konkretny typ zwracany robimy to poprzez `->`
  `[i{0}](const auto el) -> double { return el + i; };`
* Parametry przechwycone przez wyrażenie lambda w `[]` są domyslnie stałe. Dlatego nie musimy
  pisać `[const& first, const& second]` lub `[const&]`.
* Jeżeli chcemy miec możliwośc ich modyfikacji, musimy dodać ta informacje do lambdy słowem
  kluczowym `mutable`:
  `[i{0}](const auto el) mutable -> double { return el + i++; };`
  
___

### Jak kompilator interpretuje wyrażenie lambda

Kolejną zaletą wyrażeń lambda jest skórcony zapis. Otóz jeżeli zrobimy sobie następujące wyrażenie:
```
int num = 5;
std::string str = "Hello World";

auto lambda = [num, &str](const int first, const std::vector<int>& second) { doSth(first, second); }`
```

Komiplator rozwinie to przykładowo do takiej postaci
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
Oszczędnośc w pisaniu kodu!

___

## Q&A
___

## Typy funktorów
___

### Generator

* Jest to funktor, kóry nie przyjmuje żadnych argumentów, natomiast zwraca wartość 
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
  -> generator zwracajacy liczby losowe dla danego rozkładu. W naszym przypadku od 1 do 6.

___
  
### Unary function

* Jest to funktor, który przyjmuje jeden arguemnt (i opcjonalnie zwraca jakąś wartość).
* Szczególnym typem `unary function` jest funktor przyjmujący jeden argument 
  i zwracający typ `bool`. Taki funktor nazywa się predykatem.
 
* `[](const auto& el){ return el - 3; }` -> funktor odejmujący od każdej podanej mu liczby.
  wartość `3`.
* `[](const auto& el){ return el % 2; }` -> predykat sprawdzający czy liczba jest nieparzysta.
* `[&pattern](const auto& el){ return el == pattern; }` -> predykat sprawdzający
   czy podany wzór (`pattern`) jest zgodny z elementem podanym jako argument.
   
___
  
### Binary function   

* Jest to funktor przyjmujący 2 argumenty (i opcjonalnie zwracającym wartość).
* Najczęstszym przykładem takiego funktora jest oprator porównania `operator==`

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
* `std::find_if` rózni się od `std::find` tylko tym, że zamiast poszukiwanej wartośći, podajemy
  predykat jaki musi zostać spełniony aby uznać dany element za poszukiwana wartość.
* Typem zwróconym przez `std::find_if` jest iterator, wskazujący na znaleziony element.
* Jeżeli element nie został znaleziony, wartośćią zwróconą będzie równy `last`.

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
* Najprostsza wersja std::search, przyjmuje 2 zakresy i sprawdza, czy zarkres drugi `{s_first, s_last}`
  jest podzakresem `{first, last}`. Jeżeli tak zwraca iterator wskazujący na początek tego podzakresu.
* Jeżeli podzakres nie zostanie znaleziony, zwrócony iterator będzie równy `last`.
* Istnieją także wersje `std::search`, przyjmujących `binary predicate` oraz typ `searcher`. zachęcam
  Was do samodzielnej pracy w celu zdobycia wiedzy, jak wykorzystać te funckje :).
  
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
* `std::count` zlicza dla danego zakresu wystąpienie konkretnej wartośći. 
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
