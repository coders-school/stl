<!-- .slide: data-background="#111111" -->

# Associative containers

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## What is an associative container?

It's a container, in which elements are stored in predefined order.
<!-- .element: class="fragment fade-in" -->

___

## Ordered

* <!-- .element: class="fragment fade-in" --> <code>set</code>
* <!-- .element: class="fragment fade-in" --> <code>multiset</code>
* <!-- .element: class="fragment fade-in" --> <code>map</code>
* <!-- .element: class="fragment fade-in" --> <code>multimap</code>

Associative containers implement sorted data structures that can be quickly searched (`O(log n)` complexity).
<!-- .element: class="fragment fade-in" -->

___

## Unordered (hashed)

* <!-- .element: class="fragment fade-in" --> <code>unordered_set</code>
* <!-- .element: class="fragment fade-in" --> <code>unordered_multiset</code>
* <!-- .element: class="fragment fade-in" --> <code>unordered_map</code>
* <!-- .element: class="fragment fade-in" --> <code>unordered_multimap</code>

Unordered associative containers implement unsorted (hashed) data structures that can be quickly searched (`O(1)` amortized, `O(n)` worst-case complexity).
<!-- .element: class="fragment fade-in" -->

___

## What are the differences between them?

Let's have a discussion!

Consider:

* <!-- .element: class="fragment fade-in-then-semi-out" --> Ordering
* <!-- .element: class="fragment fade-in-then-semi-out" --> Key Type
* <!-- .element: class="fragment fade-in-then-semi-out" --> Uniqueness
* <!-- .element: class="fragment fade-in-then-semi-out" --> Memory usage
* <!-- .element: class="fragment fade-in-then-semi-out" --> Time complexity of accessing the specific element
* <!-- .element: class="fragment fade-in-then-semi-out" --> Time complexity of searching for a matching item
* <!-- .element: class="fragment fade-in-then-semi-out" --> Time complexity of insertion and deletion

___

## Operations complexity

<img src="../img/bigO.png" alt="BigO notation" class="plain r-stretch">
