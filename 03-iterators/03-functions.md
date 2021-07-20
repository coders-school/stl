<!-- .slide: data-background="#111111" -->

# Iteratory

## Funkcje

___

## Funkcje operujące na iteratorach

* <!-- .element: class="fragment fade-in" --> <code>std::advance()</code>
* <!-- .element: class="fragment fade-in" --> <code>std::next()</code>
* <!-- .element: class="fragment fade-in" --> <code>std::prev()</code>
* <!-- .element: class="fragment fade-in" --> <code>std::distance()</code>

___

## `std::advance()`

```cpp
template< class InputIt, class Distance >
constexpr void advance( InputIt& it, Distance n );
```
<!-- .element: class="fragment fade-in" -->

**Inkrementuje** podany iterator `it` o `n` elementów.
<!-- .element: class="fragment fade-in" -->

```cpp [5, 9]
int main() {
    std::vector<int> v{ 3, 1, 4 };

    auto vi = v.begin();
    std::advance(vi, 2);
    std::cout << *vi << ' ';

    vi = v.end();
    std::advance(vi, -2);
    std::cout << *vi << '\n';
}
```
<!-- .element: class="fragment fade-in" -->

___

## `std::next()`

```cpp
template< class InputIt >
constexpr InputIt next(
  InputIt it,
  typename std::iterator_traits<InputIt>::difference_type n = 1 );
```

**Zwraca** iterator zinkrementowany o `n` względem wejściowego `it`.
<!-- .element: class="fragment fade-in" -->

```cpp [5, 9]
int main() {
    std::vector<int> v{ 4, 5, 6 };

    auto it = v.begin();
    auto nx = std::next(it, 2);
    std::cout << *it << ' ' << *nx << '\n';

    it = v.end();
    nx = std::next(it, -2);
    std::cout << ' ' << *nx << '\n';
}
```
<!-- .element: class="fragment fade-in" -->

___

## `std::prev()`

```cpp
template< class BidirIt >
constexpr BidirIt prev(
  BidirIt it,
  typename std::iterator_traits<BidirIt>::difference_type n = 1 );
```

To samo co `next()`, tylko w drugą stronę :)
<!-- .element: class="fragment fade-in" -->

```cpp [5, 9]
int main() {
    std::vector<int> v{ 3, 1, 4 };

    auto it = v.end();
    auto pv = std::prev(it, 2);
    std::cout << *pv << '\n';

    it = v.begin();
    pv = std::prev(it, -2);
    std::cout << *pv << '\n';
}
```
<!-- .element: class="fragment fade-in" -->

___

## `std::distance()`

[Zobacz na cppreference.com](https://en.cppreference.com/w/cpp/iterator/distance)
