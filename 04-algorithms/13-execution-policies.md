<!-- .slide: data-background="#111111" -->

# Bonus

## Sposoby wykonania

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

Od C++ możemy używać współbieżnych wersji algorytmów STL. Musisz im dostarczyć dodatkowy tag `std::execution_policy` jako pierwszy argument.

```cpp
std::vector<int> v(1'000'000);
std::generate(std::execution::par,
              begin(v),
              end(v),
              [n = 0]() mutable { return n++; });
```

___

## `std::execution`

* `seq` = wykonanie sekwencyjne (standardowo)
* `par` = wykonanie współbieżne
* `unseq` = wykonanie niesekwencyjne
* `par_unseq` = wykonanie współbieżne niesekwencyjne

Za pomocą powyższych tagów możesz wyspecyfikować rodzaj współbieżnego wykonania algorytmów. Zazwyczaj musisz jeszcze zlinkować program z biblioteką `-litbb` (Intel Threading Building Blocks).
