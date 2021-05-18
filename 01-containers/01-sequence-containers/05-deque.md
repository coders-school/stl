<!-- .slide: data-background="#111111" -->

# `std::deque<T>`

## Double-ended queue

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png"  alt="Coders School" class="plain">
</a>

___

## `std::deque<T>` traits

* <!-- .element: class="fragment fade-in" --> The hybrid of a list and a vector
* <!-- .element: class="fragment fade-in" --> <code>deque</code> is divided into chunks of arrays, which are scattered around the memory
* <!-- .element: class="fragment fade-in" --> The size of chunks in up to the implementation
* <!-- .element: class="fragment fade-in" --> Additionally, deque comes with one more vector of pointers that indicate the start of each chunk in memory.
* <!-- .element: class="fragment fade-in" --> This way we get 2 things:
  * Adding a new item is faster because we always allocate memory for the whole chunk and we will not move items like in `std::vector<T>` when we run out of space to allocate additional memory
  * The data from one chunk is cache-friendly, but the whole `std::deque` is not

___

## `std::deque<T>` structure

<img height="600" src="../img/deque-white.png" src="img/deque-white.png" alt="deque" class="plain">

___

## `std::deque<T>` traits cont.

* <!-- .element: class="fragment fade-in" --> Each chunk is represented in memory like an array, while chunks themselves are not adjacent to each other and are spread out like list nodes
* <!-- .element: class="fragment fade-in" --> Adding a new item is cheap
  * If a given chunk still has free space, we save it at the end/beginning
  * If not, a new chunk is allocated and the new element is put there
* <!-- .element: class="fragment fade-in" --> Removal from the beginning and end is cheap - it only shifts the iterators <code>begin()</code> or <code>end()</code>
* <!-- .element: class="fragment fade-in" --> Removing elements from the inside is expensive
* <!-- .element: class="fragment fade-in" --> Reading and modification is cheap
  * We know the chunk size, so we know exactly from which element in our mapping vector we should read the chunk address
  * We also know which element to read the data from, because the chunk is arranged like an array.

___

## Accessing the item

Mathematically speaking: if chunk has 16 elements and we want to get to the 100th element then:

* chunk no: `x = 100 / 16 -> x = 6`
* position: `y = 100 % 16 -> y = 4`

So we know that this is the 4th element in the 6th chunk.
<!-- .element: class="fragment fade-in" -->

This knowledge is completely unnecessary when using `std::deque`. The container takes care of this automatically.
<!-- .element: class="fragment fade-in" -->

___

### `std::deque<T>` methods

##### [`std::deque<T>` on cppreference.org](https://en.cppreference.com/w/cpp/container/deque)


* <!-- .element: class="fragment fade-in" --> adding an item: <code>push_back()</code>, <code>emplace_back()</code>, <code>push_front()</code>, <code>emplace_front()</code>, <code>insert()</code>
* <!-- .element: class="fragment fade-in" --> modifying/accessing an item: <code class="fragment highlight-green">at()</code>, <code class="fragment highlight-green">operator[]</code>
* <!-- .element: class="fragment fade-in" --> first/last item: <code>back()</code>, <code>front()</code>
* <!-- .element: class="fragment fade-in" --> size/is the container empty: <code>size()</code>, <code>empty()</code>
* <!-- .element: class="fragment fade-in" --> clearing unused memory: <code class="fragment highlight-green">shrink_to_fit()</code>
* <!-- .element: class="fragment fade-in" --> start/end iterator: <code>begin()</code>, <code>end()</code>
* <!-- .element: class="fragment fade-in" --> reverse iterator: <code>rbegin()</code>, <code>rend()</code>
* <!-- .element: class="fragment fade-in" --> constant iterator: <code>cbegin()</code>, <code>cend()</code>, <code>crbegin()</code>, <code>crend()</code>
* <!-- .element: class="fragment fade-in" --> clearing the container: <code>clear()</code>
* <!-- .element: class="fragment fade-in" --> preparing an item for removal: <code>remove()</code> (not <code>std::deque</code> method),
* <!-- .element: class="fragment fade-in" --> erasing items from memory: <code>erase()</code>
* <!-- .element: class="fragment fade-in" --> replacement of the entire container: <code>swap()</code>

___

## Operations complexity

* <!-- .element: class="fragment fade-in" --> Insertion/deletion
  * <!-- .element: class="fragment fade-in" --> <code>O(1)</code> - at the end or at the beginning
  * <!-- .element: class="fragment fade-in" --> <code>O(n)</code> - other
* <!-- .element: class="fragment fade-in" --> Access
  * <!-- .element: class="fragment fade-in" --> <code>O(1)</code>
* <!-- .element: class="fragment fade-in" --> Searching
  * <!-- .element: class="fragment fade-in" --> <code>O(n)</code>

___

## Memory usage

* <!-- .element: class="fragment fade-in" --> <code>n * sizeof(T) + n / chunk_size</code>
* <!-- .element: class="fragment fade-in" --> <code>O(n)</code>
* <!-- .element: class="fragment fade-in" --> Additional memory for vector of pointers is used
* <!-- .element: class="fragment fade-in" --> Additional internal data is used (size, begin, end, allocator)

___

## Iterator invalidation

* <!-- .element: class="fragment fade-in" --> Insertion and deletion at either end of a deque never invalidates pointers or references to the rest of the elements.
* <!-- .element: class="fragment fade-in" --> Otherwise - all iterators are invalidated (including the past-the-end iterator).

___

## Task

9. Add measurements for accessing the middle elements of std::deque of size 100K and 1M.

10. Refactor the code, eg. create `measureBoth` function that takes 2 containers of the same type to simplify the code.
