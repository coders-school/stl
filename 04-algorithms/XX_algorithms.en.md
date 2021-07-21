<!-- .slide: data-background="#111111" -->

# Algorithms

___

## Types of algorithms

What algorithms do you know?:

* <!-- .element: class="fragment fade-in" --> Non-modifying sequences?
* <!-- .element: class="fragment fade-in" --> Modifying sequences?
* <!-- .element: class="fragment fade-in" --> Partitioning?
* <!-- .element: class="fragment fade-in" --> Sorting?
* <!-- .element: class="fragment fade-in" --> Binary searching?
* <!-- .element: class="fragment fade-in" --> Operating on the heap?
* <!-- .element: class="fragment fade-in" --> Min/max?
* <!-- .element: class="fragment fade-in" --> Comparing?
* <!-- .element: class="fragment fade-in" --> Performing permutations?
* <!-- .element: class="fragment fade-in" --> Numeric?

___

## Quiz

Using [cppreference](https://en.cppreference.com/w/) answer the questions:

* <!-- .element: class="fragment fade-in" --> What complexity does <code>std::sort()</code> have?
* <!-- .element: class="fragment fade-in" --> Which algorithm will you use to connect 2 containers alternately?
* <!-- .element: class="fragment fade-in" --> What algorithm will you use to sum all the elements in <code>std::vector</code>?
* <!-- .element: class="fragment fade-in" --> What algorithm will you use to multiply 2 containers together?
* <!-- .element: class="fragment fade-in" --> What algorithm will you use to remove even numbers?
* <!-- .element: class="fragment fade-in" --> What algorithm will you use to fill the structure with values ​​from 0 to n?
* <!-- .element: class="fragment fade-in" --> What algorithm will you use to make the largest element always in the 1st place (0 index)?
* <!-- .element: class="fragment fade-in" --> What algorithm will you use to find if a given number is in a sorted container?
* <!-- .element: class="fragment fade-in" --> What algorithm will you use to split a container into 2 ranges containing greater and less than 10?
* <!-- .element: class="fragment fade-in" --> What algorithm will you use to reorder 2 items in a container?

___

## std :: rotate

<iframe data-src = "https://www.youtube.com/embed/W2tWOdzgXHA?start=560" width = "800px" height = "450px"> </iframe>

[Link to the video](https://youtu.be/W2tWOdzgXHA?t=560)

___

## Task 1

Write a function that takes `std::vector<int>&`, a variable `int value`, and a variable `int new_pos`. The function should find `value` in `std::vector<int>` and if it finds it, put it in a new place `new_pos` by properly shifting the rest of the elements so as not to disturb their order. Then return `true` if the process was successful, or `false` if the order could not be changed (e.g., the value does not exist).

`bool ChangePos(std::vector<int>& vec, int value, int new_pos)`
<!-- .element: class="fragment fade-in" -->

___

## Solution 1

```cpp
bool ChangePos(std::vector<int>& vec, int value, int new_pos) {
    if (new_pos >= vec.size()) {
        return false;
    }

    auto begin = vec.begin();
    auto end = vec.end();
    auto it = std::find(begin, end, value);
    if (it == end) {
        return false;
    }

    auto item_pos = std::distance(begin, it);
    if (item_pos > new_pos) {
        std::rotate(begin + new_pos, begin + item_pos, begin + item_pos + 1);
    } else {
        std::rotate(begin + item_pos, begin + item_pos + 1, begin + new_pos + 1);
    }

    return true;
}
```

___

## std :: stable_partition

<iframe data-src = "https://www.youtube.com/embed/W2tWOdzgXHA?start=798" width = "800px" height = "450px"> </iframe>

[Video example](https://youtu.be/W2tWOdzgXHA?t=798)

___

## Task 2

Write a function that takes two `std::vector<int>` and a variable `int`. First `std::vector<int>` contains the container on which we operate, the second contains the values ​​we want to transfer, and the value `int` is the index number to which we want to transfer the values.

`void ChangePos(std::vector<int>& vec, const std::vector<int>& values, int position)`
<!-- .element: class="fragment fade-in" -->

___
<!-- .slide: style="font-size: 0.9em" -->

## Solution 2

```cpp
void ChangePos(std::vector<int>& vec, const std::vector<int>& values, int new_pos) {
    auto pred {[&](auto& el){
        return (std::find(values.begin(), values.end(), el) == values.end());
    }};

    auto middle = vec.begin() + new_pos + values.size() - 1;
    std::stable_partition(vec.begin(), middle, pred);
    std::stable_partition(middle, vec.end(), [&](auto& el){ return !pred(el); });
}

void PrintVec(const std::vector<int>& vec) {
    for (const auto el : vec) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    PrintVec(vec);
    ChangePos(vec, {1, 3, 9}, 4);
    PrintVec(vec);

    return 0;
}
```

___

## Task 3

Write a Gather function that will take `std::vector<char>` and will put all appearances of `*` to the middle of `std::vector<char>`.

Input: `std::vector<char> vec {'*', '@', '*', '#', '@', '^', '*', '(', ')', '*'};`
<!-- .element: class="fragment fade-in" -->

Output: `@ # @ * * * * ^ ( )`
<!-- .element: class="fragment fade-in" -->
___
<!-- .slide: style="font-size: 0.9em" -->

## Solution 3

```cpp
void Gather(std::vector<char>& vec) {
    auto pred {[&](auto& el){
        return el != '*';
    }};

    auto middle = vec.begin() + vec.size() / 2;
    std::stable_partition(vec.begin(), middle, pred);
    std::stable_partition(middle, vec.end(), [&](auto& el){ return !pred(el); });
}

void PrintVec(const std::vector<char>& vec) {
    for (const auto el : vec) {
        std::cout << el << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::vector<char> vec {'*', '$', '@', '*', '#', '@', '^', '*', '(', ')', '$', '*'};
    PrintVec(vec);
    Gather(vec);
    PrintVec(vec);

    return 0;
}
```

___

## Task 4

Write a function `GetVec(size_t count)` which will return `std::vector<int>` with values ​​from `10` to `10 + n` by incrementing them by 1. Then write the second function `int Multiply(std::vector<int> vec)` which will return a value equal to the product of each element of `std::vector<int>`.

Input: `GetVec(7)`
<!-- .element: class="fragment fade-in" -->

Output: `{10, 11, 12, 13, 14, 15, 16}`
<!-- .element: class="fragment fade-in" -->

Input: `Multiply(vec)`
<!-- .element: class="fragment fade-in" -->

Output: `57657600`
<!-- .element: class="fragment fade-in" -->

___

## Solution 4

```cpp
std::vector<int> GetVec(size_t count) {
    std::vector<int> vec(count);
    std::iota(begin(vec), end(vec), 10);
    return vec;
}

int Multiply(const std::vector<int>& vec) {
    return std::accumulate(begin(vec), end(vec), 1, std::multiplies<int>());
}

int main() {
    std::cout << Multiply(GetVec(7)) << '\n';

    return 0;
}
```

___

## Q&A
