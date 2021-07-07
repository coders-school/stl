<!-- .slide: data-background="#111111" -->

# Wskaźniki na funkcje

<a href="https://coders.school">
    <img width="500" data-src="../img/coders_school_logo.png" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Po co nam wskaźniki na funkcje?

Przede wszystkim, możemy dzięki nim przekazywać funkcje jako argumenty funkcji.
<!-- .element: class="fragment fade-in" -->

___

## Przykład - callback

Możemy dzięki nim stworzyć tzw. mechanizm callback. Dzięki niemu mówimy, co ma się stać, gdy funkcja zakończy swoją pracę.
<!-- .element: class="fragment fade-in" -->

Na razie jako typu używam `auto`, żeby tylko pokazać istotę działania tego mechanizmu.
<!-- .element: class="fragment fade-in" -->

```cpp []
void function(auto ptrToFunction) {  // auto is conceptual, it may not work
    doSomeJob();
    // finished!
    ptrToFunction();
}
```
<!-- .element: class="fragment fade-in" -->

Dzięki takiemu podejściu nie musimy sami czekać na moment zakończenia się funkcji `function` aby zawołać jakąś funkcję, bo mechanizm callback robi to za nas.
<!-- .element: class="fragment fade-in" -->

Co więcej, nie zmieniając implementacji funkcji `function` możemy zmieniać jej zachowanie.
<!-- .element: class="fragment fade-in" -->

___

## Przykład - custom algorithm

Możemy też "customizować" zachowanie innych funkcji czy algorytmów.
<!-- .element: class="fragment fade-in" -->

```cpp []
int compute(int a, int b, auto operation) {  // auto is conceptual, it may not work
    return operation(a, b);
}

int sum(int a, int b) {
    return a + b;
}

int multi(int a, int b) {
    return a * b;
}

auto s = compute(2, 3, sum);    // s = 5
auto m = compute(2, 3, multi);  // m = 6
```
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.83em" -->

## Jaki typ ma wskaźnik na funkcje?

To zależy od sygnatury funkcji.
<!-- .element: class="fragment fade-in" -->

```cpp []
void (*f1)();
int (*f2)(int);
int (*f3)(double, std::vector<int>);
```
<!-- .element: class="fragment fade-in" -->

Możemy od razu przypisać im funkcje. Jeśli sygnatury nie będą się zgadzać dostaniemy błąd kompilacji.
<!-- .element: class="fragment fade-in" -->

```cpp []
void function() {
    std::cout << "I'm a function!\n";
}

int triple(int value) {
    return 3 * value;
}

void (*f1)() = function;
int (*f2)(int) = triple;
int (*f3)(double, std::vector<int>) = nullptr;
```
<!-- .element: class="fragment fade-in" -->

Wywołanie `f2(4)` spowoduje wykonanie funkcji triple z argumentem 4.
<!-- .element: class="fragment fade-in" -->

Wywołanie np. `f3(3.14, {1, 2, 3})` to undefined behavior, ponieważ f3 nie wskazuje na żadną funkcję.
<!-- .element: class="fragment fade-in" -->

___

## Jak tworzyć wskaźniki na funkcje?

Wystarczy skopiować sygnaturę funkcji a zamiast nazwy podać nazwę wskaźnika poprzedzoną gwiazdką. To wszystko w nawiasie, bo inaczej będzie błąd składniowy.
<!-- .element: class="fragment fade-in" -->

```cpp []
int triple(int value) {
    return 3 * value;
}

int (*ptr)(int);
```
<!-- .element: class="fragment fade-in" -->

Najlepiej jednak zgodnie z dobrymi praktykami od razu inicjalizować wskaźniki. Wtedy używajmy `auto` 🙂
<!-- .element: class="fragment fade-in" -->

```cpp []
int triple(int value) {
    return 3 * value;
}

auto ptr = triple;
```
<!-- .element: class="fragment fade-in" -->

___

## Przekazywanie wskaźnika na funkcje

Tak wygląda przekazanie wskaźnika na funkcję do innej funkcji.

```cpp []
int compute(int a, int b,  int (*operation)(int, int)) {
    return operation(a, b);
}

int sum(int a, int b) {
    return a + b;
}

int multi(int a, int b) {
    return a * b;
}

auto s = compute(2, 3, sum);    // s = 5
auto m = compute(2, 3, multi);  // m = 6
```
