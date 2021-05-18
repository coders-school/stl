<!-- .slide: data-background="#111111" -->

# STL containers

## Recap

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## How did you enjoy this training session?

## What was the most surprising for you?

___

## Recap

Mention containers from these groups:

1. <!-- .element: class="fragment fade-in" --> Sequence containers
2. <!-- .element: class="fragment fade-in" --> Associative containers
3. <!-- .element: class="fragment fade-in" --> Adaptors
4. <!-- .element: class="fragment fade-in" --> Other containers

___

### What is the difference between `std::stack` and `std::priority_queue`?

`std::priority_queue` is a sorted `std::stack`. Sorting is done during insertion.
<!-- .element: class="fragment fade-in" -->

___

### What is the complexity of operations of `std::deque`?

<div class="fragment fade-in">

* Insertion/deletion
  * `O(1)` - at the end or at the beginning
  * `O(n)` - other
* Access
  * `O(1)`
* Searching
  * `O(n)`

</div>

___

### What is the role of `operator[]` in `std::map`?

It returns a reference to value under the provided key. If it does not exist, it is created with the default constructor.
<!-- .element: class="fragment fade-in" -->

___

## Pre-test answers 1/3 🤯

### Mark true statements about STL containers

1. <!-- .element: class="fragment highlight-green" --> In <code>std::deque</code>, items can be added from both sides using <code>push_front()</code> and <code>push_back()</code>, respectively.
2. <!-- .element: class="fragment highlight-red" --> <code>std::set</code> supports random access to contained elements.
3. <!-- .element: class="fragment highlight-green" --> <code>std::vector</code> supports random access to contained elements.
4. <!-- .element: class="fragment highlight-green" --> <code>std::deque</code> supports random access to contained elements.
5. <!-- .element: class="fragment highlight-green" --> <code>std::multimap</code> allows multiple values to be stored for every key value.

___

## Pre-test answers 2/3 🤯

### Which of the following containers are contiguous?

1. <!-- .element: class="fragment highlight-red" --> <code>deque</code>
2. <!-- .element: class="fragment highlight-green" --> <code>vector</code>
3. <!-- .element: class="fragment highlight-red" --> <code>unordered_set</code>
4. <!-- .element: class="fragment highlight-green" --> <code>array</code>
5. <!-- .element: class="fragment highlight-red" --> <code>forward_list</code>

___
<!-- .slide: style="font-size: 0.95em" -->

## Pre-test answers 3/3 🤯

### What is the complexity of operations on `std::unordered_map`?

1. <!-- .element: class="fragment highlight-red" --> Inserting/removing <code>O(log n)</code>, accessing <code>O(1)</code>, searching <code>O(log n)</code>
2. <!-- .element: class="fragment highlight-green" --> Inserting/removing <code>O(1)</code>, accessing <code>O(1)</code>, searching <code>O(1)</code> <span class="fragment fade-in">average-case</span>
3. <!-- .element: class="fragment highlight-green" --> Inserting/removing <code>O(n)</code>, accessing <code>O(n)</code>, searching <code>O(n)</code> <span class="fragment fade-in">worst-case</span>
4. <!-- .element: class="fragment highlight-red" --> Inserting/removing <code>O(nlog n)</code>, accessing <code>O(log n)</code>, searching <code>O(n)</code>
5. <!-- .element: class="fragment highlight-red" --> Inserting/removing <code>O(nlog n)</code>, accessing <code>O(1)</code>, searching <code>O(log n)</code>

___

## [Rate this training session](https://forms.gle/ADXRttpAaZgW8KwM6)
