<!-- .slide: data-background="#111111" -->

# Non-modifying algorithms

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Algorithms that do not modify containers

They do not modify the containers they run on.

They cannot:

* rearrange items in a container
* delete items
* add items

Here you will only find popular or interesting uses of some algorithms. The full list of algorithms is available on cppreference.com

[Algorithms on cppreference.com](https://en.cppreference.com/w/cpp/algorithm)

___

## `std::find_if`

```cpp
template< class InputIt, class UnaryPredicate >
InputIt find_if( InputIt first, InputIt last, UnaryPredicate p );
```

* Predicate = functor, function, lambda that returns `bool` (`true/false`)
* Algorithm used to search for items of interest. What interests us will be decided by the passed predicate. If we want numbers divisible by 3 we will use the predicate:
  * `[](const auto& el){ return (el % 3 == 0); }`
* `std::find_if` is different from `std::find` only that instead of the searched value, we give the predicate that must be met in order to consider a given element as the value sought.
* The type returned by `std::find_if` is an iterator pointing to the found element.
* If the item is not found, the return value will be equal to `last`.

___

## `std::find_if` - use

```cpp
std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
auto found = std::find_if(begin(vec), end(vec), [](const auto& el) {
    return el == 7;
});
if (found != vec.end()) {
    std::cout << *found << '\n';
}
```

Output: `found 7`

___

## `std::search`

```cpp
template< class ForwardIt1, class ForwardIt2 >
ForwardIt1 search( ForwardIt1 first, ForwardIt1 last,
                   ForwardIt2 s_first, ForwardIt2 s_last );
```

* The simplest version `std::search`, takes 2 ranges and checks if the second range `{s_first, s_last}` is a subsequence of `{first, last}`.
  * If so, it returns an iterator pointing to the beginning of this subsequence.
  * If no subsequence is found, the iterator returned will be equal to `last`.
* There are also versions of `std::search` that take `binary predicate` and type `searcher`. I encourage you to work independently in order to learn how to use this function :).

___

## `std::search` - use

```cpp
std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
std::vector<int> vec2 {4, 5, 6};
auto found = std::search(begin(vec), end(vec),
                         begin(vec2), end(vec2));
if (found != vec.end()) {
    std::cout << "first found element: " << *found << '\n';
}
```

Output: `first found element: 4`

___

## `std::count` and `std::count_if`

```cpp
template< class InputIt, class T >
typename iterator_traits<InputIt>::difference_type
    count( InputIt first, InputIt last, const T &value );
```

```cpp
template< class InputIt, class UnaryPredicate >
typename iterator_traits<InputIt>::difference_type
    count_if( InputIt first, InputIt last, UnaryPredicate p );
```

* `std::count` counts the occurrence of a specific value for a given range.
* `std::count_if` counts the number of returned `true` values for a given range by the predicate.

___

## `std::count` and `std::count_if` - use

```cpp
std::vector<int> vec {1, 2, 3, 4, 5, 1, 1, 1, 6, 7};

std::cout << std::count(begin(vec), end(vec), 1) << '\n';

auto counter = std::count_if(begin(vec), end(vec), [](const auto& el){
    return el % 3 == 0;
});
std::cout << counter << '\n';
```

Output:

```text
4
2
```

___

## `std::equal`

```cpp
  template< class InputIt1, class InputIt2 >
  bool equal( InputIt1 first1, InputIt1 last1,
              InputIt2 first2 );
```

```cpp
  template< class InputIt1, class InputIt2 >
  bool equal( InputIt1 first1, InputIt1 last1,
              InputIt2 first2, InputIt2 last2 )
```

* The algorithm takes the scope of the first container and the beginning of the second container. The function will perform check until it reaches the end of range 1, even if range 2 is longer. If the 2nd range is shorter the function will return false, because for sure the range 1 will not be identical since it is longer.
* The second version of the algorithm allows you to take the full scope of container 1 and 2 and compare these ranges.

___

## `std::equal` - use # 1

```cpp
// Missing vec1 and vec2 :D Can you think of the examples of vec1 and 2 that
// will make the output look like below?
std::cout << std::boolalpha << "EQUAL?: "
          << std::equal(begin(vec1), end(vec1), begin(vec2)) << '\n';
std::cout << std::boolalpha << "EQUAL?: "
          << std::equal(begin(vec2), end(vec2), begin(vec1)) << '\n';
std::cout << std::boolalpha << "EQUAL?: "
          << std::equal(begin(vec1), end(vec1),
                        begin(vec2), std::next(vec2.begin(), 5))
          << '\n';
```

Output:

```text
EQUAL?: true
EQUAL?: false
EQUAL?: true
```

___

## `std::equal` - use # 2

```cpp
bool is_palindrome(const std::string& s) {
    return std::equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}
void test(const std::string& s) {
    std::cout << "\"" << s << "\" "
              << (is_palindrome(s) ? "is" : "is not")
              << " a palindrome\n";
}
int main() {
    test("radar");
    test("hello");
}
```

Output:

```text
  "radar" is a palindrome
  "hello" is not a palindrome
```

___

## `std::mismatch`

```cpp
template< class InputIt1, class InputIt2 >
std::pair<InputIt1,InputIt2>
    mismatch( InputIt1 first1, InputIt1 last1,
              InputIt2 first2 );
```

```cpp
template< class InputIt1, class InputIt2 >
std::pair<InputIt1,InputIt2>
    mismatch( InputIt1 first1, InputIt1 last1,
              InputIt2 first2, InputIt2 last2 );
```

It works analogously to `std::equal`, except that it returns a pair of iterators (for the first and second ranges) indicating the start of the mismatch.

___

## `std::mismatch` - use

```cpp
std::string mirror_ends(const std::string& in) {
    return std::string(in.begin(),
                       std::mismatch(in.begin(), in.end(), in.rbegin()).first);
}

int main() {
    std::cout << mirror_ends("abXYZba") << '\n'
              << mirror_ends("abca") << '\n'
              << mirror_ends("aba") << '\n';
}
```

Output:

```text
ab
a
aba
```

___

## Q&A
