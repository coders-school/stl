<!-- .slide: data-background="#111111" -->

# Algorytmy numeryczne

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## `std::iota`

```cpp
std::list<char> l(10);
std::iota(l.begin(), l.end(), 'C');
// l = {'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'}
```
<!-- .element: class="fragment fade-in" -->

Wypełnia zakres sekwencyjnie rosnącymi wartościami.
<!-- .element: class="fragment fade-in" -->

___
<!-- .element: style="font-size: 0.9em" -->

## Operacje redukcji

### `std::accumulate` vs `std::reduce`
<!-- .element: class="fragment fade-in" -->

```cpp
std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int sum = std::accumulate(v.begin(), v.end(), 0);
int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
// sum = 55, product = 3628800

sum = std::reduce(std::execution::par, v.begin(), v.end(), 0);
product = std::reduce(v.begin(), v.end(), 1, std::multiplies<int>());
// sum = 55, product = 3628800
```
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>std::accumulate</code> oblicza sumę podanego zakresu + init. Można dostarczyć własną funkcję zamiast standardowego sumowania.
* <!-- .element: class="fragment fade-in" --> <code>std::reduce</code> (C++17) robi dokładnie to samo, ale kolejność dodawania poszczególnych elementów jest dowolna. To może mieć znaczenie podczas wykonywania tego algorytmu współbieżnie. Może przyjąć dodatkowy argument <code>std::execution_policy</code>, aby wykonać obliczenia współbieżnie.
* <!-- .element: class="fragment fade-in" --> Preferuj <code>std::reduce</code>

___
<!-- .element: style="font-size: 0.75em" -->

## Operacje skanowania

### `std::partial_sum` vs `std::inclusive_scan` vs `std::exclusive_scan`

```cpp
std::vector<int> v = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}; // or std::vector<int>v(10, 2);
std::partial_sum(v.begin(),
                 v.end(),
                 std::ostream_iterator<int>(std::cout, " "));
// output: 2 4 6 8 10 12 14 16 18 20

std::partial_sum(v.begin(), v.end(), v.begin(), std::multiplies<int>());
// v = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024}

v = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}; // or std::vector<int>v(10, 2);
std::inclusive_scan(v.begin(), v.end(), v.begin(), std::multiplies<int>());
// v = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024}

v = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}; // or std::vector<int>v(10, 2);
std::exclusive_scan(v.begin(), v.end(), v.begin(), 1, std::multiplies<int>());
// v = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512}
```
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>std::partial_sum</code> oblicza sumę częściową (od początku zakresu do obecnie przetwarzanego elementu). Można dostarczyć własną funkcję zamiast standardowego sumowania.
* <!-- .element: class="fragment fade-in" --> <code>std::inclusive_scan</code> robi dokładnie to samo.
* <!-- .element: class="fragment fade-in" --> <code>std::exclusive_scan</code> robi dokładnie to samo, ale obecny element nie jest brany pod uwagę (obliczamy do poprzedniego elementu).

___

## `std::adjacent_difference`

```cpp
std::vector v {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
std::adjacent_difference(v.begin(), v.end(), v.begin());
// v = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}

std::vector w {-100, 2, 4, 8, 16, 32};
std::adjacent_difference(w.begin(), w.end(), w.begin());
// w = {-100, 102, 2, 4, 8, 16}
```
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>std::adjacent_difference</code> oblicza różnicę pomiędzy parami sąsiadujących elementów

___
<!-- .element: style="font-size: 0.8em" -->

## Operacji transformacji z redukcją

### `std::transform_reduce` vs `std::inner_product`

```cpp
std::vector<int> a{0, 1, 2, 3, 4};
std::vector<int> b{5, 4, 2, 3, 1};

int r1 = std::inner_product(a.begin(), a.end(), b.begin(), 0);
// 0 x 5 + 1 x 4 + 2 x 2 + 3 x 3 + 4 x 1
// r1 = 21

int r2 = std::inner_product(a.begin(), a.end(), b.begin(), 0,
                            std::plus<>(), std::equal_to<>());
// (0 == 5) + (1 == 4) + (2 == 2) + (3 == 3) + (4 == 1)
// r2 = 2

int r3 = std::transform_reduce(a.begin(), a.end(), b.begin(), 0);
int r4 = std::transform_reduce(a.begin(), a.end(), b.begin(), 0,
                               std::plus<>(), std::equal_to<>());
```
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>std::inner_product</code> oblicza iloczyn skalarny 2 zakresów. Można dostarczyć własne operacja zamiast standardowych (op1 - sumowanie i op2 - mnożenie)
* <!-- .element: class="fragment fade-in" --> <code>std::transform_reduce</code> robi to samo, ale można go używać współbieżnie. Wymaga, aby obie operacje były przemienne i łączne.

___

## Zadanie 💻

1. Utwórz wektor `v1` z liczbami od 1 do 1000
2. Oblicz sumę tych liczb
3. Utwórz wektor `v2` z 1000 elementów powtarzających się w następującej sekwencji: `-1, 0, 1, 0, -1, 0, 1, 0, ...`
4. Oblicz iloczyn skalarny wektorów `v1` i `v2`
5. Oblicz sumę tych liczb z `v1`, które są na pozycjach dodatnich jedynek z wektora `v2`
