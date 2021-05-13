<!-- .slide: data-background="#111111" -->

# `std::list<T>`

## Doubly-linked list

<a href="https://coders.school">
    <img width="500" data-src="../img/coders_school_logo.png" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## `std::list<T>` traits

* <!-- .element: class="fragment fade-in" --> Elements are scattered around memory (cache-unfriendly)
* <!-- .element: class="fragment fade-in" --> Each element (node) has a pointer to the previous and the next element (mind the memory consumption)
* <!-- .element:  class="fragment fade-in" --> Adding a new element is easy. The necessary memory for the node is allocated and proper pointers (next/prev) are set.
* <!-- .element: class="fragment fade-in" --> Deleting an element is fast, the allocated memory is freed and neighboring nodes have their pointers changed
* <!-- .element: class="fragment fade-in" --> Searching for a node (e.g. to remove or insert a new element after it) is expensive. We have to iterate through all the nodes one by one until we find the wanted one (even if we know exactly that it is e.g. the 40th element in the list)
* <!-- .element: class="fragment fade-in" --> Iterators are not invalidated after each insertion or deletion
* <!-- .element: class="fragment fade-in" --> Only the iterator to the deleted node is invalidated

___
<!-- .element: style="font-size: 0.9em" -->

## `std::list<T>` methods

[`std::list<T>` on cppreference.org](https://en.cppreference.com/w/cpp/container/list)

* <!-- .element: class="fragment fade-in" --> adding an item: <code>push_back()</code>, <code>emplace_back()</code>, <code>push_front()</code>, <code>emplace_front()</code>, <code>insert()</code>
* <!-- .element: class="fragment fade-in" --> modify/access an item: you have to find the item yourself
* <!-- .element: class="fragment fade-in" --> first/last item: <code>back()</code>, <code>front()</code>
* <!-- .element: class="fragment fade-in" --> size/is container empty: <code>size()</code>, <code>empty()</code>
* <!-- .element: class="fragment fade-in" --> start/end iterator: <code>begin()</code>, <code>end()</code>
* <!-- .element: class="fragment fade-in" --> reverse iterator: <code>rbegin()</code>, <code>rend()</code>
* <!-- .element: class="fragment fade-in" --> constant iterator: <code>cbegin()</code>, <code>cend()</code>, <code>crbegin()</code>, <code>crend()</code>
* <!-- .element: class="fragment fade-in" --> container clearing: <code>clear()</code>
* <!-- .element: class="fragment fade-in" --> sort list: <code>sort()</code>
* <!-- .element: class="fragment fade-in" --> reverse list: <code>reverse()</code>
* <!-- .element: class="fragment fade-in" --> removing duplicates: <code>unique()</code>
* <!-- .element: class="fragment fade-in" --> removing items from the list: <code>remove()</code>
* <!-- .element: class="fragment fade-in" --> erasing items from memory: <code>erase()</code>
* <!-- .element: class="fragment fade-in" --> replacement of the entire container: <code>swap()</code>

___

## `std::list<T>::remove()` && `std::list<T>::erase()`

Because the list includes its own `remove()` method, we no longer need to use `erase()`.
<!-- .element: class="fragment fade-in" -->

```cpp []
std::list<int> list{1, 4, 2, 4, 3, 4, 5};
list.remove(4);
// list {1, 2, 3, 5}
```
<!-- .element: class="fragment fade-in" -->

`erase()` is used in similar way like for `std::vector<T>`
<!-- .element: class="fragment fade-in" -->

```cpp []
std::list<int> list{1, 2, 3, 4, 5, 6, 7, 8};
auto it = list.begin();
std::advance(it, 3); // like on pointer ptr += 3
list.erase(list.begin(), it);
// list {4, 5, 6, 7, 8}
```
<!-- .element: class="fragment fade-in" -->

`std::advance()` is used to increment iterators. In our case, we are moving 3 elements forward.
<!-- .element: class="fragment fade-in" -->

___

## Task 4

* Find documentation about `std::list` on [cppreference.com](https://en.cppreference.com)
* Create new cpp file and write `main()` function
* Create a list containing items from 0 to 5
* Print list
* Remove the third item from the list
* Add the value 10 to the beginning and end of the list
* Print list
* Add the number 20 in the fourth position
* Move list content to `std::array`
* Print `std::array`

___

## Q&A
