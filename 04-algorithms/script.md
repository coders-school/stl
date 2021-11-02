# STL algorithms

<img src="../img/coders_school_logo.png" alt="Coders School Ninja" width="800px" />

## Agenda

- [STL algorithms](#stl-algorithms)
  - [Agenda](#agenda)
  - [Intro](#intro)
    - [Something about you 👨‍💻](#something-about-you-)
    - [Pre-test 📝](#pre-test-)
      - [1/3 Mark true regarding `std::rotate`](#13-mark-true-regarding-stdrotate)
      - [2/3 Mark true regarding below code call:](#23-mark-true-regarding-below-code-call)
      - [3/3 What does `std::partial_sort(first, middle, last)` do?](#33-what-does-stdpartial_sortfirst-middle-last-do)
    - [Links for you 🔗](#links-for-you-)
    - [Warm-up task 💻](#warm-up-task-)
  - [Overview](#overview)
  - [Algorithm versions](#algorithm-versions)
  - [Iterators - `begin(v)` vs `v.begin()`](#iterators---beginv-vs-vbegin)
  - [Non-modifying sequence operations](#non-modifying-sequence-operations)
    - [`std::find_if` vs `std::find_first_of` vs `std::search` vs `std::adjacent_find`](#stdfind_if-vs-stdfind_first_of-vs-stdsearch-vs-stdadjacent_find)
    - [Task 💻](#task-)
    - [hackingcpp.com](#hackingcppcom)
  - [Modifying sequence operations](#modifying-sequence-operations)
    - [`std::generate*` vs `std::transform`](#stdgenerate-vs-stdtransform)
    - [Task 💻](#task--1)
    - [`std::reverse*`, `std::rotate*`, `std::shift*`, `std::shuffle`](#stdreverse-stdrotate-stdshift-stdshuffle)
    - [Task 💻](#task--2)
  - [Partitioning operations](#partitioning-operations)
  - [Sorting operations](#sorting-operations)
    - [Task 💻](#task--3)
    - [`std::partial_sort` vs `std::nth_element`](#stdpartial_sort-vs-stdnth_element)
  - [Binary search operations](#binary-search-operations)
  - [Set operations](#set-operations)
  - [Min/max operations](#minmax-operations)
  - [Numeric operations](#numeric-operations)
    - [`std::iota`](#stdiota)
    - [Reductions - `std::accumulate` vs `std::reduce`](#reductions---stdaccumulate-vs-stdreduce)
    - [Scans - `std::partial_sum` vs `std::inclusive_scan` vs `std::exclusive_scan`](#scans---stdpartial_sum-vs-stdinclusive_scan-vs-stdexclusive_scan)
    - [`std::adjacent_difference`](#stdadjacent_difference)
    - [`std::transform_reduce` vs `std::inner_product`](#stdtransform_reduce-vs-stdinner_product)
    - [Task 💻](#task--4)
  - [Bonus: Execution policies](#bonus-execution-policies)
    - [`std::execution`](#stdexecution)
  - [Recap](#recap)
    - [What do you remember from today? 🧠](#what-do-you-remember-from-today-)
    - [Pre-test answers 📝](#pre-test-answers-)
      - [1/3 Mark true regarding `std::rotate`](#13-mark-true-regarding-stdrotate-1)
      - [2/3 Mark true regarding below code call:](#23-mark-true-regarding-below-code-call-1)
      - [3/3 What does `std::partial_sort(first, middle, last)` do?](#33-what-does-stdpartial_sortfirst-middle-last-do-1)
    - [Post-work 💻](#post-work-)
      - [No raw loops challenge 🤔](#no-raw-loops-challenge-)
      - [Sorting Singly-Linked List 🤯](#sorting-singly-linked-list-)
      - [Watch a video](#watch-a-video)
  - [Rate this training session 📊](#rate-this-training-session-)
  - [Thank you! 🥷](#thank-you-)

___

## Intro

### Something about you 👨‍💻

* What do you expect from today's session?
* Mention STL algorithms you know and use

### Pre-test 📝

#### 1/3 Mark true regarding `std::rotate`

1. Returns `void`
2. There is a similar right rotation algorithm - `std::rrotate`
3. It is possible to perform right rotation with special argument
4. Performs left rotation

#### 2/3 Mark true regarding below code call:

```cpp
std::vector<int> v{3, 1, 4, 2, 5};
std::none_of(v.begin(), v.end(), [](auto e){ return e < 5; })
```

1. The code will not compile
2. Returns `true`
3. Returns `ForwardIt` to element on 4th position
4. Returns `false`
5. Segmentation fault

#### 3/3 What does `std::partial_sort(first, middle, last)` do?

1. Performs a quick_sort on whole range with the middle element as a pivot
2. Sorts only elements which are greater than middle
3. Put the middle element in proper position and everything less than it is before it and everything greater is after it
4. Sorts only the range [middle, last)
5. Sorts only the range [first, middle)

### Links for you 🔗

No presentation!
Fully interactive session 😉

* [This document on Github](https://github.com/coders-school/stl/blob/cr/04-algorithms/script.md)
* [Algorithms library on cppreference.com](https://en.cppreference.com/w/cpp/algorithm)
* [Numerics library on cppreference.com](https://en.cppreference.com/w/cpp/numeric)
* [Algorithms on hackingcpp.com](https://hackingcpp.com/cpp/std/algorithms.png)

### Warm-up task 💻

Let's do it together.

1. Create `std::vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}`
2. Create a lambda that captures this vector and displays its contents
3. Create a lambda that takes an int as an argument and displays it
4. Use this lambda in the `std::for_each()` algorithm to display the entire container

___

## Overview

[Algorithms library at cppreference.com](https://en.cppreference.com/w/cpp/algorithm)

All algorithms work on ranges defined by 2 iterators.
They are always given as the first and second argument.

___

## Algorithm versions

* `*_if` - takes a predicate instead of a value

    ```cpp
    std::find(v.begin(), v.end(), 5);
    std::find_if(v.begin(), v.end(), [](auto x){ return x > 5; });
    ```

* `*_copy` - produce result in another container

    ```cpp
    std::reverse(v.begin(), v.end());
    std::reverse_copy(v.begin(), v.end(), r.begin())
    ```

* `*_n` - takes `n` items/operations instead of `last` iterator

    ```cpp
    std::fill(v.begin(), v.end(), -1);
    std::fill_n(v.begin(), 5, -1);
    ```

* `ranges::` - works on the whole container (C++20)

    ```cpp
    std::sort(v.begin(), v.end());
    std::ranges::sort(v);
    ```

___

## Iterators - `begin(v)` vs `v.begin()`

```cpp
std::sort(v.begin(), v.end());
std::sort(begin(v), end(v));
```

* Usually no difference
* `begin(v)` works with C-style arrays
* When working with your own types you can specify both

___

## Non-modifying sequence operations

They do not modify the containers they run on. They cannot:

* rearrange items in a container
* delete items
* add items

### `std::find_if` vs `std::find_first_of` vs `std::search` vs `std::adjacent_find`

* `std::find_if` returns the first element that satisfies the given predicate (for which the predicate returns true)
* `std::find_first_of` searches the first range for any of the elements given in the second range
* `std::search` searches in the first range for the first occurrence of the sequence of elements from the second range
* `std::adjacent_find` finds the first two adjacent items that are equal (or satisfy a given predicate)
* All of them return:
  * an iterator to the first matching element, or...
  * last (second argument - the iterator from the first range, usually `end()`) if nothing was found

### Task 💻

1. Create `std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};`
2. Find all elements greater than `6` and print them
3. Find all elements equal to `2`, `4`, `6` or `8` and print them
4. Search the vector `v` for a range `{6, 6}` and `{7, 7}`
5. Run `std::adjacent_find` on the vector `v`

### hackingcpp.com

[Finding / Locating Elements](https://hackingcpp.com/cpp/std/algorithms.html)

___

## Modifying sequence operations

They modify the containers they operate on.

They can:

* rearrange items in a container
* delete items
* add items

### `std::generate*` vs `std::transform`

```cpp
std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8};
std::list<int> list {10, 20, 30 , 40 , 50, 60, 70, 80};
std::transform(begin(vec),
               end(vec),
               begin(list),
               begin(vec),
               [](auto first, auto second) {
                   return first + second;
               });
// vec = {11, 22, 33, 44, 55, 66, 77, 88}
}
```

```cpp
std::vector<int> vec(10);
std::generate(begin(vec), end(vec), [i{0}]() mutable { return i++; });
// vec = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
```

```cpp
std::mt19937 rng;
std::generate_n(std::ostream_iterator<std::mt19937::result_type>(std::cout, " "),
                5,
                std::ref(rng));
// Possible output: 3499211612 581869302 3890346734 3586334585 545404204
```

* `std::generate` generates values into a container "from nothing"
* `std::transform` transform values from one container into another one
* Both take a function object telling how to generate/transform elements
* Remember to use `std::back_inserter(v)` to create new elements in the output container
* You can provide `std::ostream_iterator<T>(std::cout, " ")` as the output iterator to print the result on the screen!

### Task 💻

1. Create a below vector

    ```cpp
    std::vector<std::pair<int, std::string>> v {
        {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}
    };
    ```

2. Create a vector of ints `v2` and fill it with all ints (first item of pair) from `v`
3. Create a vector of strings `v3` and fill it with concatenated string + colon + int from all pairs from `v`
4. Create a vector of chars `v4` and fill it with every other letter of the alphabet

### `std::reverse*`, `std::rotate*`, `std::shift*`, `std::shuffle`

```cpp
int a[] = {4, 5, 6, 7};
std::reverse(std::begin(a), std::end(a));
// a = {7, 6, 5, 4};
```

```cpp
std::vector<int> v{2, 4, 2, 0, 5, 10, 7, 3, 7, 1};
std::rotate(v.begin(), v.begin() + 3, v.end());
// v = {0, 5, 10, 7, 3, 7, 1, 2, 4, 2}
```

```cpp
std::vector<std::string>  c{"a", "b", "c", "d", "e", "f", "g"};
std::shift_left(begin(c), end(c), 3);
// c = {"d", "e", "f", "g", "", "", ""}
std::shift_right(begin(c), end(c), 2);
// c = {"", "", "d", "e", "f", "g", ""}
```

```cpp
std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
std::random_device rd;
std::mt19937 g(rd());
std::shuffle(v.begin(), v.end(), g);
std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
```

* `std::reverse` reverses the order of elements
* `std::rotate` takes 3 iterators: first, middle, last. After rotation middle is the first element and a range [first, middle) is moved after last.
* `std::shift_left/std::shift_right` (C++20) shifts all elements by N positions to left/right
* `std::shuffle` reorders the elements with the given random number generator

### Task 💻

1. Create `std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};`
2. Remove all duplicated values from `v`
3. Print all elements using `std::copy` and `std::ostream_iterator`
4. Shuffle all elements
5. Print all elements once again

___

## Partitioning operations

Range is partitioned according to a predicate P, when all elements for which P is satisfied are ordered before all elements for which P is not satisfied.

```cpp
auto is_even = [](auto i){ return i % 2 == 0; };
std::array<int, 9> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
std::cout << std::is_partitioned(v.begin(), v.end(), is_even);  // false

std::partition(v.begin(), v.end(), is_even);
std::cout << std::is_partitioned(v.begin(), v.end(), is_even);  // true
auto p = std::partition_point(v.begin(), v.end(), is_even);
// v = {8, 2, 6, 4, 5, 3, 7, 1, 9}
//                  p

v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
std::stable_partition(v.begin(), v.end(), is_even);
std::cout << std::is_partitioned(v.begin(), v.end(), is_even);  // true
// v = {2, 4, 6, 8, 1, 3, 5, 7, 9}

v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
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

___

## Sorting operations

### Task 💻

```cpp
struct Point { int x, y; }
```

1. Create `std::deque<Point> d = {{1, 3}, {0, 0}, {1, 2}, {2, 4}, {4, 1}, {0, 2}, {2, 2}};`
2. Create a function for printing the content of `d`
3. Write 2 comparators:
   1. `pointXCompare` that compares only `x` values of `Point`
   2. `pointYCompare` that compares only `y` values of `Point`
4. Check if `d` is sorted according to `pointXCompare` and `pointYCompare`
5. Use `stable_sort` to sort `d` by `x`
6. Use `sort` to sort `d` by `y`

### `std::partial_sort` vs `std::nth_element`

```cpp
std::vector<int> v{5, 6, 4, 3, 2, 6, 7, 9, 3};
std::nth_element(v.begin(), v.begin() + v.size()/2, v.end());
std::cout << "The median is " << v[v.size()/2] << '\n';
```

```cpp
std::array<int, 10> s{5, 7, 4, 2, 8, 6, 1, 9, 0, 3};
std::partial_sort(s.begin(), s.begin() + 3, s.end());
// possible s = {0, 1, 2, 7, 8, 6, 5, 9, 4, 3}
```

* `std::nth_element` and `std::partial_sort` are both partial sort algorithms
* `std::nth_element` rearranges the items in the way, that:
  * n-th element is on it's position
  * all elements less than or equal to n-th element are ordered before it
  * all other elements are ordered after it
  * `O(n)` complexity
* `std::partial_sort` rearranges the items in the way, that:
  * the range [first, middle) contains sorted smallest elements
  * the order of the range [middle, last) is unspecified
  * the order of equal elements is not guaranteed to be preserved
  * `O(n logn)`, or more precisely `(last-first)log(middle-first)` operations

___

## Binary search operations

Binary search algorithms must be used on sorted/partitioned ranges. Otherwise it will not give proper results.

```cpp
std::vector<int> data = { 1, 2, 2, 4, 5, 5, 5, 6 };
auto [l, u] = std::equal_range(data.begin(), data.end(), 5);
// data = { 1, 2, 2, 4, 5, 5, 5, 6 };
//                      l        u

auto [l, u] = std::equal_range(data.begin(), data.end(), 3);
// data = { 1, 2, 2, 4  , 5, 5, 5, 6 };
//                   l=u
```

* `std::lower_bound` returns an iterator the the first element that is not less than the given value
* `std::upper_bound` returns an iterator the the first element that is greater than the given value
* `std::distance` between `lower` and `upper` is the number of elements in the range
* `std::equal_range` return a pair of `[lower_bound, upper_bound]`
* `std::binary_search` performs a binary search operation and checks if a given element exists in a given range. **Returns `true/false`**.

___

## Set operations

```cpp
std::vector<int> v1 {1, 2, 5, 5, 5, 9};
std::vector<int> v2 {2, 5, 7};

std::includes(v1.begin(), v1.end(), v2.begin(), v2.end());  // false

std::vector<int> union;
std::set_union(v1.begin(), v1.end(),
               v2.begin(), v2.end(),
               std::back_inserter(union));
// union = {1, 2, 5, 5, 5, 7, 9}

std::vector<int> intersection;
std::set_intersection(v1.begin(), v1.end(),
                      v2.begin(), v2.end(),
                      std::back_inserter(intersection));
// intersection = {2, 5}

std::vector<int> symmetric_diff;
std::set_symmetric_difference(v1.begin(), v1.end(),
                              v2.begin(), v2.end(),
                              std::back_inserter(symmetric_diff));
// symmetric_diff = {1, 5, 5, 7, 9}

std::vector<int> diff;
std::set_difference(v1.begin(), v1.end(),
                    v2.begin(), v2.end(),
                    std::back_inserter(diff));
// diff = {1, 5, 5, 9}
```

___

## Min/max operations

* `std::min/std::max/std::minmax` returns the minimum, maximum or both from two of more values. They do not work on containers.
* `std::min_element/std::max_element` work on containers and return an iterator to min/max element.
* `std::minmax_element` returns a pair of iterators to min and max values.
* `std::clamp(v, lo, hi)` returns:
  * `v` if it is between `lo` and `hi`
  * `lo` if `v` is less than `lo`
  * `hi` if `v` is greater than `hi`

```cpp
for (auto v : {10, 200, -1}) {
    std::cout << std::clamp(v, 0, 100) << '\n';
}
// output: 10, 100, 0
```

___

## Numeric operations

### `std::iota`

```cpp
std::list<char> l(10);
std::iota(l.begin(), l.end(), 'C');
// l = {'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'}
```

Fills the range with sequentially increasing values

### Reductions - `std::accumulate` vs `std::reduce`

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

### Scans - `std::partial_sum` vs `std::inclusive_scan` vs `std::exclusive_scan`

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

### `std::adjacent_difference`

```cpp
std::vector v {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
std::adjacent_difference(v.begin(), v.end(), v.begin());
// v = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}
```

* `std::adjacent_difference` calculates the difference between the second and the first of each adjacent pair of elements of the range

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

* `std::inner_product` calculate the inner product of 2 ranges. It can be customized with own operations op1 (sum function) and op2 (product function).
* `std::transform_reduce` does the same, but it can be parallelized. It require both operations op1 and op2 to be commutative and associative.

### Task 💻

1. Create a vector `v1` with numbers from 1 to 1000
1. Calculate the sum of all numbers from 1 to 1000
1. Create a vector `v2` with 1000 numbers in a repeating sequence: `-1, 0, 1, 0, -1, 0, 1, 0...`
1. Calculate an inner product of vectors `v1` and `v2`
1. Calculate the sum of all numbers from `v1`, that have the corresponding value `1` in `v2`

___

## Bonus: Execution policies

From C++17 you can use parallel or unsequential versions of STL algorithms. You need to provide an additional `std::execution_policy` as the first argument.

```cpp
std::vector<int> v(1'000'000);
std::generate(std::execution::par,
              begin(v),
              end(v),
              [n = 0]() mutable { return n++; });
```

### `std::execution`

* `seq` = sequential
* `par` = parallel
* `par_unseq` = parallel unsequential
* `unseq` = unsequential

They are used to specify the execution policy of parallel algorithms - i.e., the kinds of parallelism allowed. Usually linking against `-litbb` (Intel Threading Building Blocks) is required.

___

## Recap

### What do you remember from today? 🧠

Let's have an interactive recap session in MD file.
I type items that you provide.

* many algorithms
* algorithms do not compare size of input containers
* lambdas, operations
* `rotate` vs `shift`
* `inner_product` - many customizations
* Partitioning operation
* `partition`, `sort`
* Modern versions of the same algorithms in `<numeric>`
* prefer `reduce` over `accumulate`
* `std::execution_policy` - parallel execution
* piping in `ranges`
* `ostream_iterator` for printing
* `find_*`, `search*`
* `*_if`, `*_copy`
* `copy`, `transform`
* `generate_n`, `iota`, `transform`
* `remove` - do not forget to call `erase`
* `std::ranges::` - algorithms for the whole containers
* `unique` - sort `first`, `erase` after use
* `std::set` instead of `sort` + `unique`
* `std::multiset` instead of `sort`
* `operator<=>` (spaceship operator)

### Pre-test answers 📝

#### 1/3 Mark true regarding `std::rotate`

1. Returns `void`
2. There is a similar right rotation algorithm - `std::rrotate`
3. It is possible to perform right rotation with special argument
4. ✅ **Performs left rotation**

#### 2/3 Mark true regarding below code call:

```cpp
std::vector<int> v{3, 1, 4, 2, 5};
std::none_of(v.begin(), v.end(), [](auto e){ return e < 5; })
```

1. The code will not compile
2. Returns `true`
3. Returns `ForwardIt` to element on 4th position
4. ✅ **Returns `false`**
5. Segmentation fault

#### 3/3 What does `std::partial_sort(first, middle, last)` do?

1. Performs a quick_sort on whole range with the middle element as a pivot
2. Sorts only elements which are greater than middle
3. Put the middle element in proper position and everything less than it is before it and everything greater is after it
4. Sorts only the range [middle, last)
5. ✅ **Sorts only the range [first, middle)**

### Post-work 💻

#### No raw loops challenge 🤔

Every time you want to write a raw loop on any container, think about the STL algorithm that can replace the loop

#### Sorting Singly-Linked List 🤯

Implement merge-sort or quick-sort algorithms on `std::forward_list`.

#### Watch a video

[105 STL Algorithms in Less Than an Hour](https://www.youtube.com/watch?v=bFSnXNIsK4A)

___

## [Rate this training session](https://forms.gle/ADXRttpAaZgW8KwM6) 📊

___

## Thank you! 🥷

<img src="../img/logo.png" alt="Coders School Ninja" width="200px" />