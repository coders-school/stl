<!-- .slide: data-background="#111111" -->

# `std::array<T, N>`

## Fixed size array

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## `std::array<T, N>` traits

* <!-- .element: class="fragment fade-in" --> Cache-friendly
* <!-- .element: class="fragment fade-in" --> Type <code>&lt;N&gt;</code> denotes the size of the array, which must be known at compile time
* <!-- .element: class="fragment fade-in" --> Items are arranged contiguously in memory just like in a regular array
* <!-- .element: class="fragment fade-in" --> <code>std::array</code> is the most primitive wrapper on regular arrays, the efficiency is the same
* <!-- .element: class="fragment fade-in" --> We cannot add a new item, we can only modify the existing items (size does not change)
* <!-- .element: class="fragment fade-in" --> We cannot remove items (size does not change)
* <!-- .element: class="fragment fade-in" --> Reading and modifying elements are very fast

___

## `std::array<T, N>` methods

##### [`std::array<T, N>` on cppreference.org](https://en.cppreference.com/w/cpp/container/array)

* <!-- .element: class="fragment fade-in" --> adding an item:  <span class="fragment highlight-red">impossible</span>
* <!-- .element: class="fragment fade-in" --> modifying/accessing an item: <code class="fragment highlight-green">at()</code>, <code class="fragment highlight-green">operator[]</code>
* <!-- .element: class="fragment fade-in" --> first/last item: <code>back()</code>, <code>front()</code>
* <!-- .element: class="fragment fade-in" --> size/is container empty: <code>size()</code>, <code>empty()</code>
* <!-- .element: class="fragment fade-in" --> start/end iterator: <code>begin()</code>, <code>end()</code>
* <!-- .element: class="fragment fade-in" --> reverse iterator: <code>rbegin()</code>, <code>rend()</code>
* <!-- .element: class="fragment fade-in" --> constant iterator: <code>cbegin()</code>, <code>cend()</code>, <code>crbegin()</code>, <code>crend()</code>
* <!-- .element: class="fragment fade-in" --> clearing the container: <span class="fragment highlight-red">you can't, but there is a method <code>fill</code> which can reset all elements</span>
* <!-- .element: class="fragment fade-in" --> preparing item for removal: <span class="fragment highlight-red">impossible</span>
* <!-- .element: class="fragment fade-in" --> erasing items from memory: <span class="fragment highlight-red">impossible</span>
* <!-- .element: class="fragment fade-in" --> replacement of the entire container: <code>swap()</code>

___

## Operations complexity

* <!-- .element: class="fragment fade-in" --> Insertion/deletion
  * <!-- .element: class="fragment fade-in" --> Not available
* <!-- .element: class="fragment fade-in" --> Access
  * <!-- .element: class="fragment fade-in" --> <code>O(1)</code>
* <!-- .element: class="fragment fade-in" --> Searching
  * <!-- .element: class="fragment fade-in" --> <code>O(n)</code>

___

## Memory usage

* <!-- .element: class="fragment fade-in" --> <code>n * sizeof(T)</code>
* <!-- .element: class="fragment fade-in" --> <code>O(n)</code>
* <!-- .element: class="fragment fade-in" --> No additional memory overhead
* <!-- .element: class="fragment fade-in" --> Size is kept as a template parameter, not a member

___

## Iterator invalidation

* <!-- .element: class="fragment fade-in" --> Never
* <!-- .element: class="fragment fade-in" --> During <code>swap</code>, the iterator will continue to point to the same array element, and will thus change its value

___

### Passing `std::array<T, N>` to function

Because `std::array<T, N>` has 2 template parameters, some may have a problem passing it to a function
<!-- .element: class="fragment fade-in" -->

```cpp []
template <size_t SIZE>
void print(const std::array<int, SIZE>& arr) {
    for (const auto& el : arr) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::array<int, 10> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print(arr);

    return 0;
}
```
<!-- .element: class="fragment fade-in" -->

___

## Task

Develop our performance testing framework.

3. Measure the time of accessing the middle element of the `std::array` of ints of size 100K and 1M.

4. Refactor the code - write an `access` function. It should take a container and its size as parameters.
   You need to extend the functionality of the `measure` function to take additional parameters.
   Use variadic templates and the perfect forwarding.
