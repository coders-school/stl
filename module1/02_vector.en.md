<!-- .slide: data-background="#111111" -->

# `std::vector<T>`

## An array with dynamic size

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Features `std::vector<T>`

* <!-- .element: class="fragment fade-in" --> Cache-friendly, i.e. by iterating over the vector, it will all be loaded into the processor's cache, which will speed up reading the data.
* <!-- .element: class="fragment fade-in" --> Type <code>&lt;T&gt;</code> can be any. Both the built-in type and the <code>int</code>, <code>double</code>as well as your own type defined by us.
* <!-- .element: class="fragment fade-in" --> The items are arranged side by side in memory just like in a regular array.
* <!-- .element: class="fragment fade-in" --> Adding a new item when a dependency occurs <code>vec.size() > vec.capacity()</code> will allocate additional memory space. In a critical situation, when there is no more space for additional data in the current area, the entire vector will be moved to another memory location.
* <!-- .element: class="fragment fade-in" --> Removing an element from a vector is quick when removing the last element, but expensive when removing from the center or from the beginning.

___
<!-- .element: style="font-size: 0.9em" -->

## Operations on `std::vector<T>`

* <!-- .element: class="fragment fade-in" --> adding an item: <code>push_back()</code>, <code>emplace_back()</code>, <code>insert()</code>
* <!-- .element: class="fragment fade-in" --> modifying / accessing an item: <code>at()</code>, <code>operator []</code>
* <!-- .element: class="fragment fade-in" --> first / last item: <code>back()</code>, <code>front()</code>
* <!-- .element: class="fragment fade-in" --> size / is the container empty: <code>size()</code>, <code>empty()</code>
* <!-- .element: class="fragment fade-in" --> reserved seat: <code>capacity()</code>
* <!-- .element: class="fragment fade-in" --> reserve memory space: <code>reserve()</code>
* <!-- .element: class="fragment fade-in" --> clearing unused memory from the vector: <code>shrink_to_fit()</code>
* <!-- .element: class="fragment fade-in" --> start / end iterator: <code>begin()</code>, <code>end()</code>
* <!-- .element: class="fragment fade-in" --> reverse iterator: <code>rbegin()</code>, <code>rend()</code>
* <!-- .element: class="fragment fade-in" --> constant iterator: <code>cbegin()</code>, <code>cend()</code>, <code>crbegin()</code>, <code>crend()</code>
* <!-- .element: class="fragment fade-in" --> container cleaning: <code>clear()</code>
* <!-- .element: class="fragment fade-in" --> preparing an item for removal: <code>remove()</code> (not a method <code>std::vector&lt;T&gt;</code>)
* <!-- .element: class="fragment fade-in" --> erasing items from memory: <code>erase()</code>
* <!-- .element: class="fragment fade-in" --> replacement of the entire container: <code>swap()</code>

___

## Inserting # 1 items

### `std::vector<T>::insert()`

```cpp
iterator insert( const_iterator pos, const T& value );
```
<!-- .element: class="fragment fade-in" -->

In order to add an element to a vector, we can use an iterator:
<!-- .element: class="fragment fade-in" -->

```cpp
std::vector<int> vec{1, 2, 3, 4};
auto it = vec.begin();
vec.insert(it, 20); // {20, 1, 2, 3, 4};
```
<!-- .element: class="fragment fade-in" -->

___

## Insert items # 2

### `std::vector<T>::insert()`

```cpp
iterator insert( const_iterator pos, size_type count, const T& value );
```
<!-- .element: class="fragment fade-in" -->

We can also define how many elements we want to add:
<!-- .element: class="fragment fade-in" -->

```cpp
std::vector<int> vec{1, 2, 3, 4};
auto it = vec.begin();
vec.insert(it, 5, 20); // {20, 20, 20, 20, 20, 1, 2, 3, 4};
```
<!-- .element: class="fragment fade-in" -->

___

## Insert items # 3

### `std::vector<T>::insert()`

```cpp
template< class InputIt >
iterator insert( const_iterator pos, InputIt first, InputIt last );
```
<!-- .element: class="fragment fade-in" -->

It is also possible to insert elements from one container to another:
<!-- .element: class="fragment fade-in" -->

```cpp
std::vector<int> vec{1, 2, 3, 4};
std::list<int> list{10, 20, 30, 40};
vec.insert(vec.begin(), list.begin(), list.end());
// vec = {10, 20, 30, 40, 1, 2, 3, 4}
```
<!-- .element: class="fragment fade-in" -->

___

## Iterating backwards

### `std::vector<T>::rbegin()`, `std::vector<T>::rend()`
<!-- .element: style="font-size: 0.9em" -->

```cpp
std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
for (auto it = vec.crbegin() ; it != vec.crend() ; ++it) {
    // cr = (r)everse iterator to (c)onst value
    std::cout << *it << ' ';
}
```
<!-- .element: class="fragment fade-in" -->

Output: `9 8 7 6 5 4 3 2 1`
<!-- .element: class="fragment fade-in" -->

```cpp
std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
for (auto it = vec.rbegin() ; it != vec.rend() ; ++it) {
    *it *= 2;
}
for (auto it = vec.crbegin() ; it != vec.crend() ; ++it) {
    std::cout << *it << ' ';
}
```
<!-- .element: class="fragment fade-in" -->

Output: `18 16 14 12 10 8 6 4 2`
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.95em" -->

## (Almost) delete 😉

### `std::remove()` from the header `<algorithm>`

```cpp
template< class ForwardIt, class T >
ForwardIt remove( ForwardIt first, ForwardIt last, const T& value );
```
<!-- .element: class="fragment fade-in" -->

Since elements are removed from the end of the vector the fastest, the STL library allows us to prepare `std::vector<T>` to remove elements by moving the correct ones to the beginning of the container.
As a result, part of the value to be removed is overwritten with values ​​at the end of the vector that should not be removed.
Therefore, "garbage" remains at the end of the vector, which must be erased from memory.
<!-- .element: class="fragment fade-in" -->

```cpp
std::vector<int> vec{1, 4, 2, 4, 3, 4, 5};
std::remove(vec.begin(), vec.end(), 4);
// for example: vec {1, 2, 3, 5, 3, 4, 5}
```
<!-- .element: class="fragment fade-in" -->

`std::remove()` will return an iterator that will point to the beginning of the data to be deleted.
<!-- .element: class="fragment fade-in" -->

___

## Delete

### `std::vector<T>::erase()`

```cpp
template< class T, class Alloc, class U >
constexpr typename std::vector<T,Alloc>::size_type
    erase(std::vector<T, Alloc>& c, const U& value);
```
<!-- .element: class="fragment fade-in" -->

Thanks to the erase function, we can now remove unnecessary data from the container:
<!-- .element: class="fragment fade-in" -->

```cpp
std::vector<int> vec{1, 4, 2, 4, 3, 4, 5};
auto it = std::remove(vec.begin(), vec.end(), 4);
vec.erase(it, vec.end());
// vec {1, 2, 3, 5}
```
<!-- .element: class="fragment fade-in" -->

We can also write it all on one line (Erase-Remove Idiom)
<!-- .element: class="fragment fade-in" -->

```cpp
vec.erase(std::remove(vec.begin(), vec.end(), 4), vec.end());
```
<!-- .element: class="fragment fade-in" -->

___

## Task 1

* [Open the vector documentation at cppreference.com](https://en.cppreference.com/w/cpp/container/vector)
* Create new cpp file and write function `main()`
* Create a vector with the values ​​{1, 2, 4, 5, 6}
* Delete the first value
* Add the value 5 to the end of the vector
* Add the value 12 to the start of the vector with the method `emplace`
* List the vector size and the maximum possible size
* List the vector content
* Clear vector
* List the size of the vector

___

## Exercise 2

* [Open the vector documentation at cppreference.com](https://en.cppreference.com/w/cpp/container/vector)
* Create new cpp file and write function `main()`
* Create an empty vector
* List the size and capacity of the vector
* Resize the vector to 10 and fill it with 5 values
* List the size and capacity of the vector
* Reserve memory for 20 items
* List the size and capacity of the vector
* Reduce vector capacitance by method `shrink_to_fit()`
* List the size and capacity of the vector

___

## Q&A
