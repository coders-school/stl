<!-- .slide: data-background="#111111" -->

# Map and multimap

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## `std::map<K, T>` and `std::multimap<K, T>` traits #1

* <!-- .element: class="fragment fade-in" --> Usually implemented as a binary tree (red-black tree)
* <!-- .element: class="fragment fade-in" --> Cache-unfriendly
* <!-- .element: class="fragment fade-in" --> Hold key-value pairs ordered by key
* <!-- .element: class="fragment fade-in" --> Unique keys (<code>map</code>) or repeating keys are allowed (<code>multimap</code>)
* <!-- .element: class="fragment fade-in" --> An alternative to multimap is <code>std::map&lt;key, std::vector&lt;value&gt;&gt;</code>

___
<!-- .slide: style="font-size: 0.95em" -->

## `std::map<K, T>` and `std::multimap<K, T>` traits #2

In red-black trees, the time to insert, delete or add an element is `O(log n)`.

Advantages:
<!-- .element: class="fragment fade-in" -->

* <!-- .element: class="fragment fade-in" --> A quick search for items - sequence containers have <code>O(n)</code> complexity,
* <!-- .element: class="fragment fade-in" --> Adding and removing elements is relatively cheap
  * <!-- .element: class="fragment fade-in" --> <code>std::vector&lt;T&gt;</code> adds items in the middle in time <code>O(n)</code>
  * <!-- .element: class="fragment fade-in" --> <code>std::list&lt;T&gt;</code> (if an iterator is given) adds items in <code>O(1)</code>
  * <!-- .element: class="fragment fade-in" --> Hence the map is relatively fast in both adding and removing
* <!-- .element: class="fragment fade-in" --> Perfect when we frequently search for data and less frequently add or delete it.

If we use it as a regular container, we will lose efficiency. The map should be used when you want to have key-value pairs and search for them often. Otherwise, we can use `std::vector<pair<K, V>>`.
<!-- .element: class="fragment fade-in" -->

___

## `std::map<K, T>` and `std::multimap<K, T>` methods

[`std::map<K, T>` on cppreference.org](https://en.cppreference.com/w/cpp/container/map)

[`std::multimap<K, T>` on cppreference.org](https://en.cppreference.com/w/cpp/container/multimap)

* <!-- .element: class="fragment fade-in" --> adding an item: <code>insert()</code>, <code>emplace()</code>, <code class="fragment highlight-green">emplace_hint()</code>. Additionally, the map has: <code class="fragment highlight-green">insert_or_assign()</code>, <code class="fragment highlight-green">try_emplace()</code> and <code class="fragment highlight-green">operator[]</code> (for inserting)
* <!-- .element: class="fragment fade-in" --> modifying/accessing an item: <code class="fragment highlight-green">at()</code>, <code class="fragment highlight-green">operator[]</code> <span  class="fragment highlight-red">(<code>multimap</code> does not have such methods)</span>
* <!-- .element: class="fragment fade-in" --> size/is the container empty: <code>size()</code>, <code>empty()</code>
* <!-- .element: class="fragment fade-in" --> clear unused memory: <span class="fragment highlight-red"><span class="fragment highlight-red">none</span></span>
* <!-- .element: class="fragment fade-in" --> first/last item: <span class="fragment highlight-red">none</span>
* <!-- .element: class="fragment fade-in" --> start/end iterator: <code>begin()</code>, <code>end()</code>

___

## `std::map<K, T>` and `std::multimap<K, T>` methods #2

* <!-- .element: class="fragment fade-in" --> reverse iterator: <code>rbegin()</code>, <code>rend()</code>
* <!-- .element: class="fragment fade-in" --> constant iterator: <code>cbegin()</code>, <code>cend()</code>, <code>crbegin()</code>, <code>crend()</code>
* <!-- .element: class="fragment fade-in" --> cleaning the container: <code>clear()</code>
* <!-- .element: class="fragment fade-in" --> preparing an item for removal: <span class="fragment highlight-red">none</span>
* <!-- .element: class="fragment fade-in" --> erasing items from memory: <code>erase()</code>
* <!-- .element: class="fragment fade-in" --> replacement of the entire container: <code>swap()</code>
* <!-- .element: class="fragment fade-in" --> counting elements matching a given key: <code class="fragment highlight-green">count()</code> (returns only 0 or 1 for <code>map</code> or any positive number from 0 to n for <code>multimap</code>)
* <!-- .element: class="fragment fade-in" --> finding an element with a given key: <code class="fragment highlight-green">find()</code>
* <!-- .element: class="fragment fade-in" --> contains a given key (C++20): <code class="fragment highlight-green">contains()</code>

___

## Operations complexity

* <!-- .element: class="fragment fade-in" --> Insertion/deletion
  * <!-- .element: class="fragment fade-in" --> <code>O(log n)</code>
* <!-- .element: class="fragment fade-in" --> Access
  * <!-- .element: class="fragment fade-in" --> <code>O(log n)</code>
* <!-- .element: class="fragment fade-in" --> Searching
  * <!-- .element: class="fragment fade-in" --> <code>O(log n)</code>

___

## Memory usage

* <!-- .element: class="fragment fade-in" --> <code>n * (sizeof(std::pair<K, T>) + 2 * sizeof(X*))</code>
* <!-- .element: class="fragment fade-in" --> <code>O(n)</code>
* <!-- .element: class="fragment fade-in" --> Additional small constant memory for internal data is used (root, compare, allocator)

___

## Iterator invalidation

* <!-- .element: class="fragment fade-in" --> Adding, removing and moving the elements within the map or across several maps does not invalidate the iterators or references.
* <!-- .element: class="fragment fade-in" --> An iterator is invalidated only when the corresponding element is deleted.

___

## Example of `emplace_hint` usage

```cpp []
int main() {
    std::map<int, std::string> map;

    auto it = map.begin();
    map.emplace_hint(it, 10, "Ten");

    std::cout << map[10] << '\n';
}
```
<!-- .element: class="fragment fade-in" -->

Output:
`Ten`
<!-- .element: class="fragment fade-in" -->

We suggest the place where the element should be inserted in the map. Thanks to that, such an operation can have `O(1)` complexity.
<!-- .element: class="fragment fade-in" -->

However, if we give an incorrect hint, the insertion time is `O(log n)`. Rather rarely used 🙂
<!-- .element: class="fragment fade-in" -->

___

### Example of `count` usage

```cpp
int main() {
    std::multimap<int, std::string> map;

    map.insert({5, "Five"});
    map.insert({5, "Funf"});
    map.insert({5, "Piec"});
    map.insert({5, "Cinq"});
    std::cout << map.count(5) << '\n';
}
```
<!-- .element: class="fragment fade-in" -->

Output: `4`
<!-- .element: class="fragment fade-in" -->

___

## Task

13. Measure the time of accessing/inserting the middle element of the `std::map` and `std::multimap` of size 100K and 1M.
14. Measure the time of accessing/inserting data with `operator[]` into the `std::map` when the key exists and when it does not exist.
