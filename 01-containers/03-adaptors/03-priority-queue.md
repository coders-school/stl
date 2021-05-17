<!-- .slide: data-background="#111111" -->

# `std::priority_queue<T>`
<!-- .element: style="font-size: 2.2em" -->

## heap data structure

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## `std::priority_queue<T>` traits

* <!-- .element: class="fragment fade-in" --> Provides constant time lookup of the largest (by default) element, at the expense of logarithmic insertion
* <!-- .element: class="fragment fade-in" --> A user-provided comparator can be supplied to change the ordering
* <!-- .element: class="fragment fade-in" --> Elements are sorted on insertion
* <!-- .element: class="fragment fade-in" --> Heap == sorted stack
* <!-- .element: class="fragment fade-in" --> <code>std::vector&lt;T&gt;</code> is the default underlying container
* <!-- .element: class="fragment fade-in" --> The underlying container can be any of:
  * <code>std::vector&lt;T&gt;</code>
  * <code>std::deque&lt;T&gt;</code>

___

## `std::priority_queue<T>` methods

[`std::priority_queue<T>` on cppreference.org](https://en.cppreference.com/w/cpp/container/priority_queue)

* <!-- .element: class="fragment fade-in" --> adding an item: <code>push()</code>, <code>emplace()</code>
* <!-- .element: class="fragment fade-in" --> accessing an item: <code>top()</code>
* <!-- .element: class="fragment fade-in" --> removing an item: <code>pop()</code>
* <!-- .element: class="fragment fade-in" --> size/is the container empty: <code>size()</code>, <code>empty()</code>
