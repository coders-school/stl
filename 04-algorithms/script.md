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
6. Sorting operations
    1. Structural properties - `std::is_sorted*`
    2. Sorting - `std::sort` vs `std::stable_sort`
    3. Partial sorting - `std::partial_sort` vs `std::nth_element`
7. Binary search operations (of sorted ranges)
    1. `std::binary_search`
    2. Bounds - `std::lower_bound`, `std::upper_bound`, `std::equal_range`
    3. Merge operations - `std::merge` vs `std::inplace_merge`
8. Set operations
    1. `std::includes`
    2. `std::set_difference`, `std::set_intersection`, `std::set_symmetric_difference`, `set_union`
9. Heap operations
    1. Structural properties - `std::is_heap*`
    2. Heap - `std::make_heap`, `std::push_heap`, `std::pop_heap`
    3. Sorting - `std::sort_heap`
10. Min/max operations
    1. `std::min`, `std::max`, `std::minmax`
    2. `std::min_element`, `std::max_element`, `std::minmax_element`
    3. `std::clamp`
11. Comparison operations
    1. Comparing ranges: `std::equal` vs `std::mismatch`
    2. Comparing ranges: `std::lexicographical_compare` vs `std::lexicographical_compare_three_way`
12. Permutation operations
    1. Structural properties - `std::is_permutation`
    2. `std::next_permutation`, `std::prev_permutation`
13. Numeric operations
    1. `std::iota`
    2. Reductions - `std::accumulate` vs `std::reduce`
    3. Scans - `std::partial_sum` vs `std::inclusive_scan` vs `std::exclusive_scan`
    4. `std::adjacent_difference`
    5. `std::transform_reduce` vs `std::inner_product`
14. Uninitialized memory operations
15. [Bonus: Execution policies](#bonus-execution-policies)
16. [Recap](#recap)

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

All algorithms work on ranges defined by 2 iterators. They are always given as the first and second argument.  

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

* `std::find_if` returns the first element that satisfies the given UnaryPredicate (for which the predicate returns true)
* `std::find_first_of` searches the first range for any of the elements given in the second range
* `std::search` searches in the first range for the first occurrence of the sequence of elements from the second range
* `std::adjacent_find` finds the first two adjacent items that are equal (or satisfy a given predicate)
* All of them return:
  * an iterator to the first matching element, or...
  * last (second argument - the iterator from the first range, usually `end()`) if nothing was found

#### Task

1. Create `std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};`
2. Find all elements greater than `6` and print them
3. Find all elements equal to `2, 4, 6, 8` and print them
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
}
```

```cpp
std::vector<int> vec(10);
std::generate(begin(vec), end(vec), [i{0}]() mutable { return i++; });
```

```cpp
std::mt19937 rng; // default constructed, seeded with fixed seed
std::generate_n(std::ostream_iterator<std::mt19937::result_type>(std::cout, " "),
                5,
                std::ref(rng));
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

#### Task

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
