<!-- .slide: data-background="#111111" -->

# `std::vector<T>`

## Array with dynamic size

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## `std::vector<T>` traits

* <!-- .element: class="fragment fade-in" --> Cache-friendly
* <!-- .element: class="fragment fade-in" --> Items are arranged contiguously in memory just like in a regular array
* <!-- .element: class="fragment fade-in" --> The complexity of adding a new item:
  * <!-- .element: class="fragment fade-in" --> Is constant when  <code>size() < capacity()</code>
  * <!-- .element: class="fragment fade-in" --> Is linear when <code>size() >= capacity()</code>
  * <!-- .element: class="fragment fade-in" --> The vector allocates additional memory space
  * <!-- .element: class="fragment fade-in" --> When there is no more space for additional data in the current area, the entire vector will be copied to another memory location
* <!-- .element: class="fragment fade-in" --> Removing the last element from a vector is cheap, but removing the element from the middle or beginning is expensive
* <!-- .element: class="fragment fade-in" --> We usually do not have proper intuition about how the cache memory can improve the performance
* <!-- .element: class="fragment fade-in" --> Iterators are invalidated after each insertion or deletion

___
<!-- .element: style="font-size: 0.8em" -->

## `std::vector<T>` methods

[`std::vector<T>` on cppreference.org](https://en.cppreference.com/w/cpp/container/vector)

* <!-- .element: class="fragment fade-in" --> adding an item: <code>push_back()</code>, <code>emplace_back()</code>, <code>insert()</code>
* <!-- .element: class="fragment fade-in" --> modifying/accessing an item: <code>at()</code>, <code>operator[]</code>
* <!-- .element: class="fragment fade-in" --> first/last item: <code>back()</code>, <code>front()</code>
* <!-- .element: class="fragment fade-in" --> size/is the container empty: <code>size()</code>, <code>empty()</code>
* <!-- .element: class="fragment fade-in" --> reserved memory space: <code>capacity()</code>
* <!-- .element: class="fragment fade-in" --> reserve memory space: <code>reserve()</code>
* <!-- .element: class="fragment fade-in" --> clearing unused memory from the vector: <code>shrink_to_fit()</code>
* <!-- .element: class="fragment fade-in" --> start/end iterator: <code>begin()</code>, <code>end()</code>
* <!-- .element: class="fragment fade-in" --> reverse iterator: <code>rbegin()</code>, <code>rend()</code>
* <!-- .element: class="fragment fade-in" --> constant iterator: <code>cbegin()</code>, <code>cend()</code>, <code>crbegin()</code>, <code>crend()</code>
* <!-- .element: class="fragment fade-in" --> clearing the container: <code>clear()</code>
* <!-- .element: class="fragment fade-in" --> preparing an item for removal: <code>remove()</code> (not a method of <code>std::vector&lt;T&gt;</code>)
* <!-- .element: class="fragment fade-in" --> erasing items from memory: <code>erase()</code>
* <!-- .element: class="fragment fade-in" --> replacement of the entire container: <code>swap()</code>

___

## Operations complexity

* Insertion/deletion
  * `O(1)` at the end if `size() < capacity()`
  * `O(n)` at the end if `size() >= capacity()`
  * `O(n)` - other
* Access
  * `O(1)`
* Searching
  * `O(n)`

___

## Memory usage

* Generally: `n * sizeof(T)`
* In fact: gradual allocation dependent on the capacity (implementation defined)
  * You can use `reserve()` to allocate memory upfront
  * You can use `shrink_to_fit()` to release not used memory (shrink capacity to size)
* Additional small constant memory for internal data is used (size, capacity, allocator)

___
<!-- .slide: style="font-size: 0.85em" -->

## (Almost) deleting items 😉

### `std::remove()` from `<algorithm>` header

```cpp []
template< class ForwardIt, class T >
ForwardIt remove( ForwardIt first, ForwardIt last, const T& value );
```
<!-- .element: class="fragment fade-in" -->

Since removing items from the end of the vector is fast, the STL library allows us to prepare `std::vector<T>` to remove elements by moving the correct ones to the beginning of the container.
<!-- .element: class="fragment fade-in" -->

As a result, values to be removed are overwritten with values from the end of the vector that should not be removed.
<!-- .element: class="fragment fade-in" -->

Therefore, "garbage" remains at the end of the vector, which must be erased from memory.
<!-- .element: class="fragment fade-in" -->

```cpp []
std::vector<int> vec{1, 4, 2, 4, 3, 4, 5};
auto it = std::remove(vec.begin(), vec.end(), 4);
// for example: vec {1, 2, 3, 5, 3, 4, 5}
                                 ^it
```
<!-- .element: class="fragment fade-in" -->

`std::remove()` returns an iterator that points to the beginning of the data to be erased.
<!-- .element: class="fragment fade-in" -->

___

## Erase

### `std::vector<T>::erase()`

```cpp []
template< class T, class Alloc, class U >
constexpr typename std::vector<T,Alloc>::size_type
    erase(std::vector<T, Alloc>& c, const U& value);
```
<!-- .element: class="fragment fade-in" -->

Thanks to the `erase()` function, we can now remove unnecessary data from the container:
<!-- .element: class="fragment fade-in" -->

```cpp []
std::vector<int> vec{1, 4, 2, 4, 3, 4, 5};
auto it = std::remove(vec.begin(), vec.end(), 4);
vec.erase(it, vec.end());
// vec {1, 2, 3, 5}
```
<!-- .element: class="fragment fade-in" -->

We can also write it all on one line (Erase-Remove Idiom)
<!-- .element: class="fragment fade-in" -->

```cpp []
vec.erase(std::remove(vec.begin(), vec.end(), 4), vec.end());
```
<!-- .element: class="fragment fade-in" -->

___

## Task - remove-vowels

Implement a `removeVowels()` function, which takes `std::vector<std::string>>` and removes all vowels from all strings.

* Input: `{"abcde", "aabbbccabc", "qwerty"}`
* Output: `{"bcd", "bbccbc", "qwrt"}`

[Download the task](https://github.com/coders-school/stl/tree/cr/01-containers/tasks/removeVowels)
