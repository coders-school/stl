# STL algorithms

<!-- TODO: Functors and lambdas - skip, it will be introduced during the session -->

## Agenda

1. [Intro](#intro)
2. [Overview](#overview)
3. [Algorithm versions](#algorithm-versions)
    1. `*_if` - takes a predicate instead of a value
    2. `*_copy` - produce result in another container
    3. `*_n` - takes `n` items/operations instead of `last` iterator
    4. `ranges::` - works on the whole container
4. [Non-modifying sequence operations](#non-modifying-sequence-operations)
    1. Existence queries - `std::all_of`, `std::any_of`, `std::none_of`
    2. Counting elements - `std::count`, `std::count_if`
    3. Finding elements - `std::find_if` vs `std::find_first_of` vs `std::search` vs `std::adjacent_find`
5. [Modifying sequence operations](#modifying-sequence-operations)
    1. `std::generate*` vs `std::transform`
    2. Copying, moving elements - `std::copy*`, `std::move*`
    3. Modifying elements - `std::fill*`, `std::replace*`
    4. Shifting elements - `std::reverse*`, `std::rotate*`, `std::shift*`, `std::shuffle`
    5. Removing elements - `std::remove*`, `std::unique*`
6. [Partitioning operations](#partitioning-operations)
    1. Structural properties - `std::is_partitioned`, `std::partition_point`
    2. Partitioning - `std::partition` vs `std::stable_partition` vs `std::partition_copy`
7. [Sorting operations](#sorting-operations)
    1. Structural properties - `std::is_sorted*`
    2. Sorting - `std::sort` vs `std::stable_sort`
    3. Partial sorting - `std::partial_sort` vs `std::nth_element`
8. Binary search operations (of sorted ranges)
    1. `std::binary_search`
    2. Bounds - `std::lower_bound`, `std::upper_bound`, `std::equal_range`
    3. Merge operations - `std::merge` vs `std::inplace_merge`
9. Set operations
    1. `std::includes`
    2. `std::set_difference`, `std::set_intersection`, `std::set_symmetric_difference`, `set_union`
10. Heap operations
    1. Structural properties - `std::is_heap*`
    2. Heap - `std::make_heap`, `std::push_heap`, `std::pop_heap`
    3. Sorting - `std::sort_heap`
11. Min/max operations
    1. `std::min`, `std::max`, `std::minmax`
    2. `std::min_element`, `std::max_element`, `std::minmax_element`
    3. `std::clamp`
12. Comparison operations
    1. Comparing ranges: `std::equal` vs `std::mismatch`
    2. Comparing ranges: `std::lexicographical_compare` vs `std::lexicographical_compare_three_way`
13. Permutation operations
    1. Structural properties - `std::is_permutation`
    2. `std::next_permutation`, `std::prev_permutation`
14. Numeric operations
    1. `std::iota`
    2. Reductions - `std::accumulate` vs `std::reduce`
    3. Scans - `std::partial_sum` vs `std::inclusive_scan` vs `std::exclusive_scan`
    4. `std::adjacent_difference`
    5. `std::transform_reduce` vs `std::inner_product`
15. Uninitialized memory operations
16. [Bonus: Execution policies](#bonus-execution-policies)
17. [Recap](#recap)

___

## Intro

### Pre-test
<!-- TODO: Prepare -->

### Links for you

No presentation!
Fully interactive session 😉

* [This document on Github](https://github.com/coders-school/stl/blob/cr/04-algorithms/script.md)
* [Algorithms library on cppreference.com](https://en.cppreference.com/w/cpp/algorithm)
* [Numerics library on cppreference.com](https://en.cppreference.com/w/cpp/numeric)
* [Algorithms on hackingcpp.com](https://hackingcpp.com/cpp/std/algorithms.png)

### Task
<!-- TODO: needed? -->

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

#### Task

1. Create `std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};`
2. Find all elements greater than `6` and print them
3. Find all elements equal to `2`, `4`, `6` or `8` and print them
4. Search the vector `v` for a range `{6, 6}` and `{7, 7}`
5. Run `std::adjacent_find` on the vector `v`

#### hackingcpp.com

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
// list = {11, 22, 33, 44, 55, 66, 77, 88}
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

#### Task

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

#### Task

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

### Task

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
  * `O(nlogn)`, or more precisely `(last-first)log(middle-first)` operations

___

## all other algos

___

## Bonus: Execution policies

___

## Recap

### What do you remember from today?

Let's have an interactive recap session in MD file.
I type items that you provide.

* Type here...

### Pre-test answers

#### Q1

A
B

<!-- TODO: Come out with some nice questions -->
