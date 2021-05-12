<!-- .slide: data-background="#111111" -->

# Lambda expressions

## Modern functors

<a href="https://coders.school">
    <img width="500" data-src="../coders_school_logo.png" src="../coders_school_logo.png" alt="Coders School" class="plain">
</a>

___

## What is a lambda expression?

* Introduced in C++11, improved in C++14, C++17, C++20
* Lambda is a function object that can be called for specific parameters and return the result
* Simple to build - `[](){}`
* It is used to shortly write a function object that would normally take up several times as much space
* We gain better readability and greater freedom in operation
* The lambda type is called a closure and is known only to the compiler
* To assign a lambda expression to a variable, it must be of type auto, because only the compiler knows the type of this expression

___

## Creating a simple lambda expression

```cpp
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    []() { std::cout << "Hello"; }    // lambda printing Hello (not called)

    std::vector<int> vec {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vec.erase(std::remove_if(vec.begin(),
                             vec.end(),
                             [](int num) { return num % 2; }),
              vec.end());

    auto print = [](int num) { std::cout << num << ' '; };
    std::for_each(vec.begin(), vec.end(), print);

    return 0;
}
```

___

## Capture list - example

```cpp
int main() {
    int number = 10;
    auto add10 = [number](int num) { return num + number; };
    std::cout << add10(20) << '\n';  // 30

    // auto multiplyByX = [](int num) { return num * number; };
    // compilation error: number not declared

    return 0;
}
```

___

## Capture list

* Square bracket `[]` determines what parameters we want to capture into our expression. For example, we may want to capture some variable with which we want to compare each element of the container
* We can capture the values ​​by reference `[&value]`
* We can also catch them by copy `[value]`
* We can also mix both possibilities `[&by_ref, by_copy, by_copy2]`
* Lambda expressions also allow you to capture anything we need:
  * by copy `[=]`
  * by reference `[&]`
* As long as `[=]` is safe, `[&]` is not always recommended

Question: when [&] can be dangerous?

___

## Generic lambdas

* From C++14 we can write the so-called generic lambdas
* These are reusable lambdas (for different types) and we use `auto` type in them as a parameter
  * `[](const auto first, const auto& second, auto third) {}`
* Writing generic lambdas is effective because they can be easily reused over and over again

```cpp
int multiply(int first, int second) {
    return first * second;
}

int main() {
    int number = 10;
    auto multiplyByX = [&number](auto num) { return multiply(num, number); };
    std::cout << multiplyByX(20) << '\n';

    return 0;
}
```

___

## Return type

* We do not specify a return type, because by default the lambda expression deduces this type from the data contained in its body `{}`
* By default, the type returned by a lambda expression is deduced from the expressions `return`

  ```cpp
  [i{0}](const int el){ return el + i; }; // return type is int
  ```

* If we want to impose a specific return type we do it with `->`

  ```cpp
  [i{0}](const auto el) -> double { return el + i; };
  ```

___

## Q&A

### This time before the tasks, because the topic is difficult :)

___

## Task

1. Create a functor to check if a given number of type `int` is divisible by `6`
2. Create a lambda that takes 2 `int` type arguments and will return their product
3. Create a lambda that will append quotation marks to the given string. e.g.
   * `cow` -> `"cow"`
4. Create a lambda that outputs a string `*`. Each time the function is called, we should get a string longer by one `*`, like so:
   * `*`
   * `**`
   * `***`
   * etc.

___

## Task

1. Create `std::vector<int>` and fill it with whatever values ​​you want
2. Create a lambda that will capture this vector and display its contents
3. Create a lambda that accepts in its argument `int` and display it
4. Use this lambda in the algorithm `std::for_each()` to display the entire container
