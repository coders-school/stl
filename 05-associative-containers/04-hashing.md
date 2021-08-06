<!-- .slide: data-background="#111111" -->

# Hashing containers

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Hash Table

<image src="../img/chainedHashing.png" class="r-stretch">

___
<!-- .slide: style="font-size: 0.8em" -->

## Hash function

It is any function that can be used to map data of arbitrary size to fixed-size values, eg. an index of an array.

### Rate below hash functions
<!-- .element: class="fragment fade-in" -->

```cpp
size_t hash(const std::string& str) { return str.size(); }
```
<!-- .element: class="fragment fade-in" -->

```cpp
size_t hash(const std::string& str) {
    size_t index = 0;
    for (size_t i = 0 ; i < str.size() ; ++i) {
        index += (int)str[i];
    }
    return index;
}
```
<!-- .element: class="fragment fade-in" -->

```cpp
size_t hash(const std::string& str) {
    size_t index = 0;
    for (size_t i = 0 ; i < str.size() - 1 ; ++i) {
        index += ((int)str[i] * int(str[i + 1]) * (i + 5)) & (((int)str[i] + int(str[i + 1]) * i * i));
    }
    return index * str.size();
}
```
<!-- .element: class="fragment fade-in" -->

___

## `std::unordered_set<K>` and `std::unordered_multiset<K>` traits #1

* <!-- .element: class="fragment fade-in" --> Implemented as a hash table
* <!-- .element: class="fragment fade-in" --> It may or may not be cache friendly
  * Hash tables are often created as a hybrid of <code>std::vector&lt;T&gt;</code> and <code>std::list&lt;T&gt;</code>
* <!-- .element: class="fragment fade-in" --> Values ​​are not sorted
* <!-- .element: class="fragment fade-in" --> Unique keys (<code>set</code>) or repeating keys are (<code>multiset</code>)

___

## `std::unordered_set<K>` and `std::unordered_multiset<K>` traits #2

The hash table provides the average time of adding, removing, accessing and modification of `O(1)`. The worst time for all operations is `O(n)`.

Advantages:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> Very fast searching
* <!-- .element: class="fragment fade-in" --> Constant time of adding and removing items...
* <!-- .element: class="fragment fade-in" --> Assuming that we have a good hash function

Perfect for read-only containers. Reading time is `O(1)`.
Great for types with a good hash function.
<!-- .element: class="fragment fade-in" -->

___

## `std::unordered_set<K>` and `std::unordered_multiset<K>` methods

[`std::unordered_set<K>` on cppreference.org](https://en.cppreference.com/w/cpp/container/unordered_set)

[`std::unordered_multiset<K>` on cppreference.org](https://en.cppreference.com/w/cpp/container/unordered_multiset)

* <!-- .element: class="fragment fade-in" --> adding an item: <code>insert()</code>, <code>emplace()</code>, <code class="fragment highlight-green">emplace_hint()</code>
* <!-- .element: class="fragment fade-in" --> modifying/accessing an item: <span class="fragment highlight-red">none</span>
* <!-- .element: class="fragment fade-in" --> first/last item: <span class="fragment highlight-red">none</span>
* <!-- .element: class="fragment fade-in" --> size/is the container empty: <code>size()</code>, <code>empty()</code>
* <!-- .element: class="fragment fade-in" --> clear unused memory: <span class="fragment highlight-red">none</span>
* <!-- .element: class="fragment fade-in" --> start/end iterator: <code>begin()</code>, <code>end()</code>
* <!-- .element: class="fragment fade-in" --> reverse iterator: <span class="fragment highlight-red">none</span>

___

## `std::unordered_set<K>` and `std::unordered_multiset<K>` methods #2

* <!-- .element: class="fragment fade-in" --> constant iterator: <code>cbegin()</code>, <code>cend()</code>
* <!-- .element: class="fragment fade-in" --> container cleaning: <code>clear()</code>
* <!-- .element: class="fragment fade-in" --> preparing item for removal: <span class="fragment highlight-red">none</span>
* <!-- .element: class="fragment fade-in" --> erasing items from memory: <code>erase()</code>
* <!-- .element: class="fragment fade-in" --> replacement of the entire container: <code>swap()</code>
* <!-- .element: class="fragment fade-in" --> counting elements matching a given key: <code class="fragment highlight-green">count()</code> (returns only 0 or 1 for <code>map</code> or any positive number from 0 to n for <code>multimap</code>)
* <!-- .element: class="fragment fade-in" --> finding an element with a given key: <code class="fragment highlight-green">find()</code>

___

## Operations complexity

* <!-- .element: class="fragment fade-in" --> Insertion/deletion
  * <!-- .element: class="fragment fade-in" --> <code>O(1)</code> - average case
  * <!-- .element: class="fragment fade-in" --> <code>O(n)</code> - worst case
* <!-- .element: class="fragment fade-in" --> Access
  * <!-- .element: class="fragment fade-in" --> <code>O(1)</code> - average case
  * <!-- .element: class="fragment fade-in" --> <code>O(n)</code> - worst case
* <!-- .element: class="fragment fade-in" --> Searching
  * <!-- .element: class="fragment fade-in" --> <code>O(1)</code> - average case
  * <!-- .element: class="fragment fade-in" --> <code>O(n)</code> - worst case

___

## Memory usage

* <!-- .element: class="fragment fade-in" --> <code>n * (sizeof(K) + sizeof(X*)) + n / bucket_size</code>
* <!-- .element: class="fragment fade-in" --> <code>O(n)</code>
* <!-- .element: class="fragment fade-in" --> Additional memory for vector of pointers is used (bucket list)
* <!-- .element: class="fragment fade-in" --> Additional small constant memory for internal data is used (begin, end, size, hash, key_eq, allocator)

___

## Iterator invalidation

* All read only operations, `swap`, `std::swap`: never
* `clear()`, `rehash()`, `reserve()`, `operator=()`: always
* `insert()`, `emplace()`, `emplace_hint()`, `operator[]()`: only if causes rehash
* `erase()`: only to the erased element

___

## Example of `std::unordered_set<K>` and `std::unordered_multiset<K>` usage

```cpp
std::unordered_set<std::string> set{"Ala", "Ma", "Kota",
                                    "A", "Kot", "Ma", "ALE"};
for (const auto el : set) {
    std::cout << el << ' ';
}
std::cout << '\n';
set.insert("Ala");
set.insert("Ala");
set.insert("Ala");
for (const auto el : set) {
    std::cout << el << ' ';
}
std::cout << '\n';
```
<!-- .element: class="fragment fade-in" -->

___

## `unordered_map<K, T>` and `unordered_multimap<K, T>`

* <!-- .element: class="fragment fade-in" --> Guess the features
* <!-- .element: class="fragment fade-in" --> Guess the implementation

___

## Task

17. Measure the time of accessing/inserting the middle element of the `std::unordered_set` and `std::unordered_multiset` of size 100K and 1M.
