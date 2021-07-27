<!-- .slide: data-background="#111111" -->

# Algorytmy partycjonujące

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Operacje partycjonowania

Zakres jest "spartycjonowany" względem predykatu `P`, jeśli wszystkie elementy dla których `P` zwraca `true` są położone przed elementami dla których `P` zwraca `false`.

```cpp
auto is_even = [](auto i){ return i % 2 == 0; };                // predicate
```
<!-- .element: class="fragment fade-in" -->

```cpp
std::array<int, 9> a1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
std::cout << std::is_partitioned(a1.begin(), a1.end(), is_even);  // false
```
<!-- .element: class="fragment fade-in" -->

```cpp
std::vector a2 = {2, 4, 6, 8, 9};
std::cout << std::is_partitioned(a2.begin(), a2.end(), is_even);  // true
```
<!-- .element: class="fragment fade-in" -->

```cpp
std::vector a3 = {9, 5, 3};
std::cout << std::is_partitioned(a3.begin(), a3.end(), is_even);  // true
```
<!-- .element: class="fragment fade-in" -->

```cpp
std::array<int, 9> a4 = {9, 5, 3};
std::cout << std::is_partitioned(a4.begin(), a4.end(), is_even);  // false!
```
<!-- .element: class="fragment fade-in" -->

___

## `partition`, `partition_point`

```cpp
auto it = std::partition(v.begin(), v.end(), is_even);
std::cout << std::is_partitioned(v.begin(), v.end(), is_even);  // true
auto pp = std::partition_point(v.begin(), v.end(), is_even);
// v = {8, 2, 6, 4, 5, 3, 7, 1, 9}
//                  pp
//                  it
```
<!-- .element: class="fragment fade-in" -->

___

## `stable_partition` vs `partition`

```cpp
std::vector v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
std::stable_partition(v.begin(), v.end(), is_even);
// v = {2, 4, 6, 8, 1, 3, 5, 7, 9}
```
<!-- .element: class="fragment fade-in" -->

```cpp
std::vector v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
std::partition(v.begin(), v.end(), is_even);
// v = {8, 2, 6, 4, 5, 3, 7, 1, 9}
```
<!-- .element: class="fragment fade-in" -->

___

## `partition_copy`

```cpp
std::vector v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
std::vector<int> true_vector;
std::vector<int> false_vector;
std::partition_copy(v.begin(),
                    v.end(),
                    std::back_inserter(true_vector),
                    std::back_inserter(false_vector),
                    is_even);
// true_vector = {2, 4, 6, 8}
// false_vector = {1, 3, 5, 7, 9}
```
<!-- .element: class="fragment fade-in" -->
