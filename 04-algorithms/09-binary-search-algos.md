<!-- .slide: data-background="#111111" -->

# Algorytmy wyszukiwania binarnego

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Wyszukiwanie binarne

Algorytmy wyszukiwania binarnego muszą być używane na posortowanych lub spartycjonowanych zakresach. W innych przypadkach nie dadzą właściwych rezultatów.

___
<!-- .element: style="font-size: 0.9em" -->

## `lower_bound`, `upper_bound`, `equal_range`

```cpp
std::vector<int> data = { 1, 2, 2, 4, 5, 5, 5, 6 };
auto [l, u] = std::equal_range(data.begin(), data.end(), 5);
// data = { 1, 2, 2, 4, 5, 5, 5, 6 };
//                      l        u

auto [l, u] = std::equal_range(data.begin(), data.end(), 3);
// data = { 1, 2, 2, 4  , 5, 5, 5, 6 };
//                   l=u
```
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>std::lower_bound</code> zwraca iterator na pierwszy element NIE MNIEJSZY NIŻ podana wartość
* <!-- .element: class="fragment fade-in" --> <code>std::upper_bound</code> zwraca iterator na pierwszy element WIĘKSZY NIŻ podana wartość
* <!-- .element: class="fragment fade-in" --> <code>std::distance</code> pomiędzy <code>lower</code> i <code>upper</code> to liczba znalezionych, równych sobie elementów
* <!-- .element: class="fragment fade-in" --> <code>std::equal_range</code> zwraca parę <code>[lower_bound, upper_bound]</code>

___

## `binary_search`

```cpp
template< class ForwardIt, class T >
constexpr bool binary_search( ForwardIt first, ForwardIt last, const T& value );
```
<!-- .element: class="fragment fade-in" style="font-size: 0.55em" -->

* <!-- .element: class="fragment fade-in" --> wykonuje wyszukiwanie binarne
* <!-- .element: class="fragment fade-in" --> <b>zwraca... <code>true/false</code></b>
* <!-- .element: class="fragment fade-in" --> sprawdza tylko, czy dany element istnieje!
* <!-- .element: class="fragment fade-in" --> aby dostać iterator do szukanego elementu trzeba użyć <code>lower_bound</code> lub <code>equal_range</code>
