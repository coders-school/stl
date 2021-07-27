<!-- .slide: data-background="#111111" -->

# Wersje algorytmów

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Wersje algorytmów

* `*_if` - bierze predykat zamiast wartości
<!-- .element: class="fragment fade-in" -->

    ```cpp
    std::find(v.begin(), v.end(), 5);
    std::find_if(v.begin(), v.end(), [](auto x){ return x > 5; });
    ```
<!-- .element: class="fragment fade-in" -->

* `*_copy` - zapisuje wynik w innym kontenerze
<!-- .element: class="fragment fade-in" -->

    ```cpp
    std::reverse(v.begin(), v.end());
    std::reverse_copy(v.begin(), v.end(), r.begin());
    ```
<!-- .element: class="fragment fade-in" -->

* `*_n` - bierze `n` elementów / wykonuje `n` operacji zamiast podawania iteratora `last`
<!-- .element: class="fragment fade-in" -->

    ```cpp
    std::fill(v.begin(), v.end(), -1);
    std::fill_n(v.begin(), 5, -1);
    ```
<!-- .element: class="fragment fade-in" -->

* `ranges::` - pracuje na całych kontenerach (C++20)
<!-- .element: class="fragment fade-in" -->

    ```cpp
    std::sort(v.begin(), v.end());
    std::ranges::sort(v);
    ```
<!-- .element: class="fragment fade-in" -->

___

## Iteratory - `begin(v)` vs `v.begin()`

```cpp
std::sort(v.begin(), v.end());
std::sort(begin(v), end(v));
```

* Zazwyczaj nie ma różnicy
* `begin(v)` działa na zwykłych tablicach w stylu języka C

<!-- .element: class="fragment fade-in" -->
