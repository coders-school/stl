<!-- .slide: data-background="#111111" -->

# Algorytmy sortujące

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___
<!-- .element: style="font-size: 0.8em" -->

## Zadanie 💻

```cpp
struct Point { int x, y; }
```
<!-- .element: style="font-size: 0.8em" -->

1. Utwórz `std::deque<Point> d = {{1, 3}, {0, 0}, {1, 2}, {2, 4}, {4, 1}, {0, 2}, {2, 2}};`
2. Utwórz funkcję do wypisywania zawartości kontenera `d`
3. Napisz 2 komparatory:
   1. `pointXCompare`, który porównuje tylko wartości `x` ze struktury `Point`
   2. `pointYCompare`, który porównuje tylko wartości `y` ze struktury `Point`
4. Sprawdź czy `d` jest posortowane względem `pointXCompare` oraz `pointYCompare`
5. Użyj `stable_sort` do posortowania `d` względem wartości `x`
6. Użyj `sort` do posortowania `d` względem wartości `y`

___

## `std::partial_sort` vs `std::nth_element`

```cpp
std::vector<int> v{5, 6, 4, 3, 2, 6, 7, 9, 3};
std::nth_element(v.begin(), v.begin() + v.size()/2, v.end());
std::cout << "The median is " << v[v.size()/2] << '\n';     // 5
// possible content of v = {3, 2, 3, 4, 5, 6, 7, 9, 6}
```
<!-- .element: class="fragment fade-in" -->

```cpp
std::array<int, 10> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
std::partial_sort(s.begin(), s.begin() + 3, s.end());
// possible content of s = {0, 1, 2, 7, 8, 6, 5, 9, 4, 3}
```
<!-- .element: class="fragment fade-in" -->

___

## `std::partial_sort` vs `std::nth_element`

* <!-- .element: class="fragment fade-in" --> <code>std::nth_element</code> i <code>std::partial_sort</code> to algorytmy sortujące
* <!-- .element: class="fragment fade-in" --> <code>std::nth_element</code> zmienia kolejność elementów w kontenerze w taki sposób, że:
  * <!-- .element: class="fragment fade-in" --> n-ty element jest na właściwej pozycji
  * <!-- .element: class="fragment fade-in" --> wszystkie elementy mniejsze od niego lub równe są przed nim
  * <!-- .element: class="fragment fade-in" --> wszystkie elementy większe od niego są za nim
  * <!-- .element: class="fragment fade-in" --> złożoność liniowa - <code>O(n)</code>
* <!-- .element: class="fragment fade-in" --> <code>std::partial_sort</code> zmienia kolejność elementów w kontenerze w taki sposób, że:
  * <!-- .element: class="fragment fade-in" --> zakres <code>[first, middle)</code> zawiera posortowane najmniejsze elementy z całego zakresu <code>[first, last)</code>
  * <!-- .element: class="fragment fade-in" --> kolejność elementów w zakresie <code>[middle, last)</code> jest niewyspecyfikowana
  * <!-- .element: class="fragment fade-in" --> nie ma gwarancji, że kolejność równych sobie elementów zostanie zachowania (algorytm nie jest stabilny)
  * <!-- .element: class="fragment fade-in" --> złożoność liniowo-logarytmiczna <code>O(n logn)</code>, a dokładniej <code>(last-first) * log(middle-first)</code> operacji
