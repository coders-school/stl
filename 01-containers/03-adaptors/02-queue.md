<!-- .slide: data-background="#111111" -->

# `std::queue<T>`

## FIFO data structure

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## FIFO

<img src="../img/queue.svg" alt="FIFO - queue" class="r-stretch plain">

___

## `std::queue<T>` traits

* <!-- .element: class="fragment fade-in" --> The queue pushes the elements on the back of the underlying container and pops them from the front.
* <!-- .element: class="fragment fade-in" --> <code>std::deque&lt;T&gt;</code> is the default underlying container
* <!-- .element: class="fragment fade-in" --> The underlying container can be any of:
  * <code>std::deque&lt;T&gt;</code>
  * <code>std::list&lt;T&gt;</code>

___

## `std::queue<T>` methods

[`std::queue<T>` on cppreference.org](https://en.cppreference.com/w/cpp/container/queue)

* <!-- .element: class="fragment fade-in" --> adding an item: <code>push()</code>, <code>emplace()</code>
* <!-- .element: class="fragment fade-in" --> accessing an item: <code>front()</code>, <code>back()</code>
* <!-- .element: class="fragment fade-in" --> removing an item: <code>pop()</code>
* <!-- .element: class="fragment fade-in" --> size/is the container empty: <code>size()</code>, <code>empty()</code>
