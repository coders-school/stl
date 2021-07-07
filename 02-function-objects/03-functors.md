<!-- .slide: data-background="#111111" -->

# Funktory

## Obiekty funkcyjne

<a href="https://coders.school">
    <img width="500" data-src="../img/coders_school_logo.png" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___
<!-- .slide: style="font-size: 0.9em" -->

## Czym jest funktor?

Funktor jest to obiekt, który może zostać wywołany jak zwykła funkcja. Alternatywną nazwą dla funktora jest obiekt funkcyjny.
<!-- .element: class="fragment fade-in" -->

Każda klasa oraz struktura, która posiada zdefiniowany `operator()` może pełnić rolę funktora.
<!-- .element: class="fragment fade-in" -->

```cpp []
struct Functor {
    void operator() () {
        std::cout << "I'm a functor!\n";
    }
};

int main() {
    Functor funct{};
    funct();      // named object
    Functor{}();  // temporary object

    return 0;
}
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```text
I'm a functor!
I'm a functor!
```
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## Wykorzystanie funktorów

Funktory możemy wykorzystać w algorytmach STL.
<!-- .element: class="fragment fade-in" -->

Przykładowo algorytm `for_each` dla każdego elementu wywołuje on przekazany funktor.
<!-- .element: class="fragment fade-in" -->

Sam funktor za swój jedyny argument musi przyjmować typ elementu z zakresu, na którym pracuje.
<!-- .element: class="fragment fade-in" -->

```cpp []
struct Functor {
    void operator()(int el) {
        std::cout << el << ' ';
    }
};

int main() {
    std::vector<int> vec {1, 2, 3, 4, 5};
    std::for_each(begin(vec), end(vec), Functor{});
    std::cout << '\n';

    return 0;
}
```
<!-- .element: class="fragment fade-in" -->

output: `1 2 3 4 5`
<!-- .element: class="fragment fade-in" -->

___

## Funktor vs wskaźnik na funkcję

### Pytanie
<!-- .element: class="fragment fade-in" -->

Czy w algorytmach STL można zamiast funktora używać wskaźnika na funkcje?
<!-- .element: class="fragment fade-in" -->

### Odpowiedź
<!-- .element: class="fragment fade-in" -->

Tak. Nawet zapis wygląda na łatwiejszy.
<!-- .element: class="fragment fade-in" -->

```cpp []
void fun(int el) {
    std::cout << el << ' ';
}

int main() {
    std::vector<int> vec {1, 2, 3, 4, 5};
    std::for_each(begin(vec), end(vec), fun);
    std::cout << '\n';

    return 0;
}
```
<!-- .element: class="fragment fade-in" -->

___

## Funktor vs wskaźnik na funkcję

### Pytanie
<!-- .element: class="fragment fade-in" -->

To jaka jest różnica między jednym i drugim?
<!-- .element: class="fragment fade-in" -->

### Odpowiedź
<!-- .element: class="fragment fade-in" -->

Funktor to obiekt klasy. Może on więc żyć przez pewien czas i przechowywać coś w polach klasy. Może np. zachowywać stan pomiędzy jego kolejnymi wywołaniami.
<!-- .element: class="fragment fade-in" -->

___

## Przechowywanie stanu w funktorze

```cpp []
struct Functor {
    int index = 0;

    void operator()(int el) {
        std::cout << index << ": " << el << " | ";
        index++;
    }
};

int main() {
    std::vector<int> vec {1, 2, 3, 4, 5};
    std::for_each(begin(vec), end(vec), Functor{});
    std::cout << '\n';

    return 0;
}
```
<!-- .element: class="fragment fade-in" -->

output: `0: 1 | 1: 2 | 2: 3 | 3: 4 | 4: 5 | `
<!-- .element: class="fragment fade-in" -->

___

## Zadanie

Utwórz funktor sprawdzający czy podana liczba typu `int` jest podzielna przez `6`
