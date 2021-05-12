<!-- .slide: data-background="#111111" -->

# `std::forward_list<T>`
<!-- .element: style="font-size: 2.3em" -->

## Singly-linked list

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## `std::forward_list<T>` traits

* <!-- .element: class="fragment fade-in" --> Items scattered around memory
* <!-- .element: class="fragment fade-in" --> Each element (node) has a pointer to the next element
* <!-- .element: class="fragment fade-in" --> Type <code>&lt;T&gt;</code> can be any type. Both the built-in type like <code>int</code>, <code>double</code> as well as type defined by us.
* <!-- .element: class="fragment fade-in" --> It is not cache-friendly
* <!-- .element: class="fragment fade-in" --> Adding a new item is easy. The program will allocate the needed memory for the node and inform the previous node (if there are any) about its location.
* <!-- .element: class="fragment fade-in" --> Deleting an item is fast, the program frees memory allocated to a given node and informs the previous node so that it can change its pointer.
* <!-- .element: class="fragment fade-in" --> Searching for a node (e.g. to remove or insert a new element after it) is already expensive, because we have to iterate through all the nodes one by one until we find the wanted one (even if we know exactly that it is e.g. the 40th element in the list)

___
<!-- .slide: style="font-size: 0.9em" -->

### `std::forward_list<T>` methods

* <!-- .element: class="fragment fade-in" --> adding an item: <code>push_front()</code>, <code>emplace_front()</code>, <code>insert_after()</code>, <code>emplace_after()</code>
* <!-- .element: class="fragment fade-in" --> modify/access an item: find the item yourself
* <!-- .element: class="fragment fade-in" --> first/last item: <code>front()</code>
* <!-- .element: class="fragment fade-in" --> size/is the container empty: we do not have <code>size()</code>, <code>empty()</code> is only available
* <!-- .element: class="fragment fade-in" --> start/end iterator: <code>begin()</code>, <code>end()</code>
* <!-- .element: class="fragment fade-in" --> an iterator that points to the element before <code>begin()</code>: <code>before_begin()</code>
* <!-- .element: class="fragment fade-in" --> constant iterator: <code>cbegin()</code>, <code>cend()</code>, <code>cbefore_begin()</code>
* <!-- .element: class="fragment fade-in" --> container clearing: <code>clear()</code>
* <!-- .element: class="fragment fade-in" --> sort list: <code>sort()</code>
* <!-- .element: class="fragment fade-in" --> reverse list: <code>reverse()</code>
* <!-- .element: class="fragment fade-in" --> removing duplicates: <code>unique()</code>
* <!-- .element: class="fragment fade-in" --> removing items from the list: <code>remove()</code>
* <!-- .element: class="fragment fade-in" --> erasing items from memory: <code>erase_after()</code>
* <!-- .element: class="fragment fade-in" --> erase items from memory using <code>&lt;algorithm&gt;</code>: <code>erase()</code>
* <!-- .element: class="fragment fade-in" --> replacement of the entire container: <code>swap()</code>

___

## `std::forward_list<T>::insert_after()` && `std::forward_list<T>::before_begin()`
<!-- .element: style="font-size: 1.2em" -->

A singly linked list allows us to insert an element after a specific node.
If we want to put value at the beginning of the list using the `insert_after`, we need to give it a special iterator `before_begin` that points to the element before the first node of the list.
Thus, the method `insert_after()` will insert the desired value exactly as the first item in the list.
<!-- .element: class="fragment fade-in" -->

```cpp
std::forward_list<int> list {1, 2, 3, 4, 5, 6};
list.insert_after(list.begin(), 10);
print(list);
list.insert_after(list.before_begin(), 0);
print(list);
```
<!-- .element: class="fragment fade-in" -->

Output:
<!-- .element: class="fragment fade-in" -->

```cpp
1 10 2 3 4 5 6
0 1 10 2 3 4 5 6
```
<!-- .element: class="fragment fade-in" -->

___

## `std::forward_list<T>::remove()`

Because list includes its own method `remove()`, we no longer need to use `erase()`.
<!-- .element: class="fragment fade-in" -->

```cpp
std::forward_list<int> list {1, 4, 2, 4, 3, 4, 5};
list.remove(4);
// {1, 2, 3, 5}
```
<!-- .element: class="fragment fade-in" -->

___

## `std::forward_list<T>::erase_after()`
<!-- .element: style="font-size: 1.3em" -->

Erase_after is used to remove nodes from the position after the element indicated by the first iterator to the point indicated by the second iterator (without the element pointed to by it).
<!-- .element: class="fragment fade-in" -->

```cpp
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

```cpp
it: 5
it2: 8
1 2 3 4 5 8 9 10
```
<!-- .element: class="fragment fade-in" -->

___

## Task 5

* Find documentation about `std::forward_list` on [cppreference.com](https://en.cppreference.com)
* Use the code from `std::list` task
* Create a singly-linked list containing items from 0 to 5
* Print list
* Remove 3rd item from the list
* Add the value 10 to the beginning and end of the list
* Print list
* Add the number 20 in the fourth position
* Print list

___

## Q&A
