<!-- .slide: data-background="#111111" -->

# Wyrażenia lambda

## Nowoczesne funktory

<a href="https://coders.school">
    <img width="500" data-src="../img/coders_school_logo.png" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Czym jest wyrażenie lambda?

* Wprowadzone w C++11, ulepszane w C++14, C++17, C++20
* Lambda to obiekt funkcyjny, który może zostać wywołany dla konkretnych parametrów i zwrócić wynik
* Prosta w budowie - `[](){}`
* Służy do zwięzłego zapisu obiektu funkcyjnego, który normalnie zająłby nam kilka razy więcej miejsca
* Zyskujemy lepszą czytelność oraz większą swobodę w działaniu
* Typ lambdy nazywa się domknięciem (ang. closure) i jest znany tylko kompilatorowi
* Aby przypisać wyrażenie lambda do zmiennej musimy być ona typu auto, ponieważ tylko kompilator zna typ tego wyrażenia

___

## Utworzenie prostego wyrażenia lambda

```cpp []
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    []() { std::cout << "Hello"; }    // lambda printing Hello (not called)

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

* Kwadratowy nawias `[]` określa, jakie parametry chcemy przechwycić do naszego wyrażenia. Możemy np. chcieć przechwycić jakąś zmienną, z którą będziemy chcieli porównywać każdy element kontenera
* Wartości możemy przechwycić przez referencję `[&value]`
* Możemy je także przechwycić przez kopię `[value]`
* Możemy też mieszać obie możliwości `[&by_ref, by_copy, by_copy2]`
* Wyrażenia lambda umożliwia także przechwycenie wszystkiego, co potrzebujemy:
  * poprzez kopię `[=]`
  * poprzez referencję `[&]`
* O ile `[=]` jest bezpieczne, to `[&]` nie zawsze jest zalecane

Pytanie: kiedy [&] może być niebezpieczne?

___

## Generyczne lambdy

* Od C++14 możemy pisać tzw. generyczne lambdy
* Są to lambdy wielokrotnego użytku (dla różnych typów) i używamy w nich typu `auto` jako parametru
  * `[](const auto first, const auto& second, auto third) {}`
* Pisanie generycznych lambd jest opłacalne, ponieważ łatwo można je wielokrotnie wykorzystać

```cpp []
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

## Typ zwracany

* Nie podajemy typu zwracanego, gdyż domyślnie wyrażenie lambda dedukuje ten typ poprzez dane zawarte w jej ciele `{}`
* Domyślnie typ zwracany przez wyrażenie lambda jest dedukowany na podstawie wyrażeń `return`

  ```cpp []
  [i{0}](const int el){ return el + i; }; // return type is int
  ```

* Jeżeli chcemy narzucić konkretny typ zwracany robimy to poprzez `->`

  ```cpp []
  [i{0}](const auto el) -> double { return el + i; };
  ```

___

## Q&A

### Tym razem przed zadaniami, bo temat trudny :)

___

## Zadanie

1. Utwórz funktor sprawdzający czy podana liczba typu `int` jest podzielna przez `6`
2. Utwórz lambdę, która przyjmie 2 argumenty typu `int` oraz zwróci ich iloczyn
3. Utwórz lambdę, która do podanego ciągu znaków doda cudzysłów. np.
   * `krowa` -> `"krowa"`
4. Utwórz lambdę, która wypisze ciąg znaków `*`. Przy każdym zawołaniu funkcji powinniśmy dostać ciąg dłuższy o jedną `*`. Kolejno:
   * `*`
   * `**`
   * `***`
   * itd.

___

## Zadanie

1. Utwórz `std::vector<int>` i wypełnij go dowolnymi wartościami
2. Utwórz lambdę, która przechwyci ten wektor, oraz wyświetli jego zawartość
3. Utwórz lambdę, która w swoim argumencie przyjmie `int` i go wyświetli
4. Wykorzystaj tą lambdę w algorytmie `std::for_each()` do wyświetlenia całego kontenera
