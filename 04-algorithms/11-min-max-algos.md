<!-- .slide: data-background="#111111" -->

# Algorytmy min/max

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Algorytmy min/max

* <!-- .element: class="fragment fade-in" --> <code>std::min/std::max/std::minmax</code> zwracają odpowiednio minimum, maksimum oraz parę min i max z dwóch lub więcej wartości. Nie pracują na kontenerach.
* <!-- .element: class="fragment fade-in" --> <code>std::min_element/std::max_element</code> pracują na kontenerach i zwracają iterator do najmniejszego/największego elementu.
* <!-- .element: class="fragment fade-in" --> <code>std::minmax_element</code> zwraca parę iteratorów wskazujących minimalny i maksymalny element

___

## Odcięcie - `clamp`

* <!-- .element: class="fragment fade-in" --> <code>std::clamp(v, lo, hi)</code> zwraca:
  * <!-- .element: class="fragment fade-in" --> <code>v</code>, jeśli zawiera się ono pomiędzy <code>lo</code> i <code>hi</code>
  * <!-- .element: class="fragment fade-in" --> <code>lo</code>, jeśli <code>v</code> jest mniejsze niż <code>lo</code>
  * <!-- .element: class="fragment fade-in" --> <code>hi</code>, jeśli <code>v</code> jest większe niż <code>hi</code>

```cpp
for (auto v : {10, 200, -1}) {
    std::cout << std::clamp(v, 0, 100) << '\n';
}
// output: 10, 100, 0
```
<!-- .element: class="fragment fade-in" -->

<img height="300px" src="../img/ramp.png" alt="Coders School" class="plain fragment fade-in">
