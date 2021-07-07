<!-- .slide: data-background="#111111" -->

# Funkcje

<a href="https://coders.school">
    <img width="500" data-src="../img/coders_school_logo.png" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Co to są funkcje?

Funkcje to takie szczególne twory, które można wywołać za pomocą `()`.
<!-- .element: class="fragment fade-in" -->

Wewnątrz `()` możemy podawać argumenty do funkcji.
<!-- .element: class="fragment fade-in" -->

```cpp []
void function() {
    std::cout << "I'm a function!\n";
}

int triple(int value) {
    return 3 * value;
}

int main() {
    function();
    auto result = triple(4);

    return 0;
}
```
<!-- .element: class="fragment fade-in" -->

___

## Pytanie #1

Co się stanie, gdy zrobimy takie coś?
<!-- .element: class="fragment fade-in" -->

```cpp []
void function() {
    std::cout << "I'm a function!\n";
}

int triple(int value) {
    return 3 * value;
}

int main() {
    function;   // no ()
    triple;     // no arguments passed

    return 0;
}
```
<!-- .element: class="fragment fade-in" -->

___

## Pytanie #2

A co się stanie, gdy zrobimy takie coś?
<!-- .element: class="fragment fade-in" -->

```cpp []
void function() {
    std::cout << "I'm a function!\n";
}

int triple(int value) {
    return 3 * value;
}

int main() {
    auto f = function;
    auto t = triple;

    return 0;
}
```
<!-- .element: class="fragment fade-in" -->

___

## Odpowiedź

* <!-- .element: class="fragment fade-in" --> Kod się skompiluje w obu przypadkach
* <!-- .element: class="fragment fade-in" --> Sama nazwa funkcji bez <code>operatora()</code> to... wskaźnik na tę funkcję
* <!-- .element: class="fragment fade-in" --> <code>auto f = function</code> to utworzenie wskaźnika na funkcję o nazwie <code>f</code>, który będzie wskazywał na funkcję <code>function</code>
* <!-- .element: class="fragment fade-in" --> Samo użycie <code>function;</code> nic nie robi. Po prostu nie wykorzystujemy wskaźnika.
