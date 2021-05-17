<!-- .slide: data-background="#111111" -->

# Iterators

___

## Short revision #1

An iterator is an object that points to a given item in a container. Depending on the type, we can perform various operations on it, e.g. increment it `operator++`, decrement `operator--` or perform operations like `it += 6`. In order to refer to the pointed element by the iterator, we use `operator*` that is, dereference (as in the pointers).

___

## Short revision #2

Each container has 2 ends. `begin()` points to one of them and `end()` points to the second one.

<image src="img/iterator.png">

___

## Short revision #3

For some containers, we can also get a reverse iterator that allows us to go backwards.

<image src="img/rev_iterator.gif">

___

## Short revision #4

If we do not want to modify the data indicated by the iterator, we will use the option with the prefix `c` derived from the word `constant`.

* <!-- .element: class="fragment fade-in" --> <code>cbegin()</code>
* <!-- .element: class="fragment fade-in" --> <code>cend()</code>
* <!-- .element: class="fragment fade-in" --> <code>crbegin()</code>
* <!-- .element: class="fragment fade-in" --> <code>crend()</code>

___

## The iterator hierarchy

<image src="img/iterator_categories.gif" height="350px">

Question: what should be in place of `forward_iterator`?
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>std::forward_list<T></code>
* <!-- .element: class="fragment fade-in" --> <code>std::unordered_set<T></code>
* <!-- .element: class="fragment fade-in" --> <code>std::unordered_map<T></code>

___

### "The poorest" iterators: input and output

Input iterator comes e.g. from stream `std::istream`, that is known to us as `std::cin`. Once loaded, the data disappears, we cannot read it again. We can only go through the data once. In other words, as soon as we read given data, our operator is immediately incremented.

```cpp
int a;
int b;
std::cin >> a >> b;
```
<!-- .element: class="fragment fade-in" -->

Output iterator comes e.g. from stream `std::ostream`, that is known to us as `std::cout`. Once the data is printed, it disappears, we cannot display it again, we have to enter the data again.
<!-- .element: class="fragment fade-in" -->

```cpp
int a;
int b;
std::cin >> a >> b;
std::cout << a << ' ' << b;
```
<!-- .element: class="fragment fade-in" -->
___

### Question

What are the available operators for input iterator and for output iterator?

Input iterator:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>operator++</code>
* <!-- .element: class="fragment fade-in" --> <code>operator*</code>
* <!-- .element: class="fragment fade-in" --> <code>operator-></code>
* <!-- .element: class="fragment fade-in" --> <code>operator==</code>
* <!-- .element: class="fragment fade-in" --> <code>operator!=</code>

Output iterator:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>operator++</code>
* <!-- .element: class="fragment fade-in" --> <code>operator*</code>

___

### Forward iterator

It is an iterator that allows us to repeatedly traverse a given range in one direction (forward).

```cpp
std::forward_list<int> list {1, 2, 3, 4, 5};
for (auto it = list.begin() ; it != list.end() ; ++it) {
    std::cout << *it << '\n';
}
```
<!-- .element: class="fragment fade-in" -->

Output: `1 2 3 4 5`
<!-- .element: class="fragment fade-in" -->

Question: What are the available operators for this iterator?
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>operator++</code>
* <!-- .element: class="fragment fade-in" --> <code>operator*</code>
* <!-- .element: class="fragment fade-in" --> <code>operator-></code>
* <!-- .element: class="fragment fade-in" --> <code>operator==</code>
* <!-- .element: class="fragment fade-in" --> <code>operator!=</code>

___
<!-- .slide: style="font-size: 0.85em" -->

### Bidirectional iterator

It is an iterator that allows us to repeatedly traverse a given range in both directions (forwards and backwards).

```cpp
std::list<int> list{1, 2, 3, 4, 5};
for (auto it = list.begin(); it != list.end(); ++it) {
    std::cout << *it << ' ';
}
auto last = std::prev(list.end());
for (auto it = last; it != std::prev(list.begin()); --it) {
    std::cout << *it << ' ';
}
```
<!-- .element: class="fragment fade-in" -->

Output: `1 2 3 4 5 5 4 3 2 1`
<!-- .element: class="fragment fade-in" -->

Question: What are the available operators for this iterator?
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>operator++</code>
* <!-- .element: class="fragment fade-in" --> <code>operator*</code>
* <!-- .element: class="fragment fade-in" --> <code>operator-></code>
* <!-- .element: class="fragment fade-in" --> <code>operator==</code>
* <!-- .element: class="fragment fade-in" --> <code>operator!=</code>
* <!-- .element: class="fragment fade-in" --> <code>operator--</code>

___

### Random Access iterator

It is an iterator that allows us to repeatedly traverse a given range back and forth, as well as access any object.

```cpp
std::vec<int> vec{1, 2, 3, 4, 5};
for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << ' ';
}
auto last = std::prev(vec.end());
for (auto it = last; it != std::prev(vec.begin()); --it) {
    std::cout << *it << ' ';
}
std::cout <<  vec[3];
```
<!-- .element: class="fragment fade-in" -->

Output: `1 2 3 4 5 5 4 3 2 1 3`
<!-- .element: class="fragment fade-in" -->

___

### Random Access iterator

Question: What are the available operators for this iterator?
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> <code>operator++</code>
* <!-- .element: class="fragment fade-in" --> <code>operator*</code>
* <!-- .element: class="fragment fade-in" --> <code>operator-></code>
* <!-- .element: class="fragment fade-in" --> <code>operator==</code>
* <!-- .element: class="fragment fade-in" --> <code>operator!=</code>
* <!-- .element: class="fragment fade-in" --> <code>operator--</code>
* <!-- .element: class="fragment fade-in" --> <code>operator<</code>
* <!-- .element: class="fragment fade-in" --> <code>operator<=</code>
* <!-- .element: class="fragment fade-in" --> <code>operator></code>
* <!-- .element: class="fragment fade-in" --> <code>operator>=</code>
* <!-- .element: class="fragment fade-in" --> <code>operator+</code>
* <!-- .element: class="fragment fade-in" --> <code>operator-</code>
* <!-- .element: class="fragment fade-in" --> <code>operator[]</code>

___

### Trivia

Another type was introduced in C++17: `ContiguousIterator`. It includes all the features of the Random Access iterator and ensures that all data is arranged in one place in memory.

___

## Q&A
