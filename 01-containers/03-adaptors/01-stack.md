<!-- .slide: data-background="#111111" -->

# `std::stack<T>`

## LIFO data structure

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## LIFO

<img src="../img/stack.png" alt="LIFO - stack" class="r-stretch plain">

___

## `std::stack<T>` traits

* <!-- .element: class="fragment fade-in" --> The stack pushes and pops the element from the back of the underlying container, known as the top of the stack.
* <!-- .element: class="fragment fade-in" --> <code>std::deque&lt;T&gt;</code> is the default underlying container
* <!-- .element: class="fragment fade-in" --> The underlying container can be any of:
  * <code>std::vector&lt;T&gt;</code>
  * <code>std::deque&lt;T&gt;</code>
  * <code>std::list&lt;T&gt;</code>

___

## `std::stack<T>` methods

[`std::stack<T>` on cppreference.org](https://en.cppreference.com/w/cpp/container/stack)

* <!-- .element: class="fragment fade-in" --> adding an item: <code>push()</code>, <code>emplace()</code>
* <!-- .element: class="fragment fade-in" --> accessing an item: <code>top()</code>
* <!-- .element: class="fragment fade-in" --> removing an item: <code>pop()</code>
* <!-- .element: class="fragment fade-in" --> size/is the container empty: <code>size()</code>, <code>empty()</code>
