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

### Which container should you choose?

#### Sequential #1

* <!-- .element: class="fragment fade-in" --> Use <code>std:vector</code> as your default sequential container, especially as an alternative to built-in arrays
* <!-- .element: class="fragment fade-in" --> If size is known in advance, use <code>std::array</code> instead of a built-in array
* <!-- .element: class="fragment fade-in" --> If you add or remove elements frequently at both the front and back of a container, use <code>std::deque</code>
* <!-- .element: class="fragment fade-in" --> Use a <code>std::list</code> instead of <code>std::deque</code> if you need to insert/remove elements in the middle of the sequence
* <!-- .element: class="fragment fade-in" --> Always prefer <code>std::forward_list</code> over <code>std::list</code>
* <!-- .element: class="fragment fade-in" --> Do not use <code>std::list/std::forward_list</code> if you need random access to objects
* <!-- .element: class="fragment fade-in" --> Prefer <code>std::vector</code> over <code>std::list</code> (cache memory)

___

### Which container should you choose?

#### Sequential #2

* <!-- .element: class="fragment fade-in" --> If all your elements require a significant amount of memory do not use <code>std::array</code> (stack limitations)
* <!-- .element: class="fragment fade-in" --> The smaller your elements are, the more probable you should use <code>std::vector</code>
* <!-- .element: class="fragment fade-in" --> The bigger your elements are, the more probable you should consider <code>std::list/std::forward_list</code>
* <!-- .element: class="fragment fade-in" --> If copying elements is very expensive and insertions will be frequent, consider <code>std::list/std::forward_list</code>
* <!-- .element: class="fragment fade-in" --> <code>std::string</code> is almost always better than a C-string

___

### Which container should you choose?

#### Associative

* <!-- .element: class="fragment fade-in" --> Prefer unordered versions of associative containers. Only if element order matters use ordered versions.
* <!-- .element: class="fragment fade-in" --> If you need multiple entries for the same key, use <code>std::unordered_multimap</code>, or if element order matters, <code>std::multimap</code>
* <!-- .element: class="fragment fade-in" --> If you need all your elements to be sorted all the time use <code>std::set</code>, <code>std::multiset</code> or <code>std::priority_queue</code>
* <!-- .element: class="fragment fade-in" --> If you need sorting occasionally, consider using <code>std::vector</code> and sort it with <code>std::sort()</code> when necessary

___

### Which container should you choose?

#### General advice

* <!-- .element: class="fragment fade-in" --> By default use <code>std::vector</code>
* <!-- .element: class="fragment fade-in" --> Measure, if you think that something else might be better.
* <!-- .element: class="fragment fade-in" --> Use <code>std::map</code> if you need to store key and value pairs and you like accessing it with <code>operator[]</code>, but for better performance on small amount of elements you can use <code>std::vector&lt;std::pair&lt;Key, Value&gt;&gt;</code>

[Why you should avoid Linked Lists - Bjarne Stroustrup](https://www.youtube.com/watch?v=YQs6IC-vgmo)
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
