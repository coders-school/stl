<!-- .slide: data-background="#111111" -->

# `std::deque<T>`

## Double-ended queue

<a href="https://coders.school">
    <img width="500" data-src="../img/coders_school_logo.png" src="../img/coders_school_logo.png"  alt="Coders School" class="plain">
</a>

___

## `std::deque<T>` traits

* <!-- .element: class="fragment fade-in" --> List and vector hybrid
* <!-- .element: class="fragment fade-in" --> <code>deque</code> is divided into chunks, which are arrays scattered around the memory
* <!-- .element: class="fragment fade-in" --> The compiler decides the size of such array (there is no rule)
* <!-- .element: class="fragment fade-in" --> Additionally, deque comes with one more vector that holds pointers that indicate the start of each chunk in memory.
* <!-- .element: class="fragment fade-in" --> This way we get 2 things:
  * Adding a new item is faster because we always allocate memory for the whole chunk and we will not move items like in `std::vector<T>` when we run out of space to allocate additional memory
  * Data loaded from one chunk are cache-friendly

___

## `std::deque<T>` structure

<img height="600" data-src="img/deque-white.png" src="img/deque-white.png" alt="deque" class="plain">

___

## `std::deque<T>` traits cont.

* <!-- .element: class="fragment fade-in" --> Partially cache-friendly, that is, individual chunk will be in the processor cache
* <!-- .element: class="fragment fade-in" --> Type <code>&lt;T&gt;</code> can be any type. Both the built-in type like <code>int</code>, <code>double</code> as well as type defined by us
* <!-- .element: class="fragment fade-in" --> Each chunk is represented in memory like an array, while chunk themselves are not adjacent to each other and are spread out like list nodes
* <!-- .element: class="fragment fade-in" --> Adding a new item is quick
  * If given chunk still has free space we write it at the end
  * If not, a new chunk is allocated and new element is put there
* <!-- .element: class="fragment fade-in" --> Removal from the beginning and end is fast as it only shifts the iterators <code>begin()</code> or <code>end()</code>
* <!-- .element: class="fragment fade-in" --> Removing elements from the inside is expensive
* <!-- .element: class="fragment fade-in" --> Reading and modification is fast
  * We know the chunk size, so we know exactly from which element in our support vector we should read the chunk address
  * We also know which element to read the data from, because chunk is arranged like an array.

___

## Access to the item

Mathematically speaking: if chunk has 16 elements and we want to get to the 100th element then:

* `x = 100 / 16 -> x = 6` (truncate the decimal point)
* `y = 100 % 16 -> y = 4`

So we know that this is the 4th element in 6th chunk.
<!-- .element: class="fragment fade-in" -->

This knowledge is completely unnecessary when using `std::deque`. The container takes care of this automatically.
<!-- .element: class="fragment fade-in" -->

___

### `std::deque<T>` methods

* <!-- .element: class="fragment fade-in" --> adding an item: <code>push_back()</code>, <code>emplace_back()</code>, <code>push_front()</code>, <code>emplace_front()</code>, <code>insert()</code>
* <!-- .element: class="fragment fade-in" --> modifying/accessing an item: <code>at()</code>, <code>operator[]</code>
* <!-- .element: class="fragment fade-in" --> first/last item: <code>back()</code>, <code>front()</code>
* <!-- .element: class="fragment fade-in" --> size/is the container empty: <code>size()</code>, <code>empty()</code>
* <!-- .element: class="fragment fade-in" --> clearing unused memory: <code>shrink_to_fit()</code>,
* <!-- .element: class="fragment fade-in" --> start/end iterator: <code>begin()</code>, <code>end()</code>
* <!-- .element: class="fragment fade-in" --> reverse iterator: <code>rbegin()</code>, <code>rend()</code>
* <!-- .element: class="fragment fade-in" --> constant iterator: <code>cbegin()</code>, <code>cend()</code>, <code>crbegin()</code>, <code>crend()</code>
* <!-- .element: class="fragment fade-in" --> container clearing: <code>clear()</code>
* <!-- .element: class="fragment fade-in" --> preparing an item for removal: <code>remove()</code> (not <code>std::deque</code> method),
* <!-- .element: class="fragment fade-in" --> erasing items from memory: <code>erase()</code>
* <!-- .element: class="fragment fade-in" --> replacement of the entire container: <code>swap()</code>

___

### Example

```cpp []
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

* Find documentation about `std::deque` on [cppreference.com](https://en.cppreference.com)
* Create new cpp file and write `main()` function
* Create empty `deque`
* Add any 5 values ​​to it
* Print deque
* Delete the 2nd and 4th item
* Add the value 30 to the beginning and end
* Print deque
* Add the number 20 to the 4th position
* Print deque

___

## Q&A
