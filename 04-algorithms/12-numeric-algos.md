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

Fills the range with sequentially increasing values

___

## Reductions - `std::accumulate` vs `std::reduce`

```cpp
std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int sum = std::accumulate(v.begin(), v.end(), 0);
int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());
// sum = 55, product = 3628800

sum = std::reduce(std::execution::par, v.begin(), v.end(), 0);
product = std::reduce(v.begin(), v.end(), 1, std::multiplies<int>());
// sum = 55, product = 3628800
```

* `std::accumulate` computes the sum of the given range + init. Can be customized with a BinaryOperation function.
* `std::reduce` (C++17) does the same, but order of evaluation is arbitrary. It can take additional `std::execution_policy` tag, to run computations in parallel.
* Prefer `std::reduce`

___

## Scans - `std::partial_sum` vs `std::inclusive_scan` vs `std::exclusive_scan`

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

* `std::partial_sum` calculates the partial sum of a range of elements. Can be customized with own operation.
* `std::inclusive_scan` does the same.
* `std::exclusive_scan` does the same, but the current element is excluded from computations.

___

## `std::adjacent_difference`

```cpp
std::vector v {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
std::adjacent_difference(v.begin(), v.end(), v.begin());
// v = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
```

* `std::adjacent_difference` calculates the difference between the second and the first of each adjacent pair of elements of the range

___

## `std::transform_reduce` vs `std::inner_product`

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

* `std::inner_product` calculate the inner product of 2 ranges. It can be customized with own operations op1 (sum function) and op2 (product function).
* `std::transform_reduce` does the same, but it can be parallelized. It require both operations op1 and op2 to be commutative and associative.

___

## Zadanie 💻

1. Create a vector `v1` with numbers from 1 to 1000
1. Calculate the sum of all numbers from 1 to 1000
1. Create a vector `v2` with 1000 numbers in a repeating sequence: `-1, 0, 1, 0, -1, 0, 1, 0...`
1. Calculate an inner product of vectors `v1` and `v2`
1. Calculate the sum of all numbers from `v1`, that have the corresponding value `1` in `v2`
