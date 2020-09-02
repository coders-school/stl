<!-- .slide: data-background="#111111" -->

# `std::array<T, N>`

## Fixed size array

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## Features `std::array<T, N>`

* <!-- .element: class="fragment fade-in" --> Cache-friendly, i.e. by iterating through <code>std::array&lt;T, N&gt;</code>, it will all be loaded into the CPU cache, which will speed up reading the data
* <!-- .element: class="fragment fade-in" --> Type <code>&lt;T&gt;</code> can be any. Both the built-in type as int, double, and the own type defined by us
* <!-- .element: class="fragment fade-in" --> Type <code>&lt;N&gt;</code> denotes the size of the array, which must be known at compile time
* <!-- .element: class="fragment fade-in" --> The items are arranged side by side in memory just like in a regular array
* <!-- .element: class="fragment fade-in" --> <code>std::array</code> is the most primitive <code>wrapperem</code> on regular arrays, using it is practically just as efficient
* <!-- .element: class="fragment fade-in" --> We cannot add a new item, we can only modify the existing fields
* <!-- .element: class="fragment fade-in" --> Reading and modifying elements is very fast
* <!-- .element: class="fragment fade-in" --> Just as we cannot add elements, we cannot remove them (size does not change)

___

## Operations on `std::array<T, N>`

* <!-- .element: class="fragment fade-in" --> adding an item: can't
* <!-- .element: class="fragment fade-in" --> modifying / accessing an item: <code>at()</code>, <code>operator[]</code>
* <!-- .element: class="fragment fade-in" --> first / last item: <code>back()</code>, <code>front()</code>
* <!-- .element: class="fragment fade-in" --> size / is the container empty: <code>size()</code>, <code>empty()</code>
* <!-- .element: class="fragment fade-in" --> start / end iterator: <code>begin()</code>, <code>end()</code>
* <!-- .element: class="fragment fade-in" --> reverse iterator: <code>rbegin()</code>, <code>rend()</code>
* <!-- .element: class="fragment fade-in" --> constant iterator: <code>cbegin()</code>, <code>cend()</code>, <code>crbegin()</code>, <code>crend()</code>
* <!-- .element: class="fragment fade-in" --> container cleaning: you can't, but we have a method <code>fill</code>which we can, for example, reset all elements
* <!-- .element: class="fragment fade-in" --> preparing item for removal: impossible
* <!-- .element: class="fragment fade-in" --> erasing items from memory: impossible
* <!-- .element: class="fragment fade-in" --> replacement of the entire container: <code>swap()</code>

___

### Handover `std::array<T, N>` to function

Because `std::array<T, N>` has 2 template parameters, some may have a problem passing it to a function as typing `std::array<T>` forgetting the size of the board.
<!-- .element: class="fragment fade-in" -->

```cpp
void print(const std::array<int, 10>& arr) {
    for (const auto& el : arr) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::array<int, 10> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print(arr);

    return 0;
}
```
<!-- .element: class="fragment fade-in" -->

___

## Task

* Find documentation `std::array` on [cppreference.com](https://en.cppreference.com)
* Create new cpp file and write function `main()`
* Create `std::array` size 10
* Fill it with 5 values
* Assign the value 3 to the fourth item
* Create another board with the same size
* Replace arrays
* List both tables, each on a separate line

___

## Q&A
