<!-- .slide: data-background="#111111" -->

# Wyrażenia lambda

## Nowoczesne funktory

<a href="https://coders.school">
    <img width="500" data-src="../img/coders_school_logo.png" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Wyrażenie lambda w akcji

```cpp []
// struct Functor {
//     int index = 0;
//
//     void operator()(int el) {
//         std::cout << index << ": " << el << " | ";
//         index++;
//     }
// };

int main() {
    std::vector<int> vec {1, 2, 3, 4, 5};
    std::for_each(begin(vec), end(vec), [index = 0](int el) mutable {
        std::cout << index << ": " << el << " | ";
        index++;
    });
    std::cout << '\n';

    return 0;
}
```
<!-- .element: class="fragment fade-in" -->

output: `0: 1 | 1: 2 | 2: 3 | 3: 4 | 4: 5 | `
<!-- .element: class="fragment fade-in" -->

___

## Czym jest wyrażenie lambda?

* <!-- .element: class="fragment fade-in" --> Wprowadzone w C++11, ulepszane w C++14, C++17, C++20
* <!-- .element: class="fragment fade-in" --> Lambda to obiekt funkcyjny, który może zostać wywołany dla konkretnych parametrów i zwrócić wynik
* <!-- .element: class="fragment fade-in" --> Prosta w budowie - <code>[](){}</code>
* <!-- .element: class="fragment fade-in" --> Służy do zwięzłego zapisu obiektu funkcyjnego, który normalnie zająłby nam trochę więcej miejsca
* <!-- .element: class="fragment fade-in" --> Zyskujemy lepszą czytelność oraz większą swobodę w działaniu
* <!-- .element: class="fragment fade-in" --> Typ lambdy nazywa się domknięciem (ang. closure) i jest znany tylko kompilatorowi
* <!-- .element: class="fragment fade-in" --> Aby przypisać wyrażenie lambda do zmiennej musimy być ona typu auto, ponieważ tylko kompilator zna typ tego wyrażenia

___

## Tworzenie prostych wyrażeń lambda

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    []() { std::cout << "Hello"; }  // lambda printing Hello (not called)

    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vec.erase(std::remove_if(vec.begin(),
                             vec.end(),
                             [](int num) { return num % 2; }),
              vec.end());

    auto print = [](int num) { std::cout << num << ' '; };  // named lambda
    std::for_each(vec.begin(), vec.end(), print);

    return 0;
}
```

___

## Lista przechwytująca (capture list) - przykład

```cpp []
int main() {
    int number = 10;
    auto add10 = [number](int num) { return num + number; };
    std::cout << add10(20) << '\n';  // 30

    // auto multiplyByX = [](int num) { return num * number; };
    // compilation error: number not declared

    return 0;
}
```

___

## Lista przechwytująca (capture list)

* <!-- .element: class="fragment fade-in" --> Kwadratowy nawias <code>[]</code> określa, jakie parametry chcemy przechwycić do naszego wyrażenia. Możemy np. chcieć przechwycić jakąś zmienną, z którą będziemy chcieli porównywać każdy element kontenera
* <!-- .element: class="fragment fade-in" --> Wartości możemy przechwycić przez referencję <code>[&value]</code>
* <!-- .element: class="fragment fade-in" --> Możemy je także przechwycić przez kopię <code>[value]</code>
* <!-- .element: class="fragment fade-in" --> Możemy też mieszać obie możliwości <code>[&by_ref, by_copy, by_copy2]</code>
* <!-- .element: class="fragment fade-in" --> Wyrażenia lambda umożliwia także przechwycenie wszystkiego, co potrzebujemy:
  * poprzez kopię `[=]`
  * poprzez referencję `[&]`
* <!-- .element: class="fragment fade-in" --> O ile <code>[=]</code> jest bezpieczne, to <code>[&]</code> nie zawsze jest zalecane

Pytanie: kiedy `[&]` może być niebezpieczne?
<!-- .element: class="fragment fade-in" -->

___

## Generyczne lambdy

* Od C++14 możemy pisać tzw. generyczne lambdy
* Są to lambdy wielokrotnego użytku (dla różnych typów) i używamy w nich typu `auto` jako parametru
  * `[](const auto first, const auto& second, auto third) {}`
* Pisanie generycznych lambd jest opłacalne, ponieważ łatwo można je wielokrotnie wykorzystać

```cpp []
int main() {
    int number = 10;
    auto multiplyByX = [&number](auto num) { return num * number; };
    std::cout << multiplyByX(20) << '\n';
    std::cout << multiplyByX(3.14) << '\n';

    return 0;
}
```

___

## Zadania

1. Utwórz lambdę, która przyjmie 2 argumenty typu `int` oraz zwróci ich iloczyn
2. Utwórz lambdę, która do podanego ciągu znaków doda cudzysłów. np.
   * `krowa` -> `"krowa"`
3. Utwórz lambdę, która wypisze ciąg znaków `*`. Przy każdym zawołaniu funkcji powinniśmy dostać ciąg dłuższy o jedną `*`. Kolejno:
   * `*`
   * `**`
   * `***`
   * itd.

___

## Zadania

1. Utwórz `std::vector<int>` i wypełnij go dowolnymi wartościami
2. Utwórz lambdę, która przechwyci ten wektor, oraz wyświetli jego zawartość
3. Utwórz lambdę, która w swoim argumencie przyjmie `int` i go wyświetli
4. Wykorzystaj lambdę z pkt. 3 w algorytmie `std::for_each()` do wyświetlenia całego kontenera
