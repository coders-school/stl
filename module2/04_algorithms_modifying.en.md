<!-- .slide: data-background="#111111" -->

# Modifying algorithms

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Algorithms modifying the order of elements

They modify the containers they operate on.

They can:

* rearrange items in a container
* delete items
* add items

Here you will only find popular or interesting uses of some algorithms. The full list of algorithms is available on cppreferene.com

[Algorithms on cppreference.com](https://en.cppreference.com/w/cpp/algorithm)

___

## `std::copy`, `std::copy_if`

```cpp
template< class InputIt, class OutputIt >
OutputIt copy( InputIt first, InputIt last, OutputIt d_first );
```

```cpp
template< class InputIt, class OutputIt, class UnaryPredicate >
OutputIt copy_if( InputIt first, InputIt last,
                  OutputIt d_first,
                  UnaryPredicate pred );
```

* Basic version `std::copy`, copies the given range to another range. For example, it copies items from a vector to a list.
* `std::copy_if` copies only those elements that meet the predicate we have given. For example `::is_upper`, `::is::digit`.

___

## `std::copy`, `std::copy_if` - use

```cpp
std::vector<int> vec {1, 2, 3, 4, 5};
std::array<int, 5> arr;
std::copy(begin(vec), end(vec), begin(arr));
print(arr);

std::vector<int> vec2(3);
std::copy_if(begin(vec), end(vec), begin(vec2), [](auto num) {
    return num % 2 == 1;
});
print(vec2);
```

Output:

```text
1 2 3 4 5
1 3 5
```

___

## `std::fill`

```cpp
template< class ForwardIt, class T >
void fill( ForwardIt first, ForwardIt last, const T& value );
```

The function fills the given range with values `value`

```cpp
int main() {
    std::vector<int> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::fill(v.begin(), v.end(), -1);
    for (auto elem : v) {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}
```

Output: `-1 -1 -1 -1 -1 -1 -1 -1 -1 -1`

___
<!-- .slide: style="font-size: 0.9em" -->

## `std::transform`

A powerful algorithm that can do much more than it seems at the beginning :)

```cpp
template< class InputIt, class OutputIt, class UnaryOperation >
OutputIt transform( InputIt first1, InputIt last1,
                    OutputIt d_first,
                    UnaryOperation unary_op );
```

```cpp
template< class InputIt1, class InputIt2, class OutputIt, class BinaryOperation >
OutputIt transform( InputIt1 first1, InputIt1 last1,
                    InputIt2 first2,
                    OutputIt d_first,
                    BinaryOperation binary_op );
```

* First version `std::transform` takes the range `[first1, last1)`, and performs an operation on each element `unary_op`and then saves the modified items in the second scope (`d_first`).
* The second version, takes 2 ranges, takes 1 element from both ranges and performs operations on them `binary_op`, then writes the result in the 3 range (`d_first`).

___

## `std::transform` - example of use # 1

Converting one type of container to another

```cpp
int main() {
    std::vector<std::pair<int, std::string>> vec {
        {0, "Zero"},
        {1, "One"},
        {2, "Two"},
        {3, "Three"},
        {4, "Four"},
        {5, "Five"}
    };
    std::vector<int> vec2(5);
    std::transform(begin(vec), end(vec), vec2.begin(), [](const auto& pair) {
        return pair.first;
    });
    print(vec2);
    return 0;
}
```

Output: `0 1 2 3 4 5`

___

## `std::transform` - example of use # 2

Container conversion

```cpp
std::vector<std::pair<int, std::string>> vec {
    {0, "Zero"},
    {1, "One"},
    {2, "Two"},
    {3, "Three"},
    {4, "Four"},
    {5, "Five"}
};
std::vector<std::string> vec2;
std::transform(begin(vec),
               end(vec),
               std::back_inserter(vec2),
               [](const auto& pair){
                   return pair.second + " : " + std::to_string(pair.first);
               });
print(vec2);
```

Output: `Zero : 0, One : 1, Two : 2, Three : 3, Four : 4, Five : 5`

___

## `std::transform` - usage example # 3

Convert characters to lowercase

```cpp
int main() {
    std::vector<std::string> vec {
        "ZeRo", "ONe", "TwO", "ThREe", "FoUr", "FiVe"
    };
    std::transform(begin(vec), end(vec), begin(vec), [](auto str) {
        std::transform(begin(str), end(str), begin(str), [](auto c) {
            return std::tolower(c);
        });
        return str;
    });
    print(vec);

    return 0;
}
```

Output: `zero one two three four five`

___

## `std::transform` usage example # 4

Adding vector and list values:

```cpp
int main() {
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8};
    std::list<int> list {10, 20, 30 , 40 , 50, 60, 70, 80};
    std::transform(begin(vec),
                   end(vec),
                   begin(list),
                   begin(vec),
                   [](auto first, auto second) {
                       return first + second;
                   });
    print(vec);

    return 0;
}
```

Output: `11 22 33 44 55 66 77 88`

___

## `std::generate`

```cpp
template< class ForwardIt, class Generator >
void generate( ForwardIt first, ForwardIt last, Generator g );
```

A function for generating data.

```cpp
int main() {
    std::vector<int> vec(10);
    std::generate(begin(vec), end(vec), [i{0}]() mutable { return i++; });
    print(vec);

    return 0;
}
```

Output: `0 1 2 3 4 5 6 7 8 9`

___
<!-- .slide: style="font-size: 0.9em" -->

## `std::swap_ranges`

```cpp
template< class ForwardIt1, class ForwardIt2 >
ForwardIt2 swap_ranges( ForwardIt1 first1, ForwardIt1 last1,
                        ForwardIt2 first2 );
```

It replaces a certain range of data

```cpp
int main() {
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8};
    std::list<int> list {10, 20, 30, 40, 50, 60, 70, 80};
    std::swap_ranges(begin(vec), std::next(begin(vec), 3), std::begin(list));
    print(vec);
    print(list);

    return 0;
}
```

Output:

```text
10 20 30 4 5 6 7 8
1 2 3 40 50 60 70 80
```

___

## `std::reverse`

```cpp
template< class BidirIt >
void reverse( BidirIt first, BidirIt last );
```

Reverses the scope

```cpp
int main() {
    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8};
    std::reverse(begin(vec), end(vec));
    print(vec);

    return 0;
}
```

Output: `8 7 6 5 4 3 2 1`

___

## `std::unique`

```cpp
template< class ForwardIt >
ForwardIt unique( ForwardIt first, ForwardIt last );
```

Removes duplicates. Important! The container must be sorted. In fact, this function does not remove duplicates, but moves the unique values ​​to the top of the container (without changing their mutual order) and returns an iterator pointing to the first element where duplicates begin.

___

## `std::unique` - example

```cpp
int main() {
    std::vector<int> vec {1, 2, 1, 2, 1, 2, 3, 2, 3, 1, 3, 2, 1};
    std::sort(begin(vec), end(vec));
    auto it = std::unique(begin(vec), end(vec));
    print(vec);
    vec.erase(it, end(vec));
    print(vec);

    return 0;
}
```

Output:

```text
1 2 3 1 1 2 2 2 2 2 3 3 3
1 2 3
```

___

## Task

1. Create `std::vector<int>`
2. Fill it with odd numbers from 1 to 15
3. Turn the container over without using a loop or `std::reverse`
4. Rewrite `std::vector<int>` to the list using `std::copy`
5. Create the second `std::vector<int>` and fill it with even numbers from 0 to 14.
6. Find a way to combine both vectors into one with values ​​from 0 to 15 arranged in sequence.

___

## Task

1. Create `std::list<int>` with values ​​from 1 to 10.
2. Create `std::vector<int>` with values ​​from 5 to 10.
3. Pass the appropriate iterators to the function `std::equal`so that it would make both containers equal.
4. With `std::mismatch` and `erase`, remove mismatched items from the list
5. Call the function `std::equal` for full ranges to make sure they are now identical.

___

## Q&A
