<!-- .slide: data-background="#111111" -->

# `std::forward_list<T>`
<!-- .element: style="font-size: 2.3em" -->

## Singly-linked list

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## `std::forward_list<T>` traits

* <!-- .element: class="fragment fade-in" --> The same properties as <code>std::list&lt;T&gt;</code>
* <!-- .element: class="fragment fade-in" --> Less memory consumption - only "next" pointer, no "prev" pointers
* <!-- .element: class="fragment fade-in" --> Due to different memory layout it is considered as faster than <code>std::list&lt;T&gt;</code>
* <!-- .element: class="fragment fade-in" --> Backward iteration is not possible
* <!-- .element: class="fragment fade-in" --> There is no <code>size()</code> method

___
<!-- .slide: style="font-size: 0.8em" -->

### `std::forward_list<T>` methods

##### [`std::forward_list<T>` on cppreference.org](https://en.cppreference.com/w/cpp/container/forward_list)

* <!-- .element: class="fragment fade-in" --> adding an item: <code>push_front()</code>, <code>emplace_front()</code>, <code>insert_after()</code>, <code>emplace_after()</code>, <u class="fragment highlight-red">NO <code>push_back()</code></u>, <u class="fragment highlight-red">NO <code>emplace_back()</code></u>
* <!-- .element: class="fragment fade-in" --> modify/access an item: <span class="fragment highlight-red">via iterators</span>
* <!-- .element: class="fragment fade-in" --> first/last item: <code>front()</code>, <u class="fragment highlight-red">NO <code>back()</code></u>
* <!-- .element: class="fragment fade-in" --> size/is the container empty: <u class="fragment highlight-red">NO <code>size()</code></u>, <code>empty()</code> is available
* <!-- .element: class="fragment fade-in" --> start/end iterator: <code>begin()</code>, <code>end()</code>
* <!-- .element: class="fragment fade-in" --> an iterator that points to the element before <code>begin()</code>: <code>before_begin()</code>
* <!-- .element: class="fragment fade-in" --> constant iterator: <code>cbegin()</code>, <code>cend()</code>, <code>cbefore_begin()</code>
* <!-- .element: class="fragment fade-in" --> clearing the container: <code>clear()</code>
* <!-- .element: class="fragment fade-in" --> sorting: <code class="fragment highlight-green">sort()</code>
* <!-- .element: class="fragment fade-in" --> reversing: <code class="fragment highlight-green">reverse()</code>
* <!-- .element: class="fragment fade-in" --> removing duplicates: <code class="fragment highlight-green">unique()</code>
* <!-- .element: class="fragment fade-in" --> removing items: <code>remove()</code>
* <!-- .element: class="fragment fade-in" --> erasing items: <code>erase_after()</code>
* <!-- .element: class="fragment fade-in" --> erase items using <code>&lt;algorithm&gt;</code>: <code>erase()</code>
* <!-- .element: class="fragment fade-in" --> replacement of the entire container: <code>swap()</code>

___

## Operations complexity

* <!-- .element: class="fragment fade-in" --> The same as for <code>std::list&lt;T&gt;</code>
* <!-- .element: class="fragment fade-in" --> Insertion/deletion
  * <!-- .element: class="fragment fade-in" --> <code>O(1)</code> - at the end or the beginning
  * <!-- .element: class="fragment fade-in" --> <code>O(1)</code> - with an iterator, anywhere
  * <!-- .element: class="fragment fade-in" --> <code>O(n)</code> - other
* <!-- .element: class="fragment fade-in" --> Access
  * <!-- .element: class="fragment fade-in" --> <code>O(1)</code> - at the end or at the beginning
  * <!-- .element: class="fragment fade-in" --> <code>O(1)</code> - with an iterator, anywhere
  * <!-- .element: class="fragment fade-in" --> <code>O(n)</code> - other
* <!-- .element: class="fragment fade-in" --> Searching
  * <!-- .element: class="fragment fade-in" --> <code>O(n)</code>

___

## Memory usage

* <!-- .element: class="fragment fade-in" --> <code>n * (sizeof(T) + sizeof(X*))</code>
* <!-- .element: class="fragment fade-in" --> <code>O(n)</code>
* <!-- .element: class="fragment fade-in" --> Additional small constant memory for internal data is used (head, allocator)

___

## Iterator invalidation

* <!-- .element: class="fragment fade-in" --> Adding, removing and moving the elements within the list or across several lists does not invalidate the iterators or references.
* <!-- .element: class="fragment fade-in" --> An iterator is invalidated only when the corresponding element is deleted.

___

## `std::forward_list<T>::insert_after()` && `std::forward_list<T>::before_begin()`
<!-- .element: style="font-size: 1.2em" -->

A singly-linked list allows us to insert an element after a specific node.
If we want to put an item at the beginning of the list using the `insert_after`, we need to give it a special iterator `before_begin` that points to the element before the first node of the list.
Thus, the method `insert_after()` will insert the desired value exactly as the first item in the list.
<!-- .element: class="fragment fade-in" -->

```cpp []
std::forward_list<int> list {1, 2, 3, 4, 5, 6};
list.insert_after(list.begin(), 10);
print(list);
list.insert_after(list.before_begin(), 0);
print(list);
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```text
1 10 2 3 4 5 6
0 1 10 2 3 4 5 6
```
<!-- .element: class="fragment fade-in" -->

___

## `std::forward_list<T>::remove()`

`std::forward_list` has its own `remove()` method. We don't need to use `erase()`.
<!-- .element: class="fragment fade-in" -->

```cpp []
std::forward_list<int> list {1, 4, 2, 4, 3, 4, 5};
list.remove(4);
// {1, 2, 3, 5}
```
<!-- .element: class="fragment fade-in" -->

___

## `std::forward_list<T>::erase_after()`
<!-- .element: style="font-size: 1.3em" -->

`erase_after()` is used to remove nodes from the position after the element indicated by the first iterator to the point indicated by the second iterator (without the element pointed to by it).
<!-- .element: class="fragment fade-in" -->

```cpp []
std::forward_list<int> list {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
auto it = list.begin();
std::advance(it, 4);
std::cout << "it: " << *it << std::endl;
auto it2 = list.begin();
std::advance(it2, 7);
std::cout << "it2: " << *it2 << std::endl;
list.erase_after(it, it2);
print(list);
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```text
it: 5
it2: 8
1 2 3 4 5 8 9 10
```
<!-- .element: class="fragment fade-in" -->

___

## Task

7. Measure the time of accessing the middle element of the forward lists of size 100K and 1M.

8. Print the `sizeof()` of each container.
