<!-- .slide: data-background="#111111" -->

# `std::deque<T>`

## Double-sided queue

### deque = double ended queue

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" src="../coders_school_logo.png"  alt="Coders School" class="plain">
</a>

___

## Features `std::deque<T>`

* <!-- .element: class="fragment fade-in" --> List and vector hybrid
* <!-- .element: class="fragment fade-in" --> <code>deque</code> it is broken up into chunks, which are arrays scattered around the memory
* <!-- .element: class="fragment fade-in" --> The compiler decides the size of such a piece (there is no single rule)
* <!-- .element: class="fragment fade-in" --> Additionally, deque comes with one more vector that holds pointers that indicate the start of each `chunka` in memory.
* <!-- .element: class="fragment fade-in" --> This way we get 2 things:
  * Adding a new item is faster because we always allocate memory for the whole `chunka` and we will not move items like in `std::vector<T>`when we run out of space to allocate additional memory
  * Data loaded from one `chunka` are cache-friendly

___
<!-- .slide: data-background="#eee" -->

## Structure `std::deque<T>`

<img height="600" data-src="img/deque.png" src="img/deque.png" alt="deque" class="plain">

___

## Features `std::deque<T>` cont.

* <!-- .element: class="fragment fade-in" --> Partially cache-friendly, that is, individual `chunki` will be in the processor cache
* <!-- .element: class="fragment fade-in" --> Type <code>&lt;T&gt;</code> can be any. Both the built-in type and the <code>int</code>, <code>double</code>as well as your own type defined by us
* <!-- .element: class="fragment fade-in" --> Each `chunk` is represented in memory like an array, while the same `chunki` they are not adjacent to each other and are spread out like list nodes
* <!-- .element: class="fragment fade-in" --> Adding a new item is quick
  * If given `chunk` there is still a place to write it at the end
  * If not, a new chunk is allocated and the new element is entered there
* <!-- .element: class="fragment fade-in" --> Removal from the beginning and end is fast as it only shifts the iterators <code>begin()</code> or <code>end()</code>
* <!-- .element: class="fragment fade-in" --> Removing elements from the inside is costly
* <!-- .element: class="fragment fade-in" --> Reading and modification is fast
  * We know the size `chunka`, so we know exactly which field in our support vector we should read the address from `chunka`
  * We also know which field to read the data from, because `chunk` it is arranged like a blackboard.

___

## Access to the item

Mathematically speaking: if `chunk` has 16 elements and we want to get to the 100 element is:

* `x = 100 / 16 -> x = 6` (truncate the decimal point)
* `y = 100 % 16 -> y = 4`

So we know that this is the 4th element in the 6th `chunku`
<!-- .element: class="fragment fade-in" -->

This knowledge is completely unnecessary for use `std::deque`. The container takes care of this automatically.
<!-- .element: class="fragment fade-in" -->

___

### Operations on `std::deque<T>`

* <!-- .element: class="fragment fade-in" --> adding an item: <code>push_back()</code>, <code>emplace_back()</code>, <code>push_front()</code>, <code>emplace_front()</code>, <code>insert()</code>
* <!-- .element: class="fragment fade-in" --> modifying / accessing an item: <code>at()</code>, <code>operator[]</code>
* <!-- .element: class="fragment fade-in" --> first / last item: <code>back()</code>, <code>front()</code>
* <!-- .element: class="fragment fade-in" --> size / is the container empty: <code>size()</code>, <code>empty()</code>
* <!-- .element: class="fragment fade-in" --> clearing unused memory: <code>shrink_to_fit()</code>,
* <!-- .element: class="fragment fade-in" --> start / end iterator: <code>begin()</code>, <code>end()</code>
* <!-- .element: class="fragment fade-in" --> reverse iterator: <code>rbegin()</code>, <code>rend()</code>
* <!-- .element: class="fragment fade-in" --> constant iterator: <code>cbegin()</code>, <code>cend()</code>, <code>crbegin()</code>, <code>crend()</code>
* <!-- .element: class="fragment fade-in" --> container cleaning: <code>clear()</code>
* <!-- .element: class="fragment fade-in" --> preparing an item for removal: <code>remove()</code> (not a method <code>std::deque</code>),
* <!-- .element: class="fragment fade-in" --> erasing items from memory: <code>erase()</code>
* <!-- .element: class="fragment fade-in" --> replacement of the entire container: <code>swap()</code>

___

### Example of use

```cpp
#include <iostream>
#include <deque>

int main() {
    // Create a deque containing integers
    std::deque<int> d = {7, 5, 16, 8};

    // Add an integer to the beginning and end of the deque
    d.push_front(13);
    d.push_back(25);

    // Iterate and print values of the deque
    for(const auto& n : d) {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}
```

Output:

`13 7 5 16 8 25`

___

## Task 6

* Find documentation `std::deque` on [cppreference.com](https://en.cppreference.com)
* Create new cpp file and write function `main()`
* Create empty `deque`
* Add any 5 values ​​to it
* Display deque
* Delete the 2nd and 4th item
* Add the value 30 to the beginning and end
* Display deque
* Add the number 20 to the 4th position
* Display deque

___

## Q&A
