<!-- .slide: data-background="#111111" -->

# `std::valarray<T>`

<a href="https://coders.school">
    <img width="500" src="../img/coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## `std::valarray<T>` traits

* <!-- .element: class="fragment fade-in" --> The class for representing and manipulating arrays of values.
* <!-- .element: class="fragment fade-in" --> It supports element-wise mathematical operations and various forms of generalized subscript operators, slicing and indirect access.
* <!-- .element: class="fragment fade-in" --> Expressions such as <code>v1 = a * v2 + v3;</code> are expanded to loops that executes <code>v1[i] = a * v2[i] + v3[i];</code>

___

## `std::valarray<T>` methods

##### [`std::valarray<T>` on cppreference.org](https://en.cppreference.com/w/cpp/numeric/valarray)

___

## Example

```cpp
#include <iostream>
#include <valarray>

template <typename Container>
void print(const Container& c) {
    std::cout << '\n';
    for (auto element : c) {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::valarray<int> data = {0,1,2,3,4,5,6,7,8,9};
    std::cout << "Initial valarray:";
    print(data);

    data[data > 5] = -1;
    // the type of data > 5 is std::valarray<bool>
    // the type of data[data > 5] is std::mask_array<int>

    std::cout << "After data[data > 5] = -1:";
    print(data);

    data *= 5;
    print(data);
    std::cout << data.sum() << '\n';
}
```
