<!-- .slide: data-background="#111111" -->

# Funktory

## Obiekty funkcyjne

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___
<!-- .slide: style="font-size: 0.9em" -->

## Czym jest funktor - obiekt funkcyjny

Funktor jest to obiekt, który może zostać wywołany jak zwykła funkcja. Każda klasa oraz struktura, która posiada zdefiniowany `operator()` może pełnić rolę funktora.
Alternatywną nazwą dla funktora jest obiekt funkcyjny.

```cpp
struct Functor {
    void operator() () {
        std::cout << "I'm a functor!\n";
    }
};

int main() {
    Functor funct;
    funct();      // obiekt nazwany (linię wyżej)
    Functor{}();  // obiekt tymczasowy

    return 0;
}
```

output:

```text
I'm a functor!
I'm a functor!
```

___

## Czym jest funktor - funkcja

Funkcja także jest traktowana jako funktor, ponieważ również możemy ją wywołać poprzez `()`.

```cpp
void function() {
    std::cout << "I'm a functor!\n";
}

int main() {
    function();

    return 0;
}
```

output: `I'm a functor!`

___

## Wykorzystanie funktorów

Funktory możemy wykorzystać w algorytmach STL. Przykładowo algorytm `for_each` dla każdego elementu wywołuje on przekazany funktor. Sam funktor za swój jedyny argument musi przyjmować typ elementu z zakresu, na którym pracuje.

```cpp
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

output: `1 2 3 4 5`

___

## Q&A
